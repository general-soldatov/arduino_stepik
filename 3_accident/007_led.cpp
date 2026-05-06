int led = 5;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
    }
    for (int i = 0; i < 3; i++) {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
}