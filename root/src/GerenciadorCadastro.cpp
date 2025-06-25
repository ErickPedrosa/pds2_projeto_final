/**Realiza login dejogador
- Atualiza pontuação e numero de partidas
- Retorna ranking dos top jogadores
- Acessa e modifica arquivos de dados de jogadores   */

#include "../include/GerenciadorCadastro.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <tuple>    

void GerenciadorCadastro::Logar(std::string nome) {
    if (!this->joagdorJaExiste(nome)) {
        this->nome_jogador_atual = nome;
        this->num_jogos_jogador_atual = 0;
        this->pontuacao_maxima_jogador_atual = 0;
    }
}

void GerenciadorCadastro::AtualizarJogador(int pontuacao) {
    if (pontuacao > this->pontuacao_maxima_jogador_atual) {
        this->pontuacao_maxima_jogador_atual = pontuacao;
    }

    this->num_jogos_jogador_atual++;

    std::vector<std::string> linhas;
    bool atualizado = false;

    std::ifstream* entrada = AbrirArquivoParaLeitura();
    if (entrada) {
        std::string linha;
        while (std::getline(*entrada, linha)) {
            std::stringstream s(linha);
            std::string nome;
            std::getline(s, nome, ',');

            if (nome == this->nome_jogador_atual) {
                std::string novaLinha = this->nome_jogador_atual + "," +
                    std::to_string(this->num_jogos_jogador_atual) + "," +
                    std::to_string(this->pontuacao_maxima_jogador_atual);
                linhas.push_back(novaLinha);
                atualizado = true;
            }
            else {
                linhas.push_back(linha);
            }
        }

        FecharArquivo(entrada);
    }

    if (!atualizado) {
        std::string novaLinha = this->nome_jogador_atual + "," +
            std::to_string(this->num_jogos_jogador_atual) + "," +
            std::to_string(this->pontuacao_maxima_jogador_atual);
        linhas.push_back(novaLinha);
    }

    std::ofstream* saida = AbrirArquivoParaEscrita();
    if (!saida->is_open()) {
        delete saida;
        return;
    }

    for (const auto& l : linhas) {
        *saida << l << '\n';
    }

    FecharArquivo(saida);
}

std::ifstream* GerenciadorCadastro::AbrirArquivoParaLeitura() {
    std::ifstream* arquivo = new std::ifstream("CadastroJogadores.txt");
    if (!arquivo->is_open()) {
        delete arquivo;
        return nullptr;
    }
    return arquivo;
}

std::ofstream* GerenciadorCadastro::AbrirArquivoParaEscrita() {
    std::ofstream* arquivo = new std::ofstream("CadastroJogadores.txt", std::ios::out);
    if (!arquivo->is_open()) {
        delete arquivo;
        return nullptr;
    }
    return arquivo;
}

void GerenciadorCadastro::FecharArquivo(std::istream* arquivo) {
    if (arquivo) {
        std::ifstream* arq = dynamic_cast<std::ifstream*>(arquivo);
        if (arq && arq->is_open()) arq->close();
        delete arquivo;  // CORRIGIDO: deleta o ponteiro original
    }
}

void GerenciadorCadastro::FecharArquivo(std::ostream* arquivo) {
    if (arquivo) {
        std::ofstream* arq = dynamic_cast<std::ofstream*>(arquivo);
        if (arq && arq->is_open()) arq->close();
        delete arquivo;  // CORRIGIDO
    }
}

bool GerenciadorCadastro::joagdorJaExiste(std::string nome) {
    std::ifstream* arq = AbrirArquivoParaLeitura();
    if (!arq) return false;

    std::string linha;
    while (std::getline(*arq, linha)) {
        std::stringstream s(linha);
        std::string parte;
        std::vector<std::string> partes;

        while (std::getline(s, parte, ',')) {
            partes.push_back(parte);
        }

        if (partes.size() >= 3 && partes[0] == nome) {
            this->nome_jogador_atual = partes[0];
            this->num_jogos_jogador_atual = std::stoi(partes[1]);
            this->pontuacao_maxima_jogador_atual = std::stoi(partes[2]);

            FecharArquivo(arq);
            return true;
        }
    }

    FecharArquivo(arq);
    return false;
}

std::vector<std::tuple<std::string, int, int>> GerenciadorCadastro::TopNJogadores(int n) {
    std::ifstream* arq = AbrirArquivoParaLeitura();
    std::vector<std::tuple<std::string, int, int>> jogadores;

    if (!arq) return {};

    std::string linha;
    while (std::getline(*arq, linha)) {
        std::stringstream s(linha);
        std::string nome, jogos, pontos;

        if (std::getline(s, nome, ',') &&
            std::getline(s, jogos, ',') &&
            std::getline(s, pontos)) {
            try {
                int num_jogos = std::stoi(jogos);
                int pontuacao = std::stoi(pontos);
                jogadores.emplace_back(nome, pontuacao, num_jogos);
            }
            catch (...) {
                // Ignora entradas inválidas
            }
        }
    }

    FecharArquivo(arq);

    std::sort(jogadores.begin(), jogadores.end(),
        [](const std::tuple<std::string, int, int>& a, const std::tuple<std::string, int, int>& b) {
            return std::get<1>(a) > std::get<1>(b);
        });

    if (static_cast<int>(jogadores.size()) > n) {
        jogadores.resize(n);
    }

    return jogadores;
}

GerenciadorCadastro::GerenciadorCadastro() :
    num_jogos_jogador_atual(0),
    nome_jogador_atual(""),
    pontuacao_maxima_jogador_atual(-1)
{
}