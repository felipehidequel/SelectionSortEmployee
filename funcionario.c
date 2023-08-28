#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct funcionario {
  char nome[31];
  char cargo[101];
  int documento;
};


Funcionario *func_cria(char* nome, char* cargo, int documento) {
    Funcionario * funcionario = (Funcionario*)malloc(sizeof(funcionario));
    if (funcionario == NULL){
        printf("Sem memória!");
        exit(1);
    }
    strcpy(funcionario->nome[31], nome);
    strcpy(funcionario->cargo[101], cargo);
    funcionario->documento = documento;
    return funcionario; 
}


Funcionario *func_libera(Funcionario* func) {
    free(func);
}


int func_compara(char* nome1, char* nome2) {
  int tamanho;
  
}

void func_ordena(Funcionario** func, int count) {
  int i, primeiroID, j;
  Funcionario* valor_teste;

  /*  
    a função irá buscar pelo elemento que deve vir primeiro,
    e posicioná-lo no índice atual, desconsiderando os índices
    anteriores, com os elementos já ordenados:
  */
  for (i = 0; i < count; i++) {
    
    valor_teste = func[i];  // reserva o valor do índice testado

    /*
      a busca vai guardar apenas o índice do funcionario que
      vem primeiro, seguindo a ordem alfabética:
    */
    primeiroID = i;
    for (j = i+1; j < count; j++) {
      if (func_compara(func[j]->nome, func[primeiroID]->nome)) {
        primeiroID = j;
      }
    }
    
    // traz o funcionário para o índice correto, caso ele já não esteja:
    if (primeiroID != i) {
      func[i] = func[primeiroID];
      func[primeiroID] = valor_teste;
    }
  }
}


void func_salva(Funcionario** func, FILE* fl) {
    FILE *saida;

    saida = fopen("saida.txt", "a");
    if (saida == NULL){
        printf("Não foi possivel abrir o arquivo de saida.\n");
        return 1;
    }

    fclose(saida);
    printf("Verifique o arquivo de saida!\n");
}