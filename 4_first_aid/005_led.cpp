#undef TEST
#define TEST 2
bool onLED = false;
void setup() {
     pinMode(9, OUTPUT);
     pinMode(10, INPUT_PULLUP);
}
void loop() {
     if (digitalRead(10) == LOW) {
          if (onLED == false) {
               digitalWrite(9, HIGH);
               onLED = 1;
          } else {
               digitalWrite(9, LOW);
               onLED = 0;
          }
     }
     delay(500);
}