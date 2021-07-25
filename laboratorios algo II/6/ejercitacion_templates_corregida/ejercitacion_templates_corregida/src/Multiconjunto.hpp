#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();

    void agregar(T x);

    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T,int> _data;

};

template<class T>
Multiconjunto<T>::Multiconjunto() {}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if (_data.def(x))
        _data.definir(x,_data.obtener(x)+1);
    else
        _data.definir(x,1);
}
template<class T>
int Multiconjunto<T>::ocurrencias(T x) const{
    if (_data.def(x))
        return _data.obtener(x);
    else
        return 0;
}


/*
template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    bool res = true;
    for(int i = 0; i < _data._asociaciones.size() ; i++){
        res &= this->ocurrencias(_data._asociaciones[i]) <= otro.ocurrencias(_data._asociaciones[i]);
    }
    return res;
}
*/