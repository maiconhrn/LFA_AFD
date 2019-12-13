#include <iostream>
#include <fstream>
#include "afd.h"

using namespace std;

int main() {
    try {
        int n_estados, n_estados_finais, n_transicoes;
        string estado_nome, alfabeto, estado_inicial, de, para;
        char com;

        ifstream afdDescricao("afd.txt");

        AFD afd;

        // le estados
        afdDescricao >> n_estados;

        if (!afdDescricao.fail()) {
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
        } else {
            throw "Arquivo \"afd.txt\" no mesmo diretorio do executavel nao encontrado";
        }
    } catch (const char *e) {
        cout << e << endl;
    }
    return 0;
}