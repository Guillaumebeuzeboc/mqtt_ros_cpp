#include <mqtt_test/subscriber.hpp>

mqttSubscriber::mqttSubscriber(const char *id, const char * topic, const char *host, int port, int max_payload):
  myMqtt(id, topic, host, port),
  max_payload_(max_payload)
{
}

void mqttSubscriber::update()
{
    this->subscribe(NULL, topic_);
}

void mqttSubscriber::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    ROS_INFO_STREAM_ONCE("mqttSubscribe - Message (" << mid << ") succeed to subscribe");
}

void mqttSubscriber::on_message(const struct mosquitto_message *message)
{
    int payload_size = max_payload_ + 1;
    char buf[payload_size];
    ROS_INFO_STREAM("a message is received");

    if(!strcmp(message->topic, topic_))
    {
        memset(buf, 0, payload_size * sizeof(char));

        /* Copy N-1 bytes to ensure always 0 terminated. */
        memcpy(buf, message->payload, max_payload_ * sizeof(char));
        ROS_INFO_STREAM("message received: "<< buf);
    }
}
