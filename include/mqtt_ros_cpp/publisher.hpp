#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <mqtt_ros_cpp/myMqtt.hpp>

class mqttPublisher : public myMqtt
{
public:
  mqttPublisher(const char *id, const char * topic, const char *host, int port);
  bool send_message(const char * message);
  void on_publish(int mid);
};

#endif //PUBLISHER_HPP
