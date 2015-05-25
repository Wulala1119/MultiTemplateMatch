#ifndef GETFEATURE_H
#define GETFEATURE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void getFeature(Mat &src, Mat &dst, Mat &similarMat);
void getFeature(Mat &src, Mat &dst, float *similarMat);
#endif