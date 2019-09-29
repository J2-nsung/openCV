// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

