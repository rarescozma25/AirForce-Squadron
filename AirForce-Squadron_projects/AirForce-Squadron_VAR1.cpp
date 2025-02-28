#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <string.h>
#include <cstdlib>
using namespace std;
class IOinterface{
public:
    virtual ostream& afisare(ostream&) const=0;
    virtual istream& citire(istream&)=0;

};
class Pilot{
private:
    string nume;
    char* taradeOrigine;
    long long cnp;
    int varsta;
    float anideExperienta;
    double rating;
public:
    Pilot(){ //constructor fara param
        nume="unknwon";
        taradeOrigine=new char[strlen("unknown")+1];
        cnp=0;
        varsta=0;
        anideExperienta=0;
        rating=0;
        }

    Pilot(string nume, char* taradeOrigine,long long cnp,int varsta, float anideExperienta, double rating){//constructor cu toti param
        this->nume=nume;
        this->taradeOrigine=new char[strlen(taradeOrigine)+1];
        strcpy(this->taradeOrigine,taradeOrigine);
        this->cnp=cnp;
        this->varsta=varsta;
        this->anideExperienta=anideExperienta;
        this->rating=rating;
        }

    Pilot(const Pilot &a){ //CC
        this->nume=a.nume;
        this->taradeOrigine=new char[strlen(a.taradeOrigine)+1];
        strcpy(this->taradeOrigine,a.taradeOrigine);
        this->cnp=a.cnp;
        this->varsta=a.varsta;
        this->anideExperienta=a.anideExperienta;
        this->rating=a.rating;
        }

    Pilot& operator=(const Pilot &a){ //Operator =
        if(this!=&a){
            if(this->taradeOrigine!=NULL)
                delete[]this->taradeOrigine;
        this->nume=a.nume;
        this->taradeOrigine=new char[strlen(a.taradeOrigine)+1];
        strcpy(this->taradeOrigine,a.taradeOrigine);
        this->cnp=a.cnp;
        this->varsta=a.varsta;
        this->anideExperienta=a.anideExperienta;
        this->rating=a.rating;
        }
        return *this;
        }

    friend ostream& operator<<(ostream& out,const Pilot &a){ //functia de afisare
        out<<"Numele este: "<<a.nume<<endl;
        out<<"Tara de origine este: "<<a.taradeOrigine<<endl;
        out<<"CNP-ul este: "<<a.cnp<<endl;
        out<<"Varsta este: "<<a.varsta<<endl;
        out<<"Pilotul are "<<a.anideExperienta<<" de experienta"<<endl;
        out<<"Ratingul pilotului este "<<a.rating<<endl;
        return out;
        }
    friend istream& operator>>(istream& in,Pilot &a){ //Functia de citire
        if(a.taradeOrigine!=NULL)
            delete[] a.taradeOrigine;
        cout<<"Citeste numele pilotului: "<<endl;
        in>>a.nume;
        cout<<"Citeste tara de origine a pilotului: "<<endl;
        char aux[100];
        in.get();
        in.getline(aux,99);
        a.taradeOrigine=new char[strlen(aux)+1];
        strcpy(a.taradeOrigine,aux);
        cout<<"Citeste CNP-ul pilotului: "<<endl;
        in>>a.cnp;
        cout<<"Citeste varsta pilotului: "<<endl;
        in>>a.varsta;
        cout<<"Citeste cati ani de experienta are pilotul: "<<endl;
        in>>a.anideExperienta;
        cout<<"Citeste ce rating are pilotul: "<<endl;
        in>>a.rating;
        return in;
        }

    string getNume() const{ //Getteri
        return nume;
        }

    const char* getTaradeOrigine()const{
        return taradeOrigine;
        }

    long long getCnp()const{return cnp;}

    int getVarsta()const{return varsta;}

    float getAnideexperienta()const{return anideExperienta;}

    double getRating()const{
        return rating;
        }

    ~Pilot(){ //destructor
        if(this->taradeOrigine!=NULL)
            delete[] this->taradeOrigine;
        }

    };

class Avion:public IOinterface{
protected:
    char* numeAvion;
    int anFabricatie;
    double anvergura;
    bool SuperSonic;
    vector<Pilot> pilot;
public:
    Avion(){ //constructor fara param
    numeAvion=new char[strlen("unknown")+1];
    anFabricatie=0;
    anvergura=0;
    SuperSonic=false;
    pilot={};
    }

    Avion(char* numeAvion,int anFabricatie,double anvergura,bool SuperSonic, vector<Pilot>pilot){ //constructor cu toti param
        this->numeAvion=new char[strlen(numeAvion)+1];
        strcpy(this->numeAvion,numeAvion);
        this->anFabricatie=anFabricatie;
        this->anvergura=anvergura;
        this->SuperSonic=SuperSonic;
        this->pilot=pilot;
        }

    Avion(const Avion &a){ //copy constructor
        this->numeAvion=new char[strlen(a.numeAvion)+1];
        strcpy(this->numeAvion,a.numeAvion);
        this->anFabricatie=a.anFabricatie;
        this->anvergura=a.anvergura;
        this->SuperSonic=a.SuperSonic;
        this->pilot=a.pilot;

        }

    Avion& operator=(const Avion &a){ //operatorul =
        if(this!=&a){
            if(this->numeAvion!=NULL)
                delete[] this->numeAvion;
            this->numeAvion=new char[strlen(a.numeAvion)+1];
            strcpy(this->numeAvion,a.numeAvion);
            this->anFabricatie=a.anFabricatie;
            this->anvergura=a.anvergura;
            this->SuperSonic=a.SuperSonic;
            this->pilot=a.pilot;
        }
        return *this;
        }

    friend ostream& operator<<(ostream& out,const Avion &a);
    friend istream& operator>>(istream& in, Avion &a);


    virtual float CalculeazaScorPiloti()=0;    //functii de calculat
    virtual void PiloticuRatingmaiMare()const=0;

    virtual ostream& afisare(ostream& out) const{ //functia de afisare
        out<<"Numele avionului este: "<<this->numeAvion<<endl;
        out<<"Anul de fabricatie al avionului este: "<<this->anFabricatie<<endl;
        out<<"Anvergura aripilor este de: "<<this->anvergura<<" m"<<endl;
        out<<"Este supersonic avionul? : ";
        if(this->SuperSonic==true)
            out<<"DA"<<endl;
        else
            out<<"NU"<<endl;
        int k;
        if(pilot.size()>0){
        cout<<"\nApasa 1 daca vrei sa vezi doar numele pilotilor sau 2 daca doresti toate detaliile pentru fiecare pilot in parte"<<endl;
        cin>>k;
        switch(k){
        case 1:{ //afisez doar numele pilotilor
            cout<<"\nNumele pilotilor este:\n";
            for(int i=0;i<this->pilot.size();i++)
                out<<this->pilot[i].getNume()<<" ";
            out<<endl;
            break;
            }
        case 2:{
            cout<<"\nDetalii despre piloti:\n"; //afisez toate detaliile despre piloti
            for(int i=0;i<this->pilot.size();i++){
        out<<"Numele este: "<<this->pilot[i].getNume()<<endl;
        out<<"Tara de origine este: "<<this->pilot[i].getTaradeOrigine()<<endl;
        out<<"CNP-ul este: "<<this->pilot[i].getCnp()<<endl;
        out<<"Varsta este: "<<this->pilot[i].getVarsta()<<endl;
        out<<"Pilotul are "<<this->pilot[i].getAnideexperienta()<<" de experienta"<<endl;
        out<<"Ratingul pilotului este "<<this->pilot[i].getRating()<<endl;
        out<<endl;

            }
        break;
            }
        default:
            cout<<"Numar invalid!"<<endl;
            }}
        return out;
        }
    virtual istream& citire(istream& in){ //citire
        if(this->numeAvion!=NULL)
            delete[] this->numeAvion;
        cout<<"\nNumele avionului este: ";
        char aux[100];
        in.get();
        in.getline(aux,99);
        this->numeAvion=new char[strlen(aux)+1];
        strcpy(this->numeAvion,aux);
        cout<<"Anul de fabricatie al avionului este: ";
        in>>this->anFabricatie;
        cout<<"Anvergura aripilor este: ";
        in>>this->anvergura;
        cout<<"Este supersonic: ";
        in>>this->SuperSonic;
        int comanda;
        int k=1;
        while(k==1)
        {
            cout<<"\nApasa 1 daca vrei sa adaugi un pilot pentru avion\n";
            cout<<"\nApasa 2 daca nu vrei sa adaugi un pilot pentru avion\n";
            in>>comanda;
            if(comanda==1)
            {
                Pilot a;
                in>>a;
                this->pilot.push_back(a);
            }
            else
            {
                k=0;
            }
        }
        return in;
        }
    ~Avion(){ //destructor
        if(this->numeAvion!=NULL)
            delete[] this->numeAvion;
        }

    };
    ostream& operator<<(ostream& out,const Avion &b)
{

    return b.afisare(out);

}
istream& operator>>(istream& in,Avion &b)
{

    return b.citire(in);

}
class AviondeVanatoare:public virtual Avion{
protected:
    int nrRachete;
    float razadeLupta;//km
    char* numeRacheta;
    double calibruTun;
    string numeBombe;
public:
    AviondeVanatoare():Avion(){ //constructor default.
        this->nrRachete=0;
        this->razadeLupta=0;
        this->numeRacheta=new char[strlen("unknown")+1];
        this->calibruTun=0;
        this->numeBombe="unknown";
        }

    AviondeVanatoare(char* numeAvion,int anFabricatie,double anvergura, bool SuperSonic,vector<Pilot>pilot,
                     int nrRachete,float razadeLupta,char*numeRacheta,double calibruTun,string numeBombe):Avion(numeAvion,anFabricatie,anvergura,SuperSonic,pilot)
                     {  //constructor cu toti param
                         this->nrRachete=nrRachete;
                         this->razadeLupta=razadeLupta;
                         this->numeRacheta=new char[strlen(numeRacheta)+1];
                         strcpy(this->numeRacheta,numeRacheta);
                         this->calibruTun=calibruTun;
                         this->numeBombe=numeBombe;
                     }

    AviondeVanatoare(const AviondeVanatoare& a):Avion(a){ //CC
        this->nrRachete=a.nrRachete;
        this->razadeLupta=a.razadeLupta;
        this->numeRacheta=new char[strlen(a.numeRacheta)+1];
        strcpy(this->numeRacheta,a.numeRacheta);
        this->calibruTun=a.calibruTun;
        this->numeBombe=a.numeBombe;

        }

    AviondeVanatoare& operator=(const AviondeVanatoare& a){ //operatorul =
        if(this!=&a){
            Avion::operator=(a);
            this->nrRachete=a.nrRachete;
            this->razadeLupta=a.razadeLupta;
            if(this->numeRacheta!=NULL)
                delete[] this->numeRacheta;
            this->numeRacheta=new char[strlen(a.numeRacheta)+1];
            strcpy(this->numeRacheta,a.numeRacheta);
            this->calibruTun=a.calibruTun;
            this->numeBombe=a.numeBombe;

        }
        return *this;
        }

    istream& citire(istream& in){ //citire
        this->Avion::citire(in);
        if(this->numeRacheta!=NULL)
            delete[]this->numeRacheta;
        cout<<"Numarul rachetelor este: ";
        in>>this->nrRachete;
        cout<<"Raza de lupta a avionului este de: ";
        in>>this->razadeLupta;
        cout<<"Numele rachetei pe care o utilizeaza avionul este: ";
        char aux[100];
        in.get();
        in.getline(aux,99);
        this->numeRacheta=new char[strlen(aux)+1];
        strcpy(this->numeRacheta,aux);
        cout<<"Calibrul tunului este: ";
        in>>this->calibruTun;
        cout<<"Numele bombelor este: ";
        in>>this->numeBombe;
        return in;
        }

    ostream& afisare(ostream& out)const{ //afisare
        this->Avion::afisare(out);
        out<<"Numarul rachetelor este: "<<this->nrRachete<<endl;
        out<<"Raza de lupta a avionului este de: "<<this->razadeLupta<<" km"<<endl;
        out<<"Numele rachetei pe care o utilieaza avionul este: "<<this->numeRacheta<<endl;
        out<<"Calibrul tunului este de: "<<this->calibruTun<<" mm"<<endl;
        out<<"Numele bombelor este: "<<this->numeBombe<<endl;
        if(typeid(*this)==typeid(AviondeVanatoare))
        out << "            \n"
                     "           \\    __    /\n"
                     "____________\\.-|__|-./____________\n"
                     "    + + ---\\__| \\/ |__/--- + +\n"
                     "               \\__/\n";
        return out;
        }

     float CalculeazaScorPiloti() //calculeaza scorul pilotilor in functie de niste criterii
     {
         float s=0;
         for(int i=0;i<this->pilot.size();i++){
            float nr=0;
            nr+=pilot[i].getAnideexperienta()*0.1;
            nr+=pilot[i].getRating()*0.5;
            int supervizorNota=rand()%10+1;
            nr+=supervizorNota*0.4;
            s+=nr;}
         return s;
     }

     void PiloticuRatingmaiMare()const{ //afiseaza pilotii cu rating-ul mai mare decat un nr citit de la tastatura
        cout<<"Introduceti scorul: ";
        float scor;
        cin>>scor;
        for(int i=0;i<this->pilot.size();i++){
            float scorpilot=pilot[i].getRating();
            if(scorpilot>scor)
                cout<<pilot[i];
        }}

     ~AviondeVanatoare(){ //destructor

        if(this->numeRacheta!=NULL)
            delete[]this->numeRacheta;
        }

    };
class AviondeRecunoastere:public virtual Avion{
protected:
    float vitezaMaxima;//km/h
    int autonomieZbor;//ore
    char* numeRadar;
    int razaRadar;//km
    float inaltimeMaxima;//m

public:
    AviondeRecunoastere():Avion(){ //constructor default
        this->vitezaMaxima=0;
        this->autonomieZbor=0;
        this->numeRadar=new char[strlen("unknown")+1];
        this->razaRadar=0;
        this->inaltimeMaxima=0;
        }

    AviondeRecunoastere(char* numeAvion,int anFabricatie,double anvergura,bool SuperSonic,vector<Pilot>pilot,
                        float vitezaMaxima,int autonomieZbor,char* numeRadar,int razaRadar,float inaltimeMaxima):Avion(numeAvion,anFabricatie,anvergura,SuperSonic,pilot){
                        this->vitezaMaxima=vitezaMaxima;
                        this->autonomieZbor=autonomieZbor;
                        this->numeRadar=new char[strlen(numeRadar)+1]; ///constructor cu toti param
                        strcpy(this->numeRadar,numeRadar);
                        this->razaRadar=razaRadar;
                        this->inaltimeMaxima=inaltimeMaxima;
                        }

    AviondeRecunoastere(const AviondeRecunoastere& a):Avion(a){ //CC
        this->vitezaMaxima=a.vitezaMaxima;
        this->autonomieZbor=a.autonomieZbor;
        this->numeRadar=new char[strlen(a.numeRadar)+1];
        strcpy(this->numeRadar,a.numeRadar);
        this->razaRadar=a.razaRadar;
        this->inaltimeMaxima=a.inaltimeMaxima;

        }

    AviondeRecunoastere& operator=(const AviondeRecunoastere& a){ //operator =
            if(this!=&a){
                Avion::operator=(a);
                this->vitezaMaxima=a.vitezaMaxima;
                this->autonomieZbor=a.autonomieZbor;
                if(this->numeRadar!=NULL)
                    delete[] this->numeRadar;
                this->numeRadar=new char[strlen(a.numeRadar)+1];
                strcpy(this->numeRadar,a.numeRadar);
                this->razaRadar=a.razaRadar;
                this->inaltimeMaxima=a.inaltimeMaxima;

            }
            return *this;
            }

    istream& citire(istream& in){ //citire
        this->Avion::citire(in);
        if(this->numeRadar!=NULL){
            delete[] this->numeRadar;
            this->numeRadar = NULL;}
        cout<<"Viteza maxima a avionului este: ";
        in>>this->vitezaMaxima;
        cout<<"Autonomia de zbor a avionului este: ";
        in>>this->autonomieZbor;
        cout<<"Numele radarului pe care il utilizeaza avionul este: ";
        char aux[100];
        in.get();
        in.getline(aux,99);
        this->numeRadar=new char[strlen(aux)+1];
        strcpy(this->numeRadar,aux);
        cout<<"Raza radarului este de: ";
        in>>this->razaRadar;
        cout<<"Inaltimea maxima la care poate zbura avionul este: ";
        in>>this->inaltimeMaxima;
        return in;
        }

        ostream& afisare(ostream& out)const{ //afisare
            this->Avion::afisare(out);
            out<<"Viteza maxima cu care poate zbura avionul este: "<<this->vitezaMaxima<<" km/h"<<endl;
            out<<"Autonomia de zbor a avionului este de: "<<this->autonomieZbor<<" ore"<<endl;
            out<<"Numele radarului utilizat de avion este: "<<this->numeRadar<<endl;
            out<<"Raza radarului este de: "<<this->razaRadar<<" km"<<endl;
            out<<"Inaltimea maxima la care poate zbura acest avion este: "<<this->inaltimeMaxima<<" m"<<endl;
            if(typeid(*this)==typeid(AviondeRecunoastere))
            out << "  _____  __\n"
                     " _______ | \\\n"
                     "_________|MK\\____________-====- --..._\n"
                     "           '-----------------.._____...-'\n";
            return out;
            }

        float CalculeazaScorPiloti() //calculeaza scorul pilotilor
     {
         float s=0;
         for(int i=0;i<this->pilot.size();i++){
            float nr=0;
            nr+=pilot[i].getAnideexperienta()*0.1;
            nr+=pilot[i].getRating()*0.5;
            int supervizorNota=rand()%10+1;
            nr+=supervizorNota*0.4;
            s+=nr;}
         return s;
     }

     void PiloticuRatingmaiMare()const{
        cout<<"Introduceti scorul: ";
        float scor;
        cin>>scor;
        for(int i=0;i<this->pilot.size();i++){
            float scorpilot=pilot[i].getRating();
            if(scorpilot>scor)
                cout<<pilot[i];
        }}

     ~AviondeRecunoastere(){

        if(this->numeRadar!=NULL)
            delete[]this->numeRadar;
        }
    };
class AvionMultirol:public AviondeVanatoare, public AviondeRecunoastere{
private:
    char* numedeCod;
    float climbingrate;
    int incarcaturaCombustibil;
    bool portavion;
public:
    AvionMultirol():Avion(),AviondeVanatoare(),AviondeRecunoastere(){ //constructor default
        this->numedeCod=new char[strlen("unknown")+1];
        this->climbingrate=0;
        this->incarcaturaCombustibil=0;
        this->portavion=false;
        }

    AvionMultirol(char* numeAvion, int anFabricatie, double anvergura, bool SuperSonic, vector<Pilot> pilot, //constructorul cu toti param
                             int nrRachete, float razadeLupta, char* numeRacheta, double calibruTun, string numeBombe,
                             float vitezaMaxima, int autonomieZbor, char* numeRadar, int razaRadar, float inaltimeMaxima,
                             char* numedeCod, float climbingrate, int incarcaturaCombustibil, bool portavion)
    : Avion(numeAvion, anFabricatie, anvergura, SuperSonic, pilot),
      AviondeVanatoare(numeAvion, anFabricatie, anvergura, SuperSonic, pilot, nrRachete, razadeLupta, numeRacheta, calibruTun, numeBombe),
      AviondeRecunoastere(numeAvion, anFabricatie, anvergura, SuperSonic, pilot, vitezaMaxima, autonomieZbor, numeRadar, razaRadar, inaltimeMaxima)
{
    this->numedeCod = new char[strlen(numedeCod) + 1];
    strcpy(this->numedeCod, numedeCod);
    this->climbingrate = climbingrate;
    this->incarcaturaCombustibil = incarcaturaCombustibil;
    this->portavion = portavion;
}

        AvionMultirol(const AvionMultirol& a):Avion(a),AviondeVanatoare(a),AviondeRecunoastere(a){ //CC
            this->numedeCod=new char[strlen(a.numedeCod)+1];
            strcpy(this->numedeCod,a.numedeCod);
            this->climbingrate=a.climbingrate;
            this->incarcaturaCombustibil=a.incarcaturaCombustibil;
            this->portavion=a.portavion;

                }
        AvionMultirol& operator=(const AvionMultirol& a){ //op =
                if(this!=&a){
                    Avion::operator=(a);
                    AviondeVanatoare:operator=(a);
                    AviondeRecunoastere:operator=(a);
                    if(this->numedeCod!=NULL)
                        delete[] this->numedeCod;
                    this->numedeCod=new char[strlen(a.numedeCod)+1];
                    strcpy(this->numedeCod,a.numedeCod);
                    this->climbingrate=a.climbingrate;
                    this->incarcaturaCombustibil=a.incarcaturaCombustibil;
                    this->portavion=a.portavion;
                }
                return *this;
                }

    istream& citire(istream& in){ //citire
        this->AviondeVanatoare::citire(in);
        if(this->numeRadar!=NULL){
            delete[] this->numeRadar;
            this->numeRadar = NULL;}
        cout<<"Viteza maxima a avionului este: ";
        in>>this->vitezaMaxima;
        cout<<"Autonomia de zbor a avionului este: ";
        in>>this->autonomieZbor;
        cout<<"Numele radarului pe care il utilizeaza avionul este: ";
        char aux[100];
        in.get();
        in.getline(aux,99);
        this->numeRadar=new char[strlen(aux)+1];
        strcpy(this->numeRadar,aux);
        cout<<"Raza radarului este de: ";
        in>>this->razaRadar;
        cout<<"Inaltimea maxima la care poate zbura avionul este: ";
        in>>this->inaltimeMaxima;
        if(this->numedeCod!=NULL)
            delete[] this->numedeCod;
        cout<<"Numele de cod: ";
        in.get();
        in.getline(aux,99);
        this->numedeCod=new char[strlen(aux)+1];
        strcpy(this->numedeCod,aux);
        cout<<"Climbing rate: ";
        in>>this->climbingrate;
        cout<<"Incarcatura combustibil: ";
        in>>this->incarcaturaCombustibil;
        cout<<"Poate fi folosit pe portavion: ";
        in>>this->portavion;
        return in;
        }

    ostream& afisare(ostream& out) const{ //afisare
        this->AviondeVanatoare::afisare(out);
        out<<"Viteza maxima cu care poate zbura avionul este: "<<this->vitezaMaxima<<" km/h"<<endl;
        out<<"Autonomia de zbor a avionului este de: "<<this->autonomieZbor<<" ore"<<endl;
        out<<"Numele radarului utilizat de avion este: "<<this->numeRadar<<endl;
        out<<"Raza radarului este de: "<<this->razaRadar<<" km"<<endl;
        out<<"Inaltimea maxima la care poate zbura acest avion este: "<<this->inaltimeMaxima<<" m"<<endl;
        out<<"\nNumele de cod al avionului este: "<<this->numedeCod<<endl;
        out<<"Climbing rate-ul avionului este de: "<<this->climbingrate<<endl;
        out<<"Avionul poate cara: "<<this->incarcaturaCombustibil<<" L de combustibil"<<endl;
        out<<"Poate fi folosit pe portavion: ";
        if(this->portavion==true)
            out<<"DA"<<endl;
        else
            out<<"NU"<<endl;
        out << "    ^\n"
                     "   | |\n"
                     "  ||0||\n"
                     " /  .  \\\n"
                     "|--| |--|\n"
                     "  /|||\\\n";
        return out;
        }

    float CalculeazaScorPiloti()
     {
         float s=0;
         for(int i=0;i<this->pilot.size();i++){
            float nr=0;
            nr+=pilot[i].getAnideexperienta()*0.1;
            nr+=pilot[i].getRating()*0.5;
            int supervizorNota=rand()%10+1;
            nr+=supervizorNota*0.4;
            s+=nr;}
         return s;
     }

     void PiloticuRatingmaiMare()const{
        cout<<"Introduceti scorul: ";
        float scor;
        cin>>scor;
        for(int i=0;i<this->pilot.size();i++){
            float scorpilot=pilot[i].getRating();
            if(scorpilot>scor)
                cout<<pilot[i];
        }}

     ~AvionMultirol(){
        if(this->numedeCod!=NULL)
            delete[]this->numedeCod;
     }

    };

int main()
{
    vector <Avion *> avioane;
    int k=0;
    while(k!=5){
        cout<<"Selectati o optiune:"<<endl;
        cout<<"1.Adaugati un obiect."<<endl;
        cout<<"2.Arati toate obiectele din vector"<<endl;
        cout<<"3.Stergeti un obiect"<<endl;
        cout<<"4.Update"<<endl;
        cout<<"5.Exit"<<endl;
        cout <<"Introduceti un numar:";
        cin>>k;
        switch(k){
            case 1:{ //adaugam avioane in vectori
                int x;
                cout<<"Selectati ce obiect vreti sa adaugati: "<< endl;
                cout<<"1.Avion de vanatoare "<<endl;
                cout<<"2.Avion de recunoastere "<<endl;
                cout<<"3.Avion multirol "<<endl;
                cin>>x;
                switch (x){
                    case 1:{
                        avioane.push_back(new AviondeVanatoare); //adaugam avioane de vanatoare
                        cin>>*avioane.back();
                        break;
                    }
                    case 2:{
                        avioane.push_back(new AviondeRecunoastere); //adaugam avioane de recunoastere
                        cin>>*avioane.back();
                        break;
                    }
                    case 3:{
                        avioane.push_back(new AvionMultirol); //adaugam avioane multirol
                        cin>>*avioane.back();
                        break;
                    }
                    default:
                        cout <<"Numar invalid"<<endl;
                }
                break;
            }
            case 2:{
                int k; //afisare
                cout<<"Selectati ce tip de obiecte vreti sa afisati: "<<endl;
                cout<<"1.Avioanele de vanatoare"<<endl;
                cout<<"2.Avioanele de recunoastere"<<endl;
                cout<<"3.Avioanele multirol"<<endl;
                cout<<"4.Toate avioanele existente, indiferent de tipul lor"<<endl;
                cin>>k;
                switch(k){
                    case 1:{
                        cout<<"Avioane de vanatoare: "<<endl; //afisam avioanele de vanatoare
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            cout<<*avioane[i];

                        break;
                        }
                    case 2:{
                        cout<<"Avioane de recunoastere: "<<endl; //afisam avioanele de recunoastere
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AviondeRecunoastere)==typeid(*avioane[i]))
                            cout<<*avioane[i];

                        break;
                        }

                    case 3:{
                        cout<<"Avioane multirol: "<<endl; //afisam avioanele multirol
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            cout<<*avioane[i];

                        break;
                    break;
                        }
                    case 4:{
                        cout<<"Avioane de vanatoare: "<<endl; //afisam toate avioanele
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AviondeVanatoare) == typeid(*avioane[i]))
                            cout<<*avioane[i];
                    cout<<"Avioane de recunoastere: "<<endl;
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AviondeRecunoastere) == typeid(*avioane[i]))
                            cout<<*avioane[i];
                    cout<<"Avioane multirol: "<<endl;
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(AvionMultirol) == typeid(*avioane[i]))
                            cout<<*avioane[i];
                    break;

                        }
                    default:
                        cout<<"Numar invalid"<<endl;
                }
                break;}
            case 3:{ //eliminam avioane in functie de scorul pilotilor, folosind functia CalculeazaScorPiloti
                int x;
                cout<<"Selectati ce fel de avion vreti sa stegeti in functie de scorul pilotilor: "<<endl;
                cout<<"1.Avioanele de vanatoare"<<endl;
                cout<<"2.Avioanele de recunoastere"<<endl;
                cout<<"3.Avioanele multirol"<<endl;
                cout<<"4.Toate avioanele existente, indiferent de tipul lor"<<endl;
                cin>>x;
                switch(x){
                    case 1:{
                    cout<<"Stergem avionele de vanatoare care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    int scor;
                    cout<<"Introduceti scorul: ";
                    cin>>scor;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                                cout<<"Deleting Avion de Vanatoare "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Vanatoare "<<i<<endl;
                            i++;}
                    break;
                        }
                    case 2:{
                    cout<<"Stergem avionele de recunoastere care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    int scor;
                    cout<<"Introduceti scorul: ";
                    cin>>scor;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeRecunoastere)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                            cout<<"Deleting Avion de Recunoastere "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Recunoastere "<<i<<endl;
                            i++;}
                    break;
                        }
                    case 3:{
                    cout<<"Stergem avionele multirol care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    int scor;
                    cout<<"Introduceti scorul: ";
                    cin>>scor;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                            cout<<"Deleting Avion Multirol "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion Multirol "<<i<<endl;
                            i++;}
                    break;

                        }
                    case 4:{
                    cout<<"Stergem avionele de vanatoare care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    int scor;
                    cout<<"Introduceti scorul: ";
                    cin>>scor;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                                cout<<"Deleting Avion de Vanatoare "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Vanatoare "<<i<<endl;
                            i++;}
                    cout<<"Stergem avionele de recunoastere care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    cout<<"Introduceti scorul: ";
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeRecunoastere)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                                cout<<"Deleting Avion de Recunoastere "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Recunoastere "<<i<<endl;
                            i++;}
                    cout<<"Stergem avionele multirol care au scorul pilotilor mai mic decat variabila 'scor'"<<endl;
                    cout<<"Introduceti scorul: ";
                    for(int i=0;i<avioane.size();)
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            if(avioane[i]->CalculeazaScorPiloti()<scor){
                                avioane.erase(avioane.begin()+i);
                                cout<<"Deleting Avion Multirol "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion Multirol "<<i<<endl;
                            i++;}
                    break;
                        }
                    default:
                        cout<<"Numar invalid"<<endl;
                    }
                break;
                }
            case 4:{ //actualizare
                int b;
                cout<<"Ce obiect doriti sa actualizati? "<<endl;
                cout<<"1.Avion de vanatoare"<<endl;
                cout<<"2.Avion de recunoastere"<<endl;
                cout<<"3.Avion multirol"<<endl;
                cin>>b;
                int i;
                switch(b){
                    case 1:{
                        cout<<"Introduceti indexul avionului de vanatoare pe care sa-l actualizam: "<<endl;
                        cin>>i;
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            if(i>=0&&i<avioane.size()){

                                avioane[i]=new AviondeVanatoare();
                                cin>>*avioane[i];
                        }
                            else cout<<"Index Invalid"<<endl;
                        else cout<<"Tipruile avioanelor nu sunt compatibile!"<<endl;
                        break;
                    }
                    case 2:{
                        cout<<"Introduceti indexul avionului de recunoastere pe care sa-l actualizam: "<<endl;
                        cin>>i;
                        if(typeid(AviondeRecunoastere)==typeid(*avioane[i]))
                            if(i>=0&&i<avioane.size()){

                                avioane[i]=new AviondeRecunoastere();
                                cin>>*avioane[i];
                        }
                            else cout<<"Index Invalid"<<endl;
                        else cout<<"Tipruile avioanelor nu sunt compatibile!"<<endl;
                        break;

                        }
                    case 3:{
                        cout<<"Introduceti indexul avionului multirol pe care sa-l actualizam: "<<endl;
                        cin>>i;
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            if(i>=0&&i<avioane.size()){
                                avioane[i]=new AvionMultirol();
                                cin>>*avioane[i];

                        }
                            else cout<<"Index Invalid"<<endl;
                        else cout<<"Tipruile avioanelor nu sunt compatibile!"<<endl;
                        break;

                        }
                    default:{
                        cout<<"Numar invalid"<<endl;
                        }
                    }
                }
                case 5:{ //iesire din meniu..
                cout<<"Exiting..."<<endl;
                break;}
                default:
                cout<<"Numar invalid"<<endl;

    }}
    return 0;
}
