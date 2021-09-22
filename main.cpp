#include <iostream>
#include <iomanip>
#include "libraryy.hpp"

struct studentas
{
    string vardas, pavarde;
    float nd[5];
    float egzas;
    float galutinis;
    float mediana;
};

/*
void print(studentas kint)
{
    cout<<setw(20)<<kint.vardas<<setw(20)<<kint.pavarde;
    for(auto &i:kint.nd) cout<<setw(5)<<i;
    cout<<setw(5)<<kint.egzas<<setw(5)<<setprecision(2)<<kint.galutinis<<endl;
}*/

int main()
{
    cout<<"Iveskite studentu skaiciu: "<<endl;
    int n,m;
    cin>>n; //studentu skaicius
    cout<<"Iveskite 1, noredami skaiciuoti studentu vidurkius, 2 - namu darbu medianas"<<endl;
    cin>>m;
    studentas grupe[n];
    float sum=0;
    for(int i=0;i<n;i++)
    {
        if(m!=1&&m!=2)
        {
            cout<<"Ivyko klaida: irasete netinkama simboli ar skaiciu"<<endl;
            break;
        }
        cout<<"Iveskite "<<i+1<<"-o studento varda ir pavarde: ";
        cin>>grupe[i].vardas>>grupe[i].pavarde;
        sum=0;
        for(int j=0;j<5;j++)
        {
            cout<<"Iveskite "<<j+1<<"-o namu darbo ivertinima: ";
            cin>>grupe[i].nd[j];
            sum+=grupe[i].nd[j];
        }
        for(int j=0;j<5;j++)
        {
            for(int k=j;k<5;k++)
            {
                if(grupe[i].nd[j]>grupe[i].nd[k])
                {
                    swap(grupe[i].nd[j],grupe[i].nd[k]);
                }
            }
        }
        if(5%2==1) for(int j=0;j<5;j++) grupe[i].mediana=grupe[i].nd[j/2];
        else if(5%2==0) for(int j=0;j<5;j++) grupe[i].mediana=(grupe[i].nd[j/2]+grupe[i].nd[(j/2)-1])/2;

        cout<<"Iveskite "<<i+1<<"-o studento egzamino ivertinima: ";
        cin>>grupe[i].egzas;
        grupe[i].galutinis=0.4*sum/5+0.6*grupe[i].egzas;
    }

    if(m==1)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<grupe[i].vardas<<setw(20)<<grupe[i].pavarde<<setw(20)<<setprecision(2)<<grupe[i].galutinis<<endl;
        }
    }

    else if(m==2)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Med.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<grupe[i].vardas<<setw(20)<<grupe[i].pavarde<<setw(20)<<setw(20)<<grupe[i].mediana<<endl;
        }
    }
    //for(auto &kint:grupe) print(kint);
    return 0;
}
/*
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
    string vard, pavard;
    float nd[10]{};
    float ekzam;
    float gal;
};


void pild(studentas &kint);
void printas(studentas &kin);


int main()
{

    studentas st1;
    studentas st2{ "Vardas2","Pavarde2",{5,8,7,4,5,8,9,5,4},9, 0};
    //pild(st1);
    //printas(st1);
    studentas studentai[10];
    for (int i = 0; i < 2; i++)
        pild(studentai[i]);
    for (int i = 0; i < 2; i++)
        printas(studentai[i]);

}

void pild(studentas& kint) {
    int n;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vard >> kint.pavard;
    cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
    cout << "Iveskite pazymius:" << endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i];
        sum += kint.nd[i];
    }
    vid = sum / n;
    cout << "Iveskite egzamino pazymi:"; cin >> kint.ekzam;
    kint.gal = vid * 0.4 + kint.ekzam;
}

void printas(studentas& kin) {
    cout << kin.vard << " " << kin.pavard<<" ";
    for (int i = 0; i < sizeof(kin.nd) / sizeof(kin.nd[0]); i++)
        cout << kin.nd[i] << " ";
    cout << "Egzaminas = " << kin.ekzam << "; Galutinis: " << kin.gal<<endl;
}*/
