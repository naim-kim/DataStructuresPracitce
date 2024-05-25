#include <iostream>
#include <iomanip>
#include <string>

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void addTime(int hhmmss) {
        int hh = hhmmss / 10000;
        int mm = (hhmmss % 10000) / 100;
        int ss = hhmmss % 100;
        
        hours += hh;
        minutes += mm;
        seconds += ss;
        normalize();
    }

    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }

private:
    void normalize() {
        minutes += seconds / 60;
        seconds = seconds % 60;

        hours += minutes / 60;
        minutes = minutes % 60;
    }
};

int main() {
    Time time(0, 0, 0);
    std::string input;

    std::cout << "Enter times in hhmmss format (type 'q' to quit):" << std::endl;
    while (true) {
        std::cout << "Enter time in hhmmss: ";
        std::getline(std::cin, input);

        if (input == "q" || input == "Q") {
            break;
        }

        try {
            int hhmmss = std::stoi(input);
            if (input.length() != 6) {
                throw std::invalid_argument("Invalid length");
            }
            time.addTime(hhmmss);
        } catch (std::invalid_argument& e) {
            std::cerr << "Invalid input. Please enter a 6-digit number in hhmmss format or 'q' to quit." << std::endl;
            continue;
        }

        std::cout << "Current total time: ";
        time.display();
    }

    std::cout << "Final total time: ";
    time.display();

    return 0;
}
