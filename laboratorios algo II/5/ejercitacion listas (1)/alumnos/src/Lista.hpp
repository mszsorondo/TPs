#include "Lista.h"

Lista::Lista() {
    this->prim_ = nullptr;
    this->ult_ = nullptr;
    this->longitud_ = 0;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    while (this->prim_!= nullptr){
        Nodo* aux = this->prim_;
        this->prim_=this->prim_->prox_;
        delete aux;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {

    if (this->longitud_>0){
        int k = 0;
        while (k<this->longitud_){
            this->eliminar(0);
        }
    }
    Nodo* current = aCopiar.prim_;
    //dilema: tengo que usar this para construir o tengo que hacer espacio con new?
    while (current != nullptr){
        this->agregarAtras(current->valor_);
        current = current->prox_;
    }

    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    this->longitud_++;
    Nodo* nuevo = new Nodo(elem);
    if (this->prim_ != nullptr && this->prim_ != this->ult_){
        this->prim_->anter_ = nuevo;
        nuevo->prox_ = this->prim_;
        this->prim_ = nuevo;
    } else if (this->prim_ != nullptr && this->prim_==this->ult_) {
        nuevo->prox_ = this->prim_;
        this->prim_->anter_ = nuevo;
        this->prim_ = this->prim_->anter_;

    } else {
        this->prim_ = nuevo;
        this->ult_ = nuevo;
    }
}

void Lista::agregarAtras(const int& elem) {
    this->longitud_++;
    Nodo* nuevo = new Nodo(elem);
    if (this->ult_ != nullptr && this->prim_ != this->ult_){
        this->ult_->prox_ = nuevo;
        nuevo->anter_ = this->ult_;
        this->ult_ = nuevo;
    } else if(this->prim_!= nullptr && this->prim_==this->ult_){
       this->prim_->prox_ = nuevo;
       nuevo->anter_ = this->prim_;
       this->ult_ = nuevo;
    }
    else{
        this->ult_ = nuevo;
        this->prim_ = nuevo;
    }
    // Completar
}

void Lista::eliminar(Nat i) {
    Nodo* current = this->prim_;
    int k = 0;
    if (i==0){
        Nodo* aux = this->prim_;
        this->prim_=this->prim_->prox_;
        if (this->longitud_>1){
            this->prim_->anter_ = nullptr;
        }
        else{
            this->ult_= nullptr;
        }
        delete aux;
        this->longitud_--;
        return;
    }
    else if(i==this->longitud_-1){
        Nodo* aux = this->ult_;
        this->ult_ = this->ult_->anter_;
        this->ult_->prox_ = nullptr;
        delete aux;
        this->longitud_--;
        return;
    }
    while (k<i){
        current = current->prox_;
        k++;
    }
    current->anter_->prox_ = current->prox_;
    current->prox_->anter_ = current->anter_;
    this->longitud_--;
}

int Lista::longitud() const {
    return this->longitud_;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* current = this->prim_;
    int k = 0;
    while(k<i){
        current = current->prox_;
        k++;
    }
    return current->valor_;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* current = this->prim_;
    int k = 0;
    while(k<i){
        current = current->prox_;
        k++;
    }
    return current->valor_;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
