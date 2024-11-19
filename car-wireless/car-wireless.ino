#define BLYNK_TEMPLATE_ID "TMPL6TFggeSyC"
#define BLYNK_TEMPLATE_NAME "FIRST TEMPLATE"
#define BLYNK_AUTH_TOKEN "pJ3mTZOZmNNNZuS8WPCfQqc1mQkzylAz"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Thông tin mạng Wi-Fi
char ssid[] = "@@";
char pass[] = "12345888";
char auth[] = BLYNK_AUTH_TOKEN;

int EnA = 16;
int EnB = 14;
int ln1 = 5;
int ln2 = 4;
int ln3 = 12;
int ln4 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(ln1, OUTPUT);
  pinMode(ln2, OUTPUT);
  pinMode(ln3, OUTPUT);
  pinMode(ln4, OUTPUT);

  // connect to blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected to blynk");
  if(WiFi.status() == WL_CONNECTED) Serial.println("Connected to WiFi");
}

void forward();
void backward();
void turnLeft();
void turnRight();

void loop(){                                                                                                                                                  
  // put your main code here, to run repeatedly:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Mất kết nối WiFi, đang thử kết nối lại...");
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  }
  Blynk.run();
}

BLYNK_WRITE(V1){

  int buttonFw = param.asInt();

  Serial.print("button forward : ");
  Serial.println(buttonFw);
  if(buttonFw == 1){
    forward(140,150);
  }
  else{
    forward(0,0);
  }
  
}

BLYNK_WRITE(V2){

  int buttonBw = param.asInt();

  Serial.print("button backward : ");
  Serial.println(buttonBw);
  if(buttonBw == 1){
    backward(145,150);
  }
  else{
    forward(0,0);
  }
  
}

BLYNK_WRITE(V3){

  int buttonTF = param.asInt();

  Serial.print("button turn left : ");
  Serial.println(buttonTF);
  if(buttonTF == 1){
    turnLeft(100,130);
  }
  else{
    forward(0,0);
  }
  
}

BLYNK_WRITE(V4){

  int buttonTR = param.asInt();

  Serial.print("button turn right : ");
  Serial.println(buttonTR);
  if(buttonTR == 1){
    turnRight(130,100);
  }
  else{
    forward(0,0);
  }
  
}

void forward (int pwmEnA, int pwmEnB) {

  analogWrite(EnB, pwmEnB);
  analogWrite(EnA, pwmEnA);
  
  digitalWrite(ln3, LOW);
  digitalWrite(ln4, HIGH);

  digitalWrite(ln1, HIGH);
  digitalWrite(ln2, LOW);

 }

 void backward (int pwmEnA, int pwmEnB) {

  analogWrite(EnB, pwmEnB);
  analogWrite(EnA, pwmEnA);
  
  digitalWrite(ln3, HIGH);
  digitalWrite(ln4, LOW);

  digitalWrite(ln1, LOW);
  digitalWrite(ln2, HIGH);

 }

 void turnRight(int pwmEnA, int pwmEnB){
  analogWrite(EnB, pwmEnB);
  analogWrite(EnA, pwmEnA);
  
  digitalWrite(ln3, LOW);
  digitalWrite(ln4, HIGH);

  digitalWrite(ln1, LOW);
  digitalWrite(ln2, HIGH);

 }

 void turnLeft(int pwmEnA, int pwmEnB){
  analogWrite(EnB, pwmEnB);
  analogWrite(EnA, pwmEnA);
  
  digitalWrite(ln3, HIGH);
  digitalWrite(ln4, LOW);

  digitalWrite(ln1, HIGH);
  digitalWrite(ln2, LOW);
 }

 /*
quay 90
  turnRight(120,100);
  delay(500);
  turnRight(0,0);
  delay(300);
  turnLeft(100,120);
  delay(470);
  turnLeft(0,0);
  delay(300);
 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               