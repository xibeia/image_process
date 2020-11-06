//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
////人脸美颜练习
//
///*参考了一些博客，主要是先高斯滤波消除噪点，
//然后再用双边滤波的，效果已经很不错了，
//接着还有调整了对比度亮度的
//有的磨的太厉害的又用了图像增强
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
//			std::cout << "不能从视频文件中读取帧" << std::endl;
//			break;
//		}
//		else
//		{
//			GaussianBlur(frame, frame_Gau, Size(5, 5), 0, 0);
//			imshow("高斯滤波", frame_Gau);
//			int bilateralFilterVal = 15;
//			bilateralFilter(frame_Gau, frame_bilater, bilateralFilterVal, // 整体磨皮
//				bilateralFilterVal * 2, bilateralFilterVal / 2);
//			imshow("双边滤波", frame_bilater); //可以看出效果不错
//
//
//			addWeighted(frame_bilater, 1.5, frame_Gau, -0.5, 0, frame_final);
//
//			imshow("最终的", frame_final);
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
///*按照课堂要求
//调整hsv，高斯滤波，
//掩膜操作
//
//*/
//
//void facebeauty2() {
//	//打开摄像头
//	VideoCapture cap(0);
//
//	//肤色h					
//	double i_minH = 0;
//	double i_maxH = 20;
//
//	//肤色颜色饱和度s
//	double i_minS = 43;
//	double i_maxS = 255;
//
//	//肤色颜色亮度v
//	double i_minV = 55;
//	double i_maxV = 255;
//
//	while (1)
//	{
//		//定义图像容器
//		Mat frame;
//		Mat hsvMat;
//		Mat maskMat;
//		Mat objectMat;
//		Mat guss_Mat;
//
//		cap >> frame;//读取当前帧的照片
//
//		//将原图转化为hsv类型的图片
//		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
//
//		//对detecMat进行初始化
//		frame.copyTo(maskMat);
//
//		//利用inRange函数对图片进行hsv筛选（选出人脸部分）
//		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), maskMat);
//
//		//原图拷入输出中
//		frame.copyTo(objectMat);
//
//		//对图像进行高斯滤波
//		GaussianBlur(frame, guss_Mat, Size(5, 5), 3, 0);
//
//		//高斯滤波后的人脸部分送入目标图中
//		guss_Mat.copyTo(objectMat, maskMat);//从原图中取出目标图像（与运算）
//
//
//		//显示结果
//		imshow("磨皮前", frame);
//		imshow("磨皮后", objectMat);
//
//		waitKey(30);
//	}
//
//}
//
//
//int main() {
//	//开始计时
//	double start = static_cast<double>(cvGetTickCount());
//
//	//处理函数
//
//	//facebeanty1();
//	facebeauty2();
//
//	//结束计时
//	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
//	//显示时间
//	cout << "processing time:" << time / 1000 << "ms" << endl;
//
//	//等待键盘响应，按任意键结束程序
//	system("pause");
//	return 0;
//}