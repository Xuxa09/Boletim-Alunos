#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define BIMESTRES 4
#define MAX_NOME 50

struct DadosAluno {
    float notas[BIMESTRES];
    char nome[MAX_NOME];
    float media;
    char situacao[10];
};

void ordenaPorMedia(struct DadosAluno alunos[], int n);

int main(void) {
    struct DadosAluno alunos[MAX_ALUNOS];
    int i, n = 0;
    float somaSala = 0;

    printf("Entre com a quantidade de alunos (max %d): ", MAX_ALUNOS);
    scanf("%d", &n);
    getchar();  // Limpa o buffer do teclado

    for (i = 0; i < n; i++) {
        printf("\nEntre com o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, MAX_NOME, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';  // Remove o newline

        float soma = 0;
        for (int j = 0; j < BIMESTRES; j++) {
            printf("Nota do %dº bimestre: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
            soma += alunos[i].notas[j];
        }
        getchar();  // Limpa o buffer do teclado

        alunos[i].media = soma / BIMESTRES;
        strcpy(alunos[i].situacao, alunos[i].media >= 6 ? "aprovado" : "reprovado");
        somaSala += alunos[i].media;
    }

    ordenaPorMedia(alunos, n);

    printf("\nBoletim:\n");
    printf("Nome%*sNotas%*sM.F.%*sSituacao\n", 30, "", 15, "", 6, "");
    for (i = 0; i < n; i++) {
        printf("%-30s", alunos[i].nome);
        for (int j = 0; j < BIMESTRES; j++) {
            printf("%6.2f", alunos[i].notas[j]);
        }
        printf("%6.2f    %s\n", alunos[i].media, alunos[i].situacao);
    }

    printf("\nA média da sala foi: %.2f\n", somaSala / n);

    return 0;
}

void ordenaPorMedia(struct DadosAluno alunos[], int n) {
    struct DadosAluno temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (alunos[i].media < alunos[j].media) {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}

