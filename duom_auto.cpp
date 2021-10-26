#pragma once

#include "Using'ai.hpp"
#include "duom.h"
#include "rikiavimas.h"
#include "mediana.h"
#include "spausdinimas.h"

int Mainas()
{
    int n,m,l;
    srand (time(NULL));
    cout<<"Iveskite studentu skaiciu: "<<endl;
    double pazymys;
    float sum=0;
    cin>>n; //studentu skaicius
    if(n<1) {cout<<"Ivedete netinkama studentu skaiciu"<<endl; return 0;}
    cout<<"Iveskite 1, noredami skaiciuoti studentu VIDURKIUS, 2 - namu darbu MEDIANAS"<<endl;
    cin>>m;
    if(m!=1&&m!=2) {cout<<"Ivedete netinkama skaiciu"<<endl; return 0;}
    studentas grupe[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Iveskite "<<i+1<<"-o studento varda ir pavarde: ";
        cin>>grupe[i].vardas>>grupe[i].pavarde;

        int number=0,number1=0;
        for (int j=0;grupe[i].vardas[j]!='\0';j++)
        {
            // tikrinimas ar yra skaiciu
            if (isdigit(grupe[i].vardas[j])!=0)
                number++;
        }
        for (int j=0;grupe[i].pavarde[j]!='\0';j++)
        {
            // tikrinimas ar yra skaiciu
            if (isdigit(grupe[i].pavarde[j])!=0)
                number1++;
        }
        if(number>0||number1>0) {cout<<"Ivedete netinkama varda arba pavarde"<<endl; return 0;}

        sum=0,l=0;
        pazymys=rand()%10+1;
        cout<<"Iveskite "<<l+1<<"-o namu darbo ivertinima: "<<pazymys<<endl;
        grupe[i].nd.push_back(pazymys);
        l++;
        sum+=pazymys;
        while((pazymys=rand()%11)&&(pazymys!=0))
        {
            if(pazymys<0||pazymys>10) {cout<<"Ivedete netinkama namu darbo ivertinima"<<endl; return 0;}
            grupe[i].nd.push_back(pazymys);
            sum+=pazymys;
            l++;
            cout<<"Iveskite "<<l<<"-o namu darbo ivertinima: "<<pazymys<<endl;
        }
        typedef vector<double>::size_type vecSize;
        vecSize size = grupe[i].nd.size();
        if (size == 0)
        {
            cout << "Privalote įvesti ND rezultatus. Bandykite iš naujo.\n";
            return 1;
        }

        grupe[i].nd=Rikiavimas(l,grupe[i].nd);

        grupe[i].mediana=Mediana(grupe[i].nd);

        cout<<"Iveskite "<<i+1<<"-o studento egzamino ivertinima: ";
        grupe[i].egzas=rand()%11;
        cout<<grupe[i].egzas<<endl;
        if(grupe[i].egzas<0||grupe[i].egzas>10) {cout<<"Ivedete netinkama egzamino ivertinima"<<endl; return 0;}

        grupe[i].galutinis=0.4*sum/l+0.6*grupe[i].egzas;
    }

    if(m==1)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            Spausdinimas(n,m,grupe[i].vardas,grupe[i].pavarde,grupe[i].galutinis,grupe[i].mediana);
        }
    }
    else if(m==2)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Med.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            Spausdinimas(n,m,grupe[i].vardas,grupe[i].pavarde,grupe[i].galutinis,grupe[i].mediana);
        }
    }
}
