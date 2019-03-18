
#pragma once

#ifndef BOVWTRAINER_H
#define BOVWTRAINER_H

//windows库
#include  <io.h>

//其它库
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
	//下面是各个控件的响应函数

	//设置特征类型
	void setFeatureType();

	//设置BoVW训练特征类型
	void setBoVWFeatureType();

	//更新当前摄像头信息
	void updateCameraInfo();

	//设置启用的摄像头
	void setCamera();

	//选择采样数据集路径
	void selectDatasetPath();

	//运行采样程序
	void runSampling();

	//暂停采样程序
	void pauseSampling();

	//停止采样程序
	void stopSampling();

	//设置BoVW层数
	void setBoVWlevels();

	//设置BoVW分支数
	void setBoVWbranches();

	//运行BoVW训练
	void runBoVWtrain();

	//暂停BoVW训练
	void pauseBoVWtrain();

	//停止BoVW训练
	void stopBoVWtrain();

	//菜单栏:打开帮助文档
	void openHelp();
	
private:

	//更新进度信息
	void updatePrecessInfo();

	//绘制特征图像
	void drawFeature();

	//在指定文件夹下创建文件
	void createFileInFolder(string file_name,string folder);

	//采样进程
	static DWORD WINAPI threadRunSampling(LPVOID fun_input);
	 
	//BoVW训练进程
	static DWORD WINAPI threadRunBoVWtrain(LPVOID fun_input);

	Ui::BoVWTrainerClass ui;

	static TrainBoVWofFeature bovw_;//BoVW训练类

	HANDLE thread_handle_;		//采样线程的句柄
	bool thread_valid_;			//采样线程有效
	bool is_pause_;				//采样线程暂停

	HANDLE bovw_thread_handle_;		//训练线程的句柄
	bool bovw_thread_valid_;			//训练程有效
	bool bovw_is_pause_;				//训练程暂停

	string feature_type_,descriptor_type_;
	vector<QString> camera_name;

	QString out_msg_;		//输出信息

	static int cam_id_;	//摄像头id
};

#endif // BOVWTRAINER_H
