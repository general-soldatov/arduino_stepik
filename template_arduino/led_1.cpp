// c++
// header
#define TEST 3
#include <iostream>
#include <string>

#define ON "🟩"
#define OFF "⬛"

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

void delay(int ms);
void pinMode(unsigned char, unsigned char);
void digitalWrite(unsigned char, unsigned char);

// code
void setup() {
    // put your setup code here, to run once:

}

void loop() {
    // put your main code here, to run repeatedly

}

// footer
using namespace std::string_literals;

int main() {
    std::string leds[13] = {};
    setup();
    for (int i = 0; i < TEST; i++)
        loop();
    for (auto &data : leds) {
        data = OFF;
    }
    std::cout << leds << std::endl;
}



void delay(int ms) {

}

void pinMode(unsigned char pin, unsigned char mode) {

}

void digitalWrite(unsigned char pin, unsigned char mode) {

}