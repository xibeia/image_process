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
//	Mat srcMat, srcMat2, thresold_img;
//	srcMat = imread("芯片.jpg", 0);//单通道
//	srcMat2 = imread("芯片.jpg", 1);//三通道
//	if (srcMat.empty()) return -1;
//
//	imshow("原图", srcMat);
//
//	//imgconvert(srcMat);
//	//imshow("黑白转换", srcMat);
//
//	threshold(srcMat, thresold_img, 250, 255, THRESH_OTSU);  //大津法二值化
//	imshow("二值图", thresold_img);
//
//	//芯片中间有很多线，腐蚀一下，做开运算
//	Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
//	
//	Mat moropenimg;
//	morphologyEx(thresold_img, moropenimg, MORPH_OPEN, element);
//	imshow("开运算", moropenimg);
//
//
//	//通过finvontours寻找连通域
//	vector<vector<Point>>  contours;
//	vector<Vec4i> hierachy;
//
//	findContours(moropenimg, contours, hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	//CV_RETR_EXTERNAL 只检测最外围轮阔，CV_CHAIN_APPROX_NONE：保存轮廓点到contours向量内
//
//	for (int i = 0; i < contours.size(); ++i) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//
//		float width = rbox.size.width;
//		float height = rbox.size.height;
//
//		float kk = width / height;
//		float ci_area = width * height;  //外接四边形的面积
//
//		int contour_area =contourArea(contours[i]);  //连通域面积
//
//		if (kk > 0.9&& contour_area > 400) {  //取接近圆形的，面积大的，用面积限制去除小噪点
//			//绘制轮廓
//			drawContours(srcMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//
//			////绘制最小外接四边形
//			//Point2f vtx[4];
//			//for (int j = 0; j < 4; ++j) {
//			//	line(srcMat2, vtx[j], vtx[j < 3 ? j + 1 : 0], Scalar(0, 255, 255), 2, CV_AA);
//			//}
//
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(srcMat2, r, Scalar(0, 0, 255), 2);
//		}
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
