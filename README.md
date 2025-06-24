# Projeto Final de PDS II

## Descrição do Projeto
  Clone do jogo Flappy Bird, feito para o projeto prático final da disciplina Programação e Desenvolvimento de Software II (PDS II) do curso de Sistemas de Informação da Universidade Federal de Minas Gerais (UFMG).
  Projeto desenvolvido em:
   - C++
   - Biblioteca Allegro: (https://liballeg.org/)

  O objetivo do jogo é controlar um pássaro que deve voar entre obstáculos (canos) sem colidir com eles. A cada sucesso, o jogador ganha +1 ponto e o jogo termina quando o pássaro colide com os obstáculos ou com a tela de jogo. Para jogar, basta o usuário digitar seu nome e clicar para iniciar. O "voo" do pássaro é controlado pelo usuário através da tecla "espaço". 

## Estrutura do Projeto
  O programa foi dividido em vários módulos, cada um com uma responsabilidade específica, visando aplicar os conceitos de Programação Orientada a Objetos (POO) e facilitar a manutenção do código.
   
### Módulos do Projeto
- TelaInicial, TelaCadastro, TelaPlacar, TelaDeJogo, TelaGameOver: Controlam as diferentes telas do jogo.
- Passaro: Classe que representa o jogador (pássaro) no jogo, contendo sua posição, física e renderização.
- Obstaculo: Classe dos obstáculos (canos) com movimentação e controle de colisão.
- Colisao: Responsável por detectar colisões entre o pássaro, obstáculos e os limites do jogo.
- HUD: Exibe informações como pontuação, tempo e nome do jogador durante o jogo.
- GerenciadorCadastro: Controla o armazenamento de jogadores e seus dados.
- Botao e CaixaDeTexto: Elementos de interface gráfica usados nas telas para interações com o usuário.
- IRenderizavel e ObjetoJogo: Classes base/abstratas para padronizar objetos que são desenhados na tela ou fazem parte da lógica do jogo.

### Extras
- Música de fundo
- Efeito sonoro de voo do pássaro

## Instrução de Instalação
### Pré-requisitos
 - Instalar a biblioteca Allegro => [tutorial de instalação](https://github.com/liballeg/allegro_wiki/wiki/Quickstart)
- Compilador C++ 

## Instruções de Execução
### Para Compilar:
```make```

### Para Executar:
```./bin/jogo```
## Licença
 MIT License
## Autores: Erick Pedrosa, Samara Neto, Silvia Peres, Lucas Maciel