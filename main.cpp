#include <iostream>
#include <fstream>
#include "afd.h"

using namespace std;

int main() {
//    //Apenas TESTES depois aplicar leitura da descricao formal a partir de um arquivo txt
//
//    cout << "Teste AFD" << endl;
//
//    AFD afd;
//
//    afd.alfabeto = Alfabeto(vector<char>('a', 'b'));
//
//    Estado q0("q0", INICIAL);
//    Estado q1("q1");
//    Estado q2("q2");
//    Estado q3("q3", FINAL);
//    afd.add_estado(q0);
//    afd.add_estado(q1);
//    afd.add_estado(q2);
//    afd.add_estado(q3);
//
//    Transicao t0(q0, 'a', q1);
//    Transicao t1(q1, 'a', q1);
//    Transicao t2(q1, 'b', q2);
//    Transicao t3(q2, 'b', q3);
//    Transicao t4(q3, 'b', q2);
//    afd.add_transicao(t0);
//    afd.add_transicao(t1);
//    afd.add_transicao(t2);
//    afd.add_transicao(t3);
//    afd.add_transicao(t4);
//
//    cout << afd.validar_palavra("aaaaaaaabbbbbb") << endl;
//    cout << afd.validar_palavra("aaaabbaaaabbbbbb") << endl;
//    cout << afd.validar_palavra("aaaaaaaab") << endl;
//    cout << afd.validar_palavra("") << endl;
//    cout << afd.validar_palavra("aabbab") << endl;
//    cout << afd.validar_palavra("bbbba") << endl;
//    cout << afd.validar_palavra("abbbbbbbbbbbb") << endl;

    try {
        int n_estados, n_estados_finais, n_transicoes;
        string estado_nome, alfabeto, estado_inicial, de, para;
        char com;

        ifstream afdDescricao("afd.txt");

        AFD afd;

        // le estados
        afdDescricao >> n_estados;
        for (int i = 0; i < n_estados; ++i) {
            afdDescricao >> estado_nome;
            afd.add_estado(Estado(estado_nome));
        }

        // le alfabeto
        afdDescricao >> alfabeto;
        afd.alfabeto = Alfabeto(vector<char>(alfabeto.begin(), alfabeto.end()));

        // le estado inicial
        afdDescricao >> estado_inicial;
        afd.faz_estado_inicial(estado_inicial);

        // le estados finais
        afdDescricao >> n_estados_finais;
        for (int i = 0; i < n_estados_finais; ++i) {
            afdDescricao >> estado_nome;
            afd.faz_estado_final(estado_nome);
        }

        // le transicoes
        afdDescricao >> n_transicoes;
        for (int i = 0; i < n_transicoes; ++i) {
            afdDescricao >> de >> com >> para;
            afd.add_transicao(Transicao(de, com, para));
        }

        cout << "Arquivo \"afd.txt\" foi lido com sucesso" << endl;

        bool continuar = false;
        string palavra_a_validar;

        do {
            cout << "Digite uma palavra para ser validada: ";
            getline(cin, palavra_a_validar);

            cout << "A Palavra \"" << palavra_a_validar << "\" eh "
                 << (afd.validar_palavra(palavra_a_validar) ? "VALIDA" : "INVALIDA") << endl << endl;

            cout << "Deseja testar outra palavra? (0 == NAO, 1 == SIM): ";
            cin >> continuar;

            cin.ignore();
        } while (continuar);
    } catch (const char *e) {
        cout << e;
    }
    return 0;
}