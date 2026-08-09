from rclpy.node import Node
from std_msgs.msg import String


class Listener(Node):
    def __init__(self):
        super().__init__("listener")
        self.subscription = self.create_subscription(
            String, "python_chatter", self.listen, 10
        )

    def listen(self, message):
        self.get_logger().info(message.data)
