// c++
// header
#define TEST 3
#include <iostream>
#include <string>

class Led {
private:
    unsigned char count;
    const char *color;
    int digit[13] = {0};
public:
    Led(const char* colors, unsigned char counts) {
        color = colors;
        count = counts;
    }

    void pinMode(unsigned char, unsigned char);
    void digitalWrite(unsigned char, unsigned char);
    void printPanel() {
        for (auto led : digit)
            std::cout << led;
        std::cout << std::endl;
    }

};


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

int main(int argc, char* argv[]) {
    // std::string leds[13] = {};
    // setup();
    Led led(ON, 10);
    led.printPanel();
    // for (int i = 0; i < TEST; i++)
    //     loop();
    // for (auto &data : leds) {
    //     data = OFF;
    // }
    // std::cout << leds << std::endl;
    return 0;
}



void delay(int ms) {

}

void pinMode(unsigned char pin, unsigned char mode) {

}

void digitalWrite(unsigned char pin, unsigned char mode) {

}