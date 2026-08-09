#include <memory>

#include "cpp_pkg/nodes.hpp"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    auto talker = std::make_shared<Talker>();
    auto listener = std::make_shared<Listener>();

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(talker);
    executor.add_node(listener);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
