#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include <sstream>
#include <stdio.h>
#include <iostream>

int main(int argc, char **argv){

	ros::init(argc, argv, "pipe_level1");
	ros::NodeHandle n;
	ros::Publisher source = n.advertise<std_msgs::UInt8>("pipe_l1_output", 5);
	ros::Rate loop_rate(1);
	
        unsigned char count=0;
	while(ros::ok()){
		count++;
		std::cout<<"new loop "<<(unsigned int)(count)<<"\n";
	        std_msgs::UInt8 msg;
		msg.data = count;
		source.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}
