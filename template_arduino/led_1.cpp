// c++
// header
#define TEST 1
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

class Led {
private:
    std::map<std::string, std::string> colors_data {
        {"green", "🟩"}
    };
    std::string color[2] = {"⬛"};
    unsigned char console[13][2] = {{0, 0}};

public:
    Led(std::string colors) {
        color[1] = colors_data[colors];
    }

    void pinMode(unsigned char pin, unsigned char mode) {
        console[pin][0] = mode;
    }

    void digitalWrite(unsigned char pin, unsigned char mode) {
        console[pin][1] = mode;
    }

    void delay_ms(int ms, int st) {
        std::cout << "LED | ";
        for (const auto& [registr, digit] : console)
            std::cout << color[(registr & digit)];
        std::cout << " | PAUSE: " << std::setw(st) << ms << " ms |" << std::endl;
    }

};


#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

Led led("green");

void delay(int ms) {
    led.delay_ms(ms, 5);
}

void pinMode(unsigned char pin, unsigned char mode) {
    led.pinMode(pin, mode);
}

void digitalWrite(unsigned char pin, unsigned char mode) {
    led.digitalWrite(pin, mode);
}

// code
void setup() {
    // put your setup code here, to run once:
    for (int i = 0; i < 13; i++)
        pinMode(i, OUTPUT);

}

void loop() {
    // put your main code here, to run repeatedly
    for (int i = 0; i < 13; i++) {
        digitalWrite(i, HIGH);
        delay(1500);
        digitalWrite(i, LOW);
    }

}

// footer

int main(int argc, char* argv[]) {
    setup();
    for (int i = 0; i < TEST; i++) loop();
    return 0;
}
