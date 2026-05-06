int delay_pwm = 12, pin = 3;

void setup() {
    pinMode(pin, OUTPUT);
}
void loop() {
    for (int i = 0; i <= 255; i++) {
        analogWrite(pin, i);
        delay(delay_pwm);
    }
    delay(3000);
    for (int i = 255; i >= 0; i--) {
        analogWrite(pin, i);
        delay(delay_pwm + 8);
    }
    delay(3000);
}