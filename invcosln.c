#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define USERINPUTLEN 256
#define PI 3.141592653589793238462643383279502884197

// gcc invcosln.c -o invcosln.bin -lm

double invcosln(double input)  {
 // if f(x) = cos(x)ln(x)
 // then f'(x) = cos(x)/x - sin(x)ln(x)
 // Find x s.t. f(x) - y = 0
 // x_i+1 -= (f(x_i) - y)/f'(x_i)
  if (input > -1.0e-10) return exp(input);
  double middle = 0.1;
  if (input < -3.0f) middle = exp(input);
  int i;
  for (i=0; i<10; i++) {
    middle -= middle*(cos(middle)*log(middle) - input) / (cos(middle) - middle*sin(middle)*log(middle));
  }
  return middle;
}

int main(int argc, char* argv[])  {
  printf("Enter a negative number y and the program displays x such that cos(x)ln(x) = y.\n");
  char*doubledigits = "-0987654321eE.";
  char*input = calloc(1, 1+USERINPUTLEN);
  double input1 = 1;
  while (input1 >= 0) {
    printf("Enter y < 0 \n");
    fgets(input, USERINPUTLEN, stdin);
    input1 = atof(input);
  }
  double x = invcosln(input1);
  printf("cos(%.15lf)ln(%.15lf) = %.15lf  \n", x, x, cos(x)*log(x));
  free(input);
}
