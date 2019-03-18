#include "bovwtrainer.h"

TrainBoVWofFeature BoVWTrainer::bovw_=TrainBoVWofFeature::TrainBoVWofFeature();
int BoVWTrainer::cam_id_=-1;

BoVWTrainer::BoVWTrainer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//���û�����������
	feature_type_="SURF";
	descriptor_type_="SURF";

	//��ʼ��BoVWѵ����
	//bovw_=TrainBoVWofFeature::TrainBoVWofFeature(feature_type_,descriptor_type_);

	//����ͷ
	//cam_id_=-1;	//����ͷid

	is_pause_=false;

	//�̳߳�ʼ��
	thread_valid_=false;
	is_pause_=false;
	thread_handle_=NULL;

	bovw_thread_valid_=false;
	bovw_is_pause_=false;
	bovw_thread_handle_=NULL;
}

BoVWTrainer::~BoVWTrainer()
{

}

//********	��Ӧ����	*******

//������������
void BoVWTrainer::setFeatureType()
{
	feature_type_=ui.sample_detector->currentText().toStdString();
	descriptor_type_=ui.sample_extractor->currentText().toStdString();

	int descpitor_l=descriptor_type_.size();	//�޳�˵��������
	int find_p=descpitor_l;
	for(int i=0;i<descpitor_l;i++)
	{
		if(descriptor_type_[i]==' ')
		{
			find_p=i;
			break;
		}
	}
	descriptor_type_=descriptor_type_.substr(0,find_p);

	if(descriptor_type_=="BRIEF"||descriptor_type_=="FREAK")
	{
		QString current_msg=QString::fromLocal8Bit(descriptor_type_.c_str())+QString::fromLocal8Bit(" ������ ������SURF/SIFT/FAST�������: \n");
		ui.text_showfile->setText(current_msg);
	}


	bovw_.setFeatureType(feature_type_,descriptor_type_);
}

//����BoVWѵ����������
void BoVWTrainer::setBoVWFeatureType()
{
	feature_type_=ui.sample_detector->currentText().toStdString();
	descriptor_type_=ui.trainbovw_feature->currentText().toStdString();

	int descpitor_l=descriptor_type_.size();	//�޳�˵��������
	int find_p=descpitor_l;
	for(int i=0;i<descpitor_l;i++)
	{
		if(descriptor_type_[i]==' ')
		{
			find_p=i;
			break;
		}
	}
	descriptor_type_=descriptor_type_.substr(0,find_p);

	bovw_.setFeatureType(feature_type_,descriptor_type_);
}


//���µ�ǰ����ͷ��Ϣ
void BoVWTrainer::updateCameraInfo()
{
	//��ȡ�豸��Ϣ
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	int cam_n=cameras.size();//camera �������ϲ�ѡ��
	int ought_n=cam_n+1;//camera �������ϲ�ѡ��
	int curernt_n=ui.open_camera->count();

	if(curernt_n>cam_n)	//�б��豸�����࣬ɾ������
	{
		for (int i = ought_n; i < curernt_n; i++)
		{
			ui.open_camera->removeItem(i);
		}
	}
	else	//�б��豸�����٣���Ӳ���
	{
		for (int i = curernt_n; i < ought_n; i++)
		{
			ui.open_camera->addItem("");
		}
	}

	//��ȡ����
	camera_name.resize(cam_n);
	for(int i=0;i<cam_n;i++)
	{
		camera_name[i]=cameras[i].description();
	}

	//�����ѡ���б���
	for(int i=0;i<cam_n;i++)
	{
		ui.open_camera->setItemText(i+1,camera_name[i]);
	}
}

//�������õ�����ͷ
void BoVWTrainer::setCamera()
{
	QString current_cam=ui.open_camera->currentText(); 

	cam_id_=-1;
	int cam_n=camera_name.size();
	for(int i=0;i<cam_n;i++)
	{
		if(current_cam==camera_name[i])
		{
			cam_id_=i;	//��������ͷid
		}
	}
}

//ѡ��������ݼ�·��
void BoVWTrainer::selectDatasetPath()
{
	//�������·��
	QString file_name=QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.jpeg *.png *.bmp)")); 

	QTextCodec *code = QTextCodec::codecForName("gb18030");	//�����������
	if(code)
	{
		bovw_.picture_file_path_=code->fromUnicode(file_name).data();
		//�ض��ļ���
	}

	QString current_msg=QString::fromLocal8Bit("��ǰ�������ݼ�·��: \n")+file_name+"\n";
	ui.text_showfile->setText(current_msg);
}

//���в�������
void BoVWTrainer::runSampling()
{
	//�����ļ�
	string folder="feature samples";
	string file_name=descriptor_type_+" samples.dat";
	createFileInFolder(file_name,folder);

	//���������߳�
	if(thread_valid_==true&&is_pause_==true&&thread_handle_!=NULL&&WaitForSingleObject(thread_handle_,5000)!=-1)		//�ָ���ͣ�߳�
	{
		ResumeThread(thread_handle_);
		is_pause_=false;

		QString current_msg=QString::fromLocal8Bit("�ָ����� \n");
		ui.text_showfile->append(current_msg);

		return;
	}
	else if(thread_valid_==false)		//���������߳�
	{
		thread_valid_=true;
		is_pause_=false;
		thread_handle_=CreateThread(NULL,0,threadRunSampling,NULL,0,NULL);

		QString current_msg=QString::fromLocal8Bit("��ʼ�������� \n");
		ui.text_showfile->setText(current_msg);
	}
	else
	{
		QString current_msg=QString::fromLocal8Bit("���ڽ����������� \n");
		ui.text_showfile->append(current_msg);
	}

	//���������Ϣ
	float progress=0; 
	QString info_text;								//��ʾͼƬ����	

	while (WaitForSingleObject(thread_handle_,10)==WAIT_TIMEOUT)	//�ж��̵߳�������� 
	{
		//���½�����
		if(progress<100)
		{
			progress=progress+0.0001*(100-progress);
		}
		ui.progressBar->setValue(int(progress));

		//������������
		updatePrecessInfo();

		//���Ƶ�ǰ����ͼƬ
		drawFeature();

		//ˢ�������¼�
		Sleep(100);
		QCoreApplication::processEvents(QEventLoop::AllEvents,1);
	}	

	ui.progressBar->setValue(100);

	while (WaitForSingleObject(thread_handle_, 100)==WAIT_TIMEOUT)	//�ȴ��߳̽��� 
	{
		Sleep(100);
	}

	if(WaitForSingleObject(thread_handle_,5000)!=-1)	//����������ͷ��߳�
	{
		CloseHandle(thread_handle_);
	}

	QString current_msg=QString::fromLocal8Bit("�������� \n");
	ui.text_showfile->append(current_msg);

	ui.progressBar->setValue(0);

	thread_valid_=false;
	is_pause_=false;
}

//��ͣ��������
void BoVWTrainer::pauseSampling()
{
	if(thread_handle_==NULL||thread_valid_==false||is_pause_==true)	//�ж��߳���Ч��
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("����ͣ���� \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	SuspendThread(thread_handle_);
	is_pause_=true;
}

//ֹͣ��������
void BoVWTrainer::stopSampling()
{
	if(thread_valid_==false)	//�߳���Ч
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("��ֹͣ���������ڱ��������������Ժ�... \n");
	ui.text_showfile->setText(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	if(is_pause_==true)	//����߳���ͣ�������߳�
	{
		ResumeThread(thread_handle_);
		is_pause_=false;
	}

	bovw_.stop_=true;
	is_pause_=false;

	while (WaitForSingleObject(thread_handle_, 100)==WAIT_TIMEOUT)	//�ж��̵߳�������� 
	{
		Sleep(100);
	}

	ui.progressBar->setValue(0);
	if(thread_handle_!=NULL&&WaitForSingleObject(thread_handle_,100)!=-1)
	{
		CloseHandle(thread_handle_);
	}
	thread_valid_=false;

	current_msg=QString::fromLocal8Bit("���˳����� \n");
	ui.text_showfile->append(current_msg);

	QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}

//����BoVW����
void BoVWTrainer::setBoVWlevels()
{
	bovw_.setBoVWlevelsAndBranches(ui.bovw_levels->value(),ui.bovw_branches->value());
}

//����BoVW��֧��
void BoVWTrainer::setBoVWbranches()
{
	bovw_.setBoVWlevelsAndBranches(ui.bovw_levels->value(),ui.bovw_branches->value());
}

//����BoVWѵ��
void BoVWTrainer::runBoVWtrain()
{
	//�����ļ�
	string folder="BoVW";
	string file_name=descriptor_type_+" BoVW.dat";
	createFileInFolder(file_name,folder);

	//���������߳�
	if(bovw_thread_valid_==true&&bovw_is_pause_==true&&bovw_thread_handle_!=NULL&&WaitForSingleObject(bovw_thread_handle_,5000)!=-1)		//�ָ���ͣ�߳�
	{
		ResumeThread(bovw_thread_handle_);
		bovw_is_pause_=false;

		QString current_msg=QString::fromLocal8Bit("�ָ�BoVWѵ�� \n");
		ui.text_showfile->append(current_msg);

		return;
	}
	else if(bovw_thread_valid_==false)		//���������߳�
	{
		bovw_thread_valid_=true;
		bovw_is_pause_=false;
		bovw_thread_handle_=CreateThread(NULL,0,threadRunBoVWtrain,NULL,0,NULL);

		QString current_msg=QString::fromLocal8Bit("��ʼBoVWѵ�� \n");
		ui.text_showfile->setText(current_msg);
	}
	else
	{
		QString current_msg=QString::fromLocal8Bit("����ѵ��BoVW \n");
		ui.text_showfile->append(current_msg);
	}

	//���������Ϣ
	float progress=0; 
	QString info_text;								//��ʾͼƬ����	

	while (WaitForSingleObject(bovw_thread_handle_,10)==WAIT_TIMEOUT)	//�ж��̵߳�������� 
	{
		//���½�����
		if(progress<100)
		{
			progress=progress+0.0001*(100-progress);
		}
		ui.progressBar->setValue(int(progress));

		//������������
		updatePrecessInfo();

		//���Ƶ�ǰ����ͼƬ
		drawFeature();

		//ˢ�������¼�
		Sleep(100);
		QCoreApplication::processEvents(QEventLoop::AllEvents,1);
	}	

	ui.progressBar->setValue(100);

	while (WaitForSingleObject(bovw_thread_handle_, 100)==WAIT_TIMEOUT)	//�ȴ��߳̽��� 
	{
		Sleep(100);
	}

	if(WaitForSingleObject(bovw_thread_handle_,5000)!=-1)	//����������ͷ��߳�
	{
		CloseHandle(bovw_thread_handle_);
	}

	QString current_msg=QString::fromLocal8Bit("BoVWѵ������ \n");
	ui.text_showfile->append(current_msg);

	ui.progressBar->setValue(0);

	bovw_thread_valid_=false;
	bovw_is_pause_=false;
}

//��ͣBoVWѵ��
void BoVWTrainer::pauseBoVWtrain()
{
	if(bovw_thread_handle_==NULL||bovw_thread_valid_==false||bovw_is_pause_==true)	//�ж��߳���Ч��
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("����ͣBoVWѵ�� \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	SuspendThread(bovw_thread_handle_);
	bovw_is_pause_=true;
}

//ֹͣBoVWѵ��
void BoVWTrainer::stopBoVWtrain()
{
	if(bovw_thread_valid_==false)	//�߳���Ч
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("��ֹͣBoVWѵ�������ڱ��棬���Ժ�... \n");
	ui.text_showfile->setText(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	if(bovw_is_pause_==true)	//����߳���ͣ�������߳�
	{
		ResumeThread(bovw_thread_handle_);
		bovw_is_pause_=false;
	}

	bovw_.stop_=true;
	bovw_is_pause_=false;

	while (WaitForSingleObject(bovw_thread_handle_, 100)==WAIT_TIMEOUT)	//�ж��̵߳�������� 
	{
		Sleep(100);
	}

	ui.progressBar->setValue(0);
	if(bovw_thread_handle_!=NULL&&WaitForSingleObject(bovw_thread_handle_,100)!=-1)
	{
		CloseHandle(bovw_thread_handle_);
	}
	bovw_thread_valid_=false;

	current_msg=QString::fromLocal8Bit("���˳�BoVWѵ�� \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}


//�˵���:�򿪰����ĵ�
void BoVWTrainer::openHelp()
{
	QString strPath = "Help.txt";	//������д���ļ���·���������ĵĻ�������Ҫ����ת��
	bool re=QDesktopServices::openUrl(QUrl(strPath));  

	if(re==false)
	{
		QString current_msg=QString::fromLocal8Bit("δ�ҵ������ĵ� \n");
		ui.text_showfile->setText(current_msg);
	}
}

//******	private ����	******

//���½�����Ϣ
void BoVWTrainer::updatePrecessInfo()
{
	//������������
	QString info_text=QString::fromLocal8Bit(bovw_.out_message_.c_str());

	if(!(out_msg_==info_text))
	{
		ui.text_showfile->append(info_text);
		ui.text_showfile->moveCursor(QTextCursor::End);
	}

	out_msg_=info_text;
}

//��������ͼ��
void BoVWTrainer::drawFeature()
{
	//ͼ����������
	if(bovw_.draw_keypoints_.rows<=0)	//ͼ��
		return;

	//���ݴ��ڴ�С����ͼƬ
	int window_w,window_h;
	window_w=ui.show_im_feature->width();
	window_h=ui.show_im_feature->height();

	cv::Mat show_image;

	if(bovw_.draw_keypoints_.rows!=window_h||bovw_.draw_keypoints_.cols!=window_w)
	{
		cv::resize(bovw_.draw_keypoints_,show_image,cv::Size(window_w,window_h));
	}
	else
	{
		show_image=bovw_.draw_keypoints_.clone();
	}

	//opencv bgrתrgb
	int n_ch=show_image.channels();	//ͼ��ͨ����
	if(n_ch==3)
	{
		cv::cvtColor(show_image,show_image,CV_BGR2RGB);
	}

	//ͼƬ����ΪQImage��ʽ
	QImage image_in;
	if(bovw_.draw_keypoints_.depth()==CV_8U)
	{
		if(n_ch==3)
			image_in=QImage(show_image.data,window_w,window_h,show_image.step,QImage::Format_RGB888);
		else if(n_ch==1)
			image_in=QImage(show_image.data,window_w,window_h,show_image.step,QImage::Format_Indexed8);
	}

	//��ʾͼƬ
	ui.show_im_feature->setPixmap(QPixmap::fromImage(image_in));
	ui.show_im_feature->show();
}

//��ָ���ļ����´����ļ�
void BoVWTrainer::createFileInFolder(string file_name,string folder)
{
	//1.�����ļ��Ƿ����
	string f_name=folder+"/"+file_name;
	int re=access(f_name.c_str(),0);

	if(re!=-1)	//�ļ�����
	{
		return;
	}
	else
	{
		f_name="../"+f_name;
		re=access(f_name.c_str(),0);

		if(re!=-1)	//�ļ�����
		{
			return;
		}
	}

	//2.�����ļ����Ƿ����
	re=access(folder.c_str(),0);

	if(re!=-1)
	{
		f_name=folder+"/"+file_name;
		fopen(f_name.c_str(),"a+");
	}
	else
	{
		folder="../"+folder;
		re=access(folder.c_str(),0);

		if(re!=-1)
		{
			f_name=folder+"/"+file_name;
			fopen(f_name.c_str(),"a+");
		}
		else
		{
			QString current_msg=QString::fromLocal8Bit("�ļ��в����ڣ��޷�������Ӧ�ļ� \n");
			ui.text_showfile->append(current_msg);
		}
	}
}


//��������
DWORD WINAPI BoVWTrainer::threadRunSampling(LPVOID fun_input)
{
	if(cam_id_==-1)	//����������ͷ
	{
		bovw_.getSamplesOfFeature(1,cam_id_);
	}
	else			//����ָ������ͷ
	{
		bovw_.getSamplesOfFeature(0,cam_id_);
	}

	return 0;
}

	 
//BoVWѵ������
DWORD WINAPI BoVWTrainer::threadRunBoVWtrain(LPVOID fun_input)
{
	bovw_.buildBagofVisvalWord();

	return 0;
}
