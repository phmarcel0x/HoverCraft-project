#define D3_led 11
#define trigPin 13
#define echoPin 3
//#define led 13

void setup() {
  Serial.begin(9600); 
  pinMode(D3_led, OUTPUT);
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
//sound speed
float speed=343;//  in m/s
// calculate the distance
  distance=((speed*duration)/10000)/2;




  if(distance>=0 && distance<=15){
  analogWrite(D3_led,0);
  digitalWrite(trigPin,HIGH);
  }
  else if(distance>15 && distance<40){
      
      x=(float)7.2857*distance-109.2857;
      analogWrite(D3_led,x);
        digitalWrite(trigPin,LOW);
    }
  else{
  analogWrite(D3_led, 255);
  digitalWrite(trigPin,HIGH);
  }

  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(analogRead(trigPin));
  
  delay(1000);
}
