# gameOfLife

## Como jogar

### Obtendo o jogo
Baixar o repositório atual ```git clone https://github.com/augustodsgv/gameOfLife.git```
Entrar no diretório do jogo ````cd src```
Compilar o jogo```make```

### Criando uma mapa
O jogo lê um arquivo .txt da pasta _/src/fases_ \
Lá, copie os templates com o tamanho do mapa que deseja\
e troque 0 por 1 nas células que deseja que estejam vivas\

### Rodando a simulação
Com o jogo compilado e a fase criada, basta rodar o jogo com o nome da fase criada\
```./gameOfLife <nomeDaFase>```\
exemplo: ```./gameOfLife blinker```

## Sobre o jogo
Neste jogo, foi usado c puro, com algumas bibliotecas padrões como _string.h_ e _time_ somente\
para facilitar a leitura do input.\

## Autor
[Augusto dos Santos](https://github.com/augustodsgv/)
