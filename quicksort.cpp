#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]){
    int i;
    cout << "\n";
    for(i = 0; i < TAM; i++){
        cout << " |" << vetor[i] << "| ";
    }
}

void quick_sort(int vetor[TAM], int inicio, int fim){

    int pivo, esq, dir, meio, aux;
    //limites esquerda e direita
    esq = inicio;
    dir = fim;
    //ajustando auxiliares do centro
    meio = (int) ((esq + dir) / 2);
    pivo = vetor[meio];

    while (dir > esq){

        while (vetor[esq] < pivo){
            esq = esq + 1;
        }

        while (vetor[dir] > pivo){
            dir = dir - 1;
        }

        if (esq <= dir) {
            //realiza troca
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
            //faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;
        }
    }
    // recursao para continuar ordenando
    if (inicio < dir) {
        quick_sort(vetor, inicio, dir);
    }
    // recursao para continuar ordenando
    if (esq < fim){
        quick_sort(vetor, esq, fim);
    }
}

int main () {

    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    quick_sort(vetor, 0 , TAM-1);
    imprimeVetor(vetor);
    return 0;
}
