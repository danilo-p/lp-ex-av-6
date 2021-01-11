#include <iostream>

#define INCREMENTA(VALOR, DESTINO) \
  {                                \
    int tmp = VALOR;               \
    tmp++;                         \
    DESTINO = tmp;                 \
  }

void semCapture()
{
  int a = 0;
  int b = 0;

  // A expansao da macro neste caso não vai causar problemas, pois nao ha
  // nenhuma variavel tmp no escopo desta funcao. O valor de b vai ser o valor
  // de a incrementado de 1, ou seja, 1.
  INCREMENTA(a, b);

  std::cout << "Sem capture:\n";
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n\n\n";
}

void comCapture()
{
  int tmp = 0;
  int a = 0;

  // A expansao de macro neste caso tera o problema de capture, por causa da
  // variavel local chamada tmp. O valor de tmp nao e alterado pois o valor da
  // operacao vai ser assinalada na variavel tmp da macro, e nao na variavel tmp
  // da funcao.
  INCREMENTA(a, tmp);

  std::cout << "Com capture:\n";
  std::cout << "tmp: " << tmp << "\n";
  std::cout << "a: " << a << "\n\n\n";
}

int main()
{
  semCapture();
  comCapture();
}