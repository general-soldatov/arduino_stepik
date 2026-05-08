#define BUTTON 6
int speaker = 7;


int melody[2][6] = {
    {440, 440, 349, 262, 494, 330},
    {262, 494, 294, 392, 330, 494}
};

int durations[2][6] = {
    {250, 250, 500, 250, 250, 250},
    {250, 250, 250, 250, 250, 500}
};
int j = 1;

void setup() {
    pinMode(6, INPUT_PULLUP);
}

void loop() {
    // put your main code here, to run repeatedly:
    j = !digitalRead(BUTTON);
    for (int i = 0; i < 6; i++) {
            tone(speaker, melody[j][i], durations[j][i]);
            delay(durations[j][i] + 50);  // Маленькая пауза между нотами
        }
}