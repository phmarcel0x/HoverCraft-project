#define trigPin 11
#define echoPin 2
#define led 13

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

float duration,distance,speed,x;


void loop() {

//send the first cycle (pulse) 
  digitalWrite(trigPin, LOW);
  //10 us TTL pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
//calculate the time for the complete cycle
  duration = pulseIn(echoPin, HIGH);
//sound speed might change due to temperature and other factors
float speed=343;//  in m/s
// calculate the distance
  distance=((speed*duration)/10000)/2;




  if(distance>=0 && distance<=15){
  analogWrite(trigPin,0);
  //delay(1000);  
  digitalWrite(led,HIGH);
  }
  else if(distance>15 && distance<40){
      
      x=(float)7.2857*distance-109.2857;
      analogWrite(trigPin,x);
        digitalWrite(led,LOW);
    }
  else{
  analogWrite(trigPin, 255);
  digitalWrite(led,HIGH);
  }

  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
