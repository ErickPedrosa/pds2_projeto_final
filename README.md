# Projeto Final de PDS II

## Descri��o do Projeto
  Clone do jogo Flappy Bird, feito para o projeto pr�tico final da disciplina Programa��o e Desenvolvimento de Software II (PDS II) do curso de Sistemas de Informa��o da Universidade Federal de Minas Gerais (UFMG).
  Projeto desenvolvido em:
   - C++
   - Biblioteca Allegro: (https://liballeg.org/)

  O objetivo do jogo � controlar um p�ssaro que deve voar entre obst�culos (canos) sem colidir com eles. A cada sucesso, o jogador ganha +1 ponto e o jogo termina quando o p�ssaro colide com os obst�culos ou com a tela de jogo. Para jogar, basta o usu�rio digitar seu nome e clicar para iniciar. O "voo" do p�ssaro � controlado pelo usu�rio atrav�s da tecla "espa�o". 

## Estrutura do Projeto
  O programa foi dividido em v�rios m�dulos, cada um com uma responsabilidade espec�fica, visando aplicar os conceitos de Programa��o Orientada a Objetos (POO) e facilitar a manuten��o do c�digo.
   
### M�dulos do Projeto
- TelaInicial, TelaCadastro, TelaPlacar, TelaDeJogo, TelaGameOver: Controlam as diferentes telas do jogo.
- Passaro: Classe que representa o jogador (p�ssaro) no jogo, contendo sua posi��o, f�sica e renderiza��o.
- Obstaculo: Classe dos obst�culos (canos) com movimenta��o e controle de colis�o.
- Colisao: Respons�vel por detectar colis�es entre o p�ssaro, obst�culos e os limites do jogo.
- HUD: Exibe informa��es como pontua��o, tempo e nome do jogador durante o jogo.
- GerenciadorCadastro: Controla o armazenamento de jogadores e seus dados.
- Botao e CaixaDeTexto: Elementos de interface gr�fica usados nas telas para intera��es com o usu�rio.
- IRenderizavel e ObjetoJogo: Classes base/abstratas para padronizar objetos que s�o desenhados na tela ou fazem parte da l�gica do jogo.

### Extras
- M�sica de fundo
- Efeito sonoro de voo do p�ssaro

## Instru��o de Instala��o
### Pr�-requisitos
 - Instalar a biblioteca Allegro => [tutorial de instala��o](https://github.com/liballeg/allegro_wiki/wiki/Quickstart)
- Compilador C++ 

## Instru��es de Execu��o
### Para Compilar:
```make```

### Para Executar:
```./bin/jogo```
## Licen�a
 MIT License
## Autores: Erick Pedrosa, Samara Neto, Silvia Peres, Lucas Maciel