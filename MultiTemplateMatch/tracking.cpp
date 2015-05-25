#include "tracking.h"
void tracking(Mat &src, Object& obj)
{
	//-------------------------------------------模板匹配-------------------------------//
	
	calShiftSimilarMat(obj.ShiftSimilarMat, obj.similarMat);

	for(int i = 0; i < SHIFT_NUM; i ++)
	{
		getFeature(src, dst, obj.ShiftSimilarMat[i]);
		for(int j = 0; j < obj.templateNum; j ++)
		{
			calSimilarity();
		}
	}

	//-------------------------------------------遮挡分析-------------------------------//


	//-------------------------------------------模板更新-------------------------------//


	//-------------------------------------------跟踪结束-------------------------------//
}
void calShiftSimilarMat(float ** ShiftSimilarMat, Mat& similarMat)
{
	float sx = similarMat.at<float>(0, 0);
	float tx = similarMat.at<float>(0, 2);
	float sy = similarMat.at<float>(1, 1);
	float ty = similarMat.at<float>(1, 2);
	int key = 0;
	for(int i = -1; i < 2; i ++)
	{		
		for(int j = -1; j < 2; j ++)
		{			
			for(int m = -1; m < 2; m ++)
			{
				for(int n = -1; n < 2; n ++)
				{
					ShiftSimilarMat[key][0] = sx + i * SX_SHIFT;
					ShiftSimilarMat[key][1] = tx + j * TX_SHIFT;
					ShiftSimilarMat[key][2] = sy + m * SY_SHIFT;
					ShiftSimilarMat[key][3] = ty + n * TY_SHIFT;
					key ++;
				}
			}
		}
	}
}