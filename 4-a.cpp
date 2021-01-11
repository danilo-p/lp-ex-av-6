#include <iostream>

#define SUM(X, Y) (X) + (Y)

// Antes
// int main(int argc, char **argv)
// {
//   printf("sum = %d\n", SUM(argc, argv[0][0]));
// }

// Depois
int main(int argc, char **argv)
{
  printf("sum = %d\n", argc + argv[0][0]);
}