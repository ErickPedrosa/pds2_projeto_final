#ifndef GERENCIACAD_H
#define GERENCIACAD_H 

#include <string>
#include <vector>
#include <tuple>

class GerenciadorCadastro
{
public:
	GerenciadorCadastro();
	void Logar(std::string nome);
	void AtualizarJogador(int pontuacao);
	std::vector<std::tuple<std::string, int, int>> TopNJogadores(int n);


private:
	int num_jogos_jogador_atual;
	std::string nome_jogador_atual;
	int pontuacao_maxima_jogador_atual;

	std::ifstream* AbrirArquivoParaLeitura();
	std::ofstream* AbrirArquivoParaEscrita();
	void FecharArquivo(std::istream* arquivo); 
	void FecharArquivo(std::ostream* arquivo);  
	bool joagdorJaExiste(std::string nome);

};







#endif