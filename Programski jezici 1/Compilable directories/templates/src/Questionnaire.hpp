#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H

#include <filesystem>
#include <string>
using std::string;

// apstraktna klasa, konstrukciju vrse nasljednici
class Questionnaire {
public:
    virtual void start(int allowedWrongs) = 0;
    virtual void end() = 0;
protected:
    std::filesystem::path path;
};

#endif