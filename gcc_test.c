// gcc ./gcc_test.c -lm -o ./app
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ever  ;;

int main(int argc, char** argv)
{
  float A = 0, B = 0, dA, dB, i, j, z[1760];
  char b[1760];

  switch (argc)
  {
  case 1:
    dA = 0.02;
    dB = 0.01;
    break;
  case 3:
    dA = atof(argv[1]);
    dB = atof(argv[2]);
    break;
  default:
    printf("Argc can only be 1 or 3.\nif argc == 1\n\tdA and dB take default values.\nif argc == 2\n\tdA = argv[1]\n\tdB = argv[2]\n");
    return 1;
  }

  printf("\x1b[2J");
  for (ever)
  {
    memset(b,32,1760);
    memset(z,0,7040);
    for(j = 0; 6.28 > j; j += 0.07)
      for(i = 0; 6.28 > i; i += 0.02)
      {
        float sini = sin(i);
        float cosj = cos(j);
        float sinA = sin(A);
        float sinj = sin(j);
        float cosA = cos(A);
        float cosj2 = cosj + 2;
        float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);
        float cosi = cos(i);
        float cosB = cos(B);
        float sinB = sin(B);
        float t = sini * cosj2 * cosA - sinj * sinA;

        int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB);
        int y =  12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB);
        int o = x + 80 * y;
        int N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

        if(22 > y && y > 0 && x > 0 && 80 > x && mess > z[o])
        {
          z[o] = mess;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
      }
    printf("\x1b[d");
    for(int k = 0; 1761 > k; k++)
      putchar(k % 80 ? b[k] : 10);

    A += dA;
    B += dB;
  }
  return 0;
}