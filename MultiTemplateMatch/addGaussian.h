#ifndef ADDGAUSSIAN_H
#define ADDGAUSSIAN_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
using namespace cv;
Mat addGaussian(Mat& src, Mat& seed);
double gausS();
#endif