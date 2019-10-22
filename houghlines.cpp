// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../_res/building.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat edge;
	Canny(src, edge, 50, 150);

	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		float r = lines[i][0], t = lines[i][1];
		double cos_t = cos(t), sin_t = sin(t);
		double x0 = r*cos_t, y0 = r*sin_t;
		double alpha = 1000;
		Point pt1(cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*cos_t));
		Point pt2(cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

	return 0;
}