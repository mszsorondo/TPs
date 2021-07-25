#include <iostream>
#include "list"
using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
using Mes = int;
using Dia = int;
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();
    bool operator<(Fecha f);
  private:
    int mes_;
    int dia_;
};
Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){
}
int Fecha::mes(){
    return this->mes_;
}
int Fecha::dia(){
    return this->dia_;
}
ostream& operator<<(ostream& os, Fecha f){
    os << f.dia()<<"/"<<f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    igual_dia &= this->mes()==o.mes();
    return igual_dia;
}
bool Fecha::operator<(Fecha f) {
    bool res;
    if(mes_<f.mes())
        res = true;
    else if(mes_==f.mes())
        res = this->dia_<f.dia();
    else res=false;
    return res;
}
#endif
void Fecha::incrementar_dia() {
    if(dias_en_mes(this->mes_)==dia_){
        this->dia_ = 1;
        this->mes_++;
    } else{
        dia_++;
    }
}
// Ejercicio 11, 12

// Clase Horario
class Horario{
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator<(Horario h);

    private:
        uint hora_;
        uint min_;
};
Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {}
uint Horario::hora() {
    return this->hora_;
}
uint Horario::min() {
    return this->min_;
}
ostream& operator<<(ostream& os, Horario h){
    os << h.hora()<<":"<<h.min();
    return os;
}
bool Horario::operator<(Horario h) {
    bool esIgual;

    if (h.hora()==hora_)
        esIgual = h.min()>min_;
    else
        esIgual = h.hora()>hora_;
    return esIgual;
}

// Ejercicio 13

// Clase Recordatorio
using Msj = string;
class Recordatorio{
    public:
        Recordatorio(Fecha f, Horario h, Msj msj);
        Fecha f();
        Horario ho();
        Msj msj();
        bool operator<(Recordatorio r);
    private:
        Fecha f_;
        Horario ho_;
        Msj msj_;
};
Recordatorio::Recordatorio(Fecha f, Horario h, Msj msj):f_(f),ho_(h),msj_(msj) {
}
bool Recordatorio::operator<(Recordatorio r){
    bool res;
    if(f_ < r.f()){
        res = true;
    } else if(f_ == r.f()){
        res =  ho_<r.ho();
    } else {
        res=false;
    }
    return res;
}
Fecha Recordatorio::f() {
    return this->f_;
}
Horario Recordatorio::ho() {
    return this->ho_;
}
Msj Recordatorio::msj() {
    return this->msj_;
}

ostream& operator<<(ostream& os, Recordatorio r){
    os<< r.msj()<<" @ " << r.f().dia() <<"/"<<r.f().mes() <<" "<< r.ho().hora()<<":"<<r.ho().min();
    return os;
}

// Ejercicio 14

// Clase Agenda
class Agenda{
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

    private:
        Fecha hoy_;
        list<Recordatorio> todos_;
};
Agenda::Agenda(Fecha fecha_inicial): hoy_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    this->todos_.push_back(rec);
}
list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> res;
    for(Recordatorio r : this->todos_){
        if(r.f()==hoy_)
            res.push_back(r);
    }
    res.sort();
    return res;
}
void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}
Fecha Agenda::hoy() {
    return this->hoy_;

}
ostream& operator<<(ostream& os, Agenda a){

    os << a.hoy().dia() <<"/"<< a.hoy().mes()<<"\n"<<"=====\n";

    for(Recordatorio r : a.recordatorios_de_hoy()){
        os << r <<"\n";
    };
    return os;
}