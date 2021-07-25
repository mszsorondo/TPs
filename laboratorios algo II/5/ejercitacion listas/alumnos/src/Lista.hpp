#include "Lista.h"

Lista::Lista():_len(0),primero(nullptr),ultimo(nullptr){

}

Lista::Lista(const Lista& l) : Lista() {
    //InicialLista::Lista(const Lista& l) :iza una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    Nodo* temp = this->primero;
    while (temp != nullptr){
        Nodo* aux = temp->sig;
        delete temp;
        temp = aux;

    }
}



void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if(primero== nullptr){
        primero = nuevo;
        ultimo = nuevo;

    }
    else{
        nuevo->sig = primero;
        primero->ant = nuevo;

        primero = nuevo;
    }
    this->_len++;

}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if (primero== nullptr){
        primero = nuevo;
        ultimo = nuevo;
    }

    else{
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        ultimo = nuevo;
    }


    this->_len++;
}

int Lista::longitud() const {
    int res = 0;
    Nodo* temp = primero;
    while (temp != nullptr){
        res++;
        temp = temp->sig;
    }
    return res;
}

void Lista::eliminar(Nat i) {
    int act = 0;
    Nodo* ahora = this->primero;

    while (act != i){
        act++;
        ahora = ahora->sig;
    }
    if(act!=0 && act!=_len-1){
        ahora->sig->ant = ahora->ant;
        ahora->ant->sig = ahora->sig;
    }
    else if (act == 0){
        if(this->_len==1){
            primero = nullptr;
            ultimo = nullptr;
        }
        else{
            primero = primero->sig;
            if(primero != nullptr)
                primero->ant = nullptr;
        }


    }
    else{
        ultimo = ultimo->ant;
        if(ultimo!= nullptr)
            ultimo->sig = nullptr;
    }
    delete ahora;
    this->_len--;
}
Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    if(this->_len == 0){
        Nodo* temp = aCopiar.primero;
        while (temp->sig!= nullptr){
            this->agregarAtras(temp->valor);
            temp = temp->sig;
        }
        this->agregarAtras(temp->valor);
    }
    else{
        while(this->_len>0){
            this->eliminar(0);
        }
        Nodo* temp = aCopiar.primero;
        if(aCopiar._len>0){
            while (temp->sig!= nullptr){
                this->agregarAtras(temp->valor);
                temp = temp->sig;
            }
            this->agregarAtras(temp->valor);
        }

    }

    return *this;
}

const int& Lista::iesimo(Nat i) const {
    int act = 0;
    Nodo* temp = this->primero;
    while(act!=i){
        temp=temp->sig;
    }
    return temp->valor;
}

int& Lista::iesimo(Nat i) {
    int act = 0;
    Nodo* temp = this->primero;
    while(act!=i){
        temp=temp->sig;
        act++;
    }
    return temp->valor;
}

void Lista::mostrar(ostream& o) {
    Nodo* temp = this->primero;
    o<<'{';
    while(temp->sig!= nullptr){
        o<<(temp->valor)<<", ";
        temp = temp->sig;
    }
    o<<'}';


}
