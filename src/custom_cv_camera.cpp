//This node captures video streaming from the laptop camera using OpenCV Library, as the image could be used as a sensors_msgs/Image message on ROS
// the cv_bridge library was used to transform an OpenCV image to a ROS one, finally the ROS image is published (using image_transport library) so 
// it can be used by other nodes

#include "ros/ros.h"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>


using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	VideoCapture cap(0); //capture the video from webcam

	if ( !cap.isOpened() )  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	Mat img; //OpenCV image variable

	ros::init(argc, argv, "custom_cv_camera");
	ros::NodeHandle n;
	image_transport::ImageTransport it(n);
	image_transport::Publisher pub = it.advertise("camera/image", 1);//Image_transport publisher

	sensor_msgs::ImagePtr msg; //ROS Image Variable

	ros::Rate loop_rate(5);



	while (ros::ok())
	{
		cap >> img; //Copy the frame captured to the OpenCV image variable
		if(!img.empty()) 
		{
			msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", img).toImageMsg(); //Convert OpenCV to ROS image
			pub.publish(msg);//ROS Image Publication
			cv::waitKey(1);
		}
	}

	return 0;
}
