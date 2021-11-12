#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include <bits/stdc++.h>
#include <stdexcept>
#include <limits>
#include <chrono>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::to_string;
using std::ifstream;
using std::ofstream;
using std::list;

namespace chrono = std::chrono;

struct studentas
{
	string vardas, pavarde;
	vector<float>nd;
    float egzas;
    float galutinis;
};

int RandomPazymys()
{
	return rand()%10+1;
}

vector<int>RandomPazymiai(int pazsk)
{
	vector<int>skaiciai;
	for (int i=0;i<pazsk;i++)
	{
		skaiciai.push_back(RandomPazymys());
	}
	return skaiciai;
}

float GalutSkaiciavimas(vector<int>skaiciai)
{
	studentas st;
	st.galutinis=0.4*accumulate(skaiciai.begin(), skaiciai.end(),0)/skaiciai.size()+0.6*RandomPazymys();
	return st.galutinis;
}

int PazymiuGeneravimas(vector<int>pazymiai)
{
	int n,m;
	cout<<"iveskite skaiciu, kiek norite sugeneruoti studentu: \n";
	cin>>n;//studentu skaicius
	cout<<"iveskite pazymiu skaiciu kiekvienam studentui: \n";
	cin>>m;//Pazymiu skaicius
	string failopav = "Studentai_" + to_string(n)+".txt";
	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	ofstream out_data(failopav);
	vector<int>skaiciai;
	out_data<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid.)"<<endl;

	for (int i=1;i<=n;i++)
	{
		skaiciai=RandomPazymiai(m);
		out_data<<setw(20)<<"Vardas"+to_string(i)<<setw(20)<<"Pavarde"+to_string(i)<<setw(20)<<GalutSkaiciavimas(skaiciai)<<endl;
		skaiciai.clear();
	}

	auto end=chrono::high_resolution_clock::now();
	chrono::duration<double>diff = end-start;
	cout<<"Failo su "+to_string(n)+" studentu sukurimas uztruko: "<<diff.count()<<" s\n";
	return n;
}

void SkaitymasIsFailo(list<studentas>& eilute,int n)
{
	int m=0; //Kyla iki studentu skaiciaus
	ifstream f;
	string failopav = "Studentai_"+to_string(n)+".txt";
	string buff;
	f.open(failopav);
	if (f.is_open())
    {
		auto start = chrono::high_resolution_clock::now();
		auto st = start;
		getline(f>>std::ws, buff);
		while(m<n)
		{
		    studentas stud;
			f>>stud.vardas;
			f>>stud.pavarde;
			f>>stud.galutinis;
			eilute.push_back(stud);
			m++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double>diff = end-start;
		cout<<"Failo su "+to_string(n)+" studentu nuskaitymas uztruko: "<<diff.count()<<" s\n";
	}
}

studentas get(list<studentas> _list, int _i)
{
    list<studentas>::iterator it=_list.begin();
    for(int i=0;i<_i;i++)
    {
        ++it;
    }
    return *it;
}

int main()

{
    srand(time(NULL));
	vector<int>skaiciai;
	int n = PazymiuGeneravimas(skaiciai);
	list<studentas>students;
	SkaitymasIsFailo(students,n);
	list<studentas>protingi;
	list<studentas>vargseliai;
	int vargs=0;
	int prot=0;
	float riba=5.00;

	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	for (int i=0;i<n;i++)
    {
		if (get(students,i).galutinis < riba)
		{
			vargseliai.push_back(get(students,i));
			vargs++;
		}
	}

	for (int i=0;i<n;i++)
    {
		if (get(students,i).galutinis >= riba)
		{
			protingi.push_back(get(students,i));
			prot++;
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout<<"Failo rusiavimas su "+to_string(n)+" studentu i dvi kategorijas uztruko: "<<diff.count()<<" s\n";
	string failopav;
	failopav = "Vargseliai_"+to_string(vargs)+".txt";
	ofstream vargs_failas(failopav);
	auto start1 = chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i=0;i<n;i++)
    {
		if (get(students,i).galutinis < riba)
        {
			vargs_failas<<get(students,i).vardas<<setw(20)<<get(students,i).pavarde<<setw(18)<<get(students,i).galutinis<<endl;
		}
	}
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff1 = end1 - start1;
	cout<<"Failo isvedimas su "+to_string(vargs)+" studentu i vargselius uztruko: "<<diff1.count()<<" s\n";
	failopav = "Protingi_" + to_string(prot) + ".txt";
	ofstream prot_failas(failopav);
	auto start2= chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int i=0;i<n;i++)
    {
		if (get(students,i).galutinis >= riba)
		{
			prot_failas<<get(students,i).vardas<<setw(20)<<get(students,i).pavarde<<setw(18)<<std::setprecision(2)<<get(students,i).galutinis<<endl;
		}
	}
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout<<"Failo isvedimas su "+to_string(prot)+" studentu i protingus uztruko: "<<diff2.count()<<" s\n\n";
}
