::c++
::header
#define TEST 1
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

#define INPUT 0
#define INPUT_PULLUP 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

using String = const char*;
// #define byte unsigned char

class COMPORT {
private:
    int bond_auto = 0;
    int bond_speed = 0;
    std::string com = "COM: | ";
    bool string = true;
public:
    COMPORT(int bond_auto_input) {
        bond_auto = bond_auto_input;
    }
    void begin(int bond) {
        bond_speed = bond;
    }

    void print(const char* text) {
        if (string) {
            std::cout << com;
            string = false;
        }
        while (*text != '\0') {
            std::cout << (char)((*(text++) * bond_speed / bond_auto));
        }
    }

    void set_string(bool value) {
        string = value;
    }

    void print(int number, unsigned char mode = DEC) {
        if (string) {
            std::cout << com;
            string = false;
        }
        if (mode == HEX) {
            std::cout << std::hex << number * bond_speed / bond_auto;
            return;
        }
        if (number >= mode)
            print(number / mode, mode);
        std::cout << (number % mode * (bond_speed / bond_auto));

    }

    void print(float number, unsigned char mode) {
        if (string) {
            std::cout << com;
            string = false;
        }
        std::cout << std::fixed << std::setprecision(mode) << number;
    }

    void println(int number, unsigned char mode = DEC) {
        print(number, mode);
        std::cout << std::endl;
        string = true;
    }

    void println(const char *text) {
        print(text);
        std::cout << std::endl;
        string = true;
    }

    void println(float number, unsigned char mode) {
        print(number, mode);
        std::cout << std::endl;
        string = true;
    }

};

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
        std::cout << "PIN: " << pin <<" | Value: " << button << " |\n";
        return !(!(console[pin][0]) && button && (pins == pin));
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
        std::cout << "LED: | ";
        for (auto digit : console)
            std::cout << color[(digit[0] & digit[1])];
        std::cout << " | PAUSE: " << std::setw(st) << ms << " ms |";
        if (intensity != -1)
            std::cout << " Intensity:" << std::setw(3) << intensity << " % |";
        std::cout << std::endl;
    }

};

Led led_("yellow");
COMPORT Serial(9600);


void delay(int ms) {
    led_.delay_ms(ms, 5);
    Serial.set_string(true);
}

void pinMode(unsigned char pin, unsigned char mode) {
    led_.pinMode(pin, mode);
}

bool digitalRead(unsigned char pin) {
    return led_.digitalRead(pin);
}

int analogRead(unsigned char pin) {
    return led_.analogRead(pin);
}

void digitalWrite(unsigned char pin, unsigned char mode) {
    led_.digitalWrite(pin, mode);
}

void analogWrite(unsigned char pin, unsigned char mode) {
    led_.analogWrite(pin, mode);
}

::code
void setup() {

}

void loop() {

}

::footer

int main(int argc, char* argv[]) {
    setup();
    for (int i = 0; i < TEST; i++) loop();
    return 0;
}
