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
//	srcMat = imread("��·.jpg",0);
//	imshow("ԭͼ", srcMat);
//
//	imgconvert(srcMat);
//	imshow("�ڰ�ת��", srcMat);
//
//	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //��򷨶�ֵ��
//
//	imshow("��ֵͼ", thresold_img);
//
//	Mat stats;
//	Mat centroids;
//	Mat labels;
//
//
//
//	//��ͼ���ȸ�ʴ��Ҫ���߸���ʴ��
//	int g_nStructElementSize = 20; //�ṹԪ��(�ں˾���)�ĳߴ�
//	Mat element = getStructuringElement(MORPH_RECT,
//		Size(g_nStructElementSize, g_nStructElementSize));
//	//Mat element = getStructuringElement(MORPH_ELLIPSE,
////	Size(g_nStructElementSize, g_nStructElementSize));  //��Բ�γߴ�
//
//	Mat erode_cv;
//	erode(thresold_img,erode_cv, element);
//	imshow("��ʴ��", erode_cv);
//
//	//dilate(thresold_img, dilated_cv, element);
//	//	imshow("���ͺ�", dilated_cv);
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
