<img src="imgs/ros_logo.svg" alt="ROS 2" height="48">
<img src="imgs/zed-logo-wordmark-pure-white-fff.svg" alt="Zed" height="48">

## Develop your ROS2 packages in Zed

This repository shows how to configure the [Zed](https://zed.dev/) code editor for [ROS2](https://www.ros.org/) development, enabling IntelliSense features that make development easier. This has been **tested to work on Ubuntu 22.04 with ROS2 Humble and Zed 1.14.2**.

Two very basic packages, `cpp_pkg` and `python_pkg`, have been used as examples, each with a `std_msgs/String` talker-listener. The goal here is not to serve as a guide on how to set up ROS2 packages or to teach any ROS2 functionality, but more to demonstrate how to configure Zed for developing ROS2 packages.

**Note**: ROS2 distro should already be sourced in `~/.bashrc`. Launch Zed from a shell because GUI-launched Zed does not inherit environment modifications made by `~/.bashrc`.

## How to use this repository


Building the workspace is necessary to generate `build/compile_commands.json` which is required for IntelliSense. Clone this repository and build the workspace with:
```bash
colcon build --symlink-install --continue-on-error --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

There are no dependencies beyond what comes with the standard ROS2 installation, so if ROS2 has been installed correctly it will be surprising if the build fails.

### Running the nodes
Unimportant, but if you wanted to run the nodes, source the workspace, and then do:
- C++: `ros2 run cpp_pkg main`
- Python: `ros2 run python_pkg main`

Again, this is not a ROS2 tutorial, so the nodes running successfully doesn't mean a whole lot here.

### Confirming IntelliSense and autocomplete
In `cpp_pkg`, go into a `.hpp` or `.cpp` file and then start typing out some `rclcpp` keyword and you should see autocomplete suggestions. Likewise, in `python_pkg`, go into a `.py` file and then start typing out any `rclpy` keyword and autocomplete suggestions should come up.

### What files to lift into your own project
Right, you're not here to work on *this* repository but rather to see what can you take from here for your own project. Here goes:
1. `.zed/settings.json`: Place this in your project root. Chances are you already have this file set up with your preferences, but feel free to take what's missing or different. Play around with language servers of your choice and settings like `"tab_size"` and `"format_on_save"`.
2. `.clang-format` and `.clangd`: These are clang specific so are useful only if you choose to stay with clang.

## References
Zed docs: [C++](https://zed.dev/docs/languages/cpp), [Python](https://zed.dev/docs/languages/python)
