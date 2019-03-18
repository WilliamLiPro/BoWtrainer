#include "bovwtrainer.h"

TrainBoVWofFeature BoVWTrainer::bovw_=TrainBoVWofFeature::TrainBoVWofFeature();
int BoVWTrainer::cam_id_=-1;

BoVWTrainer::BoVWTrainer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置基本特征类型
	feature_type_="SURF";
	descriptor_type_="SURF";

	//初始化BoVW训练类
	//bovw_=TrainBoVWofFeature::TrainBoVWofFeature(feature_type_,descriptor_type_);

	//摄像头
	//cam_id_=-1;	//摄像头id

	is_pause_=false;

	//线程初始化
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

//********	响应函数	*******

//设置特征类型
void BoVWTrainer::setFeatureType()
{
	feature_type_=ui.sample_detector->currentText().toStdString();
	descriptor_type_=ui.sample_extractor->currentText().toStdString();

	int descpitor_l=descriptor_type_.size();	//剔除说明性内容
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
		QString current_msg=QString::fromLocal8Bit(descriptor_type_.c_str())+QString::fromLocal8Bit(" 描述子 建议用SURF/SIFT/FAST特征检测: \n");
		ui.text_showfile->setText(current_msg);
	}


	bovw_.setFeatureType(feature_type_,descriptor_type_);
}

//设置BoVW训练特征类型
void BoVWTrainer::setBoVWFeatureType()
{
	feature_type_=ui.sample_detector->currentText().toStdString();
	descriptor_type_=ui.trainbovw_feature->currentText().toStdString();

	int descpitor_l=descriptor_type_.size();	//剔除说明性内容
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


//更新当前摄像头信息
void BoVWTrainer::updateCameraInfo()
{
	//获取设备信息
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	int cam_n=cameras.size();//camera 个数加上不选择
	int ought_n=cam_n+1;//camera 个数加上不选择
	int curernt_n=ui.open_camera->count();

	if(curernt_n>cam_n)	//列表设备数过多，删除部分
	{
		for (int i = ought_n; i < curernt_n; i++)
		{
			ui.open_camera->removeItem(i);
		}
	}
	else	//列表设备数过少，添加部分
	{
		for (int i = curernt_n; i < ought_n; i++)
		{
			ui.open_camera->addItem("");
		}
	}

	//获取名称
	camera_name.resize(cam_n);
	for(int i=0;i<cam_n;i++)
	{
		camera_name[i]=cameras[i].description();
	}

	//输出到选择列表中
	for(int i=0;i<cam_n;i++)
	{
		ui.open_camera->setItemText(i+1,camera_name[i]);
	}
}

//设置启用的摄像头
void BoVWTrainer::setCamera()
{
	QString current_cam=ui.open_camera->currentText(); 

	cam_id_=-1;
	int cam_n=camera_name.size();
	for(int i=0;i<cam_n;i++)
	{
		if(current_cam==camera_name[i])
		{
			cam_id_=i;	//设置摄像头id
		}
	}
}

//选择采样数据集路径
void BoVWTrainer::selectDatasetPath()
{
	//获得数据路径
	QString file_name=QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.jpeg *.png *.bmp)")); 

	QTextCodec *code = QTextCodec::codecForName("gb18030");	//解决中文乱码
	if(code)
	{
		bovw_.picture_file_path_=code->fromUnicode(file_name).data();
		//截断文件名
	}

	QString current_msg=QString::fromLocal8Bit("当前采样数据集路径: \n")+file_name+"\n";
	ui.text_showfile->setText(current_msg);
}

//运行采样程序
void BoVWTrainer::runSampling()
{
	//创建文件
	string folder="feature samples";
	string file_name=descriptor_type_+" samples.dat";
	createFileInFolder(file_name,folder);

	//创建采样线程
	if(thread_valid_==true&&is_pause_==true&&thread_handle_!=NULL&&WaitForSingleObject(thread_handle_,5000)!=-1)		//恢复暂停线程
	{
		ResumeThread(thread_handle_);
		is_pause_=false;

		QString current_msg=QString::fromLocal8Bit("恢复采样 \n");
		ui.text_showfile->append(current_msg);

		return;
	}
	else if(thread_valid_==false)		//创建采样线程
	{
		thread_valid_=true;
		is_pause_=false;
		thread_handle_=CreateThread(NULL,0,threadRunSampling,NULL,0,NULL);

		QString current_msg=QString::fromLocal8Bit("开始特征采样 \n");
		ui.text_showfile->setText(current_msg);
	}
	else
	{
		QString current_msg=QString::fromLocal8Bit("正在进行特征采样 \n");
		ui.text_showfile->append(current_msg);
	}

	//更新输出信息
	float progress=0; 
	QString info_text;								//显示图片名称	

	while (WaitForSingleObject(thread_handle_,10)==WAIT_TIMEOUT)	//判断线程的运行情况 
	{
		//更新进度条
		if(progress<100)
		{
			progress=progress+0.0001*(100-progress);
		}
		ui.progressBar->setValue(int(progress));

		//更新文字内容
		updatePrecessInfo();

		//绘制当前特征图片
		drawFeature();

		//刷新所有事件
		Sleep(100);
		QCoreApplication::processEvents(QEventLoop::AllEvents,1);
	}	

	ui.progressBar->setValue(100);

	while (WaitForSingleObject(thread_handle_, 100)==WAIT_TIMEOUT)	//等待线程结束 
	{
		Sleep(100);
	}

	if(WaitForSingleObject(thread_handle_,5000)!=-1)	//程序结束，释放线程
	{
		CloseHandle(thread_handle_);
	}

	QString current_msg=QString::fromLocal8Bit("采样结束 \n");
	ui.text_showfile->append(current_msg);

	ui.progressBar->setValue(0);

	thread_valid_=false;
	is_pause_=false;
}

//暂停采样程序
void BoVWTrainer::pauseSampling()
{
	if(thread_handle_==NULL||thread_valid_==false||is_pause_==true)	//判断线程有效性
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("已暂停采样 \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	SuspendThread(thread_handle_);
	is_pause_=true;
}

//停止采样程序
void BoVWTrainer::stopSampling()
{
	if(thread_valid_==false)	//线程无效
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("已停止采样，正在保存采样结果，请稍后... \n");
	ui.text_showfile->setText(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	if(is_pause_==true)	//如果线程暂停，继续线程
	{
		ResumeThread(thread_handle_);
		is_pause_=false;
	}

	bovw_.stop_=true;
	is_pause_=false;

	while (WaitForSingleObject(thread_handle_, 100)==WAIT_TIMEOUT)	//判断线程的运行情况 
	{
		Sleep(100);
	}

	ui.progressBar->setValue(0);
	if(thread_handle_!=NULL&&WaitForSingleObject(thread_handle_,100)!=-1)
	{
		CloseHandle(thread_handle_);
	}
	thread_valid_=false;

	current_msg=QString::fromLocal8Bit("已退出采样 \n");
	ui.text_showfile->append(current_msg);

	QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}

//设置BoVW层数
void BoVWTrainer::setBoVWlevels()
{
	bovw_.setBoVWlevelsAndBranches(ui.bovw_levels->value(),ui.bovw_branches->value());
}

//设置BoVW分支数
void BoVWTrainer::setBoVWbranches()
{
	bovw_.setBoVWlevelsAndBranches(ui.bovw_levels->value(),ui.bovw_branches->value());
}

//运行BoVW训练
void BoVWTrainer::runBoVWtrain()
{
	//创建文件
	string folder="BoVW";
	string file_name=descriptor_type_+" BoVW.dat";
	createFileInFolder(file_name,folder);

	//创建采样线程
	if(bovw_thread_valid_==true&&bovw_is_pause_==true&&bovw_thread_handle_!=NULL&&WaitForSingleObject(bovw_thread_handle_,5000)!=-1)		//恢复暂停线程
	{
		ResumeThread(bovw_thread_handle_);
		bovw_is_pause_=false;

		QString current_msg=QString::fromLocal8Bit("恢复BoVW训练 \n");
		ui.text_showfile->append(current_msg);

		return;
	}
	else if(bovw_thread_valid_==false)		//创建采样线程
	{
		bovw_thread_valid_=true;
		bovw_is_pause_=false;
		bovw_thread_handle_=CreateThread(NULL,0,threadRunBoVWtrain,NULL,0,NULL);

		QString current_msg=QString::fromLocal8Bit("开始BoVW训练 \n");
		ui.text_showfile->setText(current_msg);
	}
	else
	{
		QString current_msg=QString::fromLocal8Bit("正在训练BoVW \n");
		ui.text_showfile->append(current_msg);
	}

	//更新输出信息
	float progress=0; 
	QString info_text;								//显示图片名称	

	while (WaitForSingleObject(bovw_thread_handle_,10)==WAIT_TIMEOUT)	//判断线程的运行情况 
	{
		//更新进度条
		if(progress<100)
		{
			progress=progress+0.0001*(100-progress);
		}
		ui.progressBar->setValue(int(progress));

		//更新文字内容
		updatePrecessInfo();

		//绘制当前特征图片
		drawFeature();

		//刷新所有事件
		Sleep(100);
		QCoreApplication::processEvents(QEventLoop::AllEvents,1);
	}	

	ui.progressBar->setValue(100);

	while (WaitForSingleObject(bovw_thread_handle_, 100)==WAIT_TIMEOUT)	//等待线程结束 
	{
		Sleep(100);
	}

	if(WaitForSingleObject(bovw_thread_handle_,5000)!=-1)	//程序结束，释放线程
	{
		CloseHandle(bovw_thread_handle_);
	}

	QString current_msg=QString::fromLocal8Bit("BoVW训练结束 \n");
	ui.text_showfile->append(current_msg);

	ui.progressBar->setValue(0);

	bovw_thread_valid_=false;
	bovw_is_pause_=false;
}

//暂停BoVW训练
void BoVWTrainer::pauseBoVWtrain()
{
	if(bovw_thread_handle_==NULL||bovw_thread_valid_==false||bovw_is_pause_==true)	//判断线程有效性
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("已暂停BoVW训练 \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	SuspendThread(bovw_thread_handle_);
	bovw_is_pause_=true;
}

//停止BoVW训练
void BoVWTrainer::stopBoVWtrain()
{
	if(bovw_thread_valid_==false)	//线程无效
	{
		return;
	}

	QString current_msg=QString::fromLocal8Bit("已停止BoVW训练，正在保存，请稍后... \n");
	ui.text_showfile->setText(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);

	if(bovw_is_pause_==true)	//如果线程暂停，继续线程
	{
		ResumeThread(bovw_thread_handle_);
		bovw_is_pause_=false;
	}

	bovw_.stop_=true;
	bovw_is_pause_=false;

	while (WaitForSingleObject(bovw_thread_handle_, 100)==WAIT_TIMEOUT)	//判断线程的运行情况 
	{
		Sleep(100);
	}

	ui.progressBar->setValue(0);
	if(bovw_thread_handle_!=NULL&&WaitForSingleObject(bovw_thread_handle_,100)!=-1)
	{
		CloseHandle(bovw_thread_handle_);
	}
	bovw_thread_valid_=false;

	current_msg=QString::fromLocal8Bit("已退出BoVW训练 \n");
	ui.text_showfile->append(current_msg);
	QCoreApplication::processEvents(QEventLoop::AllEvents,1);
}


//菜单栏:打开帮助文档
void BoVWTrainer::openHelp()
{
	QString strPath = "Help.txt";	//这里填写你文件的路径，有中文的话可能需要编码转换
	bool re=QDesktopServices::openUrl(QUrl(strPath));  

	if(re==false)
	{
		QString current_msg=QString::fromLocal8Bit("未找到帮助文档 \n");
		ui.text_showfile->setText(current_msg);
	}
}

//******	private 函数	******

//更新进度信息
void BoVWTrainer::updatePrecessInfo()
{
	//更新文字内容
	QString info_text=QString::fromLocal8Bit(bovw_.out_message_.c_str());

	if(!(out_msg_==info_text))
	{
		ui.text_showfile->append(info_text);
		ui.text_showfile->moveCursor(QTextCursor::End);
	}

	out_msg_=info_text;
}

//绘制特征图像
void BoVWTrainer::drawFeature()
{
	//图像有误，跳出
	if(bovw_.draw_keypoints_.rows<=0)	//图像
		return;

	//根据窗口大小调整图片
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

	//opencv bgr转rgb
	int n_ch=show_image.channels();	//图像通道数
	if(n_ch==3)
	{
		cv::cvtColor(show_image,show_image,CV_BGR2RGB);
	}

	//图片保存为QImage格式
	QImage image_in;
	if(bovw_.draw_keypoints_.depth()==CV_8U)
	{
		if(n_ch==3)
			image_in=QImage(show_image.data,window_w,window_h,show_image.step,QImage::Format_RGB888);
		else if(n_ch==1)
			image_in=QImage(show_image.data,window_w,window_h,show_image.step,QImage::Format_Indexed8);
	}

	//显示图片
	ui.show_im_feature->setPixmap(QPixmap::fromImage(image_in));
	ui.show_im_feature->show();
}

//在指定文件夹下创建文件
void BoVWTrainer::createFileInFolder(string file_name,string folder)
{
	//1.查找文件是否存在
	string f_name=folder+"/"+file_name;
	int re=access(f_name.c_str(),0);

	if(re!=-1)	//文件存在
	{
		return;
	}
	else
	{
		f_name="../"+f_name;
		re=access(f_name.c_str(),0);

		if(re!=-1)	//文件存在
		{
			return;
		}
	}

	//2.查找文件夹是否存在
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
			QString current_msg=QString::fromLocal8Bit("文件夹不存在，无法创建相应文件 \n");
			ui.text_showfile->append(current_msg);
		}
	}
}


//采样进程
DWORD WINAPI BoVWTrainer::threadRunSampling(LPVOID fun_input)
{
	if(cam_id_==-1)	//不开启摄像头
	{
		bovw_.getSamplesOfFeature(1,cam_id_);
	}
	else			//开启指定摄像头
	{
		bovw_.getSamplesOfFeature(0,cam_id_);
	}

	return 0;
}

	 
//BoVW训练进程
DWORD WINAPI BoVWTrainer::threadRunBoVWtrain(LPVOID fun_input)
{
	bovw_.buildBagofVisvalWord();

	return 0;
}
