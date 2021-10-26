#pragma once

float Mediana(std::vector<float>ND)
{
    sort (ND.begin(), ND.end());
    if (ND.size() % 2 != 0) {return ND[ND.size()/2];}
    else {return (double)(ND[(ND.size() - 1)/2]+ND[ND.size()/2])/2.0;}
}
