
//Created on Nov 11 16:23 2018
//Author : Kailin Xu
//Email : 10405501@qq.com
//Last edit time : Nov 12 22:42 2018
//South East University Automation College, 211189 Nanjing China


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc_c.h" 
#include <opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>  
#include <windows.h> 
#include <sys/timeb.h>  
#include<sys\utime.h>  
using namespace cv;
using namespace std;


//打开并保存视频的图片_使用空格储存图片
int videoProcess_blank(VideoCapture& capture)
{
	int n = 0;
	char filename[200];
	char numImage[200] = "images";
	string window_name = "KINGDOM OF PLANTS";
	std::cout << "按下【Space】空格键可以截图" << std::endl;
	std::cout << "【Esc】和【q】键 - 退出程序" << endl;
	namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable	window;
	cv::Mat frame;

	float second;
	float minute;
	float hour;
	float millisec;
	SYSTEMTIME sys;
	
	for (;;)
	{
		GetLocalTime(&sys);//获取本机系统时间
		second = sys.wSecond;
		minute = sys.wMinute;
		hour = sys.wHour;
		millisec = sys.wMilliseconds;

		char num[5], num2[5] = ".png";
		string src_image_name = "F:\\downloads\\";
		
		//图片的格式为minute_second_millisec.png
		_itoa(minute, num, 10);
		src_image_name += num;
		src_image_name += "_";
		_itoa(second, num, 10);
		src_image_name += num;
		src_image_name += "_";
		_itoa(millisec, num, 10);
		src_image_name += num;
		src_image_name += num2;

		capture >> frame;
		if (frame.empty())break;
		cv::imshow(window_name, frame);
		char key = (char)waitKey(10);
		switch (key)
		{
		case 'q':
		case 'Q':
		case 27:
			//[1]escape key
			return 0;
		case ' ': //[2]Save an image
			
			imwrite(src_image_name, frame);
			cout << "\n\t>保存了 " << src_image_name << "文件到工程目录下" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}

//打开并保存视频的图片_每隔一百毫秒储存图片
int videoProcess(VideoCapture& capture)
{
	int n = 0;
	char filename[200];
	char numImage[200] = "images";
	string window_name = "KINGDOM OF PLANTS";
	namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable	window;
	cv::Mat frame;

	float second;
	float minute;
	float hour;
	float millisec;
	SYSTEMTIME sys;

	for (;;)
	{
		GetLocalTime(&sys);//获取本机系统时间
		second = sys.wSecond;
		minute = sys.wMinute;
		hour = sys.wHour;
		millisec = sys.wMilliseconds;

		char num[5], num2[5] = ".png";
		string src_image_name = "F:\\downloads\\";

		//图片的格式为minute_second_millisec.png
		_itoa(minute, num, 10);
		src_image_name += num;
		src_image_name += "_";
		_itoa(second, num, 10);
		src_image_name += num;
		src_image_name += "_";
		_itoa(millisec, num, 10);
		src_image_name += num;
		src_image_name += num2;

		capture >> frame;
		if (frame.empty())break;
		cv::imshow(window_name, frame);
		waitKey(100);
		imwrite(src_image_name, frame);
		cout << "\n\t>保存了 " << src_image_name << "文件到工程目录下" << endl;	
	}
	return 0;
}


int main()
{
	//通过0/1来选择摄像头,1为外接设备
	VideoCapture capture(0); //从摄像头载入视频
	VideoCapture cap(1);
	//函数应该加判断提高鲁棒性
	if (!capture.isOpened())
	{
		std::cerr << "Failed to open a video device or video file!\n" << endl;
		return 1;
	}
	if (!cap.isOpened())
	{
		std::cerr << "Failed to open a video device_cap or video file!\n" << endl;
		return 1;
	}
	videoProcess_blank(capture);
	return 1;
}





