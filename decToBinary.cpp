#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class conversion
{
public:
    int storeDecToBinary[8] = {0};

    string convertDecToBinary(int decInput)
    {
        if (decInput == 0)
        {
            return "0";
        }
        string getRemainder = to_string(decInput % 2);
        int nextInput = decInput / 2;

        return convertDecToBinary(nextInput) + getRemainder;
    };
};

int binaryToDecimal(long long n)
{
    int dec = 0, i = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;

        // Calculate 2 raised to the power of i without pow function
        int powerOfTwo = 1;
        for (int j = 0; j < i; j++)
        {
            powerOfTwo *= 2;
        }

        dec += rem * powerOfTwo;
        ++i;
    }
    return dec;
}

int main()
{

    string setLoop;
    long int bin;
    int nav, inputNav, dec, indexDec = 0, indexBin = 0;
    bool onLoop = true;
    conversion data[99];
    string getBinaryResult;
    int getDecimalResult;

    while (onLoop)
    {
        system("cls");
        cout << "===================\n";
        cout << "| ATHALLA ZACHARI |\n";
        cout << "| 123210094       |\n";
        cout << "===================\n\n";
        cout << "MAIN MENU\n1. Input Data\n2. Show Data\nPilih : ";
        cin >> nav;

        if (nav > 2 && nav < 1)
        {
            cout << "Incorrect input!!" << endl;
        }
        else
        {
            switch (nav)
            {
            case 1:
                system("cls");
                cout << "DATA INPUT\n";
                cout << "PILIH JENIS INPUT\n1. Decimal to Binary\n2. Binary to Decimal\nPilih : ";
                cin >> inputNav;

                switch (inputNav)
                {
                case 1:
                    system("cls");
                    cout << "DECIMAL TO BINARY\n";
                    cout << "Input ke - " << indexDec + 1 << endl;
                    cout << "\nAngka desimal \t\t\t=> ";
                    cin >> dec;

                    getBinaryResult = data[indexDec].convertDecToBinary(dec);
                    cout << "Result (recursive) \t\t=> " << getBinaryResult << endl;

                    for (int i = 7; dec > 0 && i >= 0; --i)
                    {
                        data[indexDec].storeDecToBinary[i] = dec % 2;
                        dec /= 2;
                    }
                    cout << "Result (Non - recursive) \t=> ";
                    for (int j = 0; j < 8; ++j)
                    {
                        cout << data[indexDec].storeDecToBinary[j];
                    }

                    indexDec++;

                    cout << "\n\n---------------------------------------" << endl;
                    cout << "Data ke - " << indexDec << " berhasil disimpan!" << endl;

                    break;

                case 2:

                    system("cls");
                    cout << "BINARY TO DECIMAL\n";
                    cout << "Input ke - " << indexBin + 1 << endl;
                    cout << "\nAngka binary => ";
                    cin >> bin;

                    getDecimalResult = binaryToDecimal(bin);
                    cout << "Angka binary => " << bin << " = " << getDecimalResult << " dalam decimal." << endl;

                    indexBin++;
                    break;

                default:
                    break;
                }

                break;

            case 2:
                system("cls");
                cout << "SHOW DATA \n";
                cout << "Jumlah Data = " << indexDec << endl;
                cout << "----------------" << endl;
                cout << "Binary => ";

                for (int i = 0; i < indexDec; i++)
                {
                    for (int j = 0; j < 8; ++j)
                    {
                        cout << data[i].storeDecToBinary[j];
                        if (j == 7)
                        {
                            cout << ".";
                        }
                    }
                }
                cout<<"\n";
                break;

            default:
                break;
            }
        }

        cout << "\nKembali ke awal?(Y/N)";
        cin >> setLoop;
        setLoop == "Y" || setLoop == "y" ? onLoop = true : onLoop = false;
    }

    return 0;
}