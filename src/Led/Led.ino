int pin = 21;


void setup() {
  pinMode(pin, OUTPUT);


}

void loop() {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin,LOW);

}
