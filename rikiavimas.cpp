#pragma once

vector<float>Rikiavimas(int ndnr, vector<float>ND)
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
