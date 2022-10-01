#define trigPin 11
#define echoPin 2

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2.0) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print(duration);
  Serial.println(" us");
  delay(500);
} 
phmarcel0x — Yesterday at 5:25 PM
#define LED P5

int main(){


DDRB|=(1<<LED); // set the pin as output
// there is no need to set EchoPin as input, as it is input by default.
// If you wish to do it anyways: DDRD&=~(1<<EchoPin);
PORTB&=~(1<<LED); // just in case, not really needed as it is the default value.

while (1) {

   PORTB|=(1<<LED); //start of the pulse
  _delay_us(1000); // delay for the pulse
   PORTB&=~(1<<LED); // end of the pulse

// here you can do your reading of EchoPin pulse length, sending the reading, etc.
// from now on your Arduino code will work.
//...

}}
