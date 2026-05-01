int led = 3, pause = 100;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    digitalWrite(led, HIGH);
    delay(pause);
    digitalWrite(led, LOW);
    delay(pause);
}