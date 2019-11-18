#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat src = imread("../_res/box_in_scene.png", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "image load failed!" << endl;
		return -1;
	}

	Ptr<Feature2D> feature = ORB::create();

	vector<KeyPoint> keypoints;
	feature->detect(src, keypoints);

	Mat desc;
	feature->compute(src, keypoints, desc);

	cout << "keypoints.size(): " << keypoints.size() << endl;
	cout << "desc.size(): " << desc.size() << endl;

	Mat dst;
	drawKeypoints(src, keypoints, dst, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

	return 0;
}