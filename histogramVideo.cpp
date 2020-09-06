#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	VideoCapture cap("showvid.mp4");

	if (cap.isOpened() == false) {
		cout << "Sorry could not find or open the video file may be your are at the end of the video file"<<endl;
		cin.get(); // Wait for keypressing 
		return -1;
	}

	string windowOriginal = "Orignial window";
	string windowHist = "Histogram window";

	namedWindow(windowOriginal,WINDOW_NORMAL);
	namedWindow(windowHist,WINDOW_NORMAL);

	while(true) {
		Mat frame;
		float frameRate = cap.get(CAP_PROP_FPS);
		bool bSuccess = cap.read(frame) ; // Reading every frame

		cout <<"Fps is : "<< frameRate<<endl;

		if (bSuccess == false) {
			cout << "Found the end of the video"<<endl;
			break;
		}
		Mat hist_eq;
		cvtColor(frame,hist_eq,COLOR_BGR2YCrCb);

		vector<Mat> vec_cannel;

		split(hist_eq,vec_cannel);

		equalizeHist(vec_cannel[0],vec_cannel[0]);

		merge(vec_cannel,hist_eq);

		cvtColor(hist_eq,hist_eq,COLOR_YCrCb2BGR);

		imshow(windowOriginal,frame);
		imshow(windowHist,hist_eq);

		if (waitKey(5) == 27) {
			cout << "Esc key is pressed exiting the programm"<<endl;
			break;
		}

	}

	 destroyAllWindows();
	return 0;
}