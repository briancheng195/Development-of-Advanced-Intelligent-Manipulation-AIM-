# Development-of-Advanced-Intelligent-Manipulation-AIM-
Developed and programmed a tele-operated robotic head system with headset device for head tracking and vision 

There are two components in this project: the head tracking device and the robotic head system. The objective of this project was for the user to control the robotic head with a headset which contains the head tracking device. For example, when the user tilts his/her head upwards or sideways, the robotic head will move accordingly. Additionally, the robotic head system provides the vision of the tele-operated robot and allows the user to be in the robot's persepective.

# Head Tracking Device 
- Contains the GY-85 9DOF IMU (in-built acccelerometer, gyrometer and magnetometer)
- Using the accelerometer, able to determine the pitch angle based on calculating the angle from the change in acceleration in the x and z-directions as the IMU   sensor is tilted upwards/downwards (pitch movement)
- Using the magnetometer, able to determine the yaw angle based on calculating the angle from the change in magnetic field strength in the x and y-directions as   the IMU sensor is rotated clockwise/anticlockwise (yaw movement)
- Data (pitch and yaw values) are transmitted through radio (using the nRF2401L module) to the robotic head system
- A 3-D printed headset is created to store the head tracking device and for the user to wear the headset to control the robot's head movements

# Proof of Concept for Head Tracking Device
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/79ee00bb-3385-4e97-8222-6f4aef45af4b">

# Electronics Design for Head Tracking Device (Transmitter)
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/e4d2b2c6-9d0b-4163-8f4a-d6dd45b940ae">

# Mechanical Design for Headset
- The head tracking device is then stored in a headset so that the user could wear the headset to control the robotic head with his/her head.
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/ab180147-7e26-447e-a447-f444e93ba8c4">
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/77878777-7e89-498f-8ee5-885e92a7bf23">

# Robotic Head System 
- It acts as the receiver as the microcontroller receives the pitch and yaw data from the head tracking device (using the nRF2401L module)
- The microcontroller processes the pitch and yaw data and maps them to degree values, in order to control two 180 degree posiitonal servo motors (one for each movement)
  respectively
- The servo motors are set up in a pan-tilt mount system to mimic the head movements of the user

# Proof of Concept for Robotic Head System
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/c5d5ab02-8ad9-4a19-a431-52c146fa03a2">

# Electronics Design for Robotic Head System (Receiver)
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/41297ba6-87d1-4fb7-b4c5-20d8700b760e">

# Mechanical Design for Robotic Head System
<img width="400" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/f8b35be6-bcfe-483c-a307-06b34159eedf">
<img width="400" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/db29efdf-7645-48b5-92c9-1e1334fdc43a">

# Vision of the Robotic Head System
- A Intel RealSense Depth Camera (D415) provides the vision for the robotic head. A 3-D printed casing is created to attach the depth camera on the pan-tilt mount system
- To remotely stream the depth camera footage, the camera is connected to a single board computer (Raspberry Pi 4) with the camera packages and a VNC client installed
- Any electronic devices (such as a smartphone) with the VNC viewer can access the depth camera footage remotely and the electronic device can be slotted inside the headset
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/b1e3289c-e6d1-4acb-b121-355098604bd3">
<img width="500" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/7a69ff8d-8bea-44d5-801c-bb3e686f7e5f">

# Video Demonstration
HTTPS://WWW.YOUTUBE.COM/SHORTS/YSLO3FRVPRW

<img width="400" alt="image" src="https://github.com/briancheng195/Development-of-Advanced-Intelligent-Manipulation-AIM-/assets/122734373/0e374af2-5742-4ff1-a699-8b1588e1552c">

# Considerations 
- Did not utilise the gyroscope within the IMU sensor as it resulted in a sudden fluctuation of pitch and yaw values due to drifting issues (when using MPU6050)
- Considered that utilising the acclerometer and magnetometer to calculate the pitch and yaw values resulted the IMU sensor to be extremely sensitive to rotational movements
- Future development works would be to utilise all 3 sensors (accelerometer, gyroscope and magnetometer) to create a complementary filter which may help in
  reducing sensor sensitivity for the calculation of pitch and yaw values

# Future Developments
- For this project, the robotic head movement is only restricted to 2 DOF (pitch and yaw) which does not completely mimic the head movement of a human, where it can pitch, yaw and
  roll (tilt sideways)
- To develop a 3 DOF system which acts as the neck for the robotic head, and its mechanical design should replicate the head movement of a humanoid

