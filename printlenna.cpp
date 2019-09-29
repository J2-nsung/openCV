// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;


int main()
{
	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img;
	img = imread("../_res/lenna.bmp",IMREAD_GRAYSCALE);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);

	waitKey();
    return 0;
}

