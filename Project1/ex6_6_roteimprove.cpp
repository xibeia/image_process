#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	Mat srcMat, dstMat;
	srcMat = imread("lenna2.jpg", 1);
	if (srcMat.empty()) return -1;

	//练习六，直接仿射变换吧
	/*
	设旋转后 短边长为wl
	旋转的角度为
	 
	 theta=arc(wl/n-wl)

*/

	//找到点
	int n1 = srcMat.rows;
	int nc = srcMat.cols;

	Point2f a;  //(左上角)
	Point2f b;  //(左下角)
	Point2f c;  //右上角


	float wl = 20;
	a.x = 0;
	a.y = n1 - wl;

	b.x = nc;
	b.y = wl;

	c.x = wl;
	c.y = 0;


	Mat dst_affine;


	const Point2f src_pt[] = {
		Point2f(0,n1),
		Point2f(nc,0),
		Point2f(0,0)
	};

	const Point2f dst_pt[] = {
	a,
	b,
	c
	};

	//计算放射矩阵

	const Mat affine_matrix2 = getAffineTransform(src_pt, dst_pt);
	warpAffine(srcMat, dst_affine, affine_matrix2, srcMat.size());

	circle(srcMat, a, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	circle(srcMat, b, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	circle(srcMat, c, 5, CV_RGB(255, 0, 0), 1, 8, 0);

	imshow("原图", srcMat);
	imshow("仿射变换", dst_affine);


	waitKey(0);

	return 0;
}