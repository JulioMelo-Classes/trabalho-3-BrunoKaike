# Snaze

Snaze é um projeto para simular um jogo em que uma cobra tem que coletar todas as comidas em um labirinto sem perder todas as suas vidas batendo em paredes ou em si mesma.

## Objetivos

Projeto desenvolvido e apresentado ao curso de Tecnologia da Informação da Universidade Federal do Rio Grande do Norte, como requisito parcial para obtenção de nota na disciplina de Linguagem de Programação I, ministrada pelo professor Julio Cesar Paulino de Melo(*<julio.melo@imd.ufrn.br>*).

## O que é Snaze?
Snaze é uma mistura do clássico jogo de arcade [Snake video game](https://en.wikipedia.org/wiki/Snake_(video_game_genre)) com o jogo [Mouse in the Maze](https://www.youtube.com/watch?v=Kdzzbl_Nd4I).

## Sobre o projeto
<center>
<img src="data/snaze.png">
</center>

O projeto Snaze foi desenvolvido utilizando da linguagem C++.

A simulação do jogo Snaze carrega o nível do labirinto a partir de um arquivo texto de entrada, cujo nome é fornecido via argumento de linha de comando, e controla os movimentos da cobra por meio de uma IA.

## Compilando e executando o projeto

No linux você pode compilar usando o g++. Apenas faça clone do projeto, e faça:

```bash
g++ src/*.cpp -o main -I./include
./main <diretório> <comRabo/semrabo>
```

No windows você pode compilar usando o g++ ou o cl de forma análoga:

```bash
g++ src/*.cpp -o main -I./include
.\main.exe <diretório> <comRabo/semrabo>
```
ou usando o CL

```bash
cl src/*.cpp -I./include
.\main.exe <diretório> <comRabo/semrabo>
.\Snaze.exe 
```

## Testes por linha de comando

<details>
<summary>Testes de funcionalidade</summary>


<p>Spawn randômico</p>

```console
./main data/maze1.txt <comRabo/semrabo>

```

<p>Spawn definido</p>

```console
./main data/maze1.txt <comRabo/semrabo>

```

</details>

<details>
<summary>Testes de Erro</summary>


<p>Uma ou mais dimensões superiores a 100</p>

```console
./main data/erro1.txt <comRabo/semrabo>

```

<p>Uma ou mais dimensões inferiores a 1</p>

```console
./main data/erro2.txt <comRabo/semrabo>

```

<p>Bateu na parede</p>

```console
./main data/erro3.txt <comRabo/semrabo>

```

</details>

__Observação sobre o windows__: Caso o programa seja detectado como vírus usar a versão compilada com o g++ ou configurar o windows defender para ignorar o executável que está na pasta do projeto (o problema só ocorre com a versão compilada pelo CL).

## Contato

Bruno Kaike do Nascimento Batista -
*<brunokaike@ufrn.edu.br>*

Link do projeto: [https://github.com/JulioMelo-Classes/trabalho-3-BrunoKaike](https://github.com/JulioMelo-Classes/trabalho-3-BrunoKaike)

