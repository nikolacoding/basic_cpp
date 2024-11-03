#ifndef ARRAY_H
#define ARRAY_H

class Array{
private:
    int _id;
    int _capacity;
    int _size;
    int *_array;

public:
    static int count;

    Array();
    explicit Array(int n);
    Array(int a, int b);
    Array(const Array& original);
    Array(Array&& original);
    ~Array();

    bool append(int value);
    void write();
    int getSize();
    int* getArrayPtr();
};

#endif