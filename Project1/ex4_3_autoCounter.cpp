//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//void imgconvert(cv::Mat &image) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//			image.at<uchar>(j, i) = 255 - image.at<uchar>(j, i);
//		}
//	}
//}
//
//int main() {
//	Mat srcMat, thresold_img;
//	srcMat = imread("电路.jpg",0);
//	imshow("原图", srcMat);
//
//	imgconvert(srcMat);
//	imshow("黑白转换", srcMat);
//
//	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //大津法二值化
//
//	imshow("二值图", thresold_img);
//
//	Mat stats;
//	Mat centroids;
//	Mat labels;
//
//
//
//	//对图像先腐蚀，要把线给腐蚀掉
//	int g_nStructElementSize = 20; //结构元素(内核矩阵)的尺寸
//	Mat element = getStructuringElement(MORPH_RECT,
//		Size(g_nStructElementSize, g_nStructElementSize));
//	//Mat element = getStructuringElement(MORPH_ELLIPSE,
////	Size(g_nStructElementSize, g_nStructElementSize));  //椭圆形尺寸
//
//	Mat erode_cv;
//	erode(thresold_img,erode_cv, element);
//	imshow("腐蚀后", erode_cv);
//
//	//dilate(thresold_img, dilated_cv, element);
//	//	imshow("膨胀后", dilated_cv);
//
//
//	int num_labels = connectedComponentsWithStats(thresold_img, labels, stats, centroids, 8, CV_32S);
//	cout << num_labels -1<< endl;
//
//
//	waitKey(0);
//	return 0;
//}
//
//
//
//
//
