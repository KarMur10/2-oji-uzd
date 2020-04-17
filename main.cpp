#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

int inputType ();
int studentuSk ();
vector<Studentas> StudInput (char inputType);
vector<int> ndInput ();
int egzInput();
double ndVidurkis(vector<int> nd);
double Mediana(vector<int> nd, double egz);
double Galutinis(double vidurkis, int egz);
void Output (vector<Studentas> Studentai);

int main()
{
    char ipType;
    //srand(time(NULL));
    ipType = inputType();
    Output(StudInput(ipType));
    return 0;
}

int inputType ()
{
    char inputType;
    cout << "Ar duomenys bus ivesti po viena ar nuskaitomi is failo?\nJei ivesite ranka iveskite: 'y', jei is failo: 'n'\n";
    cin >> inputType;
    while (inputType != 'y' && inputType != 'n')
    {
        cin.clear();
        cin.ignore();
        cout << "Klaida: iveskite 'y' jei duomenis ivesite ranka, jei jie bus nuskaitomi is failo: 'n'\n";
        cin >> inputType;
    }
    return inputType;
}

int studentuSk ()
{
    int studSk;
    cout << "Iveskite studentu skaiciu\n";
    cin >> studSk;
    while (studSk < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Klaida: studentu skaicius turi buti teigiamas skaicius.\n";
        cin >> studSk;
    }
    return studSk;
}

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

vector<int> ndInput ()
{
    int tempnd;
    vector<int> nd;
    while(tempnd != 0)
    {
        cin >> tempnd;
        if (tempnd < 0 || tempnd > 10 || cin.fail())
        {
            cin.ignore();
            cout << "Klaida: namu darbo rezultatas turi buti tarp 1 ir 10\n";
        }
        else if (tempnd == 0)
        {
            break;
        }
        else
        {
            nd.push_back(tempnd);
        }
    }

    return nd;
}

int egzInput()
{
    int egz;
    cin >> egz;
    while (egz < 0 || egz > 10 || cin.fail())
    {
        cin.ignore();
        cout << "Klaida: egzamino rezultatas turi buti tarp 1 ir 10\n";
        cin >> egz;
    }
    return egz;
}

double ndVidurkis(vector<int> nd)
{
    int suma = 0;
    double vidurkis;
    for(int i = 0; i < nd.size(); i++)
    {
        suma += nd[i];
    }
    vidurkis = suma / nd.size();
    return vidurkis;
}

double Mediana(vector<int> nd, double egz)
{
    double mediana;
    if(nd.size() == 1)
    {
        mediana = (nd[0] + egz) / 2;
    }
    else if ((nd.size() + 1) % 2 == 0)
    {
         mediana = (nd[((nd.size() + 1) / 2) - 1] + nd[(nd.size() + 1) / 2]) / 2;
    }
    else
    {
        mediana = nd[nd.size() / 2];
    }
    return mediana;
}

double Galutinis(double vidurkis, int egz)
{
    double galutinis;
    galutinis = 0.4 * vidurkis + 0.6 * egz;
    return galutinis;
}

void Output (vector<Studentas> Studentai)
{
    cout << setw(12) << "VARDAS" << setw(15) << "PAVARDE" << setw(15) << "GALUTINIS" << setw(15) << "MEDIANA" << endl;
    cout << "----------------------------------------------------------" << endl;
    for(int i = 0; i < Studentai.size(); i++)
    {

        cout << setw(12) << Studentai[i].vardas << setw(15) << Studentai[i].pavarde << setw(15) << fixed << setprecision(2) << Galutinis(ndVidurkis(Studentai[i].nd), Studentai[i].egz) << setw(15) << Mediana(Studentai[i].nd, Studentai[i].egz) << endl;
    }
}
