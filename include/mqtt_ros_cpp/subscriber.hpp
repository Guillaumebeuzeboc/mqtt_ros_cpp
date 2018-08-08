#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <mqtt_ros_cpp/myMqtt.hpp>

class mqttSubscriber : public myMqtt
{
public:
  mqttSubscriber(const char *id, const char * topic, const char *host, int port, int max_payload);

  void startSubscribe();

  void on_connect(int rc);
  void on_message(const struct mosquitto_message *message);
  void on_subscribe(int mid, int qos_count, const int *granted_qos);

private:

  int max_payload_;
};

#endif //SUBSCRIBER_HPP
