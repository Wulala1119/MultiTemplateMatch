#include "dataStruct.h"
//-----------------------------------Object的成员函数-----------------------//
//初始化函数
Object::Object()
{
	//初始化三步搜索偏移相似矩阵
	ShiftSimilarMat = new float*[81];
	for(int i = 0; i < 81; i ++)
	{
		ShiftSimilarMat[i] = new float[4];
	}
}
void Object::calSimilarMat(Point leftTop, Point rightButtom)
{
	tx = leftTop.x;
	ty = leftTop.y;
	sx = width / (templateWidth - 1);
	sy = height / (templateHeight - 1);
	similarMat = (Mat_<float>(2, 3) << sx, 0, tx, 0, sy, ty);
}
//-----------------------------------VideoMessage的成员函数----------------//
VideoMessage::VideoMessage(string fileName)
{
	capture.open(fileName);
	if(!capture.isOpened())
	{
		cout << "打开视频失败" << endl; 
	}
	capture.set( CV_CAP_PROP_POS_FRAMES,1);
	//capture.read(nowFrame);
	frameNum = capture.get(CV_CAP_PROP_FRAME_COUNT);
	rate = capture.get(CV_CAP_PROP_FPS);
}
Mat VideoMessage::getNowFrame()
{
	if(!capture.read(nowFrame))
	{
		cout << "读取视频失败" << endl;
	}
	return nowFrame;
}
int VideoMessage:: getFrameNum()
{
	return frameNum;
}