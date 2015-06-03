/*************************************************************************************/
/********************多模版分块匹配目标跟踪算法***************************************/
/*********************nuaaylh030910225@163.com****************************************/
/***********https://github.com/Wulala1119/MultiTemplateMatch**************************/
//-------------------------------------include文件-----------------------------------//

#include "mainProcess.h"
#include "dataStruct.h"
#include "initialize.h"
#include "tracking.h"

#define templateWidth 32
#define templateHeight 32
#define templateNum 10
#define gaussianSeed 1


//-------------------------------------全局变量--------------------------------------//
Point leftTopPoint = Point(0, 0);
Point rightButtomPoint = Point(0, 0);
//-------------------------------------主函数----------------------------------------//
int main()
{
	//---------------------------------初始化----------------------------------------//
	//---------------------------------初始化数据结构--------------------------------//
	Object obj;
	cout << "1 开始测试！" << endl;
	string fileName = "C:\\Users\\wulala1119\\Documents\\visual studio 2012\\Projects\\MultiTemplateMatch\\videosrc\\CarScale.avi";
	VideoMessage videoMessage(fileName);
	cout << "2 视频捕获成功！" << endl;
	Mat nowFrame;
	namedWindow("VideoTrack");
	cvSetMouseCallback("VideoTrack",on_mouse,0);// 为窗口绑定鼠标侦测函数		
	nowFrame = videoMessage.getNowFrame();
	imshow("VideoTrack", nowFrame);
	waitKey(0);
	cout << "3 目标已选中！" << endl;
	Mat seed = (Mat_<float>(2, 3) << 0.1, 0, 2, 0, 0.1, 2);
	initialize(obj, videoMessage, nowFrame, leftTopPoint, rightButtomPoint, templateWidth, templateHeight, templateNum, seed);
	cout << "4 初始化成功！" << endl;
	int frameNum = videoMessage.getFrameNum(); 
	int frameCount = 1;
	//---------------------------------跟踪循环--------------------------------------//
	while(frameCount < frameNum - 1)
	{
		cout << "正在处理第：" << frameCount << "帧" << endl;
		nowFrame = videoMessage.getNowFrame();
		tracking(nowFrame, obj);
		rectangle(nowFrame, Point(obj.x, obj.y), Point(obj.x + obj.width, obj.y + obj.height), Scalar(255,0,0));
		imshow("VideoTrack", nowFrame);
		waitKey(1);
		cout << "第：" << frameCount << "帧处理完成" << endl;
		frameCount ++;
	}

	////---------------------------------数据存储--------------------------------------//
	//restoreData();

	////---------------------------------结束------------------------------------------//

}


void on_mouse(int event, int x, int y, int flags, void* param)
{		
    if( event == CV_EVENT_LBUTTONDOWN)   //按下鼠标左键
	{
		leftTopPoint = Point(x, y);
	}
    else if( event == CV_EVENT_LBUTTONUP )   //鼠标左键弹起
	{		
		rightButtomPoint = Point(x, y);
	}
}
