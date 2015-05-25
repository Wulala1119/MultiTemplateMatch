#include "initialize.h"
void initialize(Object& obj, VideoMessage& videoMessage, Mat& Frame, Point leftTop, Point rightButtom, int tW, int tH, int tN, Mat& seed)
{
	cout << "4.1 初始化函数" << endl;
	//------------------------------目标位置初始化-----------------------------//
	obj.x = leftTop.x;
	obj.y = leftTop.y;
	//------------------------------目标大小初始化-----------------------------//
	obj.width = rightButtom.x - leftTop.x;
	obj.height = rightButtom.y - leftTop.y;
	//------------------------------初始化模板大小-----------------------------//
	obj.templateWidth = tW;
	obj.templateHeight = tH;
	obj.templateNum = tN;
	//------------------------------初始化描述子-------------------------------//
	obj.calSimilarMat(leftTop, rightButtom);
	cout << obj.similarMat.at<float>(0, 0) << endl;
	//------------------------------模板初始化---------------------------------//
	obj.templateFeature = new Mat[obj.templateNum];
	//namedWindow("test");
	obj.templateFeature[0] = Mat(obj.templateHeight, obj.templateWidth, CV_8UC1);
	getFeature(Frame, obj.templateFeature[0], obj.similarMat);
	/*for(int i = 0; i < obj.templateFeature[0].rows; i ++)
	{
		for(int j = 0; j < obj.templateFeature[0].cols; j ++)
		{
			cout << (int)obj.templateFeature[0].at<uchar>(i, j) << "\t";
		}
		cout << endl;
	}
	imshow("test", obj.templateFeature[0]);
	cvWaitKey(0);*/
	for(int i = 1; i < obj.templateNum; i ++)
	{
		//加高斯噪声
		Mat similarMatAddGaussian = addGaussian(obj.similarMat, seed);
		//为模板分配内存
		obj.templateFeature[i] = Mat(obj.templateHeight, obj.templateWidth, CV_8UC1);
		getFeature(Frame, obj.templateFeature[i], similarMatAddGaussian);
		/*imshow("test", obj.templateFeature[i]);
		cvWaitKey(0);*/
	}
	//------------------------------初始化结束---------------------------------//
	cout << "4.2 初始化结束" << endl;
}

