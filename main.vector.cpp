#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::swap;
using std::nothrow;
using std::vector;

struct studentas
{
    string vardas, pavarde;
    vector<double>nd;
    float egzas;
    float galutinis;
    float mediana;
};

int main()
{
    srand (time(NULL));
    cout<<"Iveskite studentu skaiciu: "<<endl;
    int n,m,l;
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

        int *q=new(nothrow) int[l];
        if(!q) cout<<"allocation of memory failed\n";
        else
        {
            for(int j=0;j<l;j++) q[j]=j;
        }
        cout<<endl;

        for(int j=0;j<l;j++)
        {
            for(int k=j;k<l;k++)
            {
                if(grupe[i].nd[j]>grupe[i].nd[k])
                {
                    swap(grupe[i].nd[j],grupe[i].nd[k]);
                }
            }
        }

        for(int j=0;j<l;j++)
        {
            cout<<grupe[i].nd[q[j]]<<" ";
        }
        cout<<endl;

        if(l%2==1) grupe[i].mediana=grupe[i].nd[l/2]; //nelyginis nd skaicius
        else if(l%2==0) grupe[i].mediana=(grupe[i].nd[l/2]+grupe[i].nd[(l/2)-1])/2; //lyginis nd skaicius

        cout<<"Iveskite "<<i+1<<"-o studento egzamino ivertinima: ";
        grupe[i].egzas=rand()%11;
        cout<<grupe[i].egzas<<endl;
        if(grupe[i].egzas<0||grupe[i].egzas>10) {cout<<"Ivedete netinkama egzamino ivertinima"<<endl; return 0;}

        grupe[i].galutinis=0.4*sum/l+0.6*grupe[i].egzas;

        delete[] q;
    }

    if(m==1)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<grupe[i].vardas<<setw(20)<<grupe[i].pavarde<<setw(20)<<setprecision(3)<<grupe[i].galutinis<<endl;
        }
    }
    else if(m==2)
    {
        cout<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis (Med.)"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<grupe[i].vardas<<setw(20)<<grupe[i].pavarde<<setw(20)<<setprecision(2)<<grupe[i].mediana<<endl;
        }
    }
    return 0;
}
