import rclpy
from rclpy.executors import SingleThreadedExecutor

from python_pkg.listener import Listener
from python_pkg.talker import Talker


def main(args=None):
    rclpy.init(args=args)

    talker = Talker()
    listener = Listener()
    executor = SingleThreadedExecutor()
    executor.add_node(talker)
    executor.add_node(listener)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        talker.destroy_node()
        listener.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
