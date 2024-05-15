#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

// Função para embaralhar um array de strings
void wordShuffle(string array[], int tamanho)
{
  // Obtém uma semente única com base no relógio do sistema
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  // Embaralha o array usando a semente obtida
  shuffle(array, array + (tamanho - 1), default_random_engine(seed));
}

// Função para gerar números aleatórios e populacionar um array com eles
void GeradorNumerosAleatorios(int populacao[], int amostra[], int tamanho)
{
  // Popula um array com números sequenciais
  for (int i = 0; i < tamanho * 10; i++)
  {
    populacao[i] = i;
  }

  // Obtém uma semente única com base no relógio do sistema
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  // Embaralha o array de números sequenciais
  shuffle(populacao, populacao + (tamanho * 10 - 1), default_random_engine(seed));

  // Seleciona uma amostra aleatória dos números embaralhados
  for (int i = 0; i < tamanho; i++)
  {
    amostra[i] = populacao[i];
  }
}

int main()
{
  string arquivo;
  cout << "Digite o nome do arquivo: ";
  cin >> arquivo;

  // Abre um arquivo de leitura
  ifstream MyReadFile("words.txt");

  int size;
  cout << "Digite o tamanho desejado para o arquivo: ";
  cin >> size;

  int tipo;
  cout << "Tipo de arquivo desejado:" << endl;
  cout << "1. ORDENADO" << endl;
  cout << "2. NAO ORDENADO" << endl;
  cin >> tipo;

  // Declara um array de strings para armazenar as palavras do arquivo
  string words[10000];
  int i = 0;

  // Lê o arquivo e armazena as palavras em um array
  string word;
  while (getline(MyReadFile, word))
  {
    words[i] = word;
    i++;
  }

  // Embaralha as palavras lidas do arquivo
  wordShuffle(words, 10000);

  // Cria um array de strings do tamanho especificado pelo usuário
  string strings[size];

  // Seleciona um número de palavras aleatórias para o novo array
  for (int i = 0; i < size; i++)
  {
    strings[i] = words[i];
  }

  // Declara dois arrays para armazenar amostras de números aleatórios
  int amostraDados[size];
  int amostraChaves[size];

  if (tipo == 1)
  {
    // Se o tipo for ordenado, gera amostras de números sequenciais
    for (int i = 0; i < size; i++)
    {
      amostraChaves[i] = i;
    }

    // Declara um array para armazenar uma população de números aleatórios
    int populacaoDados[size * 10];
    int tamanhoDados = sizeof(amostraDados) / sizeof(int);

    // Gera números aleatórios para a população
    GeradorNumerosAleatorios(populacaoDados, amostraDados, tamanhoDados);
  }
  else
  {
    // Se o tipo for não ordenado, gera amostras de números aleatórios
    int populacaoChaves[size * 10];
    int tamanhoChaves = sizeof(amostraChaves) / sizeof(int);

    // Gera números aleatórios para a população de chaves
    GeradorNumerosAleatorios(populacaoChaves, amostraChaves, tamanhoChaves);

    // Gera números aleatórios para a população de dados
    int populacaoDados[size * 10];
    int tamanhoDados = sizeof(amostraDados) / sizeof(int);

    // Gera números aleatórios para a população de dados
    GeradorNumerosAleatorios(populacaoDados, amostraDados, tamanhoDados);
  }

  // Abre um arquivo de escrita
  ofstream myfile;
  myfile.open(arquivo);

  // Escreve os dados no arquivo
  for (int i = 0; i < size; i++)
  {
    if (i == size - 1)
    {
      myfile << amostraChaves[i] << " " << amostraDados[i] << " " << strings[i];
    }
    else
    {
      myfile << amostraChaves[i] << " " << amostraDados[i] << " " << strings[i] << endl;
    }
  }
  // Fecha o arquivo
  myfile.close();
}
