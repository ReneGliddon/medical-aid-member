#ifndef MEDICALAIDMEMBER_H
#define MEDICALAIDMEMBER_H
using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>

class MedicalAidMember
{
public:
    MedicalAidMember();
    MedicalAidMember(string nameP, int numberP);
    ~MedicalAidMember();

    string getName() const;
    int getNumber() const;
    void setNrDeps(int nrDeps);

    void addDependent(int i, const string dependent);
    void calcContribution();

    friend ostream &operator<<(ostream &outs, MedicalAidMember ma);
private:
    string name;
    int number;
    int nrDependents;
    string dependents[6];
    double contribution;
};

#endif

MedicalAidMember::MedicalAidMember()
{
    name = "";
    number = 0;
    nrDependents =0;
    contribution =0;
    for (int i = 0; i<6; i++)
    {
        dependents[i] = "";
    }
}
MedicalAidMember::MedicalAidMember(string nameP, int numberP)
{
    name=nameP;
    number=numberP;
    nrDependents=0;
    contribution=1000;
    for (int i = 0; i<6;i++)
    {
        dependents[i]="";
    }
}

  MedicalAidMember::~MedicalAidMember()
  {
      //does nothing
  }


string MedicalAidMember::getName() const
    {
        return name;
    }

int MedicalAidMember::getNumber() const
    {
        return number;
    }
void MedicalAidMember::setNrDeps(int nrDepsP)
{
    nrDependents = nrDepsP;
}

void MedicalAidMember::addDependent(int i, const string dependent)
    {
       dependents[i]=dependent;
    }

void MedicalAidMember::calcContribution()
{
    contribution+=nrDependents*150.55;
}

ostream &operator<<(ostream &outs, MedicalAidMember ma)
{
    outs<<ma.name<<endl<<ma.number<<endl<<ma.nrDependents<<endl;
    for(int i = 0; i <ma.nrDependents;i++)
    {
        outs<<ma.dependents[i]<<endl;
    }
    outs<<ma.contribution;
}

