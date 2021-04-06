#include "main.h"
#include <chrono>

int fileGenerator()
{
    srand(time(NULL));
    string filePav;
    int studNr, ndNr;

    cout << "iveskite kuriamo failo pavadinima\n";
    cin >> filePav;
    cout << "iveskite studentu kieki\n";
    cin >> studNr;
    cout << "iveskite namu darbu kieki\n";
    cin >> ndNr;

    ofstream studFile(filePav.c_str());

    chrono::steady_clock::time_point startFile = chrono::steady_clock::now();

    studFile << left << setw(15) << "Vardas" << setw(15) << "Pavardė";
    for (int j = 1; j <= ndNr; j++)
    {
        studFile << left << "ND" << setw(15) << j;
    }
    studFile << "Egz.\n";

    for (int i = 1; i <= studNr; i++)
    {
        studFile << left << "Vardas" << setw(15) << i << "Pavardė" << setw(15) << i;
        for (int j = 1; j <= ndNr; j++)
        {
            studFile << left << setw(15) << rand() % 10 + 1;
        }
        studFile << left << setw(15) << rand() % 10 + 1 << endl;
    }

    cout << "Failas sukurtas\n";

    chrono::steady_clock::time_point endFile = chrono::steady_clock::now();

    cout << "Failo kurimo laikas: " << (double)chrono::duration_cast<chrono::milliseconds>(endFile - startFile).count() / 1000 << "s\n";

    return 0;
}
