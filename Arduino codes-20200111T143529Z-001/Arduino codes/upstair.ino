int f =6;
int pwmf =7;
#define a1 2
#define b1  4
float theta1c=0;
long int temp1, counter1 = 0;


int m =8;
int pwmm =9;
#define a2 3
#define b2  5
float theta2c=0;
long int temp2, counter2 = 0;


int b =10;
int pwmb =11;
#define a3 20
#define b3  19
float theta3c=0;
long int temp3, counter3 = 0;
int x;

                                                        ///////////////////////////////////////////////////////////////////////////

void ai2() {
  if (digitalRead(b2) == !digitalRead(a2)) {
    counter2--; 
  } else {
    counter2++;
  }
}

                                                         ////////////////////////////////////////////////////////////////////////////

void ai1() {
  if (digitalRead(b1) == !digitalRead(a1)) {
    counter1--; 
  } else {
    counter1++;
  }
}


                                                            /////////////////////////////////////////////////////////////////////////////


void ai3() {
  if (digitalRead(b3) == !digitalRead(a3)) {
    counter3--; 
  } else {
    counter3++;
  }
}

                                                          //////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  pinMode(a1, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP); 
  pinMode(f,OUTPUT); 
  pinMode(pwmf, OUTPUT); 
  pinMode(a2, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP); 
  pinMode(m,OUTPUT); 
  pinMode(pwmm, OUTPUT); 
  pinMode(a3, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP); 
  pinMode(b,OUTPUT); 
  pinMode(pwmb, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(a1), ai1, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(a2), ai2, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(a3), ai3, CHANGE);
  Serial.begin(9600);
}

                                                          /////////////////////////////////////////////////////////////////////////////////

void loop() {
  if (Serial.available())
  {
    x = Serial.parseInt();
  }
  if(x){
   if(x==1){
    digitalWrite(m,HIGH);
    analogWrite(pwmm,150);      
    digitalWrite(f,HIGH);
    analogWrite(pwmf,149);
    digitalWrite(b,HIGH);
    analogWrite(pwmb,150);} 
   else if(x==2){
    digitalWrite(m,LOW);
    analogWrite(pwmm,150);      
    digitalWrite(f,LOW);
    analogWrite(pwmf,75);
    digitalWrite(b,LOW);
    analogWrite(pwmb,120);} 
   else if(x==0){
    analogWrite(pwmm,0);      
    analogWrite(pwmf,0);
    analogWrite(pwmb,0);}

}
    Serial.print("1==");
    Serial.println(counter1);
    Serial.print("2==");
    Serial.println(counter2);
    Serial.print("3==");
    Serial.println(counter3);
}
