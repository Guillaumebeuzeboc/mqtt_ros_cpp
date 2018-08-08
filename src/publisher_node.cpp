#include <mqtt_test/publisher.hpp>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "mqtt_publisher");
  ros::NodeHandle nh;

  mqttPublisher myPublisher("mqtt_publisher", "hello",  "localhost", 1883);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {
    myPublisher.send_message(std::to_string(count).c_str());
    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }
  ROS_INFO("Exiting");
  return 0;
}
