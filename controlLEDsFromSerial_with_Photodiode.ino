
char inputString[10]; //Command string from Serial monitor (make sure commands end in newline)
int stringIndex = 0; //What character we're on
boolean stringComplete = false; //Is the whole string entered?
//boolean LEDonFlag = false;

int LED1 = 5;
int LED2 = 6;
int LED3 = 9;
int LED4 = 10;

int LED1_set = 360;
int LED2_set = 370;
int LED3_set = 800;
int LED4_set = 400;

int LED1_lastPWM = 128;
int LED2_lastPWM = 128;
int LED3_lastPWM = 128;
int LED4_lastPWM = 128;

int target;
int LED_pin;
int currentPWM = 128;
bool warningFlag = false;

boolean LED_on[4] = {0,0,0,0};
const int sampsToAvg = 1500;

long int runSum=0;
int loopNum=0;
float AvgValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  serialCheck(); //Check for new serial input
  if (stringComplete) { //If the string is complete, do something about it
    parseInput();
  }
  
  if (loopNum == sampsToAvg){
    AvgValue = runSum/sampsToAvg;
    //Serial.println(AvgValue);
    loopNum = 0;
    runSum = 0;
  if (LED_pin != 0){
    if (AvgValue > target+2){
      currentPWM = currentPWM + 1;
    }
    if (AvgValue < target - 2) {
      currentPWM = currentPWM - 1;
    }
    if (currentPWM > 255){
      currentPWM = 255;
      warningFlag = true;
    }
    if (currentPWM < 0){
      currentPWM = 0;
      warningFlag = true;
    }  
    
      analogWrite(LED_pin,currentPWM);
    }
    if (LED_pin == LED1){
      LED1_lastPWM = currentPWM;
      target = LED1_set;
    }
    if (LED_pin == LED2){
      LED2_lastPWM = currentPWM;
      target = LED2_set;
    }
    if (LED_pin == LED3) {
      LED3_lastPWM = currentPWM;
      target = LED3_set;
    }
    if (LED_pin == LED4) {
      LED4_lastPWM = currentPWM;
      target = LED4_set;
    }
  }
   runSum = runSum + analogRead(0);
   loopNum = loopNum+1;
}

void serialCheck() {
  while (Serial.available()) {

    // get the new byte:
    char inChar = (char)Serial.read();

    // add it to the inputString:
    inputString[stringIndex] = inChar;
    //Serial.println(inputString);
    stringIndex++;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      //Serial.println(inputString[0]);
      inputString[stringIndex] = 0;
    }
  }
}
void parseInput() {
  ////////////////////////////////////////////////////////////////////////////////////
  //Commands:
  //(0) Turn all LEDs off
  //(1) Turn on LED 1 and turn all others off
  //(2) Same for LED 2
  //(3) Same for LED 3
  //(4) Same for LED 4
  //(s1) Set the photodiode voltage for LED1
  //(s2) Same for LED 2
  //(s3) Same for LED 3
  //(s4) Same for LED 4
  //(m) Return monitor photodiode voltage (0-868)
  ////////////////////////////////////////////////////////////////////////////
  if (inputString[0] == '0') { //If LabView wants all the LEDs to be off
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
   // LEDonFlag = false;
    target = 0;
    LED_pin = 0;
  }
  if (inputString[0] == '1') { //If LabView wants LED1 to be on, turn it on (and the others off)
    analogWrite(LED1, LED1_lastPWM);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    //LED_on = [1,0,0,0];
    target = LED1_set;
    LED_pin = LED1;
    currentPWM = LED1_lastPWM;
    loopNum = 0;
    runSum = 0;
    //LEDonFlag = true;
  }
  if (inputString[0] == '2') { //If LabView wants LED2 to be on, turn it on (and the others off)
    digitalWrite(LED1, HIGH);
    analogWrite(LED2, LED2_lastPWM);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    //LED_on = [0,1,0,0];
    target=LED2_set;
    LED_pin = LED2;
    currentPWM = LED2_lastPWM;
    loopNum = 0;
    runSum = 0;
  //  LEDonFlag = true;
  }
  if (inputString[0] == '3') { //If LabView wants LED3 to be on, turn it on (and the others off)
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    analogWrite(LED3, LED3_lastPWM);
    digitalWrite(LED4, HIGH);
    //LED_on = [0,0,1,0];
    target = LED3_set;
    LED_pin = LED3;
    currentPWM = LED3_lastPWM;
    loopNum = 0;
    runSum = 0;
   // LEDonFlag = true;
  }
  if (inputString[0] == '4') { //If LabView wants LED4 to be on, turn it on (and the others off)
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    analogWrite(LED4, LED4_lastPWM);
//    LED_on = [0,0,0,1];
    target = LED4_set;
    LED_pin = LED4;
    currentPWM = LED4_lastPWM;
    loopNum = 0;
    runSum = 0;
   // LEDonFlag = true;
  }
  if (inputString[0] == 's') {
    char arg[4];
    for (int i = 3; i<7; i++){
      if (isDigit(inputString[i])){
        arg[i-3] = inputString[i];
      }
      else{
        arg[i-3] = '\0';
      }
    }
    int numArg = atoi(arg);
    if (numArg > 1024) {
      numArg = 1024;
    }
    if (numArg < 0) {
      numArg = 0;
    }
    if (inputString[1] == '1') {
      LED1_set = numArg;
    }
    else{
      if (inputString[1] == '2') {
        LED2_set = numArg;
      }
      else {
          if (inputString[1] == '3') {
            LED3_set = numArg;
          }
          else {
              if (inputString[1] == '4'){
                LED4_set = numArg;  
              }
              else {
                
            }
          }
        }
      }
    }

    if (inputString[0] == 'm'){
      if (warningFlag == true) {
        Serial.println("LW"); //If the PWM was saturated issue (L)ED (W)arning
        warningFlag = false; //reset warning flag
      }
      else {
        float currVoltage = 0;
        long int thisSum = 0;
        for (int i = 0; i<500;i++){
          thisSum += analogRead(0);
        }
        currVoltage = thisSum/500;
        if (currVoltage < 860) {
          Serial.println(currVoltage);
        }
        else {
          Serial.println("PW"); //If the Photodiode is saturated issue (P)hotodiode (W)arning
        }
      }   
    }
  
  memset(inputString, 0, sizeof(inputString)); //reset input string
  stringComplete = false; //reset string complete flag
  stringIndex = 0;
}
