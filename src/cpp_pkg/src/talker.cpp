#include <chrono>

#include "cpp_pkg/nodes.hpp"

Talker::Talker() : Node("talker") {
    publisher_ = create_publisher<std_msgs::msg::String>("cpp_chatter", 10);
    timer_ = create_wall_timer(std::chrono::seconds(1), [this] {
        std_msgs::msg::String message;
        message.data = "Help me Obi-Wan Kenobi, you're my only hope!";
        publisher_->publish(message);
    });
}
