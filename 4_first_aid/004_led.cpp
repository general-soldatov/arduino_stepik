#define LED_LEFT 4
#define BUT_LEFT 7
#define LED_RIGHT 3
#define BUT_RIGHT 6

void setup() {
    pinMode(LED_LEFT, OUTPUT);
    pinMode(BUT_LEFT, INPUT_PULLUP);
    pinMode(LED_RIGHT, OUTPUT);
    pinMode(BUT_RIGHT, INPUT_PULLUP);
}
void loop() {
    if (digitalRead(BUT_LEFT) == LOW) {
        for (int i = 0; i < 3; i++) {
            digitalWrite(LED_LEFT, HIGH);
            delay(500);
            digitalWrite(LED_LEFT, LOW);
            delay(500);
        }
    }
    if (digitalRead(BUT_RIGHT) == LOW) {
        for (int i = 0; i < 3; i++) {
            digitalWrite(LED_RIGHT, HIGH);
            delay(500);
            digitalWrite(LED_RIGHT, LOW);
            delay(500);
        }
    }
}