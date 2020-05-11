#include "main.h"
vector<Studentas> StudInput (char inputType)
{
    vector<Studentas> Studentai;
    int egz;
    string vardas, pavarde;
    vector<int> nd;
    if (inputType == 'y')
    {
        int studSk;
        studSk = studentuSk();
        for(int i = 0; i < studSk; i++)
        {
            cout << "Iveskite studento varda\n";
            cin >> vardas;
            cout << "Iveskite studento pavarde\n";
            cin >> pavarde;
            cout << "Iveskite sio studento namu darbu rezultatus. Ivedus visus rezultatus iveskite 0\n";
            nd = ndInput();
            cout << "Iveskite sio studento egzamino rezultata.\n";
            egz = egzInput();
            Studentai.push_back({vardas, pavarde, nd, egz});
        }
    }
    else
    {
        int ndcount = 0, tempNd;
        string temp;
        ifstream file;
        file.open("input.txt");
        file >> vardas;
        file >> pavarde;
        while(temp != "Egz.")
        {
            file >> temp;
            if (temp.at(0) == 'N')
                ndcount++;
            else
                break;
        }
        while(!file.eof())
        {
            file >> vardas;
            file >> pavarde;
            for (int i = 0; i < ndcount; i++)
            {
                file >> tempNd;
                nd.push_back(tempNd);
            }
            file >> egz;
            Studentai.push_back({vardas, pavarde, nd, egz});
            if(file.eof()) break;
        }
        file.close();
    }
    return Studentai;
}
