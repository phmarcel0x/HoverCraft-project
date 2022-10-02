#define trigPin 11
#define echoPin 2
#define led 13

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
}

float duration,distance;


void loop() {

//send the first cycle (pulse) 
  digitalWrite(trigPin, LOW);
  //high frequency are ideal for low range 
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);
//calculate the time for the complete cycle
  duration = pulseIn(echoPin, HIGH);
//sound speed might change due to temperature and other factors
float speed=172.43;//  in m/s
// calculate the distance
  distance=(speed*duration)/10000;

    Serial.print(distance);
  Serial.println(" cm");
  Serial.print(duration);
  Serial.println(" us");
  delay(500);


  if(distance<=15){
  analogWrite(trigPin,0);
  digitalWrite(led,HIGH);
  }
  else if(distance>15 && distance<40){
      float x;
      
      x=(float)7.2857*distance-109.2857;
      analogWrite(trigPin,x);
        digitalWrite(led,LOW);
    }
  else{
  analogWrite(trigPin, 255);
  digitalWrite(led,HIGH);
  }
}
