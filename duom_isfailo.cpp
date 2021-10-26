#pragma once

void Skaitymas (vector<studentas> & ST,int* ndsk)
{
    vector<string> vardai;
    int studentu_sk;
    int laikina;
    string k;
    ifstream f;
    try {
        f.open("kursiokai.txt");

        if(!f.is_open())
            throw 0;

        getline(f>>std::ws, k);
        *ndsk = skaiciukas(k) - 3;

        while(true)
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
    catch(int e)
    {
        cout<<"Neteisingai ivedete failo pavadinima arba jis neegzistuoja"<<endl;
    }
    //else {cout<<"-\n";}
    f.close();
}
