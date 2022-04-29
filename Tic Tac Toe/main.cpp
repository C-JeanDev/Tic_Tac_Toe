#include <iostream>
#include <ctime>
#include "matrix.h"
using namespace std;

int main()
{

    int choose, rematch;


    do
    {
        Field f;
        cout << "1. PVP" << endl;

        cout << "2. CPU" << endl;

        cin >> choose;

        if (choose == 1)
        {
            f.play();
        }
        else if (choose == 2)
        {
            f.cpu();
        }

        cout << "Rematch ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> rematch;

    } while (rematch == 1);

    cout<<"";

    return 0;
}
