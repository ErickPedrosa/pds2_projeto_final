CC = g++
CFLAGS = -std=c++11 -Wall -Iinclude -Iinclude/lib
LDFLAGS = $(shell pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_main-5 allegro_color-5)


BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/jogo

dirs:
	@mkdir -p $(BIN_DIR) $(OBJ_DIR)

$(OBJ_DIR)/Colisao.o: $(SRC_DIR)/Colisao.cpp $(INCLUDE_DIR)/Colisao.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/GerenciadorCadastro.o: $(SRC_DIR)/GerenciadorCadastro.cpp $(INCLUDE_DIR)/GerenciadorCadastro.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/HUD.o: $(SRC_DIR)/HUD.cpp $(INCLUDE_DIR)/HUD.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Main.o: $(SRC_DIR)/Main.cpp $(INCLUDE_DIR)/*.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Obstaculo.o: $(SRC_DIR)/Obstaculo.cpp $(INCLUDE_DIR)/Obstaculo.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Passaro.o: $(SRC_DIR)/Passaro.cpp $(INCLUDE_DIR)/Passaro.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/TelaCadastro.o: $(SRC_DIR)/TelaCadastro.cpp $(INCLUDE_DIR)/TelaCadastro.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/TelaDeJogo.o: $(SRC_DIR)/TelaDeJogo.cpp $(INCLUDE_DIR)/TelaDeJogo.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/TelaGameOver.o: $(SRC_DIR)/TelaGameOver.cpp $(INCLUDE_DIR)/TelaGameOver.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/TelaInicial.o: $(SRC_DIR)/TelaInicial.cpp $(INCLUDE_DIR)/TelaInicial.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/TelaPlacar.o: $(SRC_DIR)/TelaPlacar.cpp $(INCLUDE_DIR)/TelaPlacar.hpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/jogo: $(OBJ_DIR)/Colisao.o $(OBJ_DIR)/GerenciadorCadastro.o \
                $(OBJ_DIR)/HUD.o $(OBJ_DIR)/Main.o \
                $(OBJ_DIR)/Obstaculo.o \
                $(OBJ_DIR)/Passaro.o $(OBJ_DIR)/TelaCadastro.o \
                $(OBJ_DIR)/TelaDeJogo.o $(OBJ_DIR)/TelaGameOver.o \
                $(OBJ_DIR)/TelaInicial.o $(OBJ_DIR)/TelaPlacar.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)