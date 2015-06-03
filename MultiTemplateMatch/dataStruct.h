#ifndef MAINPROCESS_H
#define MAINPROCESS_H
#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

class Object
{
public:
	Object();
	void initObj();
	void calSimilarMat(Point leftTop, Point rightButtom);
	void similarityMat2Position();
//private:
	//目标
	//目标框位置左上角坐标（x,y）
	int x;
	int y;
	//目标框大小，宽width，高height
	int width;
	int height;
	//目标描述子，（tx,ty,s）分别是x方向平移，y方向平移，缩放比例
	float tx;
	float ty;
	float sx;
	float sy;
	//相似矩阵
	Mat similarMat;
	//模板
	//模板大小，宽templateWidth，高templateHeight
	int templateWidth;
	int templateHeight;
	//模板数
	int templateNum;
	//模板特征
	Mat* templateFeature;
	//三步搜索偏移阵
	float **ShiftSimilarMat;
};


class VideoMessage
{
public:
	VideoMessage(string fileName);
	Mat getNowFrame();
	int getFrameNum();

//private:
	Mat nowFrame;
	VideoCapture capture;
	int frameNum;
	double rate;
	
};



void on_mouse(int event, int x, int y, int flags, void* param);
#endif