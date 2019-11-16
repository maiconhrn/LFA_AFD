//
// Created by Maicon on 16/11/2019.
//

#include "afd.h"

AFD::AFD() {
    n_estados = 0;
    estados = vector<Estado>();
    alfabeto = Alfabeto();
    n_trasicoes = 0;
    transicoes = vector<Transicao>();
    n_final = 0;
    final = vector<Estado>();
}

Alfabeto::Alfabeto() {
    n_simbolos = 0;
    simbolos = vector<char>();
}

Alfabeto::Alfabeto(int nSimbolos, const vector<char> &simbolos) : n_simbolos(nSimbolos), simbolos(simbolos) {}

Estado::Estado() {}

Estado::Estado(const string &nome) : nome(nome) {}

Estado::Estado(const string &nome, Estado_Tipo tipo) : nome(nome), tipo(tipo) {}

Transicao::Transicao() {}

Transicao::Transicao(const Estado &de, char com, const Estado &para) : de(de), com(com), para(para) {}

bool AFD::existe_transicao(Estado de, char com, Estado &para) {
    for (Transicao i : transicoes) {
        if (i.de.nome == de.nome && i.com == com) {
            para = i.para;

            return true;
        }
    }

    return false;
}

bool AFD::validar_palavra(string palavra) {
    Estado atual = inicial;
    Estado para;

    for (char i : palavra) {
        if (!existe_transicao(atual, i, para)) {
            return false;
        }

        atual = para;
    }

    return atual.tipo == FINAL;
}
