#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <RF24.h>

RF24 radio(46,47); // CE, CSN
const byte address[6] = "00001";

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // Create an instance of the PWM driver
int pitchServoPos, yawServoPos;

void setup() {
  Serial.begin(19200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
  if (radio.available()) {
    float receivedData[2]; // Create an array to hold received data
    radio.read(&receivedData, sizeof(receivedData));

    float pitch = receivedData[0];
    float yaw = receivedData[1];

   // Map pitch and yaw angles to servo positions
    pitchServoPos = map(pitch, -90, 90, -90, 90); // Adjust min and max values as needed for your servos
    yawServoPos = map(yaw, -90, 90, -90, 90);

    // Write servo positions
    pwm.setPWM(0, 0, pitchServoPos); // Assuming servo for pitch is connected to channel 0
    pwm.setPWM(1, 0, yawServoPos);   // Assuming servo for yaw is connected to channel 1

    Serial.print("Pitch: ");
    Serial.print(pitch); Serial.print(" degrees, ");
    Serial.print("Yaw: ");
    Serial.print(yaw); Serial.println(" degrees");
  }
}
