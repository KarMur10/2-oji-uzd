#include "main.h"
#include <chrono>

void createFile(string fileName, vector<Studentas> studType);

void fileSplit ()
{
    vector<int> nd;
    string filePav, input, vardas, pavarde;
    int ndNr = 0, tempNd, egz;
    vector<Studentas> blogieciai, gerieciai;
    cout << "Iveskite failo pavadinima\n";
    cin >> filePav;
    chrono::steady_clock::time_point startRead = chrono::steady_clock::now();
    vector<Studentas> Stud;
    ifstream splitFile (filePav);
    if(!splitFile) cout << "Nera tokio failo" << endl;
    else
    {
        splitFile >> input;
        splitFile >> input;
        splitFile >> input;
        while ((input[0] = 'N'))
        {
            ndNr++;
            splitFile >> input;
            if (input[0] != 'N')
                break;
        }
        while (!splitFile.eof())
        {
            splitFile >> vardas;
            if(splitFile.eof())
                break;
            splitFile >> pavarde;
            for (int i = 0; i < ndNr; i++)
            {
                splitFile >> tempNd;
                nd.push_back(tempNd);
            }
            splitFile >> egz;
            Stud.push_back({vardas, pavarde, nd, egz});
            nd.clear();
        }
        splitFile.close();
    }
    chrono::steady_clock::time_point endRead = chrono::steady_clock::now();

    cout << "Skaitymo laikas: " << (double)chrono::duration_cast<chrono::milliseconds>(endRead - startRead).count() / 1000 << "s\n";

    chrono::steady_clock::time_point startSplit = chrono::steady_clock::now();
    int studVectorSize = Stud.size();
    int studNdVectorSize = Stud[0].nd.size();
    for (int i = 0; i < studVectorSize; i++) {
        double galutinis = 0;
        for(int a = 0; a < studNdVectorSize; a++)
        {
            galutinis += Stud[i].nd[a];
        }
        galutinis = galutinis / studNdVectorSize;
        galutinis = galutinis * 0.4 + Stud[i].egz * 0.6;
        if (galutinis < 5)
        {
            blogieciai.push_back(Stud[i]);
        }
        else
        {
            gerieciai.push_back(Stud[i]);
        }
    }
    chrono::steady_clock::time_point endSplit = chrono::steady_clock::now();

    cout << "Rusiavimo laikas: " << (double)chrono::duration_cast<chrono::milliseconds>(endSplit - startSplit).count() / 1000 << "s\n";

    chrono::steady_clock::time_point startFile = chrono::steady_clock::now();

    createFile("gerieciai.txt", gerieciai);
    createFile("blogieciai.txt", blogieciai);

    chrono::steady_clock::time_point endFile = chrono::steady_clock::now();
    cout << "Rasymo laikas: " << (double)chrono::duration_cast<chrono::milliseconds>(endFile - startFile).count() /1000 << "s\n";

    cout << "Failai sukurti\n";
    return;
}

void createFile(string fileName, vector<Studentas> studType)
{
    ofstream studFile(fileName);
    if(!studType.empty())
    {
        int studNdVectorSize = studType[0].nd.size(), studVecorSize = studType.size();
        studFile << left << setw(15) << "Vardas" << setw(15) << "Pavardė";
        for (int j = 1; j <= studNdVectorSize; j++)
        {
            studFile << left << "ND" << setw(15) << j;
        }
        studFile << "Egz.\n";

        for (int i = 0; i < studVecorSize; i++)
        {
            studFile << left << setw(15) << studType[i].vardas << setw(15) << studType[i].pavarde << setw(15);
            for (int j = 0; j < studNdVectorSize; j++)
            {
                studFile << left << setw(15) << studType[i].nd[j];
            }
            studFile << left << setw(15) << studType[i].egz << endl;
        }
    }
    studFile.close();
    return;
}
