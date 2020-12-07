#include "medicalAidMember.h"
using namespace std;
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <time.h>

int main()
{
    string firstName, lastName, name, depName;
    int medAidNr, nrDeps;

    ifstream fin;
    ofstream fout;

    fin.open("Staff.dat");
    if (fin.fail())
    {
        cout<<"File opening failed. Exiting program.";
        exit(1);
    }

    fout.open("MedicalAidData.dat");
    if(fout.fail())
    {
        cout<<endl<<"Output file opening failed. exiting program.";
        exit(1);
    }

    while(fin>>firstName>>lastName)
    {
        name=firstName+" "+lastName;
//        medAidNr=srand(1);

        MedicalAidMember member(name, medAidNr);

        cout<<endl<<member.getName()<<"'s medical number is "<<member.getNumber()<<"."<<endl;
        cout<<"How many dependents does this member have? ";
        cin>>nrDeps;
        member.setNrDeps(nrDeps);

        for(int i =0;i<nrDeps;i++)
        {
            cout<<endl<<"Enter name of dependent "<<i+1<<":";
            cin>>depName;
            member.addDependent(i,depName);
        }

        member.calcContribution();

        fout<<member;
    }

    fin.close();
    fout.close();
}
