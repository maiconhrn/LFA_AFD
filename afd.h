//
// Created by Maicon on 16/11/2019.
//

#ifndef AFD_AFD_H
#define AFD_AFD_H

#include <string>
#include <vector>

using namespace std;

typedef enum {
    NENHUM,
    INICIAL,
    FINAL
} Estado_Tipo;

class Alfabeto {
public:
    int n_simbolos;
    vector<char> simbolos;

    Alfabeto();

    Alfabeto(int nSimbolos, const vector<char> &simbolos);
};

class Estado {
public:
    string nome;
    Estado_Tipo tipo;

    Estado();

    Estado(const string &nome, Estado_Tipo tipo);

    Estado(const string &nome);
};

class Transicao {
public:
    Estado de;
    char com;
    Estado para;

    Transicao();

    Transicao(const Estado &de, char com, const Estado &para);
};

class AFD {
public:
    int n_estados;
    vector<Estado> estados;
    Alfabeto alfabeto;
    int n_trasicoes;
    vector<Transicao> transicoes;
    Estado inicial;
    int n_final;
    vector<Estado> final;

    AFD();

    bool existe_transicao(Estado de, char com, Estado &para);

    bool validar_palavra(string palavra);
};


#endif //AFD_AFD_H
