#ifndef CALSIMILARITY_H
#define CALSIMILARITY_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

struct NCC {};
vector<double> calSimilarity(Mat& singleTemplate, Mat& candidate, NCC);
vector<double> calBlockSimilarity(Mat& singleTemplate, Mat& candidate, NCC);
#endif