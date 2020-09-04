#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat image = imread("show.jpeg");

	Mat image100;
	Mat image50;
	Mat imagelow100;
	Mat imagelow50;

	if (image.empty()) {
		cout <<"Couldn't find the image"<<endl;
		cin.get() ; // Wait for the keystroke
		return -1;
	}
	string window_name = "Showing the image";
	string window_name_high_100 = "High 100";
	string window_name_high_50 = "High 50";
	string window_name_low_100 = "low 100";
	string window_name_low_50 = "low 50";

	image.convertTo(image100,-1,1,100);
	image.convertTo(image50,-1,1,50);
	image.convertTo(imagelow100,-1,1,-100);
	image.convertTo(imagelow50,-1,1,-50);

	namedWindow(window_name,WINDOW_NORMAL);
	
	namedWindow(window_name_high_100,WINDOW_NORMAL);
	namedWindow(window_name_high_50,WINDOW_NORMAL);
	namedWindow(window_name_low_100,WINDOW_NORMAL);
	namedWindow(window_name_low_50,WINDOW_NORMAL);

	imshow(window_name,image);
	imshow(window_name_high_100,image100);
	imshow(window_name_high_50,image50);
	imshow(window_name_low_100,imagelow100);
	imshow(window_name_low_50,imagelow50);

	waitKey(0);

	destroyWindow(window_name);
	destroyWindow(window_name_high_100);
	destroyWindow(window_name_high_50);
	destroyWindow(window_name_low_100);
	destroyWindow(window_name_low_50);
	return 0;
}