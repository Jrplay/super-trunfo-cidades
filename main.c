#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 32

// Estrutura de cada carta
typedef struct {
    char estado[3];
    char codigo[5];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular propriedades derivadas
void calcular_propriedades(Carta *c) {
    if (c->area > 0) {
        c->densidade_populacional = (float)c->populacao / c->area;
    } else {
        c->densidade_populacional = 0;
    }

    if (c->populacao > 0) {
        c->pib_per_capita = c->pib * 1000000 / c->populacao;
    } else {
        c->pib_per_capita = 0;
    }
}

// Função para exibir uma carta
void exibir_carta(Carta c) {
    printf("\n=== Carta %s - %s (%s) ===\n", c.codigo, c.nome, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f milhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", c.pib_per_capita);
}

int main() {
    Carta cartas[MAX_CARTAS];
    int total = 4; // já começa com 4 cartas
    int opcao;

    // === Cartas pré-carregadas ===
    strcpy(cartas[0].estado, "BA");
    strcpy(cartas[0].codigo, "A01");
    strcpy(cartas[0].nome, "Salvador");
    cartas[0].populacao = 2900000;
    cartas[0].area = 692.8;
    cartas[0].pib = 61000;
    cartas[0].pontos_turisticos = 12;
    calcular_propriedades(&cartas[0]);

    strcpy(cartas[1].estado, "SP");
    strcpy(cartas[1].codigo, "B02");
    strcpy(cartas[1].nome, "São Paulo");
    cartas[1].populacao = 11250000;
    cartas[1].area = 1521.1;
    cartas[1].pib = 443000;
    cartas[1].pontos_turisticos = 30;
    calcular_propriedades(&cartas[1]);

    strcpy(cartas[2].estado, "RJ");
    strcpy(cartas[2].codigo, "C03");
    strcpy(cartas[2].nome, "Rio de Janeiro");
    cartas[2].populacao = 6200000;
    cartas[2].area = 1200.3;
    cartas[2].pib = 360000;
    cartas[2].pontos_turisticos = 25;
    calcular_propriedades(&cartas[2]);

    strcpy(cartas[3].estado, "MG");
    strcpy(cartas[3].codigo, "D04");
    strcpy(cartas[3].nome, "Belo Horizonte");
    cartas[3].populacao = 2500000;
    cartas[3].area = 331.4;
    cartas[3].pib = 88000;
    cartas[3].pontos_turisticos = 10;
    calcular_propriedades(&cartas[3]);

    // === Menu ===
    do {
        printf("\n=== Super Trunfo Cidades ===\n");
        printf("1 - Listar cartas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                for (int i = 0; i < total; i++) {
                    exibir_carta(cartas[i]);
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}