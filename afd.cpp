//
// Created by Maicon on 16/11/2019.
//

#include <iostream>
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
        if (existe_estado(transicao.de) && existe_estado(transicao.para)) {
            transicao.de = achar_estado(transicao.de.nome);
            transicao.para = achar_estado(transicao.para.nome);

            transicoes.push_back(transicao);

            return true;
        }

        throw "algum estado da transicao nao existe nos estados do AFD";
    }

    throw "transicao ja existente";
}

bool AFD::faz_estado_inicial(string estado_nome) {
    Estado estado(estado_nome);

    if (existe_estado(estado)) {
        Estado &e = achar_estado(estado_nome);
        e.tipo = INICIAL;
        inicial = e;

        return true;
    }

    throw "Estado definido como inicial não esta na lista de estados";
}

bool AFD::faz_estado_final(string estado_nome) {
    Estado estado(estado_nome);

    if (existe_estado(estado)) {
        Estado &e = achar_estado(estado_nome);
        e.tipo = FINAL;
        final.push_back(e);

        if (inicial.nome == e.nome) {
            inicial = e;
        }

        return true;
    }

    throw "Estado definido como final não esta na lista de estados";
}

Estado &AFD::achar_estado(string nome_estado) {
    for (Estado &e : estados) {
        if (e.nome == nome_estado) {
            return e;
        }
    }

    throw "Estado não encontrado";
}

bool AFD::add_simbolo_alfabeto(char simbolo) {
    alfabeto.simbolos.push_back(simbolo);

    return true;
}
