#include <stdio.h>

/**
 * Representa uma carta do super trunfo. Guarda todos os atributos de uma carta.
 */
struct Carta {
        char estado;
        char codigo[4];
        char nome[100];
        unsigned long populacao;
        float area;
        float pib;
        int pontosTuristicos;
        float densidadePopulacional;
        float pibPerCapita;
        double superPoder;
};

/**
 * Cria uma nova carta, cujos atributos recebem os valores que o usuário digitar no console.
 * @returns a carta criada com os atributos que o usuário digitou no console.
 */
struct Carta scanCadastrarCarta();

/**
 * Imprime no console os valores de dada carta.
 * @param carta a carta que será impressa no console.
 */
void imprimirCarta(struct Carta *carta);

/**
 * Compara todos os atributos numéricos de duas cartas e decide qual é a vencedora da comparação.
 * 
 * Dados dois atributos de mesmo nome e tipo, vence o atributo cujo valor for maior (exceto `densidadePopulacional`, onde vence qual valor for menor). Se o valor dos dois for igual, um empate é declarado.
 * 
 * Vence a carta que tiver mais atributos com valores maiores que o adversário (exceto `densidadePopulacional`, onde vence qual valor for menor).
 * 
 * Se as duas cartas acumularem a mesma pontuação ao final da comparação, um empate é declarado.
 */
void batalhaDeCartas(struct Carta *carta1, struct Carta *carta2);

/**
 * Compara dois vaores cujo tipo é `unsigned long`. Vence o valor que for maior.
 */
void compararAtributosUnsignedLong(const char *nomeAtributo, unsigned long *atributo1, short *pontuacaoAtributo1, unsigned long *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores cujo tipo é `float`. Vence o valor que for maior.
 */
void compararAtributosFloat(const char *nomeAtributo, float *atributo1, short *pontuacaoAtributo1, float *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores cujo tipo é `int`. Vence o valor que for maior.
 */
void compararAtributosInt(const char *nomeAtributo, int *atributo1, short *pontuacaoAtributo1, int *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores de densidade populacional. Vence o valor que for menor.
 */
void compararDensidadePopulacional(float *densidade1, short *pontuacaoDensidade1, float *densidade2, short *pontuacaoDensidade2);

/**
 * Compara dois valores cujo tipo é `double`. Vence o valor que for maior.
 */
void compararAtributosDouble(const char *nomeAtributo, double *atributo1, short *pontuacaoAtributo1, double *atributo2, short *pontuacaoAtributo2);

int main() {

    long limiteDeCartas = 2;
    
    struct Carta cartas[limiteDeCartas];

    cartas[0] = scanCadastrarCarta();
    cartas[1] = scanCadastrarCarta();

    printf("\n---CARTAS---\n");

    printf("\nCarta 1\n");

    imprimirCarta(&cartas[0]);

    printf("\nCarta 2\n");

    imprimirCarta(&cartas[1]);

    printf("\n---BATALHA!---\n");

    batalhaDeCartas(&cartas[0], &cartas[1]);
    
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
    scanf("%lu", &novaCarta.populacao);

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
    novaCarta.superPoder =
        novaCarta.populacao + novaCarta.area + novaCarta.pib + novaCarta.pontosTuristicos + novaCarta.pibPerCapita - novaCarta.densidadePopulacional;

    return novaCarta;
}

void imprimirCarta(struct Carta *carta) {

    printf("\n");

    printf("Estado: %c\n", carta->estado);
    printf("Codigo: %s\n", carta->codigo);
    printf("Nome: %s\n", carta->nome);
    printf("Populacao: %lu habitantes\n", carta->populacao);
    printf("Area: %.2f km²\n", carta->area);
    printf("PIB: R$ %.2f\n", carta->pib);
    printf("Pontos turisticos: %i\n", carta->pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta->pibPerCapita);
    printf("Super poder: %.2f\n", carta->superPoder);
}

void batalhaDeCartas(struct Carta *carta1, struct Carta *carta2) {

  short pontuacaoCarta1 = 0;
  short pontuacaoCarta2 = 0;

  
  compararAtributosUnsignedLong("Populacao", &carta1->populacao, &pontuacaoCarta1, &carta2->populacao, &pontuacaoCarta2);

  compararAtributosFloat("Area", &carta1->area, &pontuacaoCarta1, &carta2->area, &pontuacaoCarta2);

  compararAtributosFloat("PIB", &carta1->pib, &pontuacaoCarta1, &carta2->pib, &pontuacaoCarta2);

  compararAtributosInt("Pontos turisticos", &carta1->pontosTuristicos, &pontuacaoCarta1, &carta2->pontosTuristicos, &pontuacaoCarta2);

  compararDensidadePopulacional(&carta1->densidadePopulacional, &pontuacaoCarta1, &carta2->densidadePopulacional, &pontuacaoCarta2);

  compararAtributosFloat("PIB per capta", &carta1->pibPerCapita, &pontuacaoCarta1, &carta2->pibPerCapita, &pontuacaoCarta2);

  compararAtributosDouble("Super poder", &carta1->superPoder, &pontuacaoCarta1, &carta2->superPoder, &pontuacaoCarta2);

  if (pontuacaoCarta1 > pontuacaoCarta2) {

    printf("\nCarta 1 vence a batalha!");

    return;
  }
  
  if (pontuacaoCarta2 > pontuacaoCarta1) {
    
    printf("\nCarta 2 vence a batalha!");

    return;
  }

  printf("\nA batalha termina em empate...");
}

void compararAtributosUnsignedLong(const char *nomeAtributo, unsigned long *atributo1, short *pontuacaoAtributo1, unsigned long *atributo2, short *pontuacaoAtributo2) {

  if (*atributo1 > *atributo2) {

    printf("\n%s: Carta 1 venceu (1)\n", nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }
  
  if (*atributo2 > *atributo1) {

    printf("\n%s: Carta 2 venceu (0)\n", nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("\n%s: empate\n", nomeAtributo);
}

void compararAtributosFloat(const char *nomeAtributo, float *atributo1, short *pontuacaoAtributo1, float *atributo2, short *pontuacaoAtributo2) {

  if (*atributo1 > *atributo2) {

    printf("\n%s: Carta 1 venceu (1)\n", nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("\n%s: Carta 2 venceu (0)\n", nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("\n%s: empate\n", nomeAtributo);
}

void compararAtributosInt(const char *nomeAtributo, int *atributo1, short *pontuacaoAtributo1, int *atributo2, short *pontuacaoAtributo2) {

  if (*atributo1 > *atributo2) {

    printf("\n%s: Carta 1 venceu (1)\n", nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("\n%s: Carta 2 venceu (0)\n", nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("\n%s: empate\n", nomeAtributo);
}

void compararAtributosDouble(const char *nomeAtributo, double *atributo1, short *pontuacaoAtributo1, double *atributo2, short *pontuacaoAtributo2) {

  if (*atributo1 > *atributo2) {

    printf("\n%s: Carta 1 venceu (1)\n", nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("\n%s: Carta 2 venceu (0)\n", nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("\n%s: empate\n", nomeAtributo);
}

void compararDensidadePopulacional(float *densidade1, short *pontuacaoDensidade1, float *densidade2, short *pontuacaoDensidade2) {

  if (*densidade1 < *densidade2) {

    printf("\nDensidade populacional: Carta 1 venceu (1)\n");

    (*pontuacaoDensidade1)++;

    return;
  }

  if (*densidade2 < *densidade1) {

    printf("\nDensidade populacional: Carta 2 venceu (0)\n");

    (*pontuacaoDensidade2)++;

    return;
  }

  printf("\nDensidade populacional: empate\n");
}
