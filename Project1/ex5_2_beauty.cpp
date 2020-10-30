#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//人脸美颜练习

/*参考了一些博客，主要是先高斯滤波消除噪点，
然后再用双边滤波的，效果已经很不错了，
接着还有调整了对比度亮度的
有的磨的太厉害的又用了图像增强

*/
int main() {
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
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
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			GaussianBlur(frame, frame_Gau, Size(5, 5), 0, 0);
			imshow("高斯滤波", frame_Gau);
			int bilateralFilterVal = 15;
			bilateralFilter(frame_Gau, frame_bilater, bilateralFilterVal, // 整体磨皮
				bilateralFilterVal * 2, bilateralFilterVal / 2);
			imshow("双边滤波", frame_bilater); //可以看出效果不错

			
			addWeighted(frame_bilater, 1.5, frame_Gau, -0.5, 0, frame_final);

			imshow("最终的", frame_final);




		}
		waitKey(30);
	}
}