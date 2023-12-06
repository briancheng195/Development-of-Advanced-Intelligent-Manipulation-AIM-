#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 mpu;
Servo servoPitch; // Define servo objects
Servo servoYaw;

float pitch = 0.0;
float yaw = 0.0;

float gyroScale = 131.0; // Gyroscope sensitivity (adjust for your specific sensor)
float alpha = 0.98;      // Complementary filter factor (adjust as needed)

void setup() {
  Wire.begin();
  Serial.begin(19200);

  mpu.initialize();
  servoPitch.attach(2); // Attach servos to pins 2 and 3
  servoYaw.attach(3);
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float pitchAcc = atan2(ay, az) * RAD_TO_DEG;
  float pitchGyro = gy / gyroScale * 0.01; // Adjust time step as needed
  float yawChange = gz / gyroScale * 0.01;

  pitch = 0.30 + alpha * (pitch + pitchGyro) + (1 - alpha) * pitchAcc;
  yaw += yawChange;

  // Map pitch and yaw angles to servo positions
  int pitchServoPos = map(pitch, -90, 90, 0, 180); // Adjust min and max values as needed
  int yawServoPos = map(yaw, -90, 90, 0, 180);

  // Write servo positions
  servoPitch.write(pitchServoPos);
  servoYaw.write(yawServoPos);

  Serial.print("Pitch: ");
  Serial.print(pitch); Serial.print(" degrees, ");
  Serial.print("Yaw: ");
  Serial.print(yaw); Serial.println(" degrees");

  delay(10); // Adjust delay as needed
}
