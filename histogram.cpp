// Resource : https://www.opencv-srf.com/2018/02/histogram-equalization.html

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat image = imread("show.jpeg");

	if (image.empty()) {
		cout << "Could not open the image or find the image"<<endl;
		cin.get(); // wait for any key press
		return -1;
	}

	// Change the color image to grayscale image
	cvtColor(image,image,COLOR_BGR2GRAY);

	// equalizse the histogram
	Mat hist_equalized_image;
	equalizeHist(image,hist_equalized_image);

	// Defines names of windows
	string original = "Original Image";
	string imageHistEqualized = "Equalized histogram version";

	// Create windows with the above name

	namedWindow(original,WINDOW_NORMAL);
	namedWindow(imageHistEqualized,WINDOW_NORMAL);

	// Show images inside created windows
	imshow(original,image);
	imshow(imageHistEqualized,hist_equalized_image);
	waitKey(0); // wait for any key press
	destroyAllWindows(); // Destroy all windows
	return 0;
}