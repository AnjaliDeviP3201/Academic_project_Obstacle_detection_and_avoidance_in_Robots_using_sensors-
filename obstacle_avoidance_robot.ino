int robot1=8;// pin used for robot movement
int robot2=9;
int robot3=10;
int robot4=11;
int buzzer=4;
int ir=5;
int pingPin = 6; 
int echoPin = 7; 

long duration, cm;

void setup() 
{
Serial.begin(9600);
pinMode(robot1,OUTPUT);  //declearing all pins using as output
pinMode(robot2,OUTPUT);
pinMode(robot3,OUTPUT);
pinMode(robot4,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(pingPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ir, INPUT);

digitalWrite(robot1,LOW);  // initially sending LOW signal to all pins
digitalWrite(robot2,LOW);
digitalWrite(robot3,LOW);
digitalWrite(robot4,LOW);
  digitalWrite(buzzer,LOW);
  Serial.println("OBSTACLE AVOIDANCE ROBOT");
 }
 void loop()
 {
   robot_move(); // calling robot movement function
//  delay(1000);
  digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
//I inches = microsecondstoInches(duration);
 cm = microsecondsToCentimeters(duration);
Serial.print(“dist=“);
Serial.print(cm);
Serial.println();
Delay(100);
If(cm<50)
{
digitalWrite(buzzer,HIGH);
      robot_stop();
delay(2000);
      digitalWrite(buzzer,LOW);
      delay(2000);
      digitalWrite(buzzer,LOW);
      robot_back();  
      delay(2000);
      robot_stop();
      delay(2000);
      if(digitalRead(ir)==LOW)
      {
      robot_left(); 
      delay(3000);
      robot_stop();
      delay(2000);
      robot_right();
      delay(3000);
      robot_stop();
      delay(2000);
      robot_move();
      delay(1000); 
      }
else
      {
      robot_right(); 
      delay(3000);
      robot_stop();
delay(2000);
      robot_left();
      delay(3000);
      robot_stop();
      delay(2000);
      robot_move();
      delay(1000);  
      } 
   }
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 36 / 2;
}
void robot_move()   // function definition for robot movement
{
  digitalWrite(robot1,LOW);
  digitalWrite(robot2,HIGH);
  digitalWrite(robot3,HIGH);
  digitalWrite(robot4,LOW);
}  
void robot_back()   // function definition for robot movement
{
  digitalWrite(robot1,HIGH);
  digitalWrite(robot2,LOW);
  digitalWrite(robot3,LOW);
  digitalWrite(robot4,HIGH);  
}  
void robot_right()   // function definition for robot movement
{
  digitalWrite(robot1,HIGH);
  digitalWrite(robot2,LOW);
  digitalWrite(robot3,HIGH);
  digitalWrite(robot4,LOW);
}  
void robot_left()   // function definition for robot movement
{
  digitalWrite(robot1,LOW);
  digitalWrite(robot2,HIGH);
  digitalWrite(robot3,LOW);
  digitalWrite(robot4,HIGH);
}  
void robot_stop()   //function definition for robot stop
{
  digitalWrite(robot1,LOW);
  digitalWrite(robot2,LOW);
 digitalWrite(robot3,LOW);
digitalWrite(robot4,LOW);
delay(1000);
}
