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

#include "Using'ai.hpp"
#include "duom.h"
#include "duom_auto.h"
#include "mediana.h"
#include "skaiciukas.h"
#include "duom_isfailo.h"
#include "spausdinimas.h"
#include "spausdinimas2.h"



int main()
{
    int q,pazymiu_skaicius;
    char temp;
    vector<studentas> ST;

    cout<<"Iveskite 1, jei norite duomenis generuoti automatiskai, 2 - nuskaityti is failo"<<endl;
    cin>>q;
    if(q!=1&&q!=2) {cout<<"Ivedete netinkama skaiciu"<<endl; return 0;}
    if(q==1) Mainas();
    else if(q==2)
    {
        Skaitymas(ST,&pazymiu_skaicius);
        spausdinimas(ST,pazymiu_skaicius);
    }

    return 0;
}
