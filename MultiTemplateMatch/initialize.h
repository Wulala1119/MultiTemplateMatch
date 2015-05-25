#ifndef INITIALIZE_H
#define INITIALIZE_H
#include "dataStruct.h"
#include "addGaussian.h"
#include "getFeature.h"
void initialize(Object& obj, VideoMessage& videoMessage, Mat& Frame, Point leftTop, Point rightButtom, int tW, int tH, int tN, Mat& seed);
#endif