#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  // Initialize the MPU6050
  Wire.begin();
  mpu.initialize();

  // Check if the MPU6050 is connected
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed. Please check your connections.");
    while (1);
  }
}

void loop() {
  // Read accelerometer and gyroscope data
  mpu.getMotion6();

  // Print the raw data
  Serial.print("AcX = "); Serial.print(mpu.getAccelerationX());
  Serial.print(" | AcY = "); Serial.print(mpu.getAccelerationY());
  Serial.print(" | AcZ = "); Serial.print(mpu.getAccelerationZ());
  Serial.print(" | Tmp = "); Serial.print(mpu.getTemperature() / 340.00 + 36.53); // Temperature in degrees Celsius
  Serial.print(" | GyX = "); Serial.print(mpu.getRotationX());
  Serial.print(" | GyY = "); Serial.print(mpu.getRotationY());
  Serial.print(" | GyZ = "); Serial.println(mpu.getRotationZ());

  delay(1000); // Adjust the delay as needed
}
