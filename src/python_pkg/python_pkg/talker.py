from rclpy.node import Node
from std_msgs.msg import String


class Talker(Node):
    def __init__(self):
        super().__init__("talker")
        self.publisher = self.create_publisher(String, "python_chatter", 10)
        self.timer = self.create_timer(1.0, self.publish)

    def publish(self):
        message = String()
        message.data = "Help me Obi-Wan Kenobi, you're my only hope!"
        self.publisher.publish(message)
