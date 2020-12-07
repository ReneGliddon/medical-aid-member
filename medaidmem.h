#ifndef MEDAIDMEM_H
#define MEDAIDMEM_H
#include <string>
#include <cstdlib>
using namespace std;

class medAidData()
{
public:
    medAidData();
    medAidData(string name_p, int number_p, int nrDep_p, double contribution_p)
    ~medAidData();

    string getName() const;
    int getNum() const;
    void addDep(int p, const string dep);
    void calContrib();
    friend ostream & operator<<(ostream&out const, medAidData ma const);
private:
   string name;
   int number;
   int nrDep;
   string dep[6];
   double contribution;
};
#endif // MEDAIDMEM_H



#include"medaidmem.h"

//default constructor
medAidData::medAidData()
{
    name ="";
    number = 0;
    nrDep =0;
    contribution = 0;
    for (int i = 0; i<=dep.size(); i++)
    {
        dep[i]="";
    }
}

//overloaded constructor
medAidData::medAidData(string name_p, int number_p)
{
    name =name_p;
    number = number_p;
    nrDep =0;
    contribution = 1000;
    for (int i = 0; i<=dep.size(); i++)
    {
        dep[i]="";
    }
}

medAidData::~medAidData()
{

};

string medAidData::getName()
{
    return name;
}

int medAidData::getNum()
{
    return number;
}

void medAidData::addDep(i, depName)
{
     if (i<6)
        dep[i] = depName;
        nrDep++;
}

void medAidData::calcContrib()
{
    contribution += nrDep*150.55;
}

ostream &operator <<(ostream & out const, medAidData ma const)
{
    out<<getName()<<endl;
    out<<getNum()<<endl;
    for(int i =o; i <ma.nrDep; i++)
    {
        out<<ma.dep[i]<<endl;
    }
     out<<ma.contribution;

}
