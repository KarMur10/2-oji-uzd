#pragma once
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

char inputType ();
int studentuSk ();
vector<Studentas> StudInput (char inputType);
vector<int> ndInput ();
int egzInput();
double ndVidurkis(vector<int> nd);
double Mediana(vector<int> nd, double egz);
double Galutinis(double vidurkis, int egz);
void Output (vector<Studentas> Studentai);
int fileGenerator();
void fileSplit ();
