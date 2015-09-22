int a = 2;  
int b = 3;  
int c = 4;  
int d = 5;  
int e = 6;  
int f = 8;  
int g = 9;  
 
void setup() {              
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);  
  pinMode(c, OUTPUT);  
  pinMode(d, OUTPUT);  
  pinMode(e, OUTPUT);  
  pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);  
}
void displayDigit(int digit)
{
 
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
 
 
void loop() {
 for(int i=0;i<10;i++)
 {
   displayDigit(i);
   delay(1000);
   turnOff();
 }
}
