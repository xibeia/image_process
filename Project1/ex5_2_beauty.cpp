//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
////����������ϰ
//
///*�ο���һЩ���ͣ���Ҫ���ȸ�˹�˲�������㣬
//Ȼ������˫���˲��ģ�Ч���Ѿ��ܲ����ˣ�
//���Ż��е����˶Աȶ����ȵ�
//�е�ĥ��̫������������ͼ����ǿ
//
//*/
//
//void facebeanty1() {
//	VideoCapture cap;
//	cap.open(0);
//
//
//	Mat frame, frame_Gau, frame_bilater;
//	Mat frame_final;
//
//	while (1) {
//
//		bool rSucess = cap.read(frame);
//		if (!rSucess)
//		{
//			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
//			break;
//		}
//		else
//		{
//			GaussianBlur(frame, frame_Gau, Size(5, 5), 0, 0);
//			imshow("��˹�˲�", frame_Gau);
//			int bilateralFilterVal = 15;
//			bilateralFilter(frame_Gau, frame_bilater, bilateralFilterVal, // ����ĥƤ
//				bilateralFilterVal * 2, bilateralFilterVal / 2);
//			imshow("˫���˲�", frame_bilater); //���Կ���Ч������
//
//
//			addWeighted(frame_bilater, 1.5, frame_Gau, -0.5, 0, frame_final);
//
//			imshow("���յ�", frame_final);
//
//
//
//
//		}
//		waitKey(30);
//	}
//}
//
//
///*���տ���Ҫ��
//����hsv����˹�˲���
//��Ĥ����
//
//*/
//
//void facebeauty2() {
//	//������ͷ
//	VideoCapture cap(0);
//
//	//��ɫh					
//	double i_minH = 0;
//	double i_maxH = 20;
//
//	//��ɫ��ɫ���Ͷ�s
//	double i_minS = 43;
//	double i_maxS = 255;
//
//	//��ɫ��ɫ����v
//	double i_minV = 55;
//	double i_maxV = 255;
//
//	while (1)
//	{
//		//����ͼ������
//		Mat frame;
//		Mat hsvMat;
//		Mat maskMat;
//		Mat objectMat;
//		Mat guss_Mat;
//
//		cap >> frame;//��ȡ��ǰ֡����Ƭ
//
//		//��ԭͼת��Ϊhsv���͵�ͼƬ
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
//
//		//��detecMat���г�ʼ��
//		frame.copyTo(maskMat);
//
//		//����inRange������ͼƬ����hsvɸѡ��ѡ���������֣�
//		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), maskMat);
//
//		//ԭͼ���������
//		frame.copyTo(objectMat);
//
//		//��ͼ����и�˹�˲�
//		GaussianBlur(frame, guss_Mat, Size(5, 5), 3, 0);
//
//		//��˹�˲����������������Ŀ��ͼ��
//		guss_Mat.copyTo(objectMat, maskMat);//��ԭͼ��ȡ��Ŀ��ͼ�������㣩
//
//
//		//��ʾ���
//		imshow("ĥƤǰ", frame);
//		imshow("ĥƤ��", objectMat);
//
//		waitKey(30);
//	}
//
//}
//
//
//int main() {
//	//��ʼ��ʱ
//	double start = static_cast<double>(cvGetTickCount());
//
//	//������
//
//	//facebeanty1();
//	facebeauty2();
//
//	//������ʱ
//	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
//	//��ʾʱ��
//	cout << "processing time:" << time / 1000 << "ms" << endl;
//
//	//�ȴ�������Ӧ�����������������
//	system("pause");
//	return 0;
//}