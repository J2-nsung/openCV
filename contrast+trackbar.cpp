// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat src;
void on_brightness(int pos, void* userdata);

int main()
{
	src = imread("../_res/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);


	waitKey();
	destroyAllWindows();

    return 0;
}

void on_brightness(int pos, void* userdata) {
	// -0.5 < alpha < 2.8
	// 0 <= pos <= 100
	float alpha = (((int)(pos) / 30)) - .5;
	//int val = -128 * alpha;
	//Mat dst = (1 + alpha) * src + val;
	Mat dst = src + (src - 128)*alpha;
	imshow("dst", dst);
}