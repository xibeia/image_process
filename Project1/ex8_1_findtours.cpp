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
//
//
//int main() {
//	Mat srcMat,srcMat2,thresold_img;
//	srcMat = imread("车轮.png", 0);//单通道
//	srcMat2 = imread("车轮.png", 1);//三通道
//	if (srcMat.empty()) return -1;
//
//	imshow("原图", srcMat);
//
//	imgconvert(srcMat);
//	imshow("黑白转换", srcMat);
//
//	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //大津法二值化
//	imshow("二值图", thresold_img);
//
//
//
//	//通过finvontours寻找连通域
//	vector<vector<Point>>  contours;
//	vector<Vec4i> hierachy;
//
//	findContours(thresold_img, contours,hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	//CV_RETR_EXTERNAL 只检测最外围轮阔，CV_CHAIN_APPROX_NONE：保存轮廓点到contours向量内
//	//coutous里面存储了所有的轮廓的点
//
//	for (int i = 0; i < contours.size(); ++i) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//
//		float width = rbox.size.width;
//		float height = rbox.size.height;
//		
//		float kk = width / height;
//		float ci_area = width * height;
//		
//		if (kk > 0.9&& ci_area > 250) {  //取接近圆形的，面积大的，用面积限制去除小噪点
//			//绘制轮廓
//			drawContours(srcMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//
//			//for (int j = 0; j < contours[i].size(); j++)
//			//{
//			//	//标记出contours向量内的像素点
//			//	Point P = Point(contours[i][j].x, contours[i][j].y);
//			//	srcMat2.at<Vec3b>(P)[0] = 0;
//			//	srcMat2.at<Vec3b>(P)[1] = 255;
//			//	srcMat2.at<Vec3b>(P)[2] = 255;
//			//}  //与drawContours功能一样
//
//			//画出外接四边形
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(srcMat2, r, Scalar(0,0,255), 2);
//		}
//		
//
//	}
//
//	imshow("标记图", srcMat2);
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
