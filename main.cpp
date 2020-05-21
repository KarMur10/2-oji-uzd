#include "main.h"

int main()
{
    char ipType;
    ipType = inputType();
    if(ipType == 'r')
        return 0;
    if(ipType == 's')
        return 0;
    Output(StudInput(ipType));
    return 0;
}

char inputType ()
{
    char inputType;
    cout << "Jei norite ranka ivesti duomenis iveskte 'y'\n" <<
            "Jei norite kad duomenys butu nuskaityti is failo iveskite 'n'\n" <<
            "Jei norite kad duomenu failas butu sugeneruotas atsitiktiniais duomenimis iveskite 'r'\n" <<
            "Jei norite iskaidyti studentu faila i islaikiusiu ir neislaikiusiu iveskite 's'\n";

    while(inputType || !inputType)
    {
        cin >> inputType;
        try
        {
            if(inputType != 'y' && inputType != 'n' && inputType != 'r' && inputType != 's')
            {
                throw inputType;
            }
            if(inputType == 'r')
            {
                fileGenerator();
                return inputType;
            }
            if(inputType == 's')
            {
                fileSplit();
                return inputType;
            }
            return inputType;
        }
            catch(char badInput)
            {
                cout << "Klaida: iveskite 'y' jei duomenis ivesite ranka, jei jie bus nuskaitomi is failo: 'n'\n";
            }
    }

    return 0;
}

int studentuSk ()
{
    int studSk;
    cout << "Iveskite studentu skaiciu\n";
    while(studSk || !studSk)
    {
        cin >> studSk;
        try
        {
            if(studSk < 1 || cin.fail())
                throw studSk;
            return studSk;
        }
        catch(int badSk)
        {
        cout << "Klaida: turite ivesti teigiama skaiciu\n";
        }
    }
    return 0;
}

vector<int> ndInput ()
{
    int tempnd;
    vector<int> nd;
    while(tempnd || !tempnd)
    {
        cin >> tempnd;
        try
        {
            if(tempnd < 0 || tempnd > 10 || cin.fail())
                throw tempnd;
            if (tempnd == 0) break;
            else nd.push_back(tempnd);
        }
        catch(int badnd)
        {
            cout << "Klaida: namu darbo rezultatas tur buti tarp 1 ir 10\n";
        }
    }
    return nd;
}

int egzInput()
{
    int egz;
    while(egz || !egz)
    {
        cin >> egz;
        try
        {
            if(egz < 1 || egz > 10 || cin.fail())
                throw egz;
            return egz;
        }
        catch(int badegz)
        {
            cout << "Klaida: egzamino rezultatas turi buti tarp 1 ir 10\n";
        }
    }
    return 0;
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
