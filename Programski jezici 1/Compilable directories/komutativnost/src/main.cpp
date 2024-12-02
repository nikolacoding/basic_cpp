#include <iostream>

class Vector2{
private:
    int m_x;
    int m_y;

public:
    Vector2(int x = 0, int y = 0) : m_x(x), m_y(y) {}

    friend Vector2 operator*(const Vector2& obj, int q);
    friend Vector2 operator*(int q, const Vector2& obj);
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector2& obj);
};

Vector2 operator*(const Vector2& obj, int q){
    return Vector2(obj.m_x * q, obj.m_y * q);
}

Vector2 operator*(int q, const Vector2& obj){
    return obj * q; // poziva se vec definisan operator gore
    // nekad ce zadati ovako nesto i reci "pridrzavati se principa ponovne upotrebe koda"
    // ocekujuci da uradis ovo
}

std::ostream& operator<<(std::ostream& stream, const Vector2& obj){
    stream << "(" << obj.m_x << ", " << obj.m_y << ")" << std::endl;

    return stream;
}

int main(void){
    Vector2 a(5, 5), b, c;

    b = a * 2;
    c = 2 * a;

    std::cout << a << b << c;
}