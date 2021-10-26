#pragma once

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
