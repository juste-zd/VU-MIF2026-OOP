#include <iostream>
#include <string>
#include <vector>
#include <iomanip> //for setw() and setprecission()
#include <algorithm> //for sort()

using std::string;
using std::vector;

struct studentas {
    string vardas, pavarde;
    vector<int> paz;
    int egz;
};
void stud_duom(studentas A, char metodas);

int main()
{
    std::vector<studentas> grupe;
    studentas A;

    //input part
    std::cout<<"Iveskite studentu kieki: ";
    int n;
    std::cin>>n;

    //loop for students' data input:
    for (int j = 0; j < n; j++) {
        std::cout<<"Iveskite studento varda ir pavarde per tarpa: ";
        std::cin>>A.vardas>>A.pavarde;

        string ivestis; 
        do {
            std::cout<<"Iveskite pazymi (0-10) arba n, jei daugiau namu darbu rezultatu nera: ";
            std::cin>>ivestis;
            if (ivestis == "n") break;
            bool skaicius = true;
            for (char c: ivestis) {
                if (c < '0' || c > '9') {
                    skaicius = false;
                    break;
                } 
            }
            if (skaicius) {
                int pazymys = std::stoi(ivestis);
                if (pazymys >= 0 && pazymys <= 10) {
                    A.paz.push_back(pazymys);
                } 
                else skaicius = false; 
            } 
            if (! skaicius) {
                std::cout << "Neteisinga ivestis. Iveskite skaiciu nuo 0 iki 10 arba n.\n";
            }
        } while (true);

        std::cout<<"Iveskite egzamino pazymi: ";
        std::cin>>A.egz;

        grupe.push_back(A);
        A.vardas.clear();
        A.pavarde.clear();
        A.paz.clear();
    }

    char metodas;
    std::cout << "\nPasirinkite galutinio balo skaiciavimo metoda:\n";
    std::cout << "v - vidurkis\n";
    std::cout << "m - mediana\n";
    std::cout << "Metodas: ";
    std::cin >> metodas;

    //output part
    std::cout<<"\nStudentu duomenys:\n";
    std::cout<<std::left
        <<std::setw(15)<<"Vardas"
        <<std::setw(15)<<"Pavarde";
    if (metodas == 'v') std::cout<<std::left<<std::setw(15)<<"Galutinis (Vid.)\n";
    else std::cout<<std::left<<std::setw(15)<<"Galutinis (Med.)\n";

    for (int i = 0; i < 45; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"\n";
    
    for (studentas B: grupe)
        stud_duom(B, metodas);
}

//function to print students, final grades
void stud_duom(studentas C, char metodas)
{
    float vidurkis = 0;
    int kiekis = C.paz.size();
    if(metodas=='v') {
        float suma = 0;
        for (int p: C.paz)
            suma += p;
        vidurkis = suma / kiekis;
    }
    else {
        vector<int> v = C.paz;
        std::sort(v.begin(), v.end());
        if (kiekis % 2 == 0) {
            vidurkis = (v[kiekis/2 - 1] + v[kiekis/2]) / 2.0;
        }
        else vidurkis = v[kiekis / 2];
    }
    
    float galutinis = 0.4*vidurkis + 0.6*C.egz;

    std::cout<<std::left
        <<std::setw(15)<<C.vardas
        <<std::setw(15)<<C.pavarde
        <<std::setw(15)<<std::fixed<<std::setprecision(2)<<galutinis<<"\n";
}
