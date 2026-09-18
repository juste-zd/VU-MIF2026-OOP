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
    int k;
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
        std::cout<<"Iveskite semestro pazymiu kieki: ";
        std::cin>>k;

        for (int i = 0; i < k; i++) {
            std::cout<<"Iveskite "<< i+1 <<" pazymi: ";
            int a;
            std::cin>>a;
            A.paz.push_back(a);
        }

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
    
    for (studentas B : grupe)
        stud_duom(B, metodas);
}

//function to print students, final grades
void stud_duom(studentas A, char metodas)
{
    float vidurkis = 0;
    int kiekis = A.paz.size();
    if(metodas=='v') {
        float suma = 0;
        for (int p: A.paz)
            suma += p;
        float vidurkis = suma / kiekis;
    }
    else {
        vector<int> v = A.paz;
        std::sort(v.begin(), v.end());
        if (kiekis % 2 == 0) {
            vidurkis = (v[kiekis/2 - 1] + v[kiekis/2]) / 2.0;
        }
        else vidurkis = v[kiekis / 2];
    }
    float galutinis = 0.4*vidurkis + 0.6*A.egz;

    std::cout<<std::left
        <<std::setw(15)<<A.vardas
        <<std::setw(15)<<A.pavarde
        <<std::setw(15)<<std::fixed<<std::setprecision(2)<<galutinis<<"\n";
}
