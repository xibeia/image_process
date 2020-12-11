//#include <iostream>  
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//
//using namespace cv;
//
//Mat Gamma(Mat &srcImage, float k) {
//
//	float Lut[256];
//	//归一化
//
//	for (int i = 0; i < 256; i++)
//	{
//		float f = (float(i)/ 255);  //归一化 ,注意数据类型计算
//		f = (float)(pow(f, k)); //f^k
//		Lut[i] = saturate_cast<uchar>(f*255);  //还原,saturate_cast保证不溢出
//	}
//
//	Mat gammaTrans = srcImage.clone();
//
//	int n1 = srcImage.rows;
//	int nc = srcImage.cols;
//
//	//判断单通道还是三通道，遍历像素进行转换
//	if (srcImage.channels() == 1) {
//
//		for (int j = 0; j < n1; j++) {
//			for (int i = 0; i < nc; i++) {
//				gammaTrans.at<uchar>(j, i) = Lut[srcImage.at<uchar>(j, i)];
//			}
//		}
//
//	}
//	else
//	{
//		for (int j = 0; j < n1; j++) {
//			for (int i = 0; i < nc; i++) {
//				gammaTrans.at<Vec3b>(j, i)[0] = Lut[srcImage.at<Vec3b>(j, i)[0]];
//				gammaTrans.at<Vec3b>(j, i)[1] = Lut[srcImage.at<Vec3b>(j, i)[1]];
//				gammaTrans.at<Vec3b>(j, i)[2] = Lut[srcImage.at<Vec3b>(j, i)[2]];
//			}
//		}
//	}
//	return gammaTrans;
//
//}
//
//
//int main()
//{
//
//	Mat srcimg = imread("直方图增强.jpg",0);   
//
//	if (!srcimg.data)
//	{
//		printf("加载失败");
//		return -1;
//	}
//
//	imshow("原图", srcimg);
//
//
//	float k =1/2.2;
//	Mat gammaResult;
//	gammaResult = Gamma(srcimg, k);
//
//	imshow("gamma矫正后", gammaResult);
//
//	//练习3，找出文字
//
//	Mat srcimg2 = imread("隐藏文字.jpg", 0);
//
//	if (!srcimg2.data)
//	{
//		printf("图片2加载失败");
//		return -1;
//	}
//
//	imshow("原图2", srcimg2);
//
//
//	float k2 = 1/2.1;
//	Mat gammaResult2;
//	gammaResult2 = Gamma(srcimg2, k2);
//
//	imshow("图2gamma矫正后", gammaResult2);
//	//文字：李竹老师超级帅
//	waitKey(0);
//	return 0;
//}
//
//
