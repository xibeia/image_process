//#include <iostream>  
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//
//using namespace cv;
//
//Mat Gamma(Mat &srcImage, float k) {
//
//	float Lut[256];
//	//��һ��
//
//	for (int i = 0; i < 256; i++)
//	{
//		float f = (float(i)/ 255);  //��һ�� ,ע���������ͼ���
//		f = (float)(pow(f, k)); //f^k
//		Lut[i] = saturate_cast<uchar>(f*255);  //��ԭ,saturate_cast��֤�����
//	}
//
//	Mat gammaTrans = srcImage.clone();
//
//	int n1 = srcImage.rows;
//	int nc = srcImage.cols;
//
//	//�жϵ�ͨ��������ͨ�����������ؽ���ת��
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
//	Mat srcimg = imread("ֱ��ͼ��ǿ.jpg",0);   
//
//	if (!srcimg.data)
//	{
//		printf("����ʧ��");
//		return -1;
//	}
//
//	imshow("ԭͼ", srcimg);
//
//
//	float k =1/2.2;
//	Mat gammaResult;
//	gammaResult = Gamma(srcimg, k);
//
//	imshow("gamma������", gammaResult);
//
//	//��ϰ3���ҳ�����
//
//	Mat srcimg2 = imread("��������.jpg", 0);
//
//	if (!srcimg2.data)
//	{
//		printf("ͼƬ2����ʧ��");
//		return -1;
//	}
//
//	imshow("ԭͼ2", srcimg2);
//
//
//	float k2 = 1/2.1;
//	Mat gammaResult2;
//	gammaResult2 = Gamma(srcimg2, k2);
//
//	imshow("ͼ2gamma������", gammaResult2);
//	//���֣�������ʦ����˧
//	waitKey(0);
//	return 0;
//}
//
//
