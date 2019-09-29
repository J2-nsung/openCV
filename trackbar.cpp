// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata);

int main()
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);
	imshow("image", img);
	waitKey();
	
    return 0;
}

void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);
	imshow("image", img);
}

