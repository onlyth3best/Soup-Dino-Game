#include <Servo.h>


int VSENS = D1;


// int currentNUMBER = 0;
// int startNum = 0;
// bool isJumping = false;
// long startTime = millis(); // track time
int jumpSensitivity = 1000;
int failedCheckThreshold = 125;


int lastTimeChecked;
int timeElapsed;

bool jumpedWithCactusOut = false;
bool gameOver = false;

/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
#pragma region systemFuncs

void setup() {
  beginJumpStuffs();
  beginCactusStuffs();
}

void loop()
{
  ElapseTime();
  jumpCheckLoop();

  if(!gameOver)
    cactusMoveLoop();
  // sensorIsOn();
}

void ElapseTime()
{
  timeElapsed = millis() - lastTimeChecked;
  lastTimeChecked = millis();
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
  JumpCheck();
  // Serial.println(digitalRead(VSENS));

  // Serial.println(digitalRead(VSENS));
  if(digitalRead(VSENS))
    jumpMilSecs++;
  else if(jumpMilSecs != 0)
  {
    if(jumpMilSecs >= jumpSensitivity)
    {
      // Serial.print(failedChecks);
      // Serial.print("    ");
      // Serial.println(jumpMilSecs);
      // Serial.print("    ");
      failedChecks = 0;
    }
    else
      failedChecks++;
    jumpMilSecs = 0;
  }
}
// - - - - - - - \*
void JumpCheck() {
  if (jumpMilSecs > jumpSensitivity) {
    if (failedChecks <= failedCheckThreshold) {
      // isJumping == true;
      jumpedWithCactusOut = true;

      // Serial.print(random(2, 500));
      if(gameOver)
        Serial.println("PLAYER IS JUMPINGG");
      // Serial.println(jumpMilSecs);

      if(gameOver)
        gameOver = false;
    }
  }
}

#pragma endregion jumpCodings
/* - - - - - - - - - - - - - - - - - // - - - - - - - - - - - - - - - - - */
#pragma region cactusControls


Servo cactus;
// int signalCord = D0;
int signalTime = 2;
int popOutTime = 1000;
int minDelay = 2000, maxDelay = 7001;

String stage = "";
int decidedDelayTime;


void beginCactusStuffs() {
  // pinMode(LED_BUILTIN, OUTPUT); //LED_BUITIN always hits the built in LED for some reason
  // Serial.begin(9600);
  randomSeed(analogRead(A0));
  // pinMode(signalCord, INPUT);
  cactus.attach(D10);

  stage = "cooldown";
  decidedDelayTime = chooseRandTimeToWait();
}

void cactusMoveLoop() {
  // digitalWrite(LED_BUILTIN, HIGH);
  // waitForRandomTime();
  // popOut();

  if(delayCactusStepForSecs("cooldown", decidedDelayTime, "popOut")) //waits for cooldown (on popOut)
  {
    jumpedWithCactusOut = false;
    
    cactus.write(0);
    Serial.println("Moved to popOut");
  }
  else if(delayCactusStepForSecs("popOut", popOutTime, "cooldown")) //waits for popOutTime (onCooldown)
  {
    Serial.println("Moved to cooldown");
    if(jumpedWithCactusOut)
    {
      cactus.write(120);
    }
    else
    {
      gameOver = true;
      delay(5000);
    }

    decidedDelayTime = chooseRandTimeToWait();
  }
}

void SignalAttempt()
{
  // pinMode(signalCord, OUTPUT); //This part is to send a signal to know that it wants to throw the cactus
  // digitalWrite(signalCord, HIGH);
  delay(signalTime);
  // digitalWrite(signalCord, LOW);
  // pinMode(signalCord, INPUT);
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

int chooseRandTimeToWait()
{
  int rand = random(minDelay, maxDelay);
  return rand;
}

int timeSinceLastPassedStep = 0;
bool delayCactusStepForSecs(String step, int timeToStall, String nextStep)
{
  if(step == stage)
  {
    // Serial.println(step);
    timeSinceLastPassedStep += timeElapsed;
    
    if(timeSinceLastPassedStep >= timeToStall)
    {
      timeSinceLastPassedStep -= timeToStall;
      stage = nextStep;
      return true;
    }
  }
  
  return false;
}

#pragma endregion cactusControls