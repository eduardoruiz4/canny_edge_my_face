# canny_edge_my_face
Exercise 2- Canny Edge Detector - ROS Package

As observed, I have chosen C++ in order to code this exercise. It works with two nodes: The first one, custom_cv_camera, is a simple 
node created by myself which mainly captures the frames from a webcam, save them on a OpenCV Mat variable and transform them to a 
ROS sensors_msgs/Image message. The second node, canny_edge, is the main node where the image processing is done. The node subscribes 
the Image messages from the custom_cv_camera, transform them to a OpenCV variable and process them. The resulting images are transformed 
again to a ROS Image message in order to be published and used by other nodes or GUI visualization tools. The threshold which indicates
in the Canny algorithm if a pixel is rejected can be modified with a rqt_reconfigure GUI.

Some remarks about this project
1.- In order to transform from OpenCV to ROS image and the other way around, should be installed the vision_opencv libraries. In
    case they are not installed, you can download and unzip in your workspace/src and then compile, the following repository:
    https://github.com/ros-perception/vision_opencv.git
    
2.- From the previous remark, some of the vision_opencv libraries needed for the project only run with OpenCV 2.x.x. If you have
    a newer version (version 3.x) then you must uninstall it and install the old one, or you can have both and modify CMakeLists.txt
    in order to depend only on the OpenCV 2 libraries.
    
3.- Finally, I was not able to run/install rqt_image_viewer, however rviz is considered also as a rqt plugin according to the rqt 
    GUI, that's why I used rviz as the plattform to show the raw image and the filtered one. The launch file runs an edited 
    configuration in order to open the rviz with the desired elements.
   
4.- The Canny edge dectector algorithm is the one showed by the OpenCV documentation tutorials.
