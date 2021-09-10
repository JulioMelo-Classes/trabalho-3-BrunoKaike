# LP1 Projeto 3

Neste projeto você irá fazer um simulador para o jogo snaze, melhores informações podem ser encontradas no [documento de especificação](https://www.overleaf.com/read/prcdstrjrdjr);

## Sistema de build

Escolha um dos sistemas de build que melhor agradar você, lembre que já vimos exemplos com [Makefile](https://www.gnu.org/software/make/manual/make.html) 
e [Cmake](https://cmake.org/). Esta versão usa compilação básica usando a linha de comando, mas fica a ~~obrigação~~ sugestão, caso você queira mudar.

## Organização

Este repositório tem algumas classes iniciais que podem te ajudar a fazer o projeto, porém, fique à vontade para explorar as possibilidades.

## Compilando e executando o exemplo

No linux você pode compilar usando o g++. Apenas faça clone do projeto, e faça:

```bash
g++ src/*.cpp -o main -I./include
./main
```

No windows você pode compilar usando o g++ ou o cl de forma análoga:

```bash
g++ src/*.cpp -o main -I./include
.\main.exe
```
ou usando o CL

```bash
cl src/*.cpp -I./include
.\Snaze.exe
```

__Observação sobre o windows__: Ao realizar testes meu sistema detectou o programa como um virus, para conseguir executar eu tive que usar a versão compilada com o g++ ou configurar o windows defender para ignorar o executável que está na pasta do projeto (o problema só ocorre com a versão compilada pelo CL).

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

Nenhum dos modos foi feito, mas vou considerar 20% uma vez que parte da lógica foi implementada.

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

70% o programa lê um arquivo porém não usa os argumentos passados.

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

Não implementado

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

Não implementado

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado.

### Classe Level ou similar

O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Não consegui fazer funcionar o caso básico, ao executar fico apenas vendo a tela do mapa mas sem ver a snake se mexer.
- Acho que o seu problema foi passar tempo demais querendo resolver o CP2 no CP1, se sua solução do CP2 estiver funcional, você pode tentar implementar apenas a visualização da solução usando apenas um mapa, isso serviria em termos de CP2.
- Mas eu sugiro que você tente implementar ao menos as funcionalidades de controle aleatório do CP1, pelo que você já fez acho que deve ser bem fácil. Seria usar a função de verificar viabilidade apenas UMA vez para cada posição onde a cobrinha pode ir a cada frame e escolher aleatoriamente uma ação que leve para essa posição.