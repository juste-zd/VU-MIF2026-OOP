#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::string;
using std::vector;

struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
};
void stud_duom(studentas A);

int main()
{
    int k;
    std::vector<studentas> grupe;
    studentas A;
    std::cout<<"Iveskite studentu kieki: ";
    int n;
    std::cin>>n;
    for (int j=0; j<n; j++) {
        std::cout<<"Iveskite studento varda ir pavarde per tarpa: ";
        std::cin>>A.vardas>>A.pavarde;
        std::cout<<"Iveskite semestro pazymiu kieki: ";
        std::cin>>k;
        
        for (int i=0; i<k; i++){
            //cin>>A.paz[i];
            std::cout<<"Iveskite "<<i+1 <<" pazymi: ";
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

    std::cout<<"Studentu duomenys:\n";
    for(studentas B:grupe) stud_duom(B);

    
}

void stud_duom(studentas A){
    std::cout<<std::left<<std::setw(10)<<A.vardas<<"|"<<std::left<<std::setw(15)<<A.pavarde<<"|";
    for (int p: A.paz) std::cout<<std::right<<std::setw(3)<<p<<"|";
    std::cout<<std::right<<std::setw(5)<<A.egz<<"|\n";    
}
