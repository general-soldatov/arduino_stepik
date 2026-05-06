int white = 3, green = 4;
void setup() {
    pinMode(white, OUTPUT);
    pinMode(green, OUTPUT);
}
void loop() {
    for (int i = 0; i <= 255; i++) {
        analogWrite(white, i);
        delay(12);
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(green, HIGH);
        delay(500);
        digitalWrite(green, LOW);
        delay(500);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(white, i);
        delay(20);
    }
    delay(3000);
}