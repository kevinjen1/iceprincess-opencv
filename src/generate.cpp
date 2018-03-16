#include<iostream>
#include<string>
#include<opencv2/aruco.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv){
	cv::Mat markerImage;
	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
	std::string file_prefix = "../resources/marker";
	std::string file_postfix = ".jpg";
	for (int i = 0; i < 10; i++){
		cv::aruco::drawMarker(dictionary, i, 250, markerImage, 1);
		std::string file_name = file_prefix + std::to_string(i) + file_postfix;
		cv::imwrite(file_name, markerImage);
	}
}
