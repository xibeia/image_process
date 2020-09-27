//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//
//void colorReduce(cv::Mat &image) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//
//			uchar ave = (image.at<Vec3b>(j, i)[0] + image.at<Vec3b>(j, i)[1] + image.at<Vec3b>(j, i)[2]) / 3;
//			image.at<Vec3b>(j, i)[0] = ave;
//			image.at<Vec3b>(j, i)[1] = ave;
//			image.at<Vec3b>(j, i)[2] = ave;
//		}
//
//	}
//}
//
//
//void colorReduce2(cv::Mat &image,uchar  threshold = 100) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//
//			uchar ave = (image.at<Vec3b>(j, i)[0] + image.at<Vec3b>(j, i)[1] + image.at<Vec3b>(j, i)[2]) / 3;
//			if (ave>threshold)
//			{
//				image.at<Vec3b>(j, i)[0] = 255;
//				image.at<Vec3b>(j, i)[1] = 255;
//				image.at<Vec3b>(j, i)[2] = 255;
//			}
//			else
//			{
//				image.at<Vec3b>(j, i)[0] = 0;
//				image.at<Vec3b>(j, i)[1] = 0;
//				image.at<Vec3b>(j, i)[2] = 0;
//			}
//			
//			
//		}
//
//	}
//}
//
//
//int main() {
//	cv::Mat imgsrc;
//	imgsrc = imread("D:/大三上学习资料/数字图像处理/lenna.jpg");
//	namedWindow("图片");
//	imshow("图片", imgsrc);
//	waitKey(0);
//
//	// 显示处理1后的图片，灰度   
//	colorReduce(imgsrc);
//	namedWindow("处理1");
//	imshow("处理1", imgsrc);
//	waitKey(0);
//
//	//处理2灰度
//	cv::Mat img2;
//	img2 = imread("D:/大三上学习资料/数字图像处理/lenna.jpg", 0);
//	namedWindow("处理2");
//	imshow("处理2", img2);
//	waitKey(0);
//
//	//处理3，二值图像
//	cv::Mat img3;
//	img3 = imread("D:/大三上学习资料/数字图像处理/lenna.jpg");
//	colorReduce2(img3);
//	namedWindow("处理3");
//	imshow("处理3", img3);
//	waitKey(0);
//	
//	//处理4
//	cv::Mat srcMat,deepMat, shallowMat;
//	srcMat= imread("D:/大三上学习资料/数字图像处理/lenna.jpg");
//	shallowMat = srcMat;  //浅复制
//	srcMat.copyTo(deepMat);  //深复制
//	colorReduce2(srcMat);
//
//	namedWindow("浅复制");
//	imshow("浅复制", shallowMat);
//	waitKey(0);
//
//	namedWindow("深复制");
//	imshow("深复制", deepMat);
//	waitKey(0);
//
//	return 0;
//
//}
