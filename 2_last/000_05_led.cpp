#define LED_BUILTIN_USER 7
#define MY_PAUSE 300

void setup() {
pinMode(LED_BUILTIN_USER , OUTPUT);
}

void loop() {
digitalWrite(LED_BUILTIN_USER, HIGH);
delay(MY_PAUSE);
digitalWrite(LED_BUILTIN_USER, LOW);
delay(MY_PAUSE);
}