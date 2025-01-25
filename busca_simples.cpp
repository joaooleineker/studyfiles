#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <new>
#define TAM 10
using namespace std;

int busca_simples (int vetor[TAM], int valorProcurado, int *posicaoEncontrada) {

    int cont;
    bool valorFoiEncontrado;

    for (cont = 0; cont < TAM; cont++){
        if (vetor[cont] == valorProcurado) {
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont;
        }
    }

    if (valorFoiEncontrado) {
        return 1;
    } else {
        return -1;
    }

}

int main () {

    int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
    int valorProcurado;
    int posicao, posicaoEncontrada;
    int cont;

    for (cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

    printf("\nQual numero deseja encontrar?");
    scanf("%d", &valorProcurado);

    if (busca_simples(vetor, valorProcurado, &posicaoEncontrada) == 1) {
        cout << "O valor foi encontrado na posicao: " << posicaoEncontrada;
    } else {
        cout << "O valor nao foi encontrado";
    }

    return 0;
}
