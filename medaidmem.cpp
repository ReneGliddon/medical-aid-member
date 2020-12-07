#include "medaidmem.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    medAidData ma;
    string firstName, lastName, name, depName;
    int medAidNr, nrDep;

    ostream fout;
    ifstream fin;

    fin.open("staff.dat");

    if(fin.fail())
    {
        cout<<endl<<"Error opening failed.";
        exit(1);
    }

    fin.open("MedicalAidData.dat");

    if(fin.fail())
    {
       cout<<endl<<"Error opening failed.";
        exit(1);
    }

    srand(time(0)); //seed random number

    while(fin>>firstName, fin>>lastName)
    {
        name = firstName+' '+lastName; //create name
        medAidNr = rand();
        medAidData ma(name,medAidNr);

        cout<<endl<<ma.getName()<<"'s medical aid number is "<<ma.getNum();
        cout<<endl<<"How many dependent's does this member have? ";
        cin>>nrDep;

        for(int i = 0; i<nrDep; i++)
        {
            cout<<"Enter the name of dependent:  ";
            cin>>depName;
            ma.addDep(i, depName);
        }

        ma.calcContrib(nrDep);
        fout<<ma<<endl;

    }
    fin.close();
    fin.close();
}
