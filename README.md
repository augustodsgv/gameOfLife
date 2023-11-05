# gameOfLife 🌱
O Game of Life foi um jogo criado pelo matemático britânico Horton Conway, em 1970.\
O jogo consiste de uma matriz em que cada posição existe uma célula viva ou morta.\
As regras são as seguintes:
1. Se uma célula viva tiver menos de 2 vizinhas vivas, ela morre.
2. Se uma célula viva tiver mais que 3 vizinhas vivas, ela morre.
3. Se uma célula viva tiver 2 ou 3 vizinhas, ela permanece viva.
4. Se uma célula morta tiver exatamente 3 células vizinhas vivas, ela renasce.

Com essas regras, é possível criar várias simulações e criar padrões muito interessantes,\
como estruturas que ficam se "mexendo" repetidamente, estruturas estáticas que continuam vivas para sempre,\
ou até mesmo estruturas que ficam se movendo pelo campo.

Alguns padrões são bem conhecidos e estão catalogados no site ```https://conwaylife.appspot.com/```

## Como jogar 🕹️

### Obtendo o jogo ⬇️
Baixar o repositório atual ```git clone https://github.com/augustodsgv/gameOfLife.git```
Entrar no diretório do jogo ```cd src```
Compilar o jogo```make```

### Criando uma mapa 🗾
O jogo lê um arquivo .txt da pasta _/src/fases_ \
Lá, copie os templates com o tamanho do mapa que deseja\
e troque 0 por 1 nas células que deseja que estejam vivas

### Rodando a simulação 🔄
Com o jogo compilado e a fase criada, basta rodar o jogo com o nome da fase criada\
```./gameOfLife <nomeDaFase>```\
exemplo: ```./gameOfLife blinker```

## Sobre o jogo 🤓
Neste jogo, foi usado c puro, com algumas bibliotecas padrões como _string.h_ e _time_ somente\
para facilitar a leitura do input.

## Autor 👨🏻‍💻
[Augusto dos Santos](https://github.com/augustodsgv/)
