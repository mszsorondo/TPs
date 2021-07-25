#include "Templates.cpp"
template<class T1>
T1 doble(T1 num){
    return 2 * num;
}
template<class T1>
T1 cuadrado(T1 num){
    return num * num;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e){
    bool res = false;
    for(Elem el : c){
        if(el==e)
            res = true;
    }
    return res;
}
