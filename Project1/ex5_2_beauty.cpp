#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//����������ϰ

/*�ο���һЩ���ͣ���Ҫ���ȸ�˹�˲�������㣬
Ȼ������˫���˲��ģ�Ч���Ѿ��ܲ����ˣ�
���Ż��е����˶Աȶ����ȵ�
�е�ĥ��̫������������ͼ����ǿ

*/
int main() {
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;

	Mat frame,frame_Gau,frame_bilater;
	Mat frame_final;

	while (1) {

		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			GaussianBlur(frame, frame_Gau, Size(5, 5), 0, 0);
			imshow("��˹�˲�", frame_Gau);
			int bilateralFilterVal = 15;
			bilateralFilter(frame_Gau, frame_bilater, bilateralFilterVal, // ����ĥƤ
				bilateralFilterVal * 2, bilateralFilterVal / 2);
			imshow("˫���˲�", frame_bilater); //���Կ���Ч������

			
			addWeighted(frame_bilater, 1.5, frame_Gau, -0.5, 0, frame_final);

			imshow("���յ�", frame_final);




		}
		waitKey(30);
	}
}