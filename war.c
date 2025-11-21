
 // ======================================================================
//  PROJETO WAR – NÍVEL AVENTUREIRO
// ======================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {

    Territorio territorios[5];
    srand(time(NULL));

    printf("=====================================\n");
    printf("Vamos cadastrar os 5 territorios iniciais.\n\n");

    // Cadastro dos territórios
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

    int opcao;

    do {
        printf("=====================================\n");
        printf("MENU PRINCIPAL\n");
        printf("1 - Exibir Territorios\n");
        printf("2 - Fase de Ataque\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("\nMAPA DO MUNDO - ESTADO ATUAL\n");
            printf("=====================================\n");
            for (int i = 0; i < 5; i++) {
                printf("%d. %s (Exercito %s, Tropas: %d)\n",
                       i + 1,
                       territorios[i].nome,
                       territorios[i].cor,
                       territorios[i].tropas);
            }

        } else if (opcao == 2) {

            printf("\nMAPA DO MUNDO - ESTADO ATUAL\n");
            printf("=====================================\n");
            for (int i = 0; i < 5; i++) {
                printf("%d. %s (Exercito %s, Tropas: %d)\n",
                       i + 1,
                       territorios[i].nome,
                       territorios[i].cor,
                       territorios[i].tropas);
            }

            int atq, def;

            printf("\n--- FASE DE ATAQUE ---\n");
            printf("Escolha o territorio atacante (1 a 5, ou 0 para sair): ");
            scanf("%d", &atq);

            if (atq == 0) continue;

            printf("Escolha o territorio defensor (1 a 5): ");
            scanf("%d", &def);

            atq--;
            def--;

            if (atq < 0 || atq >= 5 || def < 0 || def >= 5) {
                printf("Indices invalidos.\n");
                continue;
            }

            if (atq == def) {
                printf("Um territorio nao pode atacar ele mesmo.\n");
                continue;
            }

            if (territorios[atq].tropas <= 1) {
                printf("O territorio %s nao tem tropas suficientes para atacar.\n",
                       territorios[atq].nome);
                continue;
            }

            if (strcmp(territorios[atq].cor, territorios[def].cor) == 0) {
                printf("Nao e permitido atacar um territorio da mesma cor.\n");
                continue;
            }

            printf("\n--- RESULTADO DA BATALHA ---\n");

            int dadoA = (rand() % 6) + 1;
            int dadoD = (rand() % 6) + 1;

            printf("O atacante %s rolou um dado e tirou: %d\n", territorios[atq].nome, dadoA);
            printf("O defensor %s rolou um dado e tirou: %d\n", territorios[def].nome, dadoD);

            if (dadoA > dadoD) {
                printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
                territorios[def].tropas -= 1;
                if (territorios[def].tropas < 0)
                    territorios[def].tropas = 0;
            } else {
                printf("DEFESA VENCEU! O atacante perdeu 1 tropa.\n");
                territorios[atq].tropas -= 1;
                if (territorios[atq].tropas < 1)
                    territorios[atq].tropas = 1;
            }

            printf("\nPressione Enter para continuar para o proximo turno...");
            getchar();
            getchar();

        } else if (opcao != 3) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}