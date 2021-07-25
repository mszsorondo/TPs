#include "Proxy2.h"


Proxy::Proxy(ConexionJugador** conn) : _conn(conn) {}

void Proxy::enviarMensaje(string msg) {
    ConexionJugador* conn2 = *_conn;
    conn2 -> enviarMensaje(msg);
}
