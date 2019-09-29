// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat img1 = imread("../_res/lenna.bmp");

	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}
	
	Mat img2 = img1(Rect(100,100,300,300));
	Mat img3 = img1(Rect(100,100,300,300)).clone();

	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
	return 0;
}

