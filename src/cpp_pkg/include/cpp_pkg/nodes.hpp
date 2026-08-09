#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Talker : public rclcpp::Node {
  public:
    Talker();

  private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

class Listener : public rclcpp::Node {
  public:
    Listener();

  private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
