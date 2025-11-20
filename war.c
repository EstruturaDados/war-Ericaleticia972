
 
// ======================================================================
//  PROJETO WAR – NÍVEL NOVATO
// ======================================================================

#include <stdio.h>
#include <string.h>

// STRUCT do Território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {

    Territorio territorios[5];  // Vetor de 5 territórios

    printf("=====================================\n");
    printf("Vamos cadastrar os 5 territorios iniciais.\n\n");

    // Cadastro
    for (int i = 0; i < 5; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);
        printf("Nome do Territorio: ");
        scanf(" %[^\n]", territorios[i].nome);

        printf("Cor do Exercito (ex: Azul, Verde): ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("=====================================\n");
    printf("Territorios cadastrados:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}