(*
  No exemplo abaixo, mostramos que o SML nao faz passagem de parametros por
  expansão de macro. O resultado de f(); é 4, mostrando que a expressao foi
  avaliada da forma (1 + 1) * (1 + 1), ou seja, o escopo de g não é avaliado no
  escopo de f. Caso fosse, o resultado seria 3, pois 1 + 1 * 1 + 1 = 3.
*)
fun g() = 1 + 1;
fun f() = g() * g();
f();