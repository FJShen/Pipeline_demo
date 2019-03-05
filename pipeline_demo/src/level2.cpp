#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include <sstream>
#include <stdio.h>
#include <iostream>

class SubscribeAndPublish{
public:
    SubscribeAndPublish(){
      source = n.advertise<std_msgs::UInt8>("pipe_l2_output", 5);
      drain = n.subscribe("pipe_l1_output", 5, &SubscribeAndPublish::drain_callback, this);

    }

  void drain_callback(std_msgs::UInt8 msg){
    std_msgs::UInt8 new_msg;
    std::cout<<"recieved "<<(unsigned int)(msg.data)<<std::endl;
    new_msg.data = (msg.data)<<1;
    source.publish(new_msg);
    return;
  }

private:
  ros::NodeHandle n;
  ros::Subscriber drain;
  ros::Publisher source;
};


int main(int argc, char **argv){
  std::cout<<"im born\n";
	ros::init(argc, argv, "pipe_level2");

	SubscribeAndPublish obj;

	ros::spin();
	
	return 0;
}
