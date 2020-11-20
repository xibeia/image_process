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
//	srcMat = imread("红盒子.jpg", 0);//单通道
//	srcMat2 = imread("红盒子.jpg", 1);//三通道
//	if (srcMat.empty()) return -1;
//	//imshow("原图", srcMat);
//
//	//原图太大了，缩小一下
//	Mat resizeMat,resizeMat2;
//	resize(srcMat, resizeMat, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR); //单通道
//	resize(srcMat2, resizeMat2, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR);  //三通道
//	//imshow("缩小图", resizeMat2);
//
//	//imgconvert(resizeMat);
//	//imshow("黑白转换", resizeMat);
//
//	//threshold(resizeMat, thresold_img, 80, 255, THRESH_OTSU);  //这个二值化不太行，边缘都没了，换为自适应二值化
//	
//	adaptiveThreshold(resizeMat, thresold_img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
//
//	imshow("二值图", thresold_img);
//
//	////开运算
//	Mat element = getStructuringElement(MORPH_CROSS,Size(9,9));
//	
//	Mat moropenimg, erode_cv;
//	morphologyEx(thresold_img, moropenimg, MORPH_CLOSE, element);
//	imshow("闭运算", moropenimg);
//
//	//Mat element2 = getStructuringElement(MORPH_RECT, Size(2, 2));
//	//erode(moropenimg, erode_cv, element2);
//	//imshow("腐蚀后", erode_cv);
//
//
//	//通过findcontours寻找连通域
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
//		if (height < width) {
//			float tt = width;
//			width = height;  //记短边为width，长边为height
//			height = tt;
//		}
//
//		float kk = width / height;
//		float ci_area = width * height;  //外接四边形的面积
//
//		int contour_area = contourArea(contours[i]);  //连通域面积
//
//	
//		int flag = 0;
//		for (int j = 0; j < contours[i].size(); j++)
//			{
//				//标记出contours向量内的像素点
//				Point P = Point(contours[i][j].x, contours[i][j].y);
//				//如果显示红色
//				if (resizeMat2.at<Vec3b>(P)[0] < 130 && resizeMat2.at<Vec3b>(P)[1] < 130 && resizeMat2.at<Vec3b>(P)[2] > 150) {
//					flag = 1;
//					resizeMat2.at<Vec3b>(P)[0] = 255;
//					resizeMat2.at<Vec3b>(P)[1] = 0;
//					resizeMat2.at<Vec3b>(P)[2] = 0;
//				}
//
//			}
//
//		cout << flag << endl;
//
//		drawContours(resizeMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//		Rect r = boundingRect(Mat(contours[i]));
//		rectangle(resizeMat2, r, Scalar(0, 0, 255), 2);
//
//		if (flag) {  //取接近圆形的，面积大的，用面积限制去除小噪点   contour_area>50&&flag
//			//绘制轮廓  contour_area > 100&& contour_area<1000 && flag
//			drawContours(resizeMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(resizeMat2, r, Scalar(0, 0, 255), 2);
//		}
//
//	}
//
//	imshow("标记图", resizeMat2);
//
//
//	waitKey(0);
//	return 0;
//}
//
//
//
