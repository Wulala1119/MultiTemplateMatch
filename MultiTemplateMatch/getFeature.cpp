#include "getFeature.h"
void getFeature(Mat &src, Mat &dst, Mat &similarMat)
{
	float sx = similarMat.at<float>(0, 0);
	float tx = similarMat.at<float>(0, 2);
	float sy = similarMat.at<float>(1, 1);
	float ty = similarMat.at<float>(1, 2);
	/*int posix = 0;
	int posiy = 0;*/
	for(int i = 0; i < dst.rows; i ++)
	{
		for(int j = 0; j < dst.cols; j ++)
		{
			/*if(i == dst.rows - 1 && j == dst.cols - 1)
				cvWaitKey(0);
			posix = (int)(sx * j + tx);
			posiy = (int)(sy * i + ty);*/
			dst.at<uchar>(i, j) = src.at<Vec3b>((int)(sy * i + ty), (int)(sx * j + tx)).val[0];
		}
	}	
}
void getFeature(Mat &src, Mat &dst, float *similarMat)
{
	float sx = similarMat[0];
	float tx = similarMat[1];
	float sy = similarMat[2];
	float ty = similarMat[3];
	for(int i = 0; i < dst.rows; i ++)
	{
		for(int j = 0; j < dst.cols; j ++)
		{
			dst.at<uchar>(i, j) = src.at<Vec3b>(sy * i + ty, sx * j + tx).val[0];
		}
	}	
}
