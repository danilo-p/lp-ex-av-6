/*
  Solucao letra a: O programa nao modificado causaria uma falha de segmentacao,
  pois ele tenta fazer acesso do conteudo de um pointeiro nulo ao chamar o
  metodo get do objeto w da classe Wrapper na funcao main.
*/

#include <iostream>
#include <memory>

// Solucao letra b
class NoWrapperDataException : public std::exception
{
};

class Wrapper
{
private:
  int *d_o;

public:
  Wrapper() { d_o = nullptr; }
  Wrapper(int o) { d_o = new int(o); }
  int get()
  {
    if (d_o == nullptr)
    {
      // Solucao letra c
      throw NoWrapperDataException();
    }
    return *d_o;
  }
  ~Wrapper() { delete d_o; }
};

int main()
{
  std::unique_ptr<Wrapper> w(new Wrapper());

  // Solucao letra d
  try
  {
    std::cout << w->get() << "\n";
  }
  catch (NoWrapperDataException e)
  {
    std::cout << "Wrapper has no data\n";
  }
}