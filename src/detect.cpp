/*
 * detect.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: kevin
 */

#include <iostream>
#include <vector>

#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"

int main(int, char**){
	cv::VideoCapture cap("../../test4/MVI_9592.MOV");
	if(!cap.isOpened()){
		std::cout << "Couldn't open video" << std::endl;
	}

	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
	cv::Ptr<cv::aruco::DetectorParameters> detectorParams = cv::aruco::DetectorParameters::create();
	for(;;){
		cv::Mat frame;
		cap >> frame;
		std::vector<int> ids;
		std::vector<std::vector<cv::Point2f>> corners, rejected;
		cv::aruco::detectMarkers(frame, dictionary, corners, ids, detectorParams, rejected);
		cv::aruco::drawDetectedMarkers(frame, corners, ids);
		imshow("out", frame);
		if(cv::waitKey(30) >= 0) break;
	}
}

