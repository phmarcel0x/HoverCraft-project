//Parameters
const int gp2y0a21Pin  = A0;

//Variables
int gp2y0a21Val  = 0;

void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println("Initialize System");
  //Init ditance ir
  pinMode(gp2y0a21Pin, INPUT);
}

void loop() {
  testGP2Y0A21();
}

void testGP2Y0A21( ) { /* function testGP2Y0A21 */
  ////Read distance sensor
  gp2y0a21Val = analogRead(gp2y0a21Pin);
  Serial.print(gp2y0a21Val); Serial.print(" - "); Serial.println(distRawToPhys(gp2y0a21Val));
  if (gp2y0a21Val < 200) {
    delay(1000);
    Serial.println("Obstacle detected");
  } else {
    delay(1000);
    Serial.println("No obstacle");
  }

}

int distRawToPhys(int raw) { /* function distRawToPhys */
  ////IR Distance sensor conversion rule
  float Vout = float(raw) * 0.0048828125; // Conversion analog to voltage
  int phys = 13 * pow(Vout, -1); // Conversion volt to distance

  return phys;
}
