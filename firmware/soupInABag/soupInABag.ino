#include <Servo.h>
#include <vector>

int VSENS = D0;


// int currentNUMBER = 0;
// int startNum = 0;
bool isJumping = false;
// long startTime = millis(); // track time

std::vector<int> jumpList;

/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
#pragma region systemFuncs

void setup() {
  beginJumpStuffs();
  //beginCactusStuffs();
}

void loop()
{
  jumpCheckLoop();
  // cactusMoveLoop();
  // sensorIsOn();
}

#pragma endregion systemFuncs

#pragma region jumpCodings

void beginJumpStuffs() {
  pinMode(VSENS, INPUT_PULLUP);
  Serial.begin(9600);
}

int jumpMilSecs = 0;
int failedChecks = 0;
// - - - - - - -
void jumpCheckLoop(){
  long vsenstime;

  // vSensCheck();
  // JumpCheck();

  // Serial.println(digitalRead(VSENS));
  if(digitalRead(VSENS))
    jumpMilSecs++;
  else if(jumpMilSecs != 0)
  {
    if(jumpMilSecs >= 50000)
    {
      Serial.print(failedChecks);
      Serial.print("    ");
      Serial.println(jumpMilSecs);
      failedChecks = 0;
    }
    else
      failedChecks++;
    jumpList.push_back(jumpMilSecs);
    jumpMilSecs = 0;
  }
}
// - - - - - - - \*
// void JumpCheck() {
//   if (jumpMilSecs > 100) {
//     if ((jumpList[1]) > 200) {
//       isJumping == true;

      // Serial.print(random(2, 500));
      // Serial.println("PLAYER IS JUMPINGG");
//     }
//   }
// }

#pragma endregion jumpCodings
/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
#pragma region cactusControls


Servo cactus;
int signalCord = D0;
int signalTime = 2;
int popOutTime = 1000;
int minDelay = 2000, maxDelay = 7001;


void beginCactusStuffs() {
  // pinMode(LED_BUILTIN, OUTPUT); //LED_BUITIN always hits the built in LED for some reason
  // Serial.begin(9600);
  randomSeed(analogRead(A0));
  pinMode(signalCord, INPUT);
  cactus.attach(D10);
}

void cactusMoveLoop() {
  // digitalWrite(LED_BUILTIN, HIGH);
  waitForRandomTime();
  popOut();
}

void SignalAttempt()
{
  pinMode(signalCord, OUTPUT); //This part is to send a signal to know that it wants to throw the cactus
  digitalWrite(signalCord, HIGH);
  delay(signalTime);
  digitalWrite(signalCord, LOW);
  pinMode(signalCord, INPUT);
}

void popOut()
{
  cactus.write(180); //This is to actually send out the cactus
  delay(popOutTime);
  cactus.write(0);
}

void waitForRandomTime()
{
  int rand = random(minDelay, maxDelay);
  // Serial.println(rand);
  delay(rand);
}


#pragma endregion cactusControls


// void sensorIsOn() {
//   if (digitalRead(VSENS) == HIGH) {
//     Serial.println("The sensor is on!");
//     delay(100);
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
                    // Serial.begin(9600);
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
                    // Serial.println(rotationZ);
                    // }
                    // }
                    // }
                    // }
                    // }
                    // }