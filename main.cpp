#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::swap;
using std::nothrow;
using std::vector;
using std::ifstream;

struct studentas
{
    string vardas, pavarde;
    vector<double>nd;
    float egzas;
    float galutinis;
    float mediana;
};

vector<double>Rikiavimas(int ndnr, vector<double>ND)
{
    //double A[];
    for(int j=0;j<ndnr;j++)
    {
        for(int k=j;k<ndnr;k++)
        {
            if(ND[j]>ND[k])
            {
                swap(ND[j],ND[k]);
            }
        }

        cout<<ND[j]<<" ";
    }
    cout<<endl;
    return ND;
}

float Mediana(vector<double>ND)
{
    /*float med=0;
    if(ndnr%2==1) med=ND[ndnr/2]; //nelyginis nd skaicius
    else if(ndnr%2==0) med=(ND[ndnr/2]+ND[(ndnr/2)-1])/2; //lyginis nd skaicius
    return med;*/
    sort (ND.begin(), ND.end());
    if (ND.size() % 2 != 0) {return ND[ND.size()/2];}
    else {return (double)(ND[(ND.size() - 1)/2]+ND[ND.size()/2])/2.0;}
}

void Spausdinimas(int n, int m, string V, string P, float galut, float med)
{
    if(m==1)
    {
        cout<<V<<setw(20)<<P<<setw(20)<<setprecision(3)<<galut<<endl;
    }
    else if(m==2)
    {
        cout<<V<<setw(20)<<P<<setw(20)<<setprecision(2)<<med<<endl;
    }
}

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

unsigned int skaiciukas(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

ifstream f("kursiokai.txt");

void Skaitymas (vector<studentas> & ST,int* ndsk)
{
    int studentu_sk;
    int laikina;
    string k;
    ifstream f("kursiokai.txt");
    if(f.is_open())
    {

        getline(f>>std::ws, k);
        *ndsk = skaiciukas(k) - 3;

        while(!(cin.fail()))
        {
            float suma=0;
            ST.resize(ST.size()+1);

            f>>ST.at(studentu_sk).vardas;
            if(f.eof()) {ST.pop_back(); break;}
            f>>ST.at(studentu_sk).pavarde;
            for(int i=0; i<*ndsk; i++)
            {
                f>>laikina;
                ST.at(studentu_sk).nd.push_back(laikina);
                suma+=laikina;
            }
            f>>ST.at(studentu_sk).egzas;
            ST.at(studentu_sk).galutinis = 0.4*(suma/(ST.at(studentu_sk).nd.size()))+0.6*ST.at(studentu_sk).egzas;
            studentu_sk++;
        }
    }
    else {cout<<"-\n";}
    f.close();
}

void spausdinimas (vector<studentas> ST, int pazymiu_skaicius)
{
    std::ofstream output;
    output.open("rezultatas.txt");
    output<<setw(20)<<std::left<<"Vardas"<<setw(20)<<std::left<<"Pavarde"<<
    setw(20)<<std::left<<"Galutinis"<<setw(20)<<std::left<<"Mediana"<<endl;

    cout<<"-------------------------------------------------------\n";

    for(int i=0; i<ST.size();i++)
    {
        output<<setw(20)<<std::left<<ST[i].vardas<<setw(20)<<std::left<<ST[i].pavarde<<
        setw(20)<<std::left<<std::setprecision(3)<<ST[i].galutinis<<Mediana(ST[i].nd)<<endl;
    }
    output<<"\n\n";

}

//typedef char vardas[20];
//typedef char pavarde[20];

/*void nuskaitymas(int &n,studentas ST[])
{
    ifstream f("kursiokai.txt");
    n=2;
    vardas v;
    pavarde p;
    //f.ignore();
    for(int i=0;i<n;i++)
    {
        f.get(v,20);
        ST[i].vardas=v;
        f.get(p,20);
        ST[i].pavarde=p;
        for(int j=0;j<5;j++)
        {
            f>>ST[i].nd[j];
        }
        f>>ST[i].egzas;
        f.ignore();
    }
}*/

int main()
{
    int q,pazymiu_skaicius;
    char temp;
    vector<studentas> ST;
    cout<<"Iveskite 1, jei norite duomenis generuoti automatiskai, 2 - nuskaityti is failo"<<endl;
    cin>>q;
    if(q==1) Mainas();
    else if(q==2)
    {
        Skaitymas(ST,&pazymiu_skaicius);
        spausdinimas(ST,pazymiu_skaicius);
    }

    return 0;
}

