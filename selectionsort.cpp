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

void selection_sort (int vetor[TAM]) {

    int posicaoDoMenorValor, aux, i, j;

    for (i = 0; i < TAM; i++) {

        //recebe a posicao inicial para o menor valor
        posicaoDoMenorValor = i;

        //analisa os elementos na frente
        for (j = i + 1; j < TAM; j++){
            //caso encontre um valor menor na frente dos analisados
            if (vetor[j] < vetor[posicaoDoMenorValor]){
                posicaoDoMenorValor = j;

            }

        }
        //verifica se houve mudança e troca os valores
        if (posicaoDoMenorValor != i) {
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;

        }
    }

}

int main () {

    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    selection_sort(vetor);
    imprimeVetor(vetor);
    return 0;
}
