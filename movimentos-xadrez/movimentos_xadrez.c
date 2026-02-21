#include <stdio.h>

int main()
{

  // Movimento da torre, cinco casas para a direita

  printf("\n\n--- TORRE ---\n\n");

  for (size_t i1 = 0; i1 < 5; i1++)
  {
    
    printf("Direita\n");
  }

  // movimento do bispo, cinco casas na diagonal para cima e à direita

  printf("\n\n--- BISPO ---\n\n");

  short i2 = 5;
  while (i2 > 0)
  {
    
    printf("Cima, Direita\n");

    i2--;
  }

  printf("\n\n--- RAINHA ---\n\n");
  
  // movimento da rainha, oito casas para a esquerda

  short i3 = 8;
  do
  {
    
    printf("Esquerda\n");

    i3--;

  } while (i3 > 0);
  
  return 0;
}