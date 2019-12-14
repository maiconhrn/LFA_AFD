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
        vector<char> simbolos;

    Alfabeto();

    Alfabeto(const vector<char> &simbolos);
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
private:
    vector<Estado> estados;
    vector<Transicao> transicoes;
    Estado inicial;
    vector<Estado> final;
    Alfabeto alfabeto;

public:
    AFD();

    bool existe_estado(Estado estado);

    bool add_estado(Estado estado);

    bool faz_estado_inicial(string estado_nome);

    bool faz_estado_final(string estado_nome);

    Estado& achar_estado(string nome_estado);

    bool add_transicao(Transicao transicao);

    bool existe_transicao(Estado de, char com, Estado &para);

    bool validar_palavra(string palavra);

    bool add_simbolo_alfabeto(char simbolo);
};


#endif //AFD_AFD_H
