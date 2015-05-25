#ifndef TRACKING_H
#define TRACKING_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "dataStruct.h"
#include "getFeature.h"
using namespace cv;

//-------------------------------------------模板匹配参数-------------------------------//
//三步搜索时四个描述子的偏移参数
#define SX_SHIFT 0.5
#define SY_SHIFT 0.5
#define TX_SHIFT 1
#define TY_SHIFT 1
//三步搜索描述子序列总数
#define SHIFT_NUM 81
//分块数
#define X_NUM 4
#define Y_NUM 4
//判断遮挡相似度阈值
#define OCCLUSION_THRESHOLD 0.6
//模板更新相似度阈值
#define UPDATE_THRESHOLD 0.5
void tracking(Mat &src, Object& obj);
void calShiftSimilarMat(float ** ShiftSimilarMat, Mat& similarMat);
#endif