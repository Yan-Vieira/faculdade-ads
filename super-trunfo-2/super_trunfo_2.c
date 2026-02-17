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
 * @returns 0 se a função foi executado com sucesso, ou 1 se ela foi executada com erro.
 */
int menuInterativo(struct Carta *carta1, double *pontuacao1, struct Carta *carta2, double *pontuacao2);

/**
 * Compara dois valores cujo tipo é `float`. Vence o valor que for maior.
 */
void compararAtributosFloat(const char *nomeAtributo, char *nomeCarta1, float *atributo1, char *nomeCarta2, float *atributo2);

/**
 * Compara dois valores cujo tipo é `int`. Vence o valor que for maior.
 */
void compararAtributosInt(const char *nomeAtributo, char *nomeCarta1, int *atributo1, char *nomeCarta2, int *atributo2);

/**
 * Compara dois valores de densidade demográfica. Vence o valor que for menor.
 */
void compararDensidadeDemografica(char *nomeCarta1, float *atributo1, char *nomeCarta2, float *atributo2);

int main() {

    double pontuacaoCarta1 = 0;
    double pontuacaoCarta2 = 0;

    struct Carta carta1 = scanCadastrarCarta();
    struct Carta carta2 = scanCadastrarCarta();

    int menuInterativoSucesso = menuInterativo(&carta1, &pontuacaoCarta1, &carta2, &pontuacaoCarta2);

    if (menuInterativoSucesso != 0) return 0;

    printf("\n\n---PONTUACOES TOTAIS---\n\n");

    printf("%s: %.2f\n\n", carta1.nome, pontuacaoCarta1);
    printf("%s: %.2f\n", carta2.nome, pontuacaoCarta2);

    if (pontuacaoCarta1 > pontuacaoCarta2) {

      printf("\n\n%s venceu a batalha!", carta1.nome);

    } else if (pontuacaoCarta2 > pontuacaoCarta1) {

      printf("\n\n%s venceu a batalha!", carta2.nome);

    } else {

      printf("\n\nempate!");
    }
    
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

int menuInterativo(struct Carta *carta1, double *pontuacao1, struct Carta *carta2, double *pontuacao2) {

  int opcao1;
  int opcao2;

  printf("\n\n---MENU---\n\n");

  printf("Qual dos atributos abaixo voce deseja comparar/exibir?\n\n");

  printf("1. Nome (apenas exibição)\n");
  printf("2. Populacao\n");
  printf("3. Area\n");
  printf("4. PIB\n");
  printf("5. Pontos turisticos\n");
  printf("6. Densidade demografica\n");

  printf("\n\nDigite uma opcao (apenas o número): ");
  scanf("%i", &opcao1);

  if (opcao1 != 1) {

    printf("\n\nDigite o segundo atributo (apenas o número): ");
    scanf("%i", &opcao2);
  }

  if (opcao1 == opcao2) {
    
    printf("\n\nPor favor, escolha duas opcoes diferentes");

    return 1;
  }
  

  switch (opcao1) {
    case 1:
      printf("\n");
      printf("Nome da carta 1: %s\n", carta1->nome);
      printf("Nome da carta 2: %s\n", carta2->nome);
      return 1;
     case 2:
      compararAtributosInt("Populacao", carta1->nome, &carta1->populacao, carta2->nome, &carta2->populacao);
      (*pontuacao1) += carta1->populacao;
      (*pontuacao2) += carta2->populacao;
      break;
    case 3:
      compararAtributosFloat("Area", carta1->nome, &carta1->area, carta2->nome, &carta2->area);
      (*pontuacao1) += carta1->area;
      (*pontuacao2) += carta2->area;
      break;
    case 4:
      compararAtributosFloat("PIB", carta1->nome, &carta1->pib, carta2->nome, &carta2->pib);
      (*pontuacao1) += carta1->pib;
      (*pontuacao2) += carta2->pib;
      break;
    case 5:
      compararAtributosInt("Pontos turisticos", carta1->nome, &carta1->pontosTuristicos, carta2->nome, &carta2->pontosTuristicos);
      (*pontuacao1) += carta1->pontosTuristicos;
      (*pontuacao2) += carta2->pontosTuristicos;
      break;
    case 6:
      compararDensidadeDemografica(carta1->nome, &carta1->densidadeDemografica, carta2->nome, &carta2->densidadeDemografica);
      (*pontuacao1) -= carta1->densidadeDemografica;
      (*pontuacao2) -= carta2->densidadeDemografica;
      break;
    default:
      printf("Por favor, digite uma opção válida. Por exemplo, 1 para exibir o nome das cartas");
      return 1;
  }

  switch (opcao2) {
    case 2:
      compararAtributosInt("Populacao", carta1->nome, &carta1->populacao, carta2->nome, &carta2->populacao);
      (*pontuacao1) += carta1->populacao;
      (*pontuacao2) += carta2->populacao;
      break;
    case 3:
      compararAtributosFloat("Area", carta1->nome, &carta1->area, carta2->nome, &carta2->area);
      (*pontuacao1) += carta1->area;
      (*pontuacao2) += carta2->area;
      break;
    case 4:
      compararAtributosFloat("PIB", carta1->nome, &carta1->pib, carta2->nome, &carta2->pib);
      (*pontuacao1) += carta1->pib;
      (*pontuacao2) += carta2->pib;
      break;
    case 5:
      compararAtributosInt("Pontos turisticos", carta1->nome, &carta1->pontosTuristicos, carta2->nome, &carta2->pontosTuristicos);
      (*pontuacao1) += carta1->pontosTuristicos;
      (*pontuacao2) += carta2->pontosTuristicos;
      break;
    case 6:
      compararDensidadeDemografica(carta1->nome, &carta1->densidadeDemografica, carta2->nome, &carta2->densidadeDemografica);
      (*pontuacao1) -= carta1->densidadeDemografica;
      (*pontuacao2) -= carta2->densidadeDemografica;
      break;
    default:
      printf("Por favor, digite uma opção válida. Por exemplo, 2 para comparar as populacoes");
      return 1;
  }

  return 0;
}

void compararAtributosFloat(const char *nomeAtributo, char *nomeCarta1, float *atributo1, char *nomeCarta2, float *atributo2) {

   printf("\n\nAtributo a ser comparado: %s\n\n", nomeAtributo);

   printf("%s\n%s: %.2f\n\n", nomeCarta1, nomeAtributo, *atributo1);

   printf("%s\n%s: %.2f\n\n", nomeCarta2, nomeAtributo, *atributo2);

  if (*atributo1 > *atributo2) {

    printf("%s venceu\n", nomeCarta1, nomeAtributo);

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("%s venceu\n", nomeCarta2, nomeAtributo);

    return;
  }

  printf("empate\n", nomeAtributo);
}

void compararAtributosInt(const char *nomeAtributo, char *nomeCarta1, int *atributo1, char *nomeCarta2, int *atributo2) {

  printf("\n\nAtributo a ser comparado: %s\n\n", nomeAtributo);

  printf("%s\n%s: %i\n\n", nomeCarta1, nomeAtributo, *atributo1);

  printf("%s\n%s: %i\n\n", nomeCarta2, nomeAtributo, *atributo2);

  if (*atributo1 > *atributo2) {

    printf("%s venceu\n", nomeCarta1, nomeAtributo);

    return;
  }

  if (*atributo2 > *atributo1) {

    printf("%s venceu\n", nomeCarta2, nomeAtributo);

    return;
  }

  printf("empate\n", nomeAtributo);
}

void compararDensidadeDemografica(char *nomeCarta1, float *densidade1, char *nomeCarta2, float *densidade2) {

   printf("\n\nAtributo a ser comparado: Densidade demografica\n\n");

   printf("%s\nDensidade demografica: %.2f\n\n", nomeCarta1, *densidade1);

   printf("%s\nDensidade demografica: %.2f\n\n", nomeCarta2, *densidade2);

  if (*densidade1 < *densidade2) {

    printf("\nDensidade populacional: %s venceu\n", nomeCarta1);

    return;
  }

  if (*densidade2 < *densidade1) {

    printf("\nDensidade populacional: %s venceu\n", nomeCarta2);

    return;
  }

  printf("\nDensidade populacional: empate\n");
}
