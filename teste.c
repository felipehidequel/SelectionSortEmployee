#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  char nome[21];
  int matricula;
} Aluno;

Aluno *alunos[10];

int main(void) {

  int i;
  for (i = 0; i < 5; i++) {
    alunos[i] = (Aluno*)malloc(sizeof(Aluno));
    scanf(" %20[^\n]", alunos[i]->nome);
    scanf("%d", &alunos[i]->matricula);
  }
  

  FILE* arquivo = fopen("arquivo.txt", "wt");
  if (arquivo == NULL) exit(1);
  else printf("Arquivo aberto com sucesso!");

  for (i = 0; i < 5; i++) {
    fprintf(arquivo, "%20s\t");
  }
  

  return 0;
}