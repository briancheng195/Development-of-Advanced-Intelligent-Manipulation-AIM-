# Development-of-Advanced-Intelligent-Manipulation-AIM-
Developed and programmed a tele-operated robotic head system with headset device for head tracking and vision 

There are two components in this project: the head tracking device and the robotic head system. The objective of this project was for the user to control the robotic head with a headset which contains the head tracking device. For example, when the user tilts his/her head upwards or sideways, the robotic head will move accordingly. Additionally, the robotic head system provides the vision of the tele-operated robot and allows the user to be in the robot's persepective.

# Head Tracking Device 
- Contains the GY-85 9DOF IMU (in-built acccelerometer, gyrometer and magnetometer)
- Using the accelerometer, able to determine the pitch angle based on calculating the angle from the change in acceleration in the x and z-directions as the IMU   sensor is tilted upwards/downwards (pitch movement)
- Using the magnetometer, able to determine the yaw angle based on calculating the angle from the change in magnetic field strength in the x and y-directions as   the IMU sensor is rotated clockwise/anticlockwise (yaw movement)
- Data (pitch and yaw values) are transmitted through radio (using the nRF2401L module) to the robotic head system
- A 3-D printed headset is created to store the head tracking device and for the user to wear the headset to control the robot's head movements

# Robotic Head System 
- It acts as the receiver as the microcontroller receives the pitch and yaw data from the head tracking device (using the nRF2401L module)
- The microcontroller processes the pitch and yaw data and maps them to degree values, in order to control two 180 degree posiitonal servo motors (one for each    movement) respectively
- The servo motors are set up in a pan-tilt mount system to mimic the head movements of the user

# Vision of the Robotic Head System
- A Intel RealSense Depth Camera (D415) provides the vision for the robotic head. A 3-D printed casing is created to attach the depth camera on the pan-tilt     
  mount system
- To remotely stream the depth camera footage, the camera is connected to a single board computer (Raspberry Pi 4) with the camera packages and a VNC client       installed
- Any electronic devices (such as a smartphone) with the VNC viewer can access the depth camera footage remotely and the electronic device can be slotted inside   the headset

# Considerations 
- Did not utilise the gyroscope within the IMU sensor as it resulted in a sudden fluctuation of pitch and yaw values due to drifting issues
- Considered that utilising the acclerometer and magnetometer to calculate the pitch and yaw values resulted the IMU sensor to be extremely sensitive to     
  rotational movements
- Future development works would be to utilise all 3 sensors (accelerometer, gyroscope and magnetometer) to create a complementary filter which may help in
  reducing sensor sensitivity for the calculation of pitch and yaw values
