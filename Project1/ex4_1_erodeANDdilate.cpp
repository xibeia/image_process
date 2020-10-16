//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat,thresold_img;
//	srcMat = imread("硬币.jpg",0);
//	threshold(srcMat, thresold_img, 100, 255, THRESH_BINARY);
//
//	imshow("二值图", thresold_img);
//	//定义结构函数
//	int g_nStructElementSize = 3; //结构元素(内核矩阵)的尺寸
//	Mat element = getStructuringElement(MORPH_RECT,
//		Size(g_nStructElementSize, g_nStructElementSize));
//	/*这个函数的第一个参数表示内核的形状，有三种形状可以选择。
//	矩形：MORPH_RECT;
//	交叉形：MORPH_CROSS;
//	椭圆形：MORPH_ELLIPSE;*/
//	Mat erode_cv,dilated_cv,morcloseimg,moropenimg;
//	
//	erode(thresold_img,erode_cv, element);
//	imshow("腐蚀后", erode_cv);
//
//	dilate(thresold_img, dilated_cv, element);
//	imshow("膨胀后", dilated_cv);
//
//	morphologyEx(thresold_img, morcloseimg, MORPH_CLOSE, element); 
//	imshow("闭运算", morcloseimg);
//
//	morphologyEx(thresold_img, moropenimg, MORPH_OPEN, element);
//	imshow("开运算", moropenimg);
//
//	/*
//	enum { MORPH_ERODE=CV_MOP_ERODE, MORPH_DILATE=CV_MOP_DILATE,
//	   MORPH_OPEN=CV_MOP_OPEN,
//	   MORPH_CLOSE=CV_MOP_CLOSE,
//	   MORPH_GRADIENT=CV_MOP_GRADIENT,
//	   MORPH_TOPHAT=CV_MOP_TOPHAT,
//	   MORPH_BLACKHAT=CV_MOP_BLACKHAT };
//	*/
//
//	waitKey(0);
//	return 0;
//}