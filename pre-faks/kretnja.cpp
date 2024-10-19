#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void wipe()
{
    for (int i = 0; i < 32; i++)
    {
        std::cout << std::endl;
    }
}

class Coin
{
public:
    int locationX;
    int locationY;
    int collected;

    void place(int limitX, int limitY, int exceptionX, int exceptionY)
    {
        if (limitX > 1 || limitY > 1)
        {
            do
            {
                locationX = std::rand() % limitX;
                locationY = std::rand() % limitY;
            } while (locationX == exceptionX || locationY == exceptionY);
        }
        else
        {
            locationX = std::rand() % limitX;
            locationY = std::rand() % limitY;
        }
    }
} coin;

class Player
{
public:
    int locationX;
    int locationY;

    int x_max;
    int y_max;

    int totalMoves = 0;

    void locationCheck()
    {
        if (locationX < 0)
            locationX = x_max;

        if (locationX > x_max)
            locationX = 0;

        if (locationY < 0)
            locationY = y_max;

        if (locationY > y_max)
            locationY = 0;

        if (locationX == coin.locationX && locationY == coin.locationY)
        {
            coin.collected++;
            coin.place(x_max, y_max, locationX, locationY);
        }
    }

    void move(std::string choice, bool *end)
    {
        wipe();

        if (choice == "w" || choice == "W")
            locationY--;
        else if (choice == "a" || choice == "A")
            locationX--;
        else if (choice == "s" || choice == "S")
            locationY++;
        else if (choice == "d" || choice == "D")
            locationX++;
        else if (choice == "q" || choice == "Q")
            *end = true;
        else
            totalMoves--;

        locationCheck();
        totalMoves++;
    }
} player;

class Field
{
public:
    int height;
    int width;
    void draw()
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (player.locationX == x && player.locationY == y)
                {
                    std::cout << "X ";
                }
                else if (coin.locationX == x && coin.locationY == y)
                {
                    std::cout << "+ ";
                }
                else
                {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    }
} field;

int main()
{
    std::srand(std::time(nullptr));

    Field *ptrF = &field;
    Player *ptrP = &player;
    Coin *ptrC = &coin;

    int field_width_init;
    int field_height_init;

    std::string choice;
    bool done = false;

    do
    {
        std::cout << "Unesi polje: ";
        std::cin >> field_width_init >> field_height_init;
    } while (field_width_init < 2 || field_height_init < 2);
    std::cout << "       W - up" << std::endl
              << "A - left     D - right" << std::endl
              << "       S - down" << std::endl
              << std::endl;

    ptrF->height = field_height_init;
    ptrF->width = field_width_init;

    ptrP->x_max = field_width_init - 1;
    ptrP->y_max = field_height_init - 1;

    ptrP->locationX = 0;
    ptrP->locationY = 0;

    ptrC->place(ptrP->x_max, ptrP->y_max, ptrP->locationX, ptrP->locationY);

    ptrF->draw();

    while (ptrC->collected < 20)
    {
        std::cout << "Coins: " << ptrC->collected << "\n";
        std::cout << "Move: ";
        std::cin >> choice;
        ptrP->move(choice, &done);
        ptrF->draw();
    }

    wipe();
    int temp;

    std::cout << "Congratulations, you collected all 20 coins!" << std::endl;
    std::cout << "Field: " << field_width_init << "x" << field_height_init << std::endl;
    std::cout << "Total moves: " << ptrP->totalMoves << std::endl;

    std::cout << "Input anything to exit: ";
    std::cin >> temp;
}