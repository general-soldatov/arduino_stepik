int pins[] = {3, 4, 5};
int count = 3;
#undef TEST
#define TEST 2

void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Прямой порядок
  for (int i = 0; i < count; i++) {
    digitalWrite(pins[i], HIGH);
    delay(1000);
    digitalWrite(pins[i], LOW);
  }
  // Обратный порядок (пропускаем крайние, чтобы не дублировать)
  for (int i = count - 2; i > 0; i--) {
    digitalWrite(pins[i], HIGH);
    delay(1000);
    digitalWrite(pins[i], LOW);
  }
}