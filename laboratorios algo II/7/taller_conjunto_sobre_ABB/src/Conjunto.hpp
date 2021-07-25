
#include "Conjunto.h"

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    this->valor = v;
    this->izq = nullptr;
    this->der = nullptr;
}
template <class T>
Conjunto<T>::Conjunto() {
    cardin = 0;
    _raiz = nullptr;
}

template <class T>
void Conjunto<T>::destruir(Nodo* nod){
    if (nod!= nullptr){
        destruir(nod->der);
        destruir(nod->izq);
        delete nod;
        nod = nullptr;
    }
}
template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
    destruir(this->_raiz);
    this->_raiz = nullptr;

}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    bool res = false;
    Nodo* nIter = this->_raiz;
    while(nIter!= nullptr && res == false){
        if (nIter->valor==clave)
            res = true;
        else{
            if (clave>nIter->valor)
                nIter = nIter->der;
            else
                nIter = nIter->izq;
        }
    }
    return res;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    bool repetido = false;
    if(this->_raiz==nullptr){
        this->_raiz = new Nodo(clave);
    }else{
        Nodo* nIter = this->_raiz;
        bool insertado = false;
        while (!insertado){
            if (nIter->valor==clave){
                repetido = true;
                break;
            }

            if (clave>nIter->valor && nIter->der!= nullptr){
                nIter = nIter->der;
            }
            else if(clave<nIter->valor && nIter->izq!= nullptr)
                nIter = nIter->izq;
            else if (clave>nIter->valor && nIter->der == nullptr){
                nIter->der = new Nodo(clave);
                
                insertado = true;
            }
            else if (clave<nIter->valor && nIter->izq == nullptr) {
                nIter->izq = new Nodo(clave);
           
                insertado = true;
            }
            if(insertado)
                std::cout<< "Se inserto: "<< clave<<"\n";
        }

    }
    if(!repetido)
        this->cardin++;
}

template<class T>
int Conjunto<T>::nHijos(Nodo* nodo){
    return ((nodo->izq != nullptr) + (nodo->der != nullptr));
}

template<class T>//pre: el nodo es parte de arbol
typename Conjunto<T>::Nodo* Conjunto<T>::padre(const Nodo* h)const{
    Nodo* iter = this->_raiz;
    while (iter->izq!=h && iter->der!=h){
        if (iter->valor>h->valor){
            iter = iter->izq;
        }else
            iter=iter->der;

    }
    return iter;
}


template<class T>
typename Conjunto<T>::Nodo* Conjunto<T>::buscarPadre(const T& elem){
    Nodo* nIter = this->_raiz;
    Nodo* padre = this->_raiz;
    int i = 0;
    bool der;
    while (nIter->valor != elem){
            if(nIter->valor>elem){
                nIter = nIter->izq;
                der = false;
            }else{
                nIter = nIter->der;
                der = true;
            }
            if (i>0){
                if (der)
                    padre = padre->der;
                else
                    padre = padre->izq;
            }
            i++;
    }

    return padre;


}

template<class T>
typename Conjunto<T>::Nodo*& Conjunto<T>::predecesorInmediato(Nodo*& nodo){
    Nodo*& nIter = nodo->izq;
    while(nIter!= nullptr && nIter->der!= nullptr){
        nIter = nIter->der;
    }
    return nIter;
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo** padre = &(this->_raiz);
    while((*padre)->valor != clave){
        if(clave < (*padre)->valor)
            padre = &(*padre)->izq;
        else
            padre = &(*padre)->der;
    }
    if((*padre)->der != nullptr){
        const T sig = siguiente((*padre)->valor);
        remover(sig);
        (*padre)->valor = sig;
    }
    else{
        Nodo* aEliminar = *padre;
        this->cardin--;
        if((*padre)->izq != nullptr)
            *padre = (*padre)->izq;
        else
            *padre = nullptr;
        delete(aEliminar);
    }


}
/*
template<class T>
void Conjunto<T>::remover(const T& elem) {
    if (this->_raiz->valor==elem) {
        if (nHijos(this->_raiz)==0){
            delete this->_raiz;
            this->_raiz = nullptr;
        }
        else if(nHijos(this->_raiz)==1){
            if (this->_raiz->der==nullptr){
                Nodo*& hijo = this->_raiz->izq;
                delete this->_raiz;
                this->_raiz = hijo;
            }else{
                Nodo*& hijo = this->_raiz->der;
                delete this->_raiz;
                this->_raiz = hijo;
            }

        }
        else{
            Nodo* predInm = predecesorInmediato(this->_raiz);
            this->_raiz->valor = predInm->valor;
            delete predInm;
            predInm = nullptr;
        }
    }else{

        Nodo* padre = buscarPadre(elem);
        Nodo* aRem;
        bool der;
        if (padre->der->valor==elem){
            aRem = padre->der;
            der = true;
        }
        else{
            aRem = padre->izq;
            der = false;
        }

        if (nHijos(aRem)==0){
            delete aRem;
            aRem = nullptr;
        }
        else if(nHijos(aRem)==1){
            Nodo* hijoDeARem;
            if (aRem->der== nullptr)
                hijoDeARem = aRem->izq;
            else
                hijoDeARem = aRem->der;
            if (der){
                padre->der = hijoDeARem;
            }
            else
                padre->izq = hijoDeARem;
            delete aRem;
            aRem = nullptr;
        }else{
            Nodo*& predInm = predecesorInmediato(aRem);
            int copia = predInm->valor;
            aRem->valor = copia;
            delete predInm;
            predInm = nullptr;
        }

    }
    this->cardin--;
}
*/

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* nIter = this->_raiz;
    Nodo* res = buscarPadre(this->maximo())->der;
    while (nIter!= nullptr){
       if(nIter->valor>clave){
           if(nIter->valor < res->valor)
               res = nIter;
           nIter = nIter->izq;
       }
       else{
           nIter = nIter->der;
       }

    }
    return res->valor;

}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* nIter = _raiz;
    while (nIter->izq != nullptr){
        nIter = nIter->izq;
    }
    return nIter->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* nIter = _raiz;
    while (nIter->der != nullptr){
        nIter = nIter->der;
    }
    return nIter->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return this->cardin;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

