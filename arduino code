#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7);//tx, rx
String textMessage;

//Global Variables
const byte BUTTON=2; // our button pin

unsigned long buttonPushedMillis; 
unsigned long TurnedOnAt; 
unsigned long turnOnDelay = 500; 
unsigned long turnOffDelay = 2000; 
bool ledReady = false; 
bool ledState = false; 
unsigned long timejstaftrot=0;
#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11
int step_number = 0;

void SendMessage();
void ReciveMessage();


void setup() {
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(BUTTON, INPUT_PULLUP);

mySerial.begin(9600); // Setting the baud rate of GSM Module
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)

Serial.println();
delay(100);

}

void loop() {
// get the time at the start of this loop()
unsigned long currentMillis = millis();

// check the button
if (digitalRead(BUTTON) == LOW) {
// update the time when button was pushed
buttonPushedMillis = currentMillis;
ledReady = true;
}

// make sure this code isn't checked until after button has been let go
if (ledReady) {
//this is typical millis code here:
if ((unsigned long)(currentMillis - buttonPushedMillis) >= turnOnDelay) {
// okay, enough time has passed since the button was let go.
stepr();
// setup our next "state"
ledState = true;
// save when the LED turned on
TurnedOnAt = currentMillis;
// wait for next button press
ledReady = false;
}
}

// see if we are watching for the time to turn off 
if (ledState) {
// okay, led on, check for now long
if ((unsigned long)(currentMillis - TurnedOnAt) >= turnOffDelay) {
ledState = false;
steproff();
}
}
  if((unsigned long)(currentMillis -timejstaftrot ) >= 10000){
   steproff();
   SendMessage();
 
}

if(mySerial.available()>0){
    textMessage = mySerial.readString(); 
    textMessage.toUpperCase();   
    delay(10);
  } 
  if(textMessage.indexOf("OK")>=0){
    
    stepr();
    textMessage = "on";
    
  }
}

void stepr(){
for(int i=0;i<5000;i++){
   OneStep(false);
  delay(3);
}}
void steproff(){
 digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);

}
void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);


} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}

void SendMessage()
{
steproff();
Serial.println("Sending Message Detected");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+94711759035\"\r"); 
delay(1000);
mySerial.println("Feed Your PET");// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}

