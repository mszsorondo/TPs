#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    if(s.size()>0) res.push_back(s[0]);
    for(int i : s){
        bool found = false;
        for (int j = 0; j<res.size() && !found; j++){
            if(res[j]==i){
                found = true;
            }
        }
        if(!found) res.push_back(i);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res;
    set<int> chequeador;
    for(int n : s){
        if(chequeador.count(n)==0){
            chequeador.insert(n);
            res.push_back(n);
        }
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;

    set<int> chequeadorBA;
    for(int n : a) chequeadorBA.insert(n);
    for(int k : b){
        if(chequeadorBA.count(k)==0) res=false;
    }

    set<int> chequeadorAB;
    for(int n : b) chequeadorAB.insert(n);
    for(int k : a){
        if(chequeadorAB.count(k)==0) res = false;
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;

    set<int> chequeadorBA;
    for(int n : a) chequeadorBA.insert(n);
    for(int k : b){
        if(chequeadorBA.count(k)==0) res=false;
    }

    set<int> chequeadorAB;
    for(int n : b) chequeadorAB.insert(n);
    for(int k : a){
        if(chequeadorAB.count(k)==0) res = false;
    }
    return res;

}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    for(int elem : s){
        res[elem]++;
    }

    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int,int> conteo = contar_apariciones(s);
    for(int k : s){
        if(conteo[k]==1) res.push_back(k);
    }

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int k : a){
        if(b.count(k)==1) res.insert(k);
    }


    return res;
}
set<LU> interseccionStr(set<LU> a, set<LU> b) {
    set<LU> res;
    for(LU k : a){
        if(b.count(k)==1) res.insert(k);
    }


    return res;
}


// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int,set<int>> res;
    for(int l : s){
        res[l%10].insert(l);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for(char letra : str){
        bool found = false;
        for(pair<char,char> traduccion : tr){
            if(traduccion.first==letra) {
                res.push_back(traduccion.second);
                found = true;
            }
        }
        if(!found) res.push_back(letra);
    }
    return res;
}

// Ejercicio 10

bool integrantes_repetidos(vector<Mail> s) {
    bool hayRepetidos = false;
    for(Mail mail1 : s){
        set<LU> libs1 = mail1.libretas();
        for(Mail mail2 : s){
            set<LU> libs2 = mail2.libretas();
            int numIguales = 0;
            for(LU lib : libs2){
                if(libs1.count(lib)==1) numIguales++;
            }
            bool condicion1 = (numIguales>0 && numIguales<libs1.size());
            bool condicion2 = (numIguales>0 && numIguales<libs2.size());
            if(condicion1 || condicion2) hayRepetidos = true;
        }
    }
    return hayRepetidos;
}


// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail mail : s){
        int fecha_res = res[mail.libretas()].fecha();
        int fecha_mail = mail.fecha();
        if(mail.adjunto()==true && (fecha_res<fecha_mail || res.count(mail.libretas())==0)){
            res[mail.libretas()] = mail;
        }
    }
    return res;
}
