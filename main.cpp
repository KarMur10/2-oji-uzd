#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double galutinis;
    int egz, input = 1;
    vector<int> nd;
    string vardas, pavarde;
    cout << "Iveskite studento varda ir pavarde\n";
    cin >> vardas >> pavarde;
    cout << "Iveskite atliktu namu darbu rezultatus 10-baleje sistemoje\nIvedus visus namu darbu rezultatus iveskite 0\n";
    while (input != NULL)
    {
        cin >> input;
        if(input <= 10 && input >= 0)
        {
            if(input == NULL) break;
            nd.push_back(input);
        }
        else cout << "Ivestas skaicius nera 10-baleje sistemoje ir nebus pridetas prie skaiciavimu\n";
    }
    cout << "Iveskite egzamino rezultata\n";
    cin >> egz;
    int suma = 0;
    for(int i = 0; i < nd.size(); i++)
    {
        suma += nd[i];
    }
    double vidurkis = suma / nd.size();
    double Galutinis = 0.4*vidurkis + 0.6*egz;
    cout << "Galutinis studento " << vardas << " " << pavarde << " rezultatas: " << Galutinis << endl;
    return 0;
}
