
#define BLYNK_TEMPLATE_ID "TMPL6TFggeSyC"
#define BLYNK_TEMPLATE_NAME "FIRST TEMPLATE"
#define BLYNK_AUTH_TOKEN "pJ3mTZOZmNNNZuS8WPCfQqc1mQkzylAz"

int EnA = 16;
int EnB = 14;
int ln1 = 5;
int ln2 = 4;
int ln3 = 12;
int ln4 = 13;

void setup() {
  // put your setup code here, to run once:

  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(ln1, OUTPUT);
  pinMode(ln2, OUTPUT);
  pinMode(ln3, OUTPUT);
  pinMode(ln4, OUTPUT);

  // connect wifi
  

}

void forward();
void backward();
void turnLeft();
void turnRight();

void loop()                                                                                                                                                   {
  // put your main code here, to run repeatedly:

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
