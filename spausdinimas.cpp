#pragma once

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
