#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include <sstream>
#include <stdio.h>
#include <iostream>

void drain_callback(std_msgs::UInt8 msg){
  std::cout<<"received "<<(unsigned int)(msg.data)<<std::endl;

  return;
};

int main(int argc, char **argv){
	ros::init(argc, argv, "pipe_level3");
	ros::NodeHandle n;
	ros::Subscriber drain = n.subscribe("pipe_l2_output", 5, drain_callback);

	
	ros::spin();

	return 0;
}
