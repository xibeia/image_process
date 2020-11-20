//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat,dstMat;
//	srcMat = imread("D://大三上学习资料//数字图像处理//lenna2.jpg",1);
//	if (srcMat.empty()) return -1;
//

//	//练习二旋转
//	float angle = -10.0, scale = 1;
//
//	Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
//	const Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
//	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
//	imshow("原图", srcMat);
//	imshow("旋转", dstMat);
//
//	//练习三: 仿射变换
//
//	Mat dst_affine;
//	const Point2f src_pt[] = {
//		Point2f(100,100),
//		Point2f(150,100),
//		Point2f(100,50)
//	};
//
//	const Point2f dst_pt[] = {
//		Point2f(200,50),
//		Point2f(200,0),
//		Point2f(200,50)
//	};
//
//	//计算放射矩阵
//
//	const Mat affine_matrix2 = getAffineTransform(src_pt, dst_pt);
//	warpAffine(srcMat, dst_affine, affine_matrix2, srcMat.size());
//
//	imshow("仿射变换", dst_affine);
//
//
//	//练习四  投影变换
//	Mat dst_Pers;
//	const Point2f pts1[] = {
//		Point2f(150,150),
//		Point2f(150,300),
//		Point2f(350,300),
//		Point2f(350,150)
//	};
//
//	const Point2f pts2[] = {
//		Point2f(200,150),
//		Point2f(200,300),
//		Point2f(340,270),
//		Point2f(340,180)
//	};
//
//	//透视变换行列计算
//
//	Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);
//	warpPerspective(srcMat, dst_Pers, perspective_matrix, srcMat.size());
//
//	imshow("投影变换", dst_Pers);
//
//
//	waitKey(0);
//
//	return 0;
//}