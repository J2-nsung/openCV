// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat src1, src2;
void on_blending1(int pos, void* userdata);
void on_blending2(int pos, void* userdata);

int main()
{
	src1 = imread("../_res/image1.jpg", IMREAD_GRAYSCALE);
	src2 = imread("../_res/image2.jpg", IMREAD_GRAYSCALE);

	namedWindow("AlphaBlending");
	namedWindow("AlphaBlending-EQ");

	createTrackbar("alpha", "AlphaBlending", 0, 100, on_blending1);
	createTrackbar("alpha", "AlphaBlending-EQ", 0, 100, on_blending2);

	if (src1.empty() || src2.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	waitKey();
	destroyAllWindows();

    return 0;
}

void on_blending1(int pos, void* userdata) {
	double alpha = pos / 100.0;
	Mat dst;
	addWeighted(src1, alpha, src2, 1 - alpha, 0, dst);
	imshow("AlphaBlending", dst);
}

void on_blending2(int pos, void* userdata) {
	double alpha = pos / 100.0;
	Mat dst;
	addWeighted(src1, alpha, src2, 1 - alpha, 0, dst);

	Mat ehdst;
	equalizeHist(dst, ehdst);
	imshow("AlphaBlending-EQ", ehdst);

}