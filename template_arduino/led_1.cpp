// c++
// header
#define TEST 1
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

class Led {
private:
    std::map<std::string, std::string> colors_data {
        {"green", "🟩"}, {"black", "⬛"}, {"red", "🟥"},
        {"orange", "🟠"}, {"yellow", "🟡"}, {"green_round", "🟢"},
        {"blue", "🟣"}, {"brown", "🟤"}
    };
    std::string color[2] = {"⬛"};
    int intensity = -1;
    unsigned char console[13][2] = {{0, 0}};
    unsigned char pwm_pin[6] = {3, 5, 6, 9, 10, 11};

    bool check_pwm(unsigned char pin) {
        for (auto pwm : pwm_pin) {
            if (pin == pwm)
                return 1;
        }
        return 0;
    }

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

    bool digitalRead(int pin) {
        int pins;
        bool button;
        std::cin >> pins >> button;
        std::cout << "PIN: " << pin <<" | Value: " << button << " | ";
        return (!(console[pin][0]) && button && (pins == pin));
    }

    int analogRead(int pin) {
        int pins, read;
        std::cin >> pins >> read;
        std::cout << "PIN: " << pin <<" | Value: " << read << " | ";
        if ((pin == pins) && read <= 255)
            return read;
        return 0;
    }

    void analogWrite(unsigned char pin, unsigned char intensity_pin) {
        if (check_pwm(pin) &&  intensity_pin != 0) {
            console[pin][1] = HIGH;
            intensity = intensity_pin * 100 / 255;
        } else
            console[pin][1] = LOW;

    }

    void delay_ms(int ms, int st) {
        std::cout << "LED | ";
        for (const auto& [registr, digit] : console)
            std::cout << color[(registr & digit)];
        std::cout << " | PAUSE: " << std::setw(st) << ms << " ms |";
        if (intensity != -1)
            std::cout << " Intensity:" << std::setw(3) << intensity << " % |";
        std::cout << std::endl;
    }

};

Led led("green");

void delay(int ms) {
    led.delay_ms(ms, 5);
}

void pinMode(unsigned char pin, unsigned char mode) {
    led.pinMode(pin, mode);
}

bool digitalRead(unsigned char pin) {
    return led.digitalRead(pin);
}

int analogRead(unsigned char pin) {
    return led.analogRead(pin);
}

void digitalWrite(unsigned char pin, unsigned char mode) {
    led.digitalWrite(pin, mode);
}

void analogWrite(unsigned char pin, unsigned char mode) {
    led.analogWrite(pin, mode);
}

// code
void setup() {
    // put your setup code here, to run once:
    for (int i = 1; i < 13; i++)
        pinMode(i, OUTPUT);
    pinMode(0, INPUT);
}

void loop() {
    // put your main code here, to run repeatedly
    // for (int i = 0; i < 13; i++) {
    //     digitalWrite(i, HIGH);
    //     delay(1500);
    //     digitalWrite(i, LOW);
    // }
    // for (int i = 1; i < 255; i+=2) {
    //     analogWrite(3, i);
    //     delay(100);
    // }
    // std::cout << analogRead(0) << digitalRead(0) << std::endl;
    // if (digitalRead(0) == HIGH) {
    //     digitalWrite(1, HIGH);
    // } else {
    //     digitalWrite(2, HIGH);
    // }
    // delay(100);


}

// footer

int main(int argc, char* argv[]) {
    setup();
    for (int i = 0; i < TEST; i++) loop();
    return 0;
}
