#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using std::string;

constexpr uint64_t numPeople = 1000;

struct Date final {
    uint16_t day, month, year;
};

struct Person final {
    Person(string name, string ssn, Date dob)
        : name(name), ssn(ssn), dob(dob){
        
        age = 2024 - dob.year;
    }
    string name;
    string ssn;
    Date dob;
    uint8_t age;  
};

int main(void){
    auto hrcTime = []() -> auto {
        return std::chrono::high_resolution_clock::now();
    };

    auto timeFromTo = [](auto start, auto end) -> double {
        return std::chrono::duration<double, std::milli>(end - start).count();
    };

    auto startTime = hrcTime();

    Person** people = new Person*[numPeople];

    auto beforeFirstLoop = hrcTime();

    for (unsigned long long i = 0; i < numPeople; i++)
        people[i] = new Person(string("Jovan"), string("Jovanovic"), {1, 1, 2024});

    auto afterFirstLoop = hrcTime();

    auto beforeSecondLoop = hrcTime();
    for (unsigned long long i = 0; i < numPeople; i++)
        delete people[i];
    delete[] people;
    auto afterSecondLoop = hrcTime();

    auto endTime = hrcTime();
    
    double totalDuration = timeFromTo(startTime, endTime);
    double firstLoopDuration = timeFromTo(beforeFirstLoop, afterFirstLoop);
    double secondLoopDuration = timeFromTo(beforeSecondLoop, afterSecondLoop);

    std::printf("Total duration: %.1lfms\nFirst loop: %.1lfms\nSecond loop: %.1lfms\n", 
        totalDuration, firstLoopDuration, secondLoopDuration);
}