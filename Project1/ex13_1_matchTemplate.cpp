//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//
//	VideoCapture cap;
//	cap.open(0);
//	if (!cap.isOpened())
//	{
//		std::cout << "不能打开视频文件" << std::endl;
//		return -1;
//	}
//
//	Mat tempMat, refMat;
//	Mat frame;
//	Mat disMat; //最好都定义在外面
//
//	int cnt = 0;
//	while (1) {
//		
//		bool rSucess = cap.read(frame);
//		if (!rSucess)
//		{
//			std::cout << "不能从视频文件中读取帧" << std::endl;
//			break;
//		}
//
//		//选取第一帧的样本
//		if (cnt == 0) {
//			Rect2d r;
//			r = selectROI(frame, true);
//			tempMat = frame(r);
//			tempMat.copyTo(refMat);
//			destroyAllWindows();
//		}	
//
//		//模板匹配
//		Mat resultMat;//匹配Mat会比原图缩小一点
//		int match_method = 0;
//		matchTemplate(frame, refMat, resultMat, match_method);
//		normalize(resultMat, resultMat, 0, 1, NORM_MINMAX, -1, Mat());
//
//		double minVal;
//		double maxVal;
//		Point minLoc;
//		Point maxLoc;
//
//		Point matchLoc;
//		minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc, Mat()); //寻找极值
//
//		//判断是用最小值还是最大值
//		if (match_method==TM_SQDIFF||match_method==TM_SQDIFF_NORMED)
//		{
//			matchLoc = minLoc;
//		}
//		else
//		{
//			matchLoc = maxLoc;
//		}
//
//
//		frame.copyTo(disMat);
//		Point Loc2;
//		Loc2.x = matchLoc.x + refMat.rows;
//		Loc2.y = matchLoc.y + refMat.cols;
//		rectangle(disMat, matchLoc,Loc2, Scalar(1, 0, 0));
//
//		imshow("参考图", refMat);
//		imshow("追踪", disMat);
//		
//
//		cnt++;
//		waitKey(30);
//	}
//
//}