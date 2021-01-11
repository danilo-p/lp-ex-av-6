#include <iostream>

#define DOBRA(X) (X) + (X)

int dado = 0;
int getDado()
{
  dado++;
  return dado;
}

int main()
{
  // getDado() vai ser avaliado duas vezes, chamando duas vezes a funcao
  // getData, incrementando o valor de dado mais uma vez na segunda avaliacao.
  // Assim o valor imprimido e 3, nao 2.
  std::cout << DOBRA(getDado()) << "\n";
}