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
//	srcMat = imread("�����.jpg", 0);//��ͨ��
//	srcMat2 = imread("�����.jpg", 1);//��ͨ��
//	if (srcMat.empty()) return -1;
//	//imshow("ԭͼ", srcMat);
//
//	//ԭͼ̫���ˣ���Сһ��
//	Mat resizeMat,resizeMat2;
//	resize(srcMat, resizeMat, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR); //��ͨ��
//	resize(srcMat2, resizeMat2, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR);  //��ͨ��
//	//imshow("��Сͼ", resizeMat2);
//
//	//imgconvert(resizeMat);
//	//imshow("�ڰ�ת��", resizeMat);
//
//	//threshold(resizeMat, thresold_img, 80, 255, THRESH_OTSU);  //�����ֵ����̫�У���Ե��û�ˣ���Ϊ����Ӧ��ֵ��
//	
//	adaptiveThreshold(resizeMat, thresold_img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
//
//	imshow("��ֵͼ", thresold_img);
//
//	////������
//	Mat element = getStructuringElement(MORPH_CROSS,Size(9,9));
//	
//	Mat moropenimg, erode_cv;
//	morphologyEx(thresold_img, moropenimg, MORPH_CLOSE, element);
//	imshow("������", moropenimg);
//
//	//Mat element2 = getStructuringElement(MORPH_RECT, Size(2, 2));
//	//erode(moropenimg, erode_cv, element2);
//	//imshow("��ʴ��", erode_cv);
//
//
//	//ͨ��findcontoursѰ����ͨ��
//	vector<vector<Point>>  contours;
//	vector<Vec4i> hierachy;
//
//	findContours(moropenimg, contours, hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	//CV_RETR_EXTERNAL ֻ�������Χ������CV_CHAIN_APPROX_NONE�����������㵽contours������
//
//	for (int i = 0; i < contours.size(); ++i) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//
//		float width = rbox.size.width;
//		float height = rbox.size.height;
//		if (height < width) {
//			float tt = width;
//			width = height;  //�Ƕ̱�Ϊwidth������Ϊheight
//			height = tt;
//		}
//
//		float kk = width / height;
//		float ci_area = width * height;  //����ı��ε����
//
//		int contour_area = contourArea(contours[i]);  //��ͨ�����
//
//	
//		int flag = 0;
//		for (int j = 0; j < contours[i].size(); j++)
//			{
//				//��ǳ�contours�����ڵ����ص�
//				Point P = Point(contours[i][j].x, contours[i][j].y);
//				//�����ʾ��ɫ
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
//		if (flag) {  //ȡ�ӽ�Բ�εģ������ģ����������ȥ��С���   contour_area>50&&flag
//			//��������  contour_area > 100&& contour_area<1000 && flag
//			drawContours(resizeMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(resizeMat2, r, Scalar(0, 0, 255), 2);
//		}
//
//	}
//
//	imshow("���ͼ", resizeMat2);
//
//
//	waitKey(0);
//	return 0;
//}
//
//
//
