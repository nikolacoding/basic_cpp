#include <iostream>

class IntArray{
private:
    int *array;
    int capacity;
    int length;

public:
    IntArray();

    void append(int value); // add an element to the end
    int pop(); // remove and return the last element
    void clear(); // remove all elements

    void printInfo(); // log the capacity, length and all elements to stdout
};

IntArray::IntArray(){
    this->capacity = 10;
    this->length = 0;
    this->array = (int *)malloc(capacity * sizeof(int));
}

void IntArray::append(int value){
    if (this->length != this->capacity){
        int index = this->length;
        this->array[index] = value;
        this->length++;
    }
    else std::cout << "Niz je pun, pokusaj dodavanja broja " << value << " zanemaren." << std::endl;
}

int IntArray::pop(){
    if (this->length){
        this->array = (int *)realloc(this->array, --this->length * sizeof(int));
        return this->array[this->length];
    }
    else{
        std::cout << "Niz je prazan, pokusaj dohvatanja zadnjeg clana zanemaren";
        return __INT_MAX__;
    }
}

void IntArray::clear(){
    if (this->length){
        int c;
        do{
            c = this->pop();
        } while (c != __INT_MAX__);
    }
}

void IntArray::printInfo(){
    using std::cout;
    using std::endl;

    cout << "Kapacitet: " << this->capacity << endl;
    cout << "Trenutni br. elemenata: " << this->length << endl;
    if (this->length){
        cout << "Elementi:";
        for (int i = 0; i < this->length; i++) cout << " " << this->array[i] << " ";
        cout << endl;
    }
    else cout << "Niz je prazan." << endl;
}

int main(void){
    using std::cout;
    using std::endl;

    IntArray array;
    const int cap = 10;

    for (int i = 0; i < cap; i++)
        array.append(i * 2);

    int c;

    array.printInfo();
    c = array.pop(); cout << "Popped: " << c << endl; 
    array.printInfo();
    c = array.pop(); cout << "Popped: " << c << endl; 
    array.printInfo();

    return 0;
}