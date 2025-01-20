#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

void limpaTela(){
    system("CLS");
}

void imprimeEncadeada(pessoa *ponteiroEncadeada){

    pessoa *p = ponteiroEncadeada;

    while (p != NULL) {
        cout << p->nome << "," << p->rg << "\n";
        //atualiza o cursor
        p = p->proximo;
    }
}

int retornaTamanho(pessoa *ponteiroEncadeada){
    //tamanho da lista
    int tamanho = 0;

    pessoa *p = ponteiroEncadeada;
    while (p != NULL) {
        //atualiza o cursor
        p = p->proximo;

        //contador de tamanho aumenta
        tamanho++;
    }
    return tamanho;
}

void adcInicioEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    //cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = ponteiroEncadeada;

    //redireciona o ponteiro
    ponteiroEncadeada = novoValor;
}

void adcFimEncadeada (pessoa *&ponteiroEncadeada, string nome, int rg){
    //cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    while (p != NULL) {
        //quando chega no ultimo elemento, faz ele apontar para o novo valor
        if (p->proximo == NULL){
            p->proximo = novoValor;
            return;
        }
        p = p->proximo;
    }
}

void adcPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    //cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;

    //contador de posicoes
    int cont = 0;
    while (cont <= posicao) {

        if (cont == posicao - 1){
            //auxiliar do valor
            pessoa *aux = new pessoa;
            //armazena o proximo valor
            aux->proximo = p->proximo;
            //coloca o novo valor como o proximo dele
            p->proximo = novoValor;
            //faz com que o novo valor aponte para o proximo
            novoValor->proximo = aux->proximo;

            free(aux);
        }

        p = p->proximo;

        cont++;
    }
}

void removeInicioEncadeada(pessoa *&ponteiroEncadeada){
    if (ponteiroEncadeada == NULL){
        cout << "Lista vazia!!!\n";
    } else {
        //faz o ponteiro principal apontar para o proximo valor
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
}

void removeFimEncadeada(pessoa *&ponteiroEncadeada){

    //auxiliares
    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;
    //ponteiro cursor auxiliar
    p = ponteiroEncadeada;
    //passa pela lista
    while (p->proximo != NULL){
        //o auxiliar sempre fica sendo um antes do cursor
        aux = p;
        //passa o cursor para o proximo elemento
        p = p->proximo;
    }
    //muda o final da lista para o penultimo elemento
    aux->proximo = NULL;

}

void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while (cont <= posicao){
        if (cont == posicao - 1){
            //cria um auxiliar
            pessoa *aux = new pessoa;
            //auxiliar recebe o elemento que sera eliminado
            aux = p->proximo;
            //faz com que o proximo pule um elemento
            p->proximo = aux->proximo;

            free(aux);
        }
        //passa o cursor para o proximo elemento
        p = p->proximo;
        //registra uma movimentacao
        cont++;
    }

}

string retornaNomeEncadeada(pessoa *&ponteiroEncadeada, int rg) {
    string nome = "Nao encontrado";
    //ponteiro cursor auxiliar
    pessoa *p = ponteiroEncadeada;
    //passa pela lista
    while (p != NULL){
        if (p->rg == rg){
            nome = p->nome;
            return nome;
        }
        //passa o cursor para o proximo elemento
        p = p->proximo;
    }
    return nome;

}

int main() {

    int funcaoDesejada = 1;

    //cria o inicio da lista encadeada
    pessoa *ponteiroEncadeada = NULL;

    while (funcaoDesejada < 9 && funcaoDesejada >= 1){

        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista \n";
        cout << "2 - Insercao de um node no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";

        cin >> funcaoDesejada;

        limpaTela();

        string nome;
        int rg, posicao;

        switch(funcaoDesejada){
            case 1:
                cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista\n";

                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o rg: ";
                cin >> rg;

                adcInicioEncadeada(ponteiroEncadeada, nome, rg);
                break;
            case 2:
                cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista \n";

                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o rg: ";
                cin >> rg;

                if (retornaTamanho(ponteiroEncadeada) == 0) {
                    adcInicioEncadeada(ponteiroEncadeada, nome, rg);
                } else {
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }

                break;

            case 3:
                cout << "Funcao escolhida: 3 - Insercao de um node na posicao N \n";

                cout << "Digite a posicao: ";
                cin >> posicao;
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o rg: ";
                cin >> rg;

                if (posicao == 0) {
                    adcInicioEncadeada(ponteiroEncadeada, nome, rg);
                } else if (posicao == retornaTamanho(ponteiroEncadeada)-1){
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);
                } else {
                    adcPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);
                }
                break;

            case 4:
                cout << "Funcao escolhida: 4 - Retirar um node do inicio da lista \n";

                removeInicioEncadeada(ponteiroEncadeada);

                break;

            case 5:
                cout << "Funcao escolhida: 5 - Retirar um node no fim da lista \n";

                if (retornaTamanho(ponteiroEncadeada) <= 1){
                    removeInicioEncadeada(ponteiroEncadeada);
                } else {
                    removeFimEncadeada(ponteiroEncadeada);
                }

                break;

            case 6:
                cout << "Funcao escolhida: 6 - Retirar um node na posicao N \n";

                cout << "Digite a posicao: ";
                cin >> posicao;


                if (posicao <= 1){
                    removeInicioEncadeada(ponteiroEncadeada);
                } else if (posicao == retornaTamanho(ponteiroEncadeada)-1){
                    removeFimEncadeada(ponteiroEncadeada);
                } else {
                    removePosicaoEncadeada(ponteiroEncadeada, posicao);
                }
                break;

            case 7:
                cout << "Funcao escolhida: 7 - Procurar um node com o campo RG \n";

                cout << "Digite o rg: ";
                cin >> rg;

                cout << "O nome do rg (" << rg << ") eh: " << retornaNomeEncadeada(ponteiroEncadeada, rg) << "\n";

                break;

            case 8:
                cout << "Funcao escolhida: 8 - Imprimir a Lista. \n";
                cout << "Tamanho atual: " << retornaTamanho(ponteiroEncadeada) << "\n";
                if (retornaTamanho(ponteiroEncadeada) == 0){
                    cout << "Lista Vazia\n";
                } else {
                    imprimeEncadeada(ponteiroEncadeada);
                }
        }
    }
    return 0;
}
