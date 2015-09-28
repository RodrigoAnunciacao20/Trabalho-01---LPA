# Trabalho-01---LPA

Trabalho da disciplina LPA da EESC-USP
Nomes dos integrantes do grupo:
1 - Hermano Esch Ferreira da Costa  N°USP - 9312710
2 - Rodrigo Anunciação              N°USP - 9312706
3 - Andre Frauches de Conti         N°USP - 9312630

Este repositório contém os exercícios propostos em sala de aula pelo professor Adenilso Simão no primeiro trabalho de sua disciplina.

(1) QUANTO AO FUNCIONAMENTO DOS PROGRAMAS E COMPILAÇÃO:

Os códigos nesse repositório foram criados em linguagem C(.c) utilizando o DEV-C++ 5.10 em Windows 8.1 64 bits O compilador usado na compilação dos códigos foi o TDM-GCC 4.8.1 64-bit Release.Todos os programas utilizam as bibliotecas padrão math.h, stdlib.h, stdio.h, não necessitando de nenhuma outra biblioteca para a execução dos programas.

(2)DESCRIÇÃO DOS PROGRAMAS E TUTORIAL DE COMO USÁ-LOS:

1 - Closest Pair: Esse programa pega como entrada n numeros, e devolve os o primeiro par de números que gera a menor diferença entre eles. Primeiramente será pedido par entrar com o número de elementos da lista a ser analisada, após isso, entra-se com os elementos da lista(aperte enter após cada valor digitado). Feito isso, o programa irá ordenar os números pelo quicksort e calcular as diferenças entre eles e devolver os dois primeiros elementos que geram essa menor diferença como saída do programa.
Exemplo de funcionamento do programa:
"Digite o numero de elementos da lista: 7
 Digite os numeros da lista: 5
 7
 10
 15
 17
 45
 76
 A menor diferença : 7 e 5"
 
 2 - Element Uniqueness: Esse programa pega como entrada n numeros, e devolve todos os elementos que ocorrem uma única vez.
 Primeiramente será pedido par entrar com o número de elementos da lista a ser analisada, após isso, entra-se com os elementos da lista(aperte enter após cada valor digitado). Feito isso, o programa irá ordenar os números pelo quicksort e comparar cada numero com seu adjacente a direita, concluindo assim quais elementos são unicos na minha lista e devolvendo-os como saída do programa.
 Exemplo de funcionamento do programa:
 "Digite o numero de elementos da lista: 7
  Digite os numeros da lista: 1
  4
  4
  2
  6
  6
  9
  Os numeros unicos: 1 2 9"
  
  3 - Frequency Distribution: Esse programa pega como entrada n numeros, e devolve o primeiro elemento da lista ordenada que ocorre em maior frequência.Primeiramente será pedido par entrar com o número de elementos da lista a ser analisada, após isso, entra-se com os elementos da lista(aperte enter após cada valor digitado). Feito isso, o programa irá ordenar os números pelo quicksort e comparar cada numero com seu adjacente a direita, concluindo assim quantas vezes ele se repete, e devolvendo o primeiro que ocorre em maior frequência como saída do programa.
  Exemplo de funcionamento do programa:
  "Digite o numero de elementos da lista: 7
   Digite os numeros da lista: 2
   3
   3
   3
   1
   5
   5
   Maior frequencia: 3"

 4 - Convex Hull - Esse programa pega como entrada n pontos, e devolve os pontos que formam o polígono com área mínima como saída do programa.
 
 
