#include "calSimilarity.h"
vector<double> calSimilarity(Mat& singleTemplate, Mat& candidate, NCC)
{
	vector<double> ret;
	double productSum = 0;
	double tPowSum = 0;
	double cPowSum = 0;
	uchar tPixel = 0;
	uchar cPixel = 0;
	for(int i = 0; i < singleTemplate.rows; i ++)
	{
		for(int j = 0; j < singleTemplate.cols; j ++)
		{
			tPixel = singleTemplate.at<uchar>(i, j);
			cPixel = candidate.at<uchar>(i, j);
			productSum += tPixel * cPixel;
			tPowSum += tPixel * tPixel;
			cPowSum += cPixel * cPixel;
		}
	}	
	ret.push_back(productSum / sqrt(tPowSum * cPowSum));
	return ret;
}