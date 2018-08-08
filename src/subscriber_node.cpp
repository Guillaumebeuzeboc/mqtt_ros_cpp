#include <mqtt_ros_cpp/subscriber.hpp>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "mqtt_subscriber");
  ros::NodeHandle nh;
  mqttSubscriber mySubscriber("mqtt_subscriber", "hello",  "localhost", 1883, 50);

  ros::Rate loop_rate(100);

  while(ros::ok())
  {

    ros::spinOnce();
    loop_rate.sleep();
  }
  mosqpp::lib_cleanup();

  ROS_INFO("Exiting");

  return 0;
}

