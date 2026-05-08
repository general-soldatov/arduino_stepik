int speaker = 7;
int melody[] = {440, 440, 349, 262, 494, 330};
int durations[] = {250, 250, 500, 250, 250, 250};
// int melody[] = {262, 494, 294, 392, 330, 494};
// int durations[] = {250, 250, 250, 250, 250, 500};
void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 6; i++) {
        tone(speaker, melody[i], durations[i]);
        delay(durations[i] + 50);  // Маленькая пауза между нотами
    }
}