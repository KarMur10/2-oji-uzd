#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

void inputVardai (std::vector<std::string> &vardas, std::vector<std::string> &pavarde);
void pazymiai (std::vector<std::string> vardas, std::vector<std::string> pavarde, std::vector<double> &Galutinis, std::vector<double> &mediana);
void output (std::vector<std::string> vardas, std::vector<std::string> pavarde, std::vector<double> Galutinis, std::vector<double> mediana);


int main()
{
    std::vector<std::string> vardas, pavarde;
    inputVardai (vardas, pavarde);

    std::vector<double> Galutinis, mediana;
    pazymiai(vardas, pavarde, Galutinis, mediana);

    output(vardas, pavarde, Galutinis, mediana);

    return 0;
}

void inputVardai (std::vector<std::string> &vardas, std::vector<std::string> &pavarde) {

    std::string input1, input2;

    std::cout << "Iveskite studentu varda ir pavarde\nBaigus ivedinet studentu vardus ir pavardes iveskite: Baigta\n";
    while(input2 != "Baigta")
    {
        std::cin >> input1;
        if(input1 == "Baigta") break;
        std::cin >> input2;
        vardas.push_back(input1);
        pavarde.push_back(input2);
    }
}

void pazymiai (std::vector<std::string> vardas, std::vector<std::string> pavarde, std::vector<double> &Galutinis, std::vector<double> &mediana) {

    int input = 1, egz, suma = 0;
    std::vector<double> nd;

    for(int a = 0; a < vardas.size(); a++)
    {
        std::cout << "Iveskite atliktu namu darbu rezultatus 10-baleje sistemoje sio studento - " << vardas[a] << " " << pavarde[a] << ".\nIvedus visus namu darbu rezultatus iveskite 0\n";
        while (input != 0)
        {
            std::cin >> input;
            if(input <= 10 && input >= 0)
            {
                if(input == 0) break;
                nd.push_back(input);
            }
            else std::cout << "Ivestas skaicius nera 10-baleje sistemoje ir nebus pridetas prie skaiciavimu\n";
        }
        std::cout << "Iveskite sio studento egzamino rezultata\n";
        while (egz != INT_MAX)
        {
            std::cin >> egz;
            if(egz <= 10 && egz > 0) break;
            else std::cout << "Ivestas skaicius nera 10-baleje sistemoje" << std::endl;
        }
        for(int i = 0; i < nd.size(); i++)
        {
            suma += nd[i];
        }
        Galutinis.push_back(0.4 * (suma / nd.size()) + 0.6 * egz);
        std::sort(nd.begin(), nd.end());
        if(nd.size() % 2 == 0)
        {
            mediana.push_back((nd[nd.size()/2] + nd[nd.size()/2-1])/2);
        }
        else mediana.push_back(nd[nd.size()/2]);
        nd.clear();
        suma = 0;
        input = 1;
    }
}

void output (std::vector<std::string> vardas, std::vector<std::string> pavarde, std::vector<double> Galutinis, std::vector<double> mediana) {

    std::cout << std::setw(12) << "VARDAS" << std::setw(15) << "PAVARDE" << std::setw(15) << "GALUTINIS" << std::setw(15) << "MEDIANA" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    for(int g = 0; g < vardas.size(); g++)
    {
        std::cout << std::setw(12) << vardas[g] << std::setw(15) << pavarde[g] << std::setw(15) << std::fixed << std::setprecision(2) << Galutinis[g] << std::setw(15) << mediana[g] << std::endl;
    }

}
