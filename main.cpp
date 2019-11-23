#include <iostream>
#include "afd.h"

int main() {
    //Apenas TESTES depois aplicar leitura da descricao formal a partir de um arquivo txt

    cout << "Teste AFD" << endl;

    AFD afd;

    afd.alfabeto = Alfabeto(vector<char>('a', 'b'));

    Estado q0("q0", INICIAL);
    Estado q1("q1");
    Estado q2("q2");
    Estado q3("q3", FINAL);
    afd.add_estado(q0);
    afd.add_estado(q1);
    afd.add_estado(q2);
    afd.add_estado(q3);

    Transicao t0(q0, 'a', q1);
    Transicao t1(q1, 'a', q1);
    Transicao t2(q1, 'b', q2);
    Transicao t3(q2, 'b', q3);
    Transicao t4(q3, 'b', q2);
    afd.add_transicao(t0);
    afd.add_transicao(t1);
    afd.add_transicao(t2);
    afd.add_transicao(t3);
    afd.add_transicao(t4);

    cout << afd.validar_palavra("aaaaaaaabbbbbb") << endl;
    cout << afd.validar_palavra("aaaabbaaaabbbbbb") << endl;
    cout << afd.validar_palavra("aaaaaaaab") << endl;
    cout << afd.validar_palavra("") << endl;
    cout << afd.validar_palavra("aabbab") << endl;
    cout << afd.validar_palavra("bbbba") << endl;
    cout << afd.validar_palavra("abbbbbbbbbbbb") << endl;

    return 0;
}