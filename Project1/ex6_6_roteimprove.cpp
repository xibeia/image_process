#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	Mat srcMat, dstMat;
	srcMat = imread("lenna2.jpg", 1);
	if (srcMat.empty()) return -1;

	//��ϰ����ֱ�ӷ���任��
	/*
	����ת�� �̱߳�Ϊwl
	��ת�ĽǶ�Ϊ
	 
	 theta=arc(wl/n-wl)

*/

	//�ҵ���
	int n1 = srcMat.rows;
	int nc = srcMat.cols;

	Point2f a;  //(���Ͻ�)
	Point2f b;  //(���½�)
	Point2f c;  //���Ͻ�


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

	//����������

	const Mat affine_matrix2 = getAffineTransform(src_pt, dst_pt);
	warpAffine(srcMat, dst_affine, affine_matrix2, srcMat.size());

	circle(srcMat, a, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	circle(srcMat, b, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	circle(srcMat, c, 5, CV_RGB(255, 0, 0), 1, 8, 0);

	imshow("ԭͼ", srcMat);
	imshow("����任", dst_affine);


	waitKey(0);

	return 0;
}