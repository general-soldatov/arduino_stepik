void setup() {
    pinMode(1, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() {
    digitalWrite(1, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(12, LOW);
    delay(1000);
}