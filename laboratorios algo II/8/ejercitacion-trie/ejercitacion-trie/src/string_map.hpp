template <typename T>
string_map<T>::string_map():_size(0),raiz(nullptr){
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.



template<class T>
typename string_map<T>::Nodo* string_map<T>::copiarEstructura(string_map<T>::Nodo* n)const{
    if(n!= nullptr){
        Nodo* res = new Nodo();
        if (n->definicion != nullptr)
            res->definicion = new T(*n->definicion);
        if (nHijosDefinidos(n)==0)
            return res;

        for (int i = 0 ; i < 256 ; i++){
            if (n->siguientes[i] != nullptr){
                res->siguientes[i] = copiarEstructura(n->siguientes[i]);
            }
        }
        return res;

    } else return nullptr;

}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    this->raiz = copiarEstructura(d.raiz);
    this->_size = d._size;
    return *this;
}

template<class T>
void string_map<T>::borrarSignificados(Nodo *n) {
    if (n->definicion != nullptr){
        delete n->definicion;
        n->definicion = nullptr;
    }
    if (nHijosDefinidos(n)>0){
        for (int i = 0; i < n->siguientes.size() ; ++i) {
            if (n->siguientes[i]->definicion != nullptr)
                borrarSignificados(n->siguientes[i]);
        }
    }
}
template<class T>
void string_map<T>::borrarArbol(Nodo*& n){
    if (n!= nullptr){
        for (int i = 0; i < n->siguientes.size(); ++i) {
            if (n->siguientes[i]!= nullptr)
                borrarArbol(n->siguientes[i]);
        }
    if(n->definicion != nullptr){
        delete n->definicion;
        n->definicion = nullptr;
    }
        delete n;
        n = nullptr;
    }
}
template <typename T>
string_map<T>::~string_map(){
    //borrarSignificados(raiz);
    borrarArbol(raiz);
}
template<class T>
void string_map<T>::insertChar(Nodo*& n, char c){
    int code = int(c);
    if(n->siguientes[code]== nullptr){
        n->siguientes[code] = new Nodo();
        n->siguientes[code]->padre = n;
    }

}
template<class T>
void string_map<T>::insert(const pair<string, T> & nuevo) {
    if (raiz == nullptr){
        raiz = new Nodo();
    }
    Nodo* nIter = raiz;
    for (int i = 0; i < nuevo.first.size(); ++i){
        bool esUltimo =( i == nuevo.first.size()-1 );
        insertChar(nIter,nuevo.first[i]);
        int cod = int(nuevo.first[i]);
        nIter = nIter->siguientes[cod];

        if (esUltimo){
            if(nIter->definicion == nullptr)
                nIter->definicion = new T(nuevo.second);
            else{
                delete nIter->definicion;
                nIter->definicion = new T(nuevo.second);
            }
        }
    }
    _size++;
}
template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    bool res = true;
    Nodo* nIter = this->raiz;
    for (int i = 0; i < clave.size() && res == true; ++i) {
        int code = int(clave[i]);
        if(nIter == nullptr || nIter->siguientes[code]==nullptr)
            res = false;
        else
            nIter = nIter->siguientes[code];
    }
    res = res && nIter->definicion!=nullptr;
    return res;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo*& actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        int code = int(clave[i]);
        actual = actual->siguientes[code];
    }
    const T& res = actual->definicion;
    return res;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = this->raiz;
    for (int i = 0; i < clave.size(); ++i) {
        int code = int(clave[i]);
        actual = actual->siguientes[code];
    }
    return *actual->definicion;
}

template<class T>
const int string_map<T>::nHijosDefinidos(Nodo* n) const{
    int res = 0;
    for (int i = 0; i < n->siguientes.size(); ++i) {
        res = res + (n->siguientes[i] != nullptr);
    }
    return res;
}

template<class T>
void string_map<T>::borrarResiduos(string_map<T>::Nodo* n){
    if (n != nullptr && n->padre== nullptr)
        return;
    if (n->definicion == nullptr && nHijosDefinidos(n)==0){
        borrarResiduos(n->padre);
        delete n;
        n= nullptr;
    }

}
template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
    Nodo* buscador = this->raiz;
    Nodo* ultimoNodo = nullptr;
    int ultimoIndice = 0;
    for (int i = 0; i < clave.size(); ++i) {
        int code = int(clave[i]);
        buscador = buscador->siguientes[code];
        if (nHijosDefinidos(buscador)>1 or (buscador->definicion != nullptr && i!=clave.size()-1)){
            ultimoNodo = buscador;
            ultimoIndice = i;
        }

    }
    delete buscador->definicion;
    buscador->definicion = nullptr;
    int indexAborrar = clave.size()-1;
    while (buscador!=ultimoNodo && indexAborrar > ultimoIndice){
        buscador = buscador->padre;
        delete buscador->siguientes[int(clave[indexAborrar])];
        buscador->siguientes[int(clave[indexAborrar])] = nullptr;
        indexAborrar--;
    }
    this->_size--;

}

template <typename T>
int string_map<T>::size() const{
    return this->_size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size==0;
}
