#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    vector<double> Galutinis, mediana, nd;
    int suma = 0;
    double galutinis;
    string input1, input2;
    int egz, input = 1;
    vector<string> vardas, pavarde;
    cout << "Iveskite studentu varda ir pavarde\nBaigus ivedinet studentu vardus ir pavardes iveskite: Baigta\n";
    while(input2 != "Baigta")
    {
        cin >> input1;
        if(input1 == "Baigta") break;
        cin >> input2;
        vardas.push_back(input1);
        pavarde.push_back(input2);
    }
    for(int a = 0; a < vardas.size(); a++)
    {
        cout << "Iveskite atliktu namu darbu rezultatus 10-baleje sistemoje sio studento - " << vardas[a] << " " << pavarde[a] << ".\nIvedus visus namu darbu rezultatus iveskite 0\n";
        while (input != 0)
        {
            cin >> input;
            if(input <= 10 && input >= 0)
            {
                if(input == 0) break;
                nd.push_back(input);
            }
            else cout << "Ivestas skaicius nera 10-baleje sistemoje ir nebus pridetas prie skaiciavimu\n";
        }
        cout << "Iveskite sio studento egzamino rezultata\n";
        while (egz != INT_MAX)
        {
            cin >> egz;
            if(egz <= 10 && egz > 0) break;
            else cout << "Ivestas skaicius nera 10-baleje sistemoje" << endl;
        }
        for(int i = 0; i < nd.size(); i++)
        {
            suma += nd[i];
        }
        Galutinis.push_back(0.4 * (suma / nd.size()) + 0.6 * egz);
        if(nd.size() % 2 == 0)
        {
            mediana.push_back((nd[nd.size()/2] + nd[nd.size()/2-1])/2);
        }
        else mediana.push_back(nd[nd.size()/2]);
        nd.clear();
        suma = 0;
        input = 1;
    }
    cout << setw(12) << "VARDAS" << setw(15) << "PAVARDE" << setw(15) << "GALUTINIS" << setw(15) << "MEDIANA" << endl;
    cout << "----------------------------------------------------------" << endl;
    for(int g = 0; g < vardas.size(); g++)
    {
        cout << setw(12) << vardas[g] << setw(15) << pavarde[g] << setw(15) << fixed << setprecision(2) << Galutinis[g] << setw(15) << mediana[g] << "\n";
    }
    return 0;
}
