#include <iostream>
#include "afd.h"

int main() {
    //Apenas TESTES depois aplicar leitura da descricao formal a partir de um arquivo txt

    cout << "Teste AFD" << endl;

    AFD afd;

    afd.alfabeto = Alfabeto(2, vector<char>('a', 'b'));

    Estado q0("q0", INICIAL);
    Estado q1("q1");
    Estado q2("q2");
    Estado q3("q3", FINAL);
    afd.n_estados = 4;
    afd.estados.push_back(q0);
    afd.estados.push_back(q1);
    afd.estados.push_back(q2);
    afd.estados.push_back(q3);
    afd.inicial = q0;
    afd.n_final = 1;
    afd.final.push_back(q3);

    Transicao t0(q0, 'a', q1);
    Transicao t1(q1, 'a', q1);
    Transicao t2(q1, 'b', q2);
    Transicao t3(q2, 'b', q3);
    Transicao t4(q3, 'b', q2);
    afd.n_trasicoes = 5;
    afd.transicoes.push_back(t0);
    afd.transicoes.push_back(t1);
    afd.transicoes.push_back(t2);
    afd.transicoes.push_back(t3);
    afd.transicoes.push_back(t4);

    cout << afd.validar_palavra("aaaaaaaabbbbbb") << endl;
    cout << afd.validar_palavra("aaaabbaaaabbbbbb") << endl;
    cout << afd.validar_palavra("aaaaaaaab") << endl;
    cout << afd.validar_palavra("") << endl;
    cout << afd.validar_palavra("aabbab") << endl;
    cout << afd.validar_palavra("bbbba") << endl;
    cout << afd.validar_palavra("abbbbbbbbbbbb") << endl;

    return 0;
}