//
// Created by Maicon on 16/11/2019.
//

#include "afd.h"

AFD::AFD() {
    estados = vector<Estado>();
    alfabeto = Alfabeto();
    transicoes = vector<Transicao>();
    final = vector<Estado>();
}

Alfabeto::Alfabeto() {
    simbolos = vector<char>();
}

Alfabeto::Alfabeto(const vector<char> &simbolos) : simbolos(simbolos) {}

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

bool AFD::existe_estado(Estado estado) {
    for (Estado e : estados) {
        if (e.nome == estado.nome) {
            return true;
        }
    }

    return false;
}

bool AFD::add_estado(Estado estado) {

    if (!existe_estado(estado)) {
        estados.push_back(estado);

        switch (estado.tipo) {
            case INICIAL:
                inicial = estado;
                break;
            case FINAL:
                final.push_back(estado);
                break;
            case NENHUM:
                break;
        }

        return true;
    }

    return false;
}

bool AFD::add_transicao(Transicao transicao) {
    if (!existe_transicao(transicao.de, transicao.com, transicao.para)) {
        transicoes.push_back(transicao);

        return true;
    }

    return false;
}
