#include "SistemaDeMensajes.h"
SistemaDeMensajes::SistemaDeMensajes() {
    for(int i = 0; i<4 ; i++){
        _conns[i] = nullptr;
    }
}
void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if (!registrado(id)){
        (_conns[id]) = new ConexionJugador(ip);
        // Recordemos que en new no solo se reserva el espacio del heap sino que tambien nos permite inicializar la variable a la que apunta el valor devuelto.

    }
    else{
        *_conns[id] = ConexionJugador(ip);
    }

}
string SistemaDeMensajes::ipJugador(int id) const {
    return (*_conns[id]).ip();
}
bool SistemaDeMensajes::registrado(int id) const {
    bool res = _conns[id] != nullptr;
    return res;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    (*_conns[id]).enviarMensaje(mensaje);
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        if (registrado(i))
            delete _conns[i];
            _conns[i] = nullptr;
    }
    for(Proxy* k:_proxy){
        delete k;
        k = nullptr;
    }
}
void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* res = new Proxy(_conns[id]);
    _proxy.push_back(res);
    return res;
}