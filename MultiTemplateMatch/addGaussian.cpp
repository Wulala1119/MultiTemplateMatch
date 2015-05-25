#include "addGaussian.h"
Mat addGaussian(Mat& src, Mat& seed)
{
	Mat dst = Mat(src.rows, src.cols, CV_32F);
	srand((unsigned)time(NULL));
	for(int i = 0; i < src.rows; i ++)
	{
		for(int j = 0; j < src.cols; j ++)
		{
			dst.at<float>(i, j) = src.at<float>(i, j) + seed.at<float>(i, j) * gausS();
		}
	}
	return dst;
}
double gausS()
{ 
	//产生高斯样本，D为均方差
    double sum=0; 
    for(int i = 0; i < 12; i++)
		sum += rand() / 32767.00;
	//计算机中rand()函数为－32767～＋32767（2^15-1）
	//故sum＋为0～1之间的均匀随机变量
	return sum - 6;
	//产生均值为U，标准差为D的高斯分布的样本，并返回
}