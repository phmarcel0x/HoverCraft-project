
void setup() {

  Serial.begin(9600);
  pinMode(A1, INPUT);
}

float adcVal  = 0;

void loop() {
  
  adcVal = analogRead(A1);
  
    float Vout = float(adcVal) * 0.0048828125; // Conversion analog to voltage
  float distance = 29.988 * pow(Vout, -1.173);
  
  
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

 Serial.print("ADC: ");
 Serial.println(adcVal);
 
 Serial.print(distance);
 Serial.println(" cm");
 delay(1000);
 

}
