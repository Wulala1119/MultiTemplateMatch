#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#include "../MultiTemplateMatch/addGaussian.h"
#include "../MultiTemplateMatch/tracking.h"

int main()
{
	/*Mat test = (Mat_<float>(2, 3) << 1, 0, 1, 0, 1, 1);
	Mat seed = (Mat_<float>(2, 3) << 0.1, 0, 2, 0, 0.1, 2);
	Mat res = addGaussian(test, seed);
	for(int i = 0; i < res.rows; i ++)
	{
		for(int j = 0; j < res.cols; j ++)
		{
			cout << res.at<float>(i, j) << "\t";
		}
		cout << endl;
	}*/
	float **ShiftSimilarMat = new float*[81];
	for(int i = 0; i < 81; i ++)
	{
		ShiftSimilarMat[i] = new float[4];
	}
	Mat seed = (Mat_<float>(2, 3) << 1, 0, 1, 0, 1, 1);
	calShiftSimilarMat(ShiftSimilarMat, seed);
	for(int i = 0; i < 81; i ++)
	{
		for(int j = 0; j < 4; j ++)
		{
			cout << ShiftSimilarMat[i][j] << "\t";
		}
		cout << endl;
	}
	//ShiftSimilarMat[20][3] = 2;
	//cout << ShiftSimilarMat[20][3] << endl;
	system("pause");
}
