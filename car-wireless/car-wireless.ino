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

int buttonFw = 0;
int buttonBw = 0;
int buttonTL = 0;
int buttonTR = 0;

int status = buttonFw + buttonBw + buttonTL + buttonTR;

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
void stop();

void loop(){                                                                                                                                                  
  // put your main code here, to run repeatedly:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Mất kết nối WiFi, đang thử kết nối lại...");
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  }

  Blynk.run();
}

BLYNK_WRITE(V0){
  int power = param.asInt();
  if(power == 1){
    forward(240,255);
    delay(3000);
  }
  stop();
}

BLYNK_WRITE(V1){

  buttonFw = param.asInt();
  status = buttonFw + buttonBw + buttonTL + buttonTR;
  Serial.print("Status: ");
  Serial.println(status);
  if(status > 1){
    if(buttonTR==1 && buttonFw == 1){
      forward(80,240);
      Serial.println("forward - right");
    }
    else if(buttonTL==1 && buttonFw == 1){
      forward(240,80);
      Serial.println("forward - left");    
    }
  }
  if(status == 1){
    if(buttonFw == 1 && ((buttonTR ==0 && buttonTL == 0))){
      forward(140,150);
      Serial.print("forward : ");
      Serial.println(buttonFw);
    }
  }
  if(status == 0) stop();

  
}

BLYNK_WRITE(V2){

  buttonBw = param.asInt();
  status = buttonFw + buttonBw + buttonTL + buttonTR;
  Serial.print("Status: ");
  Serial.println(status);
  if(status > 1){
    if(buttonTR==1 && buttonBw == 1){
      backward(80,240);
      Serial.println("backward - right");
    }
    else if(buttonTL==1 && buttonBw == 1){
      backward(240,80);
      Serial.println("backrward - left");    
    }
  }
  if(status == 1){
    if(buttonBw == 1 && (buttonTR ==0 && buttonTL == 0)){
        backward(145,150);
        Serial.print("backward : ");
        Serial.println(buttonBw);
    }
  }  
  if(status == 0) stop();

  
}

BLYNK_WRITE(V3){

  buttonTL = param.asInt();
  status = buttonFw + buttonBw + buttonTL + buttonTR;
  Serial.print("Status: ");
  Serial.println(status);

  if(status >1){
    if(buttonTL==1 && buttonFw == 1){
      forward(240,80);
      Serial.println("forward - left");
    }
    else if(buttonTL==1 && buttonBw == 1){
      backward(240,80);
      Serial.println("backward - left");
    }
  }
  if(status == 1){
    if(buttonTL == 1 && (buttonBw == 0 && buttonFw ==0)){
      turnLeft(100,130);
      Serial.println("turn left ");
      Serial.println(buttonTL);
    }
  }
  if(status == 0) stop();
}

  


BLYNK_WRITE(V4){

  buttonTR = param.asInt();
  status = buttonFw + buttonBw + buttonTL + buttonTR;
  Serial.print("Status: ");
  Serial.println(status);

  if(status >1){
    if(buttonTR==1 && buttonFw == 1){
      forward(80,240);
      Serial.println("forward - right");
    }
    else  if(buttonTR==1 && buttonBw == 1){
      backward(80,240);
      Serial.println("backward - right");
    }
  }
  if(status ==1){
    if(buttonTR == 1 && (buttonBw == 0 && buttonFw ==0)){
      turnRight(130,100);
      Serial.println("turn right ");
      Serial.println(buttonTR);
    }
  }
  if(status == 0) stop();

  
}

void stop(){
  Serial.println("Stop");
  forward(0,0);
}

// (banh phai, banh trai)

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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               