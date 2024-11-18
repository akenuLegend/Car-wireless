

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

}

void loop()                                                                                                                                                   {
  // put your main code here, to run repeatedly:

  forward(100,100);
  delay(5000);
  forward(10,10);
  delay(1000);
  backward(100,100);
  delay(5000);
  
}

void forward (int pwmEnA, int pwmEnB) {

  analogWrite(EnB, pwmEnA);
  analogWrite(EnA, pwmEnB);
  
  digitalWrite(ln3, LOW);
  digitalWrite(ln4, HIGH);

  digitalWrite(ln1, HIGH);
  digitalWrite(ln2, LOW);

 }

 void backward (int pwmEnA, int pwmEnB) {

  analogWrite(EnB, pwmEnA);
  analogWrite(EnA, pwmEnB);
  
  digitalWrite(ln3, HIGH);
  digitalWrite(ln4, LOW);

  digitalWrite(ln1, LOW);
  digitalWrite(ln2, HIGH);

 }
