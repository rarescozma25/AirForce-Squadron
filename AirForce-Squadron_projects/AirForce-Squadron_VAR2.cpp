#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <string.h>
#include <cstdlib>
#include <list>
#include <map>
#include <set>
using namespace std;
class IOinterface{
public:
    virtual ostream& afisare(ostream&) const=0;
    virtual istream& citire(istream&)=0;

};
class Avion:public IOinterface{
protected:
    string numeAvion;
    int anFabricatie;
    double anvergura;
    bool SuperSonic;
public:
    Avion(){ //constructor fara param
    numeAvion="unknown";
    anFabricatie=0;
    anvergura=0;
    SuperSonic=false;
    }

    Avion(string numeAvion,int anFabricatie,double anvergura,bool SuperSonic){ //constructor cu toti param
        this->numeAvion=numeAvion;
        this->anFabricatie=anFabricatie;
        this->anvergura=anvergura;
        this->SuperSonic=SuperSonic;
        }

    Avion(const Avion &a){ //copy constructor
        this->numeAvion=a.numeAvion;
        this->anFabricatie=a.anFabricatie;
        this->anvergura=a.anvergura;
        this->SuperSonic=a.SuperSonic;

        }

    Avion& operator=(const Avion &a){ //operatorul =
        if(this!=&a){
            this->numeAvion=a.numeAvion;
            this->anFabricatie=a.anFabricatie;
            this->anvergura=a.anvergura;
            this->SuperSonic=a.SuperSonic;
        }
        return *this;
        }
    bool operator>(const Avion&a){
        if(this->numeAvion>a.numeAvion && this->anFabricatie>a.anFabricatie && this->anvergura>a.anvergura)
            return true;
        else
            return false;
        }

    friend ostream& operator<<(ostream& out,const Avion &a);
    friend istream& operator>>(istream& in, Avion &a);
    virtual Avion operator+(const Avion& a){
        Avion rezultatFinal;
        rezultatFinal.numeAvion=this->numeAvion+a.numeAvion;
        rezultatFinal.anFabricatie=this->anFabricatie+a.anFabricatie;
        rezultatFinal.anvergura=this->anvergura+a.anvergura;
        rezultatFinal.SuperSonic=this->SuperSonic || a.SuperSonic;
        return rezultatFinal;
        }
    int getanFabricatie(){
        return this->anFabricatie;
    }
    bool getSupersonic(){
        return this->SuperSonic;
        }
    string getnumeAvion(){
        return this->numeAvion;
        }
    double getAnvergura()const{
        return this->anvergura;
        }
    ostream& afisare(ostream& out) const{ //functia de afisare
        out<<"Numele avionului este: "<<this->numeAvion<<endl;
        out<<"Anul de fabricatie al avionului este: "<<this->anFabricatie<<endl;
        out<<"Anvergura aripilor este de: "<<this->anvergura<<" m"<<endl;
        out<<"Este supersonic avionul? : ";
        if(this->SuperSonic==true)
            out<<"DA"<<endl;
        else
            out<<"NU"<<endl;

        return out;
        }
    istream& citire(istream& in){ //citire

        cout<<"\nNumele avionului este: ";
        in>>this->numeAvion;
        cout<<"Anul de fabricatie al avionului este: ";
        in>>this->anFabricatie;
        if(cin.fail())
            throw runtime_error("Eroare la anul de fabricatie");
        cout<<"Anvergura aripilor este: ";
        in>>this->anvergura;
        if(cin.fail())
            throw runtime_error("Eroare la anvergura");
        cout<<"Este supersonic: ";
        in>>this->SuperSonic;
        if(cin.fail())
            throw runtime_error("Eroare la supersonic");
        return in;

        }
    ~Avion()=default;
};
ostream& operator<<(ostream& out,const Avion &b)
{

    return b.afisare(out);

}
istream& operator>>(istream& in,Avion &b)
{

    return b.citire(in);

}
class AviondeVanatoare:public Avion{
protected:
    int nrRachete;
    float razadeLupta;//km
    string numeRacheta;
    double calibruTun;
    string numeBombe;
public:
    AviondeVanatoare():Avion(){ //constructor default.
        this->nrRachete=0;
        this->razadeLupta=0;
        this->numeRacheta="unknown";
        this->calibruTun=0;
        this->numeBombe="unknown";
        }

    AviondeVanatoare(string numeAvion,int anFabricatie,double anvergura, bool SuperSonic,
                     int nrRachete,float razadeLupta,string numeRacheta,double calibruTun,string numeBombe):Avion(numeAvion,anFabricatie,anvergura,SuperSonic)
                     {  //constructor cu toti param
                         this->nrRachete=nrRachete;
                         this->razadeLupta=razadeLupta;
                         this->numeRacheta=numeRacheta;
                         this->calibruTun=calibruTun;
                         this->numeBombe=numeBombe;
                     }

    AviondeVanatoare(const AviondeVanatoare& a):Avion(a){ //CC
        this->nrRachete=a.nrRachete;
        this->razadeLupta=a.razadeLupta;
        this->numeRacheta=a.numeRacheta;
        this->calibruTun=a.calibruTun;
        this->numeBombe=a.numeBombe;

        }

    AviondeVanatoare& operator=(const AviondeVanatoare& a){ //operatorul =
        if(this!=&a){
            Avion::operator=(a);
            this->nrRachete=a.nrRachete;
            this->razadeLupta=a.razadeLupta;
            this->numeRacheta=numeRacheta;
            this->calibruTun=a.calibruTun;
            this->numeBombe=a.numeBombe;

        }
        return *this;
        }
    bool operator>(const AviondeVanatoare&a){
        if(this->numeAvion>a.numeAvion && this->anFabricatie>a.anFabricatie && this->anvergura>a.anvergura &&
           this->nrRachete>a.nrRachete && this->razadeLupta > a.razadeLupta && this->numeRacheta>a.numeRacheta && this->calibruTun>a.calibruTun && this->numeBombe>a.numeBombe)
            return true;
        else
            return false;
        }
    AviondeVanatoare operator+(const AviondeVanatoare& a){
        AviondeVanatoare rezultatFinal;
        rezultatFinal.numeAvion=this->numeAvion+a.numeAvion;
        rezultatFinal.anFabricatie=this->anFabricatie+a.anFabricatie;
        rezultatFinal.anvergura=this->anvergura+a.anvergura;
        rezultatFinal.SuperSonic=this->SuperSonic || a.SuperSonic;
        rezultatFinal.nrRachete=this->nrRachete+a.nrRachete;
        rezultatFinal.razadeLupta=this->razadeLupta+a.razadeLupta;
        rezultatFinal.numeRacheta=this->numeRacheta+a.numeRacheta;
        rezultatFinal.calibruTun=this->calibruTun+a.calibruTun;
        rezultatFinal.numeBombe=this->numeBombe+a.numeBombe;
        return rezultatFinal;
        }

    istream& citire(istream& in){ //citire
        this->Avion::citire(in);
        cout<<"Numarul rachetelor este: ";
        in>>this->nrRachete;
        if(cin.fail())
            throw runtime_error("Eroare la nr de rachete!");
        cout<<"Raza de lupta a avionului este de: ";
        in>>this->razadeLupta;
        if(cin.fail())
            throw runtime_error("Eroare la raza de lupta!");
        cout<<"Numele rachetei pe care o utilizeaza avionul este: ";
        in>>this->numeRacheta;
        cout<<"Calibrul tunului este: ";
        in>>this->calibruTun;
        if(cin.fail())
            throw runtime_error("Eroare la calibrul tunului!");
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
       ~AviondeVanatoare()=default;
};
class AvionMultirol:public AviondeVanatoare{
private:
    string numedeCod;
    float climbingrate;
    int incarcaturaCombustibil;
    bool portavion;
public:
    AvionMultirol():AviondeVanatoare(){ //constructor default
        this->numedeCod="unknown";
        this->climbingrate=0;
        this->incarcaturaCombustibil=0;
        this->portavion=false;
        }

    AvionMultirol(string numeAvion,int anFabricatie, double anvergura,bool SuperSonic,int nrRachete, float razadeLupta, string numeRacheta, double calibruTun, string numeBombe,
              string numedeCod, float climbingrate, int incarcaturaCombustibil, bool portavion)
              : AviondeVanatoare(numeAvion, anFabricatie, anvergura, SuperSonic, nrRachete, razadeLupta, numeRacheta, calibruTun, numeBombe){
    this->numedeCod=numedeCod;
    this->climbingrate = climbingrate;
    this->incarcaturaCombustibil = incarcaturaCombustibil;
    this->portavion = portavion;
}

        AvionMultirol(const AvionMultirol& a):AviondeVanatoare(a){ //CC
            this->numedeCod=a.numedeCod;
            this->climbingrate=a.climbingrate;
            this->incarcaturaCombustibil=a.incarcaturaCombustibil;
            this->portavion=a.portavion;

                }
        AvionMultirol& operator=(const AvionMultirol& a){ //op =
                if(this!=&a){
                    AviondeVanatoare:operator=(a);
                    this->numedeCod=a.numedeCod;
                    this->climbingrate=a.climbingrate;
                    this->incarcaturaCombustibil=a.incarcaturaCombustibil;
                    this->portavion=a.portavion;
                }
                return *this;
                }
        AvionMultirol operator+(const AvionMultirol &a){

            AvionMultirol rezultatFinal;
            rezultatFinal.numeAvion=this->numeAvion+a.numeAvion;
            rezultatFinal.anFabricatie=this->anFabricatie+a.anFabricatie;
            rezultatFinal.anvergura=this->anvergura+a.anvergura;
            rezultatFinal.SuperSonic=this->SuperSonic || a.SuperSonic;
            rezultatFinal.nrRachete=this->nrRachete+a.nrRachete;
            rezultatFinal.razadeLupta=this->razadeLupta+a.razadeLupta;
            rezultatFinal.numeRacheta=this->numeRacheta+a.numeRacheta;
            rezultatFinal.calibruTun=this->calibruTun+a.calibruTun;
            rezultatFinal.numeBombe=this->numeBombe+a.numeBombe;
            rezultatFinal.numedeCod=this->numedeCod+a.numedeCod;
            rezultatFinal.climbingrate=this->climbingrate+a.climbingrate;
            rezultatFinal.incarcaturaCombustibil=this->incarcaturaCombustibil+a.incarcaturaCombustibil;
            rezultatFinal.portavion=this->portavion||a.portavion;
            return rezultatFinal;
            }
        bool operator>(const AvionMultirol&a){
        if(this->numeAvion>a.numeAvion && this->anFabricatie>a.anFabricatie && this->anvergura>a.anvergura &&
           this->nrRachete>a.nrRachete && this->razadeLupta > a.razadeLupta && this->numeRacheta>a.numeRacheta && this->calibruTun>a.calibruTun && this->numeBombe>a.numeBombe &&
           this->numedeCod>a.numedeCod && this->climbingrate>a.climbingrate && this->incarcaturaCombustibil>a.incarcaturaCombustibil && this->portavion>a.portavion)
            return true;
        else
            return false;
        }

    istream& citire(istream& in){ //citire
        this->AviondeVanatoare::citire(in);
        cout<<"Numele de cod: ";
        in>>this->numedeCod;
        cout<<"Climbing rate: ";
        in>>this->climbingrate;
        if(cin.fail())
            throw runtime_error("Eroare la climbing rate!");
        cout<<"Incarcatura combustibil: ";
        in>>this->incarcaturaCombustibil;
        if(cin.fail())
            throw runtime_error("Eroare la incarcatura combustibil!");
        cout<<"Poate fi folosit pe portavion: ";
        in>>this->portavion;
        if(cin.fail())
            throw runtime_error("Eroare la portavion!");
        return in;
        }

    ostream& afisare(ostream& out) const{ //afisare
        this->AviondeVanatoare::afisare(out);
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
    ~AvionMultirol()=default;
};
class Meniu{
private:
    static Meniu* instance;
    Meniu()=default;
    Meniu(const Meniu&a)=delete;

public:
    static Meniu* getInstance(){
        if(Meniu::instance != NULL)
            {
                return Meniu::instance;
            }
            else
            {
               instance=new Meniu();
               return instance;
            }
        }
    void getMeniu(){
        vector <Avion*> avioane;
        set<string> numeUnice;
        map<string,string> avionMap;

    int k=0;
    try{
    while(k!=5){

        cout<<"Selectati o optiune:"<<endl;
        cout<<"1.Adaugati un obiect."<<endl;
        cout<<"2.Arati toate obiectele din vector"<<endl;
        cout<<"3.Stergeti un obiect"<<endl;
        cout<<"4.Update"<<endl;
        cout<<"5.Exit"<<endl;
        cout <<"Introduceti un numar:";
        cin>>k;
        if(cin.fail())
            throw invalid_argument("INPUT INVALID. TREBUIE INTRODUS UN NUMAR!");

        switch(k){
            case 1:{ //adaugam avioane in vectori
                int x;
                cout<<"Selectati ce obiect vreti sa adaugati: "<< endl;
                cout<<"1.Avion "<<endl;
                cout<<"2.Avion de vanatoare "<<endl;
                cout<<"3.Avion multirol "<<endl;
                cin>>x;
                switch (x){
                    case 1:{
                        try{
                        avioane.push_back(new Avion); //adaugam avion simplu

                        cin>>*avioane.back();
                        if(cin.fail())
                            throw runtime_error("S-A PRODUS O EROARE LA CITIREA AVIONULUI!");
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(avioane.back()->getSupersonic())

                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica!"));

                        } catch(const bad_alloc &e){
                            cout<<"Eroare la alocarea memoriei";
                            }
                        break;

                    }
                    case 2:{
                        try{
                        avioane.push_back(new AviondeVanatoare); //adaugam avioane de vanatoare
                        cin>>*avioane.back();
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(avioane.back()->getSupersonic())

                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica!"));
                        } catch(const bad_alloc &e){
                            cout<<"Eroare la alocarea memoriei!";
                            }
                        break;
                    }
                    case 3:{
                        try{
                        avioane.push_back(new AvionMultirol); //adaugam avioane multirol
                        cin>>*avioane.back();
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(avioane.back()->getSupersonic())

                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica"));
                        } catch(const bad_alloc &e){
                            cout<<"Eroare la alocarea memoriei!";
                            }
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
                cout<<"1.Avion normal"<<endl;
                cout<<"2.Avioanele de vanatoare"<<endl;
                cout<<"3.Avioanele multirol"<<endl;
                cout<<"4.Toate avioanele existente, indiferent de tipul lor"<<endl;
                cin>>k;
                switch(k){
                    case 1:{
                        cout<<"Avioane normale: "<<endl; //afisam avioanele normale
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(Avion)==typeid(*avioane[i])){
                                cout<<*avioane[i]<<"Numele avionului normal din SET este: ";
                                auto it=numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul "<<it1->first<<" "<<it1->second<<endl<<endl;
                        }



                        break;
                        }
                    case 2:{
                        cout<<"Avioane de vanatoare: "<<endl; //afisam avioanele de vanatoare
                    for(int i=0;i<avioane.size();i++)
                        if(dynamic_cast<AviondeVanatoare*>(avioane[i])){
                            cout<<*dynamic_cast<AviondeVanatoare*>(avioane[i])<<"Numele avionului de vanatoare din SET este: ";
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul "<<it1->first<<" "<<it1->second<<endl<<endl;
                                }

                        break;
                        }

                    case 3:{
                        cout<<"Avioane multirol: "<<endl; //afisam avioanele multirol
                    for(int i=0;i<avioane.size();i++)
                        if(dynamic_cast<AvionMultirol*>(avioane[i])){
                            cout<<*dynamic_cast<AvionMultirol*>(avioane[i])<<"Numele avionului multirol din SET este: ";
                            auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul "<<it1->first<<" "<<it1->second<<endl<<endl;}

                    break;
                        }
                    case 4:{ //afisam toate avioanele
                        cout<<"Avioane normal: "<<endl; //afisam avioanele normale
                    for(int i=0;i<avioane.size();i++)
                        if(typeid(Avion)==typeid(*avioane[i])){
                            cout<<*avioane[i]<<"Numele avionului normal din SET este: ";
                            auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                    auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul "<<it1->first<<" "<<it1->second<<endl<<endl;}
                    cout<<"Avioane de vanatoare: "<<endl; //afisam avioanele de vanatoare
                    for(int i=0;i<avioane.size();i++)
                        if(dynamic_cast<AviondeVanatoare*>(avioane[i])){
                            cout<<*dynamic_cast<AviondeVanatoare*>(avioane[i])<<"Numele avionului de vanatoare din SET este: ";
                            auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul"<<it1->first<<" "<<it1->second<<endl<<endl;}

                    cout<<"Avioane multirol: "<<endl; //afisam avioanele multirol
                    for(int i=0;i<avioane.size();i++)
                        if(dynamic_cast<AvionMultirol*>(avioane[i])){
                            cout<<*dynamic_cast<AvionMultirol*>(avioane[i])<<"Numele avionului multirol din SET este: ";
                            auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    cout<<*it<<endl;
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                            auto it1=avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    cout<<"Avionul"<<it1->first<<" "<<it1->second<<endl<<endl;}
                    break;

                        }
                    default:
                        cout<<"Numar invalid"<<endl;
                }
                break;}
            case 3:{ //eliminam avioane in functie de anul lor de fabricatie
                int x;
                cout<<"Selectati ce fel de avion vreti sa stegeti in functie de anul de fabricatie: "<<endl;
                cout<<"1.Avioanele normal"<<endl;
                cout<<"2.Avioanele de vanatoare"<<endl;
                cout<<"3.Avioanele multirol"<<endl;
                cout<<"4.Toate avioanele existente, indiferent de tipul lor"<<endl;
                cin>>x;
                switch(x){
                    case 1:{
                    cout<<"Stergem avionele normale care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    int an;
                    cout<<"Introduceti anul: ";
                    cin>>an;
                    for(int i=0;i<avioane.size();)
                        if(typeid(Avion)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";

                                cout<<"Deleting Avion "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion "<<i<<endl;
                            i++;}
                    break;
                        }
                    case 2:{
                    cout<<"Stergem avionele de vanatoare care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    int an;
                    cout<<"Introduceti anul: ";
                    cin>>an;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";
                            cout<<"Deleting Avion de Vanatoare "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Vanatoare "<<i<<endl;
                            i++;}
                    break;
                        }
                    case 3:{
                    cout<<"Stergem avionele multirol care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    int an;
                    cout<<"Introduceti anul: ";
                    cin>>an;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";
                            cout<<"Deleting Avion Multirol "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion Multirol "<<i<<endl;
                            i++;}
                    break;

                        }
                    case 4:{
                    int an;
                    cout<<"Introduceti anul: ";
                    cin>>an;
                    cout<<"Stergem avionele normale care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    for(int i=0;i<avioane.size();)
                        if(typeid(Avion)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";
                                cout<<"Deleting Avion "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion "<<i<<endl;
                            i++;}
                    cout<<"Stergem avionele de vanatoare care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AviondeVanatoare)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";
                            cout<<"Deleting Avion de Vanatoare "<<i<<endl;}
                        else{
                            cout<<"Keeping Avion de Vanatoare "<<i<<endl;
                            i++;}
                    cout<<"Stergem avionele multirol care au anul de fabricatie mai mic decat variabila 'an'"<<endl;
                    for(int i=0;i<avioane.size();)
                        if(typeid(AvionMultirol)==typeid(*avioane[i]))
                            if(avioane[i]->getanFabricatie()<an){
                                avioane.erase(avioane.begin()+i);
                                auto it = numeUnice.find(avioane[i]->getnumeAvion());
                                if (it!=numeUnice.end())
                                    numeUnice.erase(it);
                                else
                                    cout<<"Numele nu a fost gasit in set.";
                                auto it1 = avionMap.find(avioane[i]->getnumeAvion());
                                if (it1!=avionMap.end())
                                    avionMap.erase(it1);
                                else
                                    cout<<"Avionul nu a fost gasit in dictionar.";
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
    try{
        int b;
        cout<<"Ce obiect doriti sa actualizati? "<<endl;
        cout<<"1.Avion normal"<<endl;
        cout<<"2.Avion de vanatoare"<<endl;
        cout<<"3.Avion multirol"<<endl;
        cin>>b;
        int i;
        switch(b){
            case 1:{
                cout<<"Introduceti indexul avionului normal pe care sa-l actualizam: "<<endl;
                cin>>i;
                if(i>=0 && i<avioane.size()) {
                    if(typeid(Avion)==typeid(*avioane[i])) {
                        auto it=numeUnice.find(avioane[i]->getnumeAvion());
                        auto it1=avionMap.find(avioane[i]->getnumeAvion());
                        avioane[i]=new Avion();
                        cin>>*avioane[i];
                        if (it!=numeUnice.end())
                            numeUnice.erase(it);
                        else
                            cout<<"Numele nu a fost gasit in set.";
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(it1!=avionMap.end())
                            avionMap.erase(it1);
                        else
                            cout<<"Avionul nu a fost gasit in dictionar!";
                        if(avioane.back()->getSupersonic())
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica"));
                    } else {
                        cout<<"Tipruile avioanelor nu sunt compatibile!"<<endl;
                    }
                } else {
                    throw out_of_range("INDEX INVALID! Introduceti un index valid.");
                }
                break;
            }
            case 2:{
                cout<<"Introduceti indexul avionului de vanatoare pe care sa-l actualizam: "<<endl;
                cin>>i;
                if(i>=0&&i<avioane.size()) {
                    if(typeid(AviondeVanatoare)==typeid(*avioane[i])) {
                        auto it=numeUnice.find(avioane[i]->getnumeAvion());
                        auto it1=avionMap.find(avioane[i]->getnumeAvion());
                        avioane[i]=new AviondeVanatoare();
                        cin>>*avioane[i];
                        if (it!=numeUnice.end())
                            numeUnice.erase(it);
                        else
                            cout<<"Numele nu a fost gasit in set.";
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(it1!=avionMap.end())
                            avionMap.erase(it1);
                        else
                            cout<<"Avionul nu a fost gasit in dictionar!";
                        if(avioane.back()->getSupersonic())
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica"));
                    } else {
                        cout<<"Tipurile avioanelor nu sunt compatibile!"<<endl;
                    }
                } else {
                    throw out_of_range("INDEX INVALID! Introduceti un index valid.");
                }
                break;
            }
            case 3:{
                cout<<"Introduceti indexul avionului multirol pe care sa-l actualizam: "<<endl;
                cin>>i;
                if(i>=0&&i<avioane.size()) {
                    if(typeid(AvionMultirol)==typeid(*avioane[i])) {
                        auto it=numeUnice.find(avioane[i]->getnumeAvion());
                        auto it1=avionMap.find(avioane[i]->getnumeAvion());
                        avioane[i]=new AvionMultirol();
                        cin>>*avioane[i];
                        if (it!=numeUnice.end())
                            numeUnice.erase(it);
                        else
                            cout<<"Numele nu a fost gasit in set.";
                        if(it1 != avionMap.end())
                            avionMap.erase(it1);
                        else
                            cout<<"Avionul nu a fost gasit in dictionar!";
                        numeUnice.insert(avioane.back()->getnumeAvion());
                        if(avioane.back()->getSupersonic())
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"poate atinge o viteza supersonica!"));
                        else
                            avionMap.insert(pair<string,string>(avioane.back()->getnumeAvion(),"nu poate atinge o viteza supersonica"));
                    } else {
                        cout<<"Tipurile avioanelor nu sunt compatibile!"<<endl;
                    }
                } else {
                    throw out_of_range("INDEX INVALID! Introduceti un index valid.");
                }
                break;
            }
            default:{
                cout<<"Numar invalid"<<endl;
            }
        }
    } catch(const out_of_range &e){
        cout<<"AM GASIT EROAREA: "<<e.what()<<endl;
        break;
    }

    break;
}

                case 5:{ //iesire din meniu..
                cout<<"Exiting..."<<endl;
                break;}
                default:
                cout<<"Numar invalid"<<endl;

    }} }
    catch(const invalid_argument &e){
        cout<<endl<<"AM GASIT EXCEPTIA "<<e.what();
        }
    catch(const runtime_error &a){
        cout<<endl<<"Eroarea este: "<<a.what();
                            }

        }


    void stergere(){
        if(instance!=NULL)
            delete[]instance;
        }

    };
template<class T, class T2>
T add(T a, T2 b) {
    return a+b;
}
template<class T>
class Aeroport{
private:
    string numeAeroport;
    list<T>avioane;
public:
    Aeroport()=default;
    Aeroport(string numeAeroport,list<T>avioane){
        this->numeAeroport=numeAeroport;
        this->avioane=avioane;
        }
    Aeroport(string numeAeroport){
        this->numeAeroport=numeAeroport;
        }
    Aeroport(const Aeroport &a){
        this->numeAeroport=a.numeAeroport;
        this->avioane=a.avioane;
        }
    Aeroport& operator=(const Aeroport &a){
        if(this!=&a){
        this->numeAeroport=a.numeAeroport;
        this->avioane=a.avioane;
        }
        return *this;
        }
    const list<T>& getAvioane(){
        return avioane;
    }
    void adaugaAvion(const T &a){
        try{
        if(typeid(T)==typeid(a))
            avioane.push_back(a);
        else
            throw runtime_error("AVIOANELE NU SUNT COMPATIBILE!");
        }catch(const runtime_error &e){
            cout<<endl<<"Am gasit exceptia: "<<e.what()<<endl;
            }
        }
    void stergeAvion(int i){
        try{
        if (i>=0&&i<=this->avioane.size()-1){
            auto it = avioane.begin();
            advance(it, i);
            avioane.erase(it);
        }
        else
            throw out_of_range("Index invalid!");
        } catch(const out_of_range &e)
        {
            cout<<endl<<"Am gasit exceptia: "<<e.what();
        }

        }
    void sorteazaElemente(){
        try{
        if(avioane.empty())
            throw runtime_error("NU AVEM CE ELEMENTE SA SORTAM!");

        else
            for(auto it1=avioane.begin();it1!=avioane.end();++it1)
                for (auto it2=next(it1);it2!=avioane.end();++it2)
                    if (*it1>*it2)
                        swap(*it1,*it2);
            }catch(const runtime_error &e){
                cout<<"Eroarea gasita este: "<<e.what()<<endl;
                }


                }
    void afiseazaAeroporturi(){
        try{
        cout<<endl<<"Numele aeroportului este: "<<this->numeAeroport<<endl;
        if(avioane.empty())
            throw runtime_error("NU SUNT AVIOANE IN AEROPORT!");
        else{
            cout<<"Avioanele din aeroport sunt: "<<endl<<endl;
            for(auto it1=avioane.begin();it1!=avioane.end();++it1)
                cout<<*it1<<endl;}
        }catch(const runtime_error &e){
                cout<<"Eroarea gasita este: "<<e.what()<<endl;
                }
        }
    const list<T>& getAvioane()const {
        return avioane;
    }


    ~Aeroport()=default;
        };
template <typename T>
float calculeazaMediaAnvergurii(const list<T>& avioane) {
    float sumaAnverguri=0;
    try{
    if (avioane.empty()){
        throw runtime_error("NU AVEM ELEMENTE IN AEROPORT CARORA SA LE APLICAM FUNCTIA!");
        return 0;
    }

    for(auto it1=avioane.begin();it1!=avioane.end();++it1) {
        sumaAnverguri+=it1->getAnvergura();
    }
    } catch(const runtime_error &a){
        cout<<"Eroarea gasita este: "<<a.what();
        }

    return sumaAnverguri/avioane.size();
}
Meniu* Meniu::instance=NULL;
int main()
{
    Meniu *a=Meniu::getInstance();
    a->getInstance();
    a->getMeniu();
    a->stergere();
    /*AvionMultirol a,b,c;
    cin>>a>>b;
    cout<<add(a,b);*/
    /*Aeroport<AvionMultirol> c("Henri Coanda");
    AvionMultirol a("smecher",444,150,1,500,1000,"rocket",44,"bombee","RAPTOR",133,1000,1);
    AvionMultirol b("amecher",344,50,1,300,400,"aocket",24,"aombee","EAPTOR",130,100,1);
    c.adaugaAvion(a);
    c.adaugaAvion(b);
    c.afiseazaAeroporturi();
    c.sorteazaElemente();
    c.afiseazaAeroporturi();
    cout<<endl<<calculeazaMediaAnvergurii(c.getAvioane());*/

return 0;
}
