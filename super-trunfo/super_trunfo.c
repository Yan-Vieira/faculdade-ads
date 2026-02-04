#include <stdio.h>

struct Carta {
        char estado;
        char codigo[4];
        char nome[100];
        int populacao;
        float area;
        float pib;
        int pontosTuristicos;
        float densidadePopulacional;
        float pibPerCapita;
};

struct Carta scanCadastrarCarta();
void imprimirCarta(struct Carta *carta);

int main() {

    long limiteDeCartas = 2;
    
    struct Carta cartas[limiteDeCartas];

    cartas[0] = scanCadastrarCarta();
    cartas[1] = scanCadastrarCarta();

    printf("\nCarta 1\n");

    imprimirCarta(&cartas[0]);

    printf("\nCarta 2\n");

    imprimirCarta(&cartas[1]);
    
    return 0;
}

struct Carta scanCadastrarCarta() {

    struct Carta novaCarta;

    printf("Insira o estado (uma letra de 'A' a 'H')\n");
    printf("Estado: ");
    scanf(" %c", &novaCarta.estado);

    printf("\n\nInsira o codigo da carta (A letra do estado seguida de um número de 01 a 04. Exemplo:  A01, B03)\n");
    printf("Codigo: ");
    scanf("%3s", novaCarta.codigo);

    printf("\n\nInsira o nome da cidade (sem espaços, máximo 100 caracteres. Exemplo: Sao_Paulo)\n");
    printf("Cidade: ");
    scanf("%100s", novaCarta.nome);

    printf("\n\nInsira a populacao da cidade\n");
    printf("Populacao: ");
    scanf("%i", &novaCarta.populacao);

    printf("\n\nInsira a area da cidade (em quilometros quadrados)\n");
    printf("Area: ");
    scanf("%f", &novaCarta.area);

    printf("\n\nInsira o PIB da cidade (em reais)\n");
    printf("PIB: ");
    scanf("%f", &novaCarta.pib);

    printf("\n\nInsira a quantidade de pontos turisticos na cidade\n");
    printf("Pontos turisticos: ");
    scanf("%i", &novaCarta.pontosTuristicos);

    novaCarta.densidadePopulacional = novaCarta.populacao / novaCarta.area;
    novaCarta.pibPerCapita = novaCarta.pib / novaCarta.populacao;

    return novaCarta;
}

void imprimirCarta(struct Carta *carta) {

    printf("\n");

    printf("Estado: %c\n", carta->estado);
    printf("Codigo: %s\n", carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("Populacao: %i\n", carta->populacao);
    printf("Area: %.2f km²\n", carta->area);
    printf("PIB: R$ %.2f\n", carta->pib);
    printf("Pontos turisticos: %i\n", carta->pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta->pibPerCapita);
}
