#include <stdio.h>

/**
 * Representa uma carta do super trunfo. Guarda todos os atributos de uma carta.
 */
struct Carta {
  char nome[100];
  int populacao, pontosTuristicos;
  float area, pib, densidadeDemografica;
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
 * Exibe o menu interativo para escolha do atributo a ser comparado/exibido.
 */
void menuInterativo(struct Carta *carta1, short *pontuacao1, struct Carta *carta2, short *pontuacao2);

/**
 * Compara dois vaores cujo tipo é `unsigned long`. Vence o valor que for maior.
 */
void compararAtributosUnsignedLong(const char *nomeAtributo, char *nomeCarta1, unsigned long *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, unsigned long *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores cujo tipo é `float`. Vence o valor que for maior.
 */
void compararAtributosFloat(const char *nomeAtributo, char *nomeCarta1, float *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, float *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores cujo tipo é `int`. Vence o valor que for maior.
 */
void compararAtributosInt(const char *nomeAtributo, char *nomeCarta1, int *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, int *atributo2, short *pontuacaoAtributo2);

/**
 * Compara dois valores de densidade demográfica. Vence o valor que for menor.
 */
void compararDensidadeDemografica(char *nomeCarta1, float *densidade1, short *pontuacaoDensidade1, char *nomeCarta2, float *densidade2, short *pontuacaoDensidade2);

/**
 * Compara dois valores cujo tipo é `double`. Vence o valor que for maior.
 */
void compararAtributosDouble(const char *nomeAtributo, char *nomeCarta1, double *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, double *atributo2, short *pontuacaoAtributo2);

int main() {

    short pontuacaoCarta1 = 0;
    short pontuacaoCarta2 = 0;

    struct Carta carta1 = scanCadastrarCarta();
    struct Carta carta2 = scanCadastrarCarta();

    printf("\n\n---CARTAS---\n\n");

    menuInterativo(&carta1, &pontuacaoCarta1, &carta2, &pontuacaoCarta2);
    
    return 0;
}

struct Carta scanCadastrarCarta() {

    struct Carta novaCarta;

    printf("\n\n---CADASTRO DE CARTAS---\n\n");

    printf("\n\nInsira o nome (sem espaços, máximo 100 caracteres. Exemplo: Costa_Rica)\n");
    printf("Nome: ");
    scanf("%100s", novaCarta.nome);

    printf("\n\nInsira a populacao\n");
    printf("Populacao: ");
    scanf("%i", &novaCarta.populacao);

    printf("\n\nInsira a area (em quilometros quadrados)\n");
    printf("Area: ");
    scanf("%f", &novaCarta.area);

    printf("\n\nInsira o PIB (em reais)\n");
    printf("PIB: ");
    scanf("%f", &novaCarta.pib);

    printf("\n\nInsira a quantidade de pontos turisticos\n");
    printf("Pontos turisticos: ");
    scanf("%i", &novaCarta.pontosTuristicos);

    novaCarta.densidadeDemografica = novaCarta.populacao / novaCarta.area;
    
    // novaCarta.pibPerCapita = novaCarta.pib / novaCarta.populacao;
    
    /* novaCarta.superPoder =
        novaCarta.populacao + novaCarta.area + novaCarta.pib + novaCarta.pontosTuristicos + novaCarta.pibPerCapita - novaCarta.densidadePopulacional; */

    return novaCarta;
}

void imprimirCarta(struct Carta *carta) {

    printf("\n");

    printf("Nome: %s\n", carta->nome);
    printf("Populacao: %i habitantes\n", carta->populacao);
    printf("Area: %.2f km²\n", carta->area);
    printf("PIB: R$ %.2f\n", carta->pib);
    printf("Pontos turisticos: %i\n", carta->pontosTuristicos);
    printf("Densidade demografica: %.2f hab/km²\n", carta->densidadeDemografica);
    
    // printf("PIB per capita: R$ %.2f\n", carta->pibPerCapita);
    // printf("Super poder: %.2f\n", carta->superPoder);
}

void menuInterativo(struct Carta *carta1, short *pontuacao1, struct Carta *carta2, short *pontuacao2) {

  int opcao;

  printf("\n\n---MENU---\n\n");

  printf("Qual dos atributos abaixo voce deseja comparar/exibir?\n\n");

  printf("1. Nome (apenas exibição)\n");
  printf("2. Populacao\n");
  printf("3. Area\n");
  printf("4. PIB\n");
  printf("5. Pontos turisticos\n");
  printf("6. Densidade demografica\n");

  printf("\n\nDigite uma opção (apenas o número): ");
  scanf("%i", &opcao);

  switch (opcao) {
    case 1:
      printf("\n");
      printf("Nome da carta 1: %s\n", carta1->nome);
      printf("Nome da carta 2: %s\n", carta2->nome);
      break;
    case 2:
      compararAtributosInt("Populacao", carta1->nome, &carta1->populacao, pontuacao1, carta2->nome, &carta2->populacao, pontuacao2);
      break;
    case 3:
      compararAtributosFloat("Area", carta1->nome, &carta1->area, pontuacao1, carta2->nome, &carta2->area, pontuacao2);
      break;
    case 4:
      compararAtributosFloat("PIB", carta1->nome, &carta1->pib, pontuacao1, carta2->nome, &carta2->pib, pontuacao2);
      break;
    case 5:
      compararAtributosInt("Pontos turisticos", carta1->nome, &carta1->pontosTuristicos, pontuacao1, carta2->nome, &carta2->pontosTuristicos, pontuacao2);
      break;
    case 6:
      compararDensidadeDemografica(carta1->nome, &carta1->densidadeDemografica, pontuacao1, carta2->nome, &carta2->densidadeDemografica, pontuacao2);
      break;
    default:
      printf("Por favor, digite uma opção válida. Por exemplo, 1 para exibir o nome das cartas");
      menuInterativo(carta1, pontuacao1, carta2, pontuacao2);
      break;
  }
}

void compararAtributosUnsignedLong(const char *nomeAtributo, char *nomeCarta1, unsigned long *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, unsigned long *atributo2, short *pontuacaoAtributo2) {

    printf("Atributo a ser comparado: %s\n\n", nomeAtributo);

   printf("%s\n%s: %lu\n", nomeCarta1, nomeAtributo, *atributo1);

   printf("%s\n%s: %lu\n", nomeCarta2, nomeAtributo, *atributo2);

  if (*atributo1 > *atributo2) {

    printf("%s venceu\n", nomeCarta1, nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }
  
  if (*atributo2 > *atributo1) {

    printf("%s venceu\n", nomeCarta2, nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("empate\n", nomeAtributo);
}

void compararAtributosFloat(const char *nomeAtributo, char *nomeCarta1, float *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, float *atributo2, short *pontuacaoAtributo2) {

   printf("Atributo a ser comparado: %s\n\n", nomeAtributo);

   printf("%s\n%s: %.2f\n", nomeCarta1, nomeAtributo, *atributo1);

   printf("%s\n%s: %.2f\n", nomeCarta2, nomeAtributo, *atributo2);

  if (*atributo1 > *atributo2) {

    printf("%s venceu\n", nomeCarta1, nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("%s venceu\n", nomeCarta2, nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("empate\n", nomeAtributo);
}

void compararAtributosInt(const char *nomeAtributo, char *nomeCarta1, int *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, int *atributo2, short *pontuacaoAtributo2) {

  printf("Atributo a ser comparado: %s\n\n", nomeAtributo);

  printf("%s\n%s: %i\n\n", nomeCarta1, nomeAtributo, *atributo1);

  printf("%s\n%s: %i\n\n", nomeCarta2, nomeAtributo, *atributo2);

  if (*atributo1 > *atributo2) {

    printf("%s venceu\n", nomeCarta1, nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("%s venceu\n", nomeCarta2, nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("empate\n", nomeAtributo);
}

void compararAtributosDouble(const char *nomeAtributo, char *nomeCarta1, double *atributo1, short *pontuacaoAtributo1, char *nomeCarta2, double *atributo2, short *pontuacaoAtributo2) {

  if (*atributo1 > *atributo2) {

    printf("\n%s: %s venceu\n", nomeCarta1, nomeAtributo);

    (*pontuacaoAtributo1)++;

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("\n%s: %s venceu\n", nomeCarta2, nomeAtributo);

    (*pontuacaoAtributo2)++;

    return;
  }

  printf("\n%s: empate\n", nomeAtributo);
}

void compararDensidadeDemografica(char *nomeCarta1, float *densidade1, short *pontuacaoDensidade1, char *nomeCarta2, float *densidade2, short *pontuacaoDensidade2) {

   printf("Atributo a ser comparado: Densidade demografica\n\n");

   printf("%s\nDensidade demografica: %.2f\n", nomeCarta1, *densidade1);

   printf("%s\nDensidade demografica: %.2f\n", nomeCarta2, *densidade2);

  if (*densidade1 < *densidade2) {

    printf("\nDensidade populacional: %s venceu\n", nomeCarta1);

    (*pontuacaoDensidade1)++;

    return;
  }

  if (*densidade2 < *densidade1) {

    printf("\nDensidade populacional: %s venceu\n", nomeCarta2);

    (*pontuacaoDensidade2)++;

    return;
  }

  printf("\nDensidade populacional: empate\n");
}
