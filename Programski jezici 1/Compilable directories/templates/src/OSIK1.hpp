#ifndef OSIK1_H
#define OSIK1_H

#include "Questionnaire.hpp"
#include "ClosedStreamException.hpp"
#include <fstream>

class OSIK1 final : public Questionnaire {
public:
    OSIK1(string sPath){
        path = sPath;

        stream = path;
        if (!stream.is_open())
            throw ClosedStreamException();
    }

    virtual void start(int allowedWrongs) override {
        this->allowedWrongs = allowedWrongs;
    }

    virtual void end() override {
        stream.close();
    }

private:
    std::fstream stream;
    int allowedWrongs;
};

#endif