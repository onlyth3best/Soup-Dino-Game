#include <vector>

int VSENS = D0;


// int currentNUMBER = 0;
// int startNum = 0;
bool isJumping = false;
// long startTime = millis(); // track time

std::vector<int> jumpList; 

/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */

void setup() {
  pinMode(VSENS, INPUT_PULLUP);
  Serial.begin(9600);

}
/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
int jumpMilSecs = 0;
// - - - - - - -
void loop(){
  long vsenstime;

  // vSensCheck();
  // JumpCheck();

  // Serial.println(digitalRead(VSENS));
  if(digitalRead(VSENS))
    jumpMilSecs++;
  else if(jumpMilSecs != 0)
  {
    Serial.println(jumpMilSecs);
    jumpList.push_back(jumpMilSecs);
    jumpMilSecs = 0;
  }
}
/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
// void JumpCheck() {
//   if (jumpMilSecs > 200) {
//     if (((jumpList[jumpMilSecs + 1]) && (jumpList[jumpMilSecs + 2]) && (jumpList[jumpMilSecs + 3]) && (jumpList[jumpMilSecs + 4])) > 200) {
//       isJumping == true;
//       Serial.println("PLAYER IS JUMPINGG");
//     }
//   }
// }
/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
  //

















                    // #include <Wire.h>
                    // #include <Adafruit_GFX.h>
                    // // #include <Adafruit_SSD1306.h>

                    // #define MPU_ADDR 0x68

                    // float rotationZ = 0;
                    // unsigned long lastTime = 0;


                    // void setup() {
                    //   Serial.begin(9600);
                    //   Wire.begin();

                    //   // display.clearDisplay();
                    //   // display.setTextSize(1);
                    //   // display.setTextColor(SSD1306_WHITE);
                    //   delay(100);

                    //   initMPU();
                    // }

                    // void loop() {
                    //   readGyro();

                    //   displayRot();

                    //   delay(200);
                    // }

                    // void initMPU() {
                    //   // Wake up MPU
                    //   Wire.beginTransmission(MPU_ADDR);
                    //   Wire.write(0x6B);
                    //   Wire.write(0x00);
                    //   Wire.endTransmission();

                    //   // Set gyro range to ±250°/s
                    //   Wire.beginTransmission(MPU_ADDR);
                    //   Wire.write(0x1B);
                    //   Wire.write(0x00);
                    //   Wire.endTransmission();
                    // }

                    // void readGyro() {
                    //   int16_t gyroX, gyroY, gyroZ;
                    //   Wire.beginTransmission(MPU_ADDR);
                    //   Wire.write(0x43);  //GYRO_XOUT_H
                    //   Wire.endTransmission(false);

                    //   //request 6 bytes (1 per register)
                    //   Wire.requestFrom(MPU_ADDR, 6);

                    //   gyroX = (Wire.read() << 8) | Wire.read();
                    //   gyroY = (Wire.read() << 8) | Wire.read();
                    //   gyroZ = (Wire.read() << 8) | Wire.read();

                    //   //converting to degrees/second
                    //   float gyroRate = gyroZ / 131.0;

                    //   //calculating time elapsed
                    //   unsigned long now = millis();
                    //   float dt = (now - lastTime) / 1000.0;

                    //   //math to get total rotation
                    //   rotationZ += gyroRate * dt;
                    //   lastTime = now;
                    // }

                    // void displayRot() {
                    //   // display.clearDisplay();
                    //   // display.setCursor(0, 0);
                    //   // display.print("Current Rotation:");
                    //   // display.setCursor(0, 16);
                    //   // display.print(rotationZ);
                    //   Serial.println(rotationZ);
                    // }
                    // }
                    // }
                    // }
                    // }
                    // }