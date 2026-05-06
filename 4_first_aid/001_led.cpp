int green = 4;

void setup() {
    pinMode(green, OUTPUT);
}
void loop() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(green, HIGH);
        delay(500);
        digitalWrite(green, LOW);
        delay(500);
    }
    delay(5000);
}