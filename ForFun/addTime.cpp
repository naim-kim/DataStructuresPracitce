#include <iostream>
#include <iomanip>

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void addSeconds(int sec) {
        seconds += sec;
        normalize();
    }

    void addMinutes(int min) {
        minutes += min;
        normalize();
    }

    void addTime(int sec, int min) {
        addSeconds(sec);
        addMinutes(min);
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

    int sec1 = 10000;
    int sec2 = 3201;

    time.addTime(sec1, 0);
    time.addTime(0, sec2);

    std::cout << "Total time after addition: ";
    time.display();

    return 0;
}
