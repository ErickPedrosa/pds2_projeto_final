#ifndef GERENCIACAD_H
#define GERENCIACAD_H 

#include <string>

class GerenciadorCadastro
{
public:
	GerenciadorCadastro();
	~GerenciadorCadastro();
	void Logar(std::string nome);
	void AtualizarJogador(int pontuacao);

private:
	int num_jogos_jogador_atual;
	std::string nome_jogador_atual;
	int pontuacao_maxima_jogador_atual;

	std::ifstream* AbrirArquivoParaLeitura();
	std::ofstream* AbrirArquivoParaEscrita();
	void FecharArquivo(std::istream* arquivo);  // Para leitura
	void FecharArquivo(std::ostream* arquivo);  // Para escrita
	bool joagdorJaExiste(std::string nome);
};

GerenciadorCadastro::GerenciadorCadastro() : num_jogos_jogador_atual(0) , nome_jogador_atual("") , pontuacao_maxima_jogador_atual(-1)
{
}

GerenciadorCadastro::~GerenciadorCadastro()
{
}





#endif