#include "cpp_pkg/nodes.hpp"

Listener::Listener() : Node("listener") {
    subscription_ = create_subscription<std_msgs::msg::String>(
        "cpp_chatter", 10, [this](std_msgs::msg::String::SharedPtr message) {
            RCLCPP_INFO(get_logger(), "%s", message->data.c_str());
        });
}
