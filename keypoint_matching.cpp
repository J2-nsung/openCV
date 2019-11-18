#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat src1 = imread("../_res/box.png", IMREAD_GRAYSCALE);
	Mat src2 = imread("../_res/box_in_scene.png", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty()) {
		cerr << "image load failed!" << endl;
		return -1;
	}

	Ptr<Feature2D> feature = ORB::create();

	vector<KeyPoint> keypoints1, keypoints2;
	Mat desc1, desc2;
	feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
	feature->detectAndCompute(src2, Mat(), keypoints2, desc2);

	Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);

	vector<DMatch> matches;
	matcher->match(desc1, desc2, matches);

	Mat dst;
	drawMatches(src1, keypoints1, src2, keypoints2, matches, dst);

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

	return 0;
}