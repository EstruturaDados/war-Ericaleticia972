
// ======================================================================
//  PROJETO WAR – NÍVEL MESTRE
// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD_TERRITORIOS 5

typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

typedef struct {
    char descricao[100];
    int tipo;
    char alvo_cor[20];
    int numero;
} Missao;

void pauseEnter() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void cadastrarTerritorios(Territorio t[]) {
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", t[i].nome);
        printf("Cor do Exército: ");
        scanf(" %[^\n]", t[i].cor);
        printf("Tropas: ");
        scanf("%d", &t[i].tropas);
    }
}

void exibirMapa(Territorio t[]) {
    printf("\n===== MAPA ATUAL =====\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

void gerarMissao(Missao *m, Territorio t[]) {
    int escolha = rand() % 5;

    switch (escolha) {
        case 0:
            strcpy(m->descricao, "Destruir todos os territórios de uma cor específica.");
            m->tipo = 1;
            strcpy(m->alvo_cor, t[rand() % QTD_TERRITORIOS].cor);
            break;

        case 1:
            strcpy(m->descricao, "Conquistar 3 territórios.");
            m->tipo = 2;
            m->numero = 3;
            break;

        case 2:
            strcpy(m->descricao, "Destruir todos os territórios com menos de 3 tropas.");
            m->tipo = 3;
            break;

        case 3:
            strcpy(m->descricao, "Ter pelo menos 2 territórios com 5 ou mais tropas.");
            m->tipo = 4;
            break;

        case 4:
            strcpy(m->descricao, "Eliminar um território específico.");
            m->tipo = 5;
            strcpy(m->alvo_cor, t[rand() % QTD_TERRITORIOS].nome);
            break;
    }
}

int verificarMissao(Missao *m, Territorio t[]) {
    int cont;

    switch (m->tipo) {

        case 1:
            for (int i = 0; i < QTD_TERRITORIOS; i++)
                if (strcmp(t[i].cor, m->alvo_cor) == 0 && t[i].tropas > 0)
                    return 0;
            return 1;

        case 2:
            cont = 0;
            for (int i = 0; i < QTD_TERRITORIOS; i++)
                if (t[i].tropas > 0)
                    cont++;
            return cont >= m->numero;

        case 3:
            for (int i = 0; i < QTD_TERRITORIOS; i++)
                if (t[i].tropas > 0 && t[i].tropas < 3)
                    return 0;
            return 1;

        case 4:
            cont = 0;
            for (int i = 0; i < QTD_TERRITORIOS; i++)
                if (t[i].tropas >= 5)
                    cont++;
            return cont >= 2;

        case 5:
            for (int i = 0; i < QTD_TERRITORIOS; i++)
                if (strcmp(t[i].nome, m->alvo_cor) == 0 && t[i].tropas > 0)
                    return 0;
            return 1;
    }

    return 0;
}

void atacar(Territorio t[]) {
    int atq, def;

    exibirMapa(t);

    printf("\nTerritório atacante (1-5): ");
    scanf("%d", &atq);
    printf("Território defensor (1-5): ");
    scanf("%d", &def);

    atq--; 
    def--;

    if (atq < 0 || atq >= QTD_TERRITORIOS ||
        def < 0 || def >= QTD_TERRITORIOS ||
        atq == def ||
        t[atq].tropas <= 1 ||
        strcmp(t[atq].cor, t[def].cor) == 0) {

        printf("Jogada inválida.\n");
        pauseEnter();
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\nDado atacante: %d\n", dadoA);
    printf("Dado defensor: %d\n", dadoD);

    if (dadoA > dadoD) {
        t[def].tropas--;
        if (t[def].tropas < 0) t[def].tropas = 0;
        printf("Ataque venceu!\n");
    } else {
        t[atq].tropas--;
        if (t[atq].tropas < 1) t[atq].tropas = 1;
        printf("Defesa venceu!\n");
    }

    pauseEnter();
}

void mostrarMissao(Missao *m) {
    printf("\n===== SUA MISSÃO =====\n");
    printf("%s\n", m->descricao);

    if (m->tipo == 1)
        printf("Cor alvo: %s\n", m->alvo_cor);

    if (m->tipo == 5)
        printf("Território alvo: %s\n", m->alvo_cor);

    pauseEnter();
}

int main() {
    srand(time(NULL));

    Territorio territorios[QTD_TERRITORIOS];
    Missao missao;

    cadastrarTerritorios(territorios);
    gerarMissao(&missao, territorios);

    int opcao;

    do {
        printf("\n===== MENU MESTRE =====\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missão\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            atacar(territorios);

            if (verificarMissao(&missao, territorios)) {
                printf("\n===== MISSÃO CUMPRIDA! VOCÊ VENCEU! =====\n");
                pauseEnter();
                break;
            }

        } else if (opcao == 2) {
            mostrarMissao(&missao);
        }

    } while (opcao != 0);

    return 0;
}