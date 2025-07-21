// motors
#define in1  7 
#define in2  8  
#define in3  2 
#define in4  4 
#define enA  3  
#define enB  5 

// ir sensors 
int sensor1 = A5; //left
int sensor2 = A4;
int sensor3 = A3; //middle
int sensor4 = A2; //middle
int sensor5 = A1;
int sensor6 = A0; //right

void setup(){ 
pinMode(in1, OUTPUT);  
pinMode(in2, OUTPUT); 
pinMode(enA, OUTPUT);  
pinMode(in3, OUTPUT);    
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT); 
analogWrite(enA, 206); 
analogWrite(enB, 206);

pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(sensor5, INPUT);
pinMode(sensor6, INPUT);

}
void moveForward() {
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
}

void turnLeft() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
} //in the direction of sensor1 and sensor2

void turnRight() {
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
} //in the direction of sensor5 and sensor6

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop(){  
  int val1 = digitalRead(sensor1); //left
  int val2 = digitalRead(sensor2);
  int val3 = digitalRead(sensor3); //middle
  int val4 = digitalRead(sensor4); //middle
  int val5 = digitalRead(sensor5);
  int val6 = digitalRead(sensor6); //right

  // Adjust motor speeds based on sensor readings
  if (val3 == HIGH || val4 == HIGH) { // On the line
    moveForward();
  } 
 
   else if (val6 == HIGH || val5 == HIGH) { // Adjust right
      turnRight();
    }  
    else if (val2 == HIGH || val1 == HIGH) 
    { // Adjust left
      turnLeft();
    }
       
     else { // Lost the line
    stopMotors();
  }}