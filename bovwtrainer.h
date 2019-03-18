
#pragma once

#ifndef BOVWTRAINER_H
#define BOVWTRAINER_H

//windows��
#include  <io.h>

//������
#include <QtWidgets/QMainWindow>
#include <QCameraInfo>

#include "ui_bovwtrainer.h"

#include "qfiledialog.h"
#include "qtextcodec.h"
#include "qdesktopservices.h"

#include "TrainBoVWofFeature.h"

class BoVWTrainer : public QMainWindow
{
	Q_OBJECT

public:
	BoVWTrainer(QWidget *parent = 0);
	~BoVWTrainer();

public slots:
	//�����Ǹ����ؼ�����Ӧ����

	//������������
	void setFeatureType();

	//����BoVWѵ����������
	void setBoVWFeatureType();

	//���µ�ǰ����ͷ��Ϣ
	void updateCameraInfo();

	//�������õ�����ͷ
	void setCamera();

	//ѡ��������ݼ�·��
	void selectDatasetPath();

	//���в�������
	void runSampling();

	//��ͣ��������
	void pauseSampling();

	//ֹͣ��������
	void stopSampling();

	//����BoVW����
	void setBoVWlevels();

	//����BoVW��֧��
	void setBoVWbranches();

	//����BoVWѵ��
	void runBoVWtrain();

	//��ͣBoVWѵ��
	void pauseBoVWtrain();

	//ֹͣBoVWѵ��
	void stopBoVWtrain();

	//�˵���:�򿪰����ĵ�
	void openHelp();
	
private:

	//���½�����Ϣ
	void updatePrecessInfo();

	//��������ͼ��
	void drawFeature();

	//��ָ���ļ����´����ļ�
	void createFileInFolder(string file_name,string folder);

	//��������
	static DWORD WINAPI threadRunSampling(LPVOID fun_input);
	 
	//BoVWѵ������
	static DWORD WINAPI threadRunBoVWtrain(LPVOID fun_input);

	Ui::BoVWTrainerClass ui;

	static TrainBoVWofFeature bovw_;//BoVWѵ����

	HANDLE thread_handle_;		//�����̵߳ľ��
	bool thread_valid_;			//�����߳���Ч
	bool is_pause_;				//�����߳���ͣ

	HANDLE bovw_thread_handle_;		//ѵ���̵߳ľ��
	bool bovw_thread_valid_;			//ѵ������Ч
	bool bovw_is_pause_;				//ѵ������ͣ

	string feature_type_,descriptor_type_;
	vector<QString> camera_name;

	QString out_msg_;		//�����Ϣ

	static int cam_id_;	//����ͷid
};

#endif // BOVWTRAINER_H
