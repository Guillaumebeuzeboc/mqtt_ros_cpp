#include <mqtt_ros_cpp/publisher.hpp>


mqttPublisher::mqttPublisher(const char * id,const char * topic, const char * host, int port):
  myMqtt(id, topic, host, port){

}

bool mqttPublisher::send_message(const  char * message)
{
  // Should return MOSQ_ERR_SUCCESS
  int ret = publish(NULL, topic_, strlen(message), message, 1, false);
  return ( ret == MOSQ_ERR_SUCCESS );
}

void mqttPublisher::on_publish(int mid)
{
  ROS_INFO_STREAM("mqttPublisher - Message (" << mid << ") succeed to be published");
}
