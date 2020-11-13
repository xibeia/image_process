//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat, dstMat;
//	srcMat = imread("lenna_rote.jpg", 1);
//	if (srcMat.empty()) return -1;
//
//	//练习五
//
//	//找到点
//
//	int n1 = srcMat.rows;
//	int nc = srcMat.cols;
//	int l;
//	Point2f a;
//	Point2f b;
//	Point2f c;
//
//	//(0,n1)
//	for (int j = 0; j < n1; j++) {
//
//		if (srcMat.at<uchar>(j, 0) < 200){
//				a.x = 0;
//				a.y = j;
//				l = j;
//				continue;
//			}		
//	}
//
//	float wl = n1 - l;
//	b.x = nc;
//	b.y = wl;
//
//	c.x =  wl;
//	c.y = 0;
//
//	////(nc,0)
//	//for (int j = 0; j < n1; j++) {
//
//	//	if (srcMat.at<uchar>(j, nc) < 200) {
//	//		b.x = nc;
//	//		b.y = n1-j;
//	//		continue;
//	//	}
//	//}
//
//	////(0,0)
//	//for (int i = 0; i < nc; i++) {
//
//	//	if (srcMat.at<uchar>(i, 0) < 200) {
//	//		c.x =n1- i;
//	//		c.y = 0;
//	//		continue;
//	//	}
//	//}
//
//	Mat dst_affine;
//	const Point2f src_pt[] = {
//		a,
//		b,
//		c
//	};
//
//	const Point2f dst_pt[] = {
//		Point2f(0,n1),
//		Point2f(nc,0),
//		Point2f(0,0)
//	};
//
//	//计算放射矩阵
//
//	const Mat affine_matrix2 = getAffineTransform(src_pt, dst_pt);
//	warpAffine(srcMat, dst_affine, affine_matrix2, srcMat.size());
//
//	circle(srcMat, a, 5, CV_RGB(255, 0, 0), 1, 8, 0);
//	circle(srcMat, b, 5, CV_RGB(255, 0, 0), 1, 8, 0);
//	circle(srcMat, c, 5, CV_RGB(255, 0, 0), 1, 8, 0);
//
//	imshow("原图", srcMat);
//	imshow("仿射变换", dst_affine);
//
//
//	waitKey(0);
//
//	return 0;
//}