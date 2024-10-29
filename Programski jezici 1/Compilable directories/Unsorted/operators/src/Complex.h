class Complex{
private:
    int Re, Im;
    int id;
public:
    static int count;
    friend Complex operator+(Complex a, Complex b); 

    Complex(int aRe = 0, int aIm = 0);
    ~Complex();
    void write() const;

    int& getReRef();
    int& getImRef();
};