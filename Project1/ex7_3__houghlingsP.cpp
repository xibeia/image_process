//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main() {
//	Mat srcMat, srcMat2, dstMat;
//	srcMat2 = imread("零件.jpg", 1); //读取三通道 ，注意后面画图时，如果读取单通道后面画图会显示灰黑色，可以再读个三通道图
//	srcMat = imread("零件.jpg", 0); //读取单通道
//	if (srcMat.empty()) return -1;
//
//	Mat threhold_img, canny_img;
//
//	threshold(srcMat, threhold_img, 100, 255, THRESH_BINARY);
//	Canny(threhold_img, canny_img, 100, 200, 3);
//	 
//	Mat lines;
//	HoughLinesP(canny_img, lines, 1, CV_PI / 180, 30, 0, 20);
//
//	//调参思考
//	//倒数第一个参数，连线最大间隔a, 间隔大于等于a时不能连上
//	//倒数第二个参数，检测直线的最小长度b，直线长度小于b时不会出来，要想出来所有的直线，可以设为0
//	//倒数第三个参数，直线上的点数，大于该点数可显示出来
//	//其实倒数2,3个参数有些相同，可固定一个调另一个
//
//
//	for (int i = 0; i < lines.rows; i++)
//	{
//		Vec4i  myline = lines.at<Vec4i>(i);
//		line(srcMat2, Point(myline[0], myline[1]), Point(myline[2], myline[3]), Scalar(255, 0, 0), 1, CV_AA);
//	}
//
//
//	imshow("边缘", canny_img);
//	imshow("原图", srcMat2);
//
//
//
//	waitKey(0);
//
//	return 0;
//}