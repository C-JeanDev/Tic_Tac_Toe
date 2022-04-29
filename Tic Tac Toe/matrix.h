#include <iostream>

using namespace std;

class Field
{

public:
    string base[3][3] = {
        ".",
        ".",
        ".",
        ".",
        ".",
        ".",
        ".",
        ".",
        ".",
    };

    bool checkFull()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (base[i][j] == ".")
                {
                    return false;
                }
            }
        }
        return true;
    }

    void printM()
    {

        cout << "   0    1    2";
        for (int i = 0; i < 3; i++)
        {
            cout << " " << endl;
            cout << i;
            for (int j = 0; j < 3; j++)
            {
                cout << "  " << base[i][j] << "  ";
            }
        }
        cout << endl;
    };

    void play()
    {

        int riga, colonna, riga1, colonna1;

        do
        {
            printM();
            do
            {
                if (checkFull())
                {
                    cout << "The field is full" << endl;

                    exit(1);
                }
                cout << "Player 1: \nPlease enter a row" << endl;
                cin >> riga;
                cout << "insert column " << endl;
                cin >> colonna;

                if (base[riga][colonna] == ".")
                {
                    base[riga][colonna] = "X";

                    if (check("X") == true)
                    {
                        exit(1);
                    }
                    break;
                }
                else
                {
                    cout << "Position occupied" << endl;
                    printM();
                }
            } while (true);

            do
            {
                if (checkFull())
                {
                    cout << "The field is full" << endl;

                    exit(1);
                }
                printM();
                cout << "Player 2: \nPlease enter a row " << endl;
                cin >> riga1;
                cout << "Insert column" << endl;
                cin >> colonna1;

                if (base[riga1][colonna1] == ".")
                {
                    base[riga1][colonna1] = "O";

                    if (check("O") == true)
                    {
                        cout << "s";
                        exit(1);
                    }
                    break;
                }
                else
                {
                    cout << "Position occupied" << endl;
                }
            } while (true);
        } while (true);
    }

    // check the win
    bool check(string v)
    {
        if (base[0][0] == v && base[0][1] == v && base[0][2] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[1][0] == "X" && base[1][1] == "X" && base[1][2] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[2][0] == v && base[2][1] == v && base[2][2] == v)
        {
            cout << "You won" << endl;
            return true;
        }

        if (base[0][0] == v && base[1][0] == v && base[2][0] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[0][1] == v && base[1][1] == v && base[2][1] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[0][2] == v && base[1][2] == v && base[2][2] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[0][0] == v && base[1][1] == v && base[2][2] == v)
        {
            cout << "You won" << endl;
            return true;
        }
        if (base[0][2] == v && base[1][1] == v && base[2][0] == v)
        {
            cout << "You won" << endl;
            return true;
        }
    }

    // play with cpu
    void cpu()
    {

        do
        {
            if (checkFull())
            {
                cout << "The field is full" << endl;
                exit(1);
            }

            printM();

            int riga, colonna;
            cout << "Please enter a row " << endl;
            cin >> riga;
            cout << "Insert column " << endl;
            cin >> colonna;

            if (base[riga][colonna] == ".")
            {
                base[riga][colonna] = "X";

                bool z = true;
                srand(time(NULL));

                while (z == true)
                {
                    if (checkFull())
                    {
                        cout << "The field is full" << endl;
                        exit(1);
                    }
                    int r, c;
                    r = rand() % 3;
                    c = rand() % 3;
                    cout << endl
                         << "Riga CPU:  " << r << "Colonna CPU: " << c << endl;
                    if (base[r][c] == ".")
                    {

                        base[r][c] = "O";

                        z = false;
                    }
                }

                if (check("X") == true)
                {
                    break;
                }
            }
            else
            {
                cout << "Position occupied" << endl;
            }

        } while (true);
    }
};