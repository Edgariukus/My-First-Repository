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
	int n;
	cout<<"iveskite skaiciu, kiek norite sugeneruoti studentu: \n";
	cin>>n;//studentu skaicius
	string failopav = "Studentai_" + to_string(n)+".txt";
	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	ofstream out_data(failopav);
	vector<int>skaiciai;
	out_data<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid.)"<<endl;

	for (int i=1;i<=n;i++)
	{
		skaiciai=RandomPazymiai(5);
		out_data<<setw(20)<<"Vardas"+to_string(i)<<setw(20)<<"Pavarde"+to_string(i)<<setw(20)<<GalutSkaiciavimas(skaiciai)<<endl;
		skaiciai.clear();
	}

	auto end=chrono::high_resolution_clock::now();
	chrono::duration<double>diff = end-start;
	cout<<"Failo su "+to_string(n)+" studentu sukurimas uztruko: "<<diff.count()<<" s\n";
	return n;
}

void SkaitymasIsFailo(vector<studentas>& stud,int n)
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
			stud.resize(stud.size()+1);
			f>>stud.at(m).vardas;
			f>>stud.at(m).pavarde;
			f>>stud.at(m).galutinis;
			m++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double>diff = end-start;
		cout<<"Failo su "+to_string(n)+" studentu nuskaitymas uztruko: "<<diff.count()<<" s\n";
	}
}

int main()

{
    srand(time(NULL));
	vector<int>skaiciai;
	int n = PazymiuGeneravimas(skaiciai);
	vector<studentas>students;
	SkaitymasIsFailo(students,n);
	vector<studentas>protingi;
	vector<studentas>vargseliai;
	int vargs=0;
	int prot=0;

	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	for (int i=0;i<n;i++)
    {
		float riba=5.00;
		if (students.at(i).galutinis < riba)
		{
			vargseliai.push_back(students.at(i));
			vargs++;
		}
	}

	for (int i=0;i<n;i++)
    {
		float riba = 5.00;
		if (students.at(i).galutinis >= riba)
		{
			protingi.push_back(students.at(i));
			prot++;
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout<<"Failo rusiavimas su "+to_string(n)+" studentu i dvi kategorijas uztruko: "<<diff.count()<<" s\n";
	string failopav;
	failopav = "Vargseliai_"+to_string(n)+".txt";
	ofstream vargs_failas(failopav);
	auto start1 = chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i=0;i<n;i++)
    {
		float riba = 5.00;
		if (students.at(i).galutinis < riba)
        {
			vargs_failas<<students.at(i).vardas<<setw(20)<<students.at(i).pavarde<<setw(18)<<students.at(i).galutinis<<endl;
		}
	}
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff1 = end1 - start1;
	cout<<"Failo isvedimas su "+to_string(n)+" studentu i vargselius uztruko: "<<diff1.count()<<" s\n";
	failopav = "Protingi_" + to_string(n) + ".txt";
	ofstream prot_failas(failopav);
	auto start2= chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int i=0;i<n;i++)
    {
		float riba = 5.00;
		if (students.at(i).galutinis >= riba)
		{
			prot_failas<<students.at(i).vardas<<setw(20)<<students.at(i).pavarde<<setw(18)<<students.at(i).galutinis<<endl;
		}
	}
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout<<"Failo isvedimas su "+to_string(n)+" studentu i protingus uztruko: "<<diff2.count()<<" s\n\n";
	//cout<<to_string(n)+" irasu testo laikas uztruko: "<<difas+diff.count()+diff1.count()+diff2.count()<<" s\n";
}
