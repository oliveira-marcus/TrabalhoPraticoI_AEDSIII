#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

// Algoritmo de Pesquisa Sequencial
int PesquisaSequencial(string registros[][3], int chave, int tamanho)
{
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        contador++;
        if (stoi(registros[i][0]) == chave)
        {
            cout << endl
                 << "Registro encontrado" << endl;
            return contador;
        }
    }
    cout << endl
         << "Registro não encontrado" << endl;
    return -1 * contador;
}

// Função para dividir uma string em várias substrings a partir de espaços em branco
void split(string str, int size, string palavras[])
{
    int lastspace = -1;
    int contador = 0;

    for (int i = 0; i < size; i++)
    {
        if (str.at(i) == ' ')
        {
            palavras[contador] = str.substr(lastspace + 1, i - lastspace - 1);
            contador++;
            lastspace = i;
        }
        if (i == size - 1)
        {
            palavras[contador] = str.substr(lastspace + 1, i - lastspace);
        }
    }
}

// Função para calcular a media dos valores de uma array
double media(double arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

int main()
{
    // Interface para o usuário escolher o tamanho do arquivo
    int tamanho;
    cout << "Insira o tamanho do arquivo: ";
    cin >> tamanho;

    string nomeArquivo;
    int tipo;

    // Interface para o usuário escolher o tipo de arquivo
    if (tamanho == 100)
    {
        cout << "Ordenado ou Não Ordenado?" << endl;
        cout << "1. Ordenado" << endl;
        cout << "2. Não Ordenado" << endl;
        cin >> tipo;
        if (tipo == 1)
        {
            nomeArquivo = "ArquivoOrdenado100.txt";
        }
        else
        {
            nomeArquivo = "ArquivoNãoOrdenado100.txt";
        }
    }

    else if (tamanho == 500)
    {
        cout << "Ordenado ou Não Ordenado?" << endl;
        cout << "1. Ordenado" << endl;
        cout << "2. Não Ordenado" << endl;
        cin >> tipo;
        if (tipo == 1)
        {
            nomeArquivo = "ArquivoOrdenado500.txt";
        }
        else
        {
            nomeArquivo = "ArquivoNãoOrdenado500.txt";
        }
    }

    else if (tamanho == 1000)
    {
        cout << "Ordenado ou Não Ordenado?" << endl;
        cout << "1. Ordenado" << endl;
        cout << "2. Não Ordenado" << endl;
        cin >> tipo;
        if (tipo == 1)
        {
            nomeArquivo = "ArquivoOrdenado1000.txt";
        }
        else
        {
            nomeArquivo = "ArquivoNãoOrdenado1000.txt";
        }
    }

    else if (tamanho == 5000)
    {
        cout << "Ordenado ou Não Ordenado?" << endl;
        cout << "1. Ordenado" << endl;
        cout << "2. Não Ordenado" << endl;
        cin >> tipo;
        if (tipo == 1)
        {
            nomeArquivo = "ArquivoOrdenado5000.txt";
        }
        else
        {
            nomeArquivo = "ArquivoNãoOrdenado5000.txt";
        }
    }

    else if (tamanho == 10000)
    {
        cout << "Ordenado ou Não Ordenado?" << endl;
        cout << "1. Ordenado" << endl;
        cout << "2. Não Ordenado" << endl;
        cin >> tipo;
        if (tipo == 1)
        {
            nomeArquivo = "ArquivoOrdenado10000.txt";
        }
        else
        {
            nomeArquivo = "ArquivoNãoOrdenado10000.txt";
        }
    }

    // Lê o arquivo e armazena as strings em um array
    ifstream MyReadFile(nomeArquivo);
    string frase;
    string registros[tamanho][3];
    int i = 0;

    while (getline(MyReadFile, frase))
    {
        int size = frase.length();
        split(frase, size, registros[i]);
        i++;
    }

    // Faz o print da Matriz
    cout << endl;
    cout << "Chaves da matriz: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << registros[i][0] << endl;
    }

    // Mostra o número de comparações e a duração das pesquisas
    srand(time(NULL));
    double comparacoes[15];
    double durations[15];
    int randomNumber;

    // Caso o usuário escolher o tipo de arquivo ordenado
    if (tipo == 1)
    {
        cout << "Chaves não presentes: " << endl;
        for (int i = 0; i < 15; i++)
        {

            randomNumber = (tamanho * 10 + 1) + (rand() % tamanho * 12);

            int start = clock();
            comparacoes[i] = PesquisaSequencial(registros, randomNumber, tamanho) * -1; // Como a pesquisa não foi bem sucedida, o número de comparações tem que ser multiplicado por -1
            int finish = clock();

            cout << "O numero de comparacoes foi " << comparacoes[i] << endl;
            double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
            durations[i] = duration;
            cout << "Tempo de Pesquisa: ";
            printf("%2.7f seconds\n", duration);
        }

        cout << endl;
        cout << "Media comparacoes: " << media(comparacoes, 15) << endl;
        cout << "Media tempo de pesquisa: ";
        printf("%2.7f seconds\n", media(durations, 15));

        cout << endl
             << "Chaves presentes: " << endl;
        for (int i = 0; i < 15; i++)
        {

            int randomNumber = rand() % tamanho;

            int start = clock();
            comparacoes[i] = PesquisaSequencial(registros, randomNumber, tamanho);
            int finish = clock();

            cout << "O numero de comparacoes foi " << comparacoes[i] << endl;
            double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
            durations[i] = duration;
            cout << "Tempo de Pesquisa: ";
            printf("%2.7f seconds\n", duration);
        }

        cout << endl;
        cout << "Media comparacoes: " << media(comparacoes, 15) << endl;
        cout << "Media tempo de pesquisa: ";
        printf("%2.7f seconds\n", media(durations, 15));
    }

    // Caso o usuário escolher o tipo de arquivo não ordenado
    else
    {

        cout << "Chaves não presentes: " << endl;
        for (int i = 0; i < 15; i++)
        {

            randomNumber = (tamanho * 10 + 1) + (rand() % tamanho * 12);

            int start = clock();
            comparacoes[i] = PesquisaSequencial(registros, randomNumber, tamanho) * -1; // Como a pesquisa não foi bem sucedida, o número de comparações tem que ser multiplicado por -1
            int finish = clock();

            cout << "O numero de comparacoes foi " << comparacoes[i] << endl;
            double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
            durations[i] = duration;
            cout << "Tempo de Pesquisa: ";
            printf("%2.7f seconds\n", duration);
        }

        cout << endl;
        cout << "Media comparacoes: " << media(comparacoes, 15) << endl;
        cout << "Media tempo de pesquisa: ";
        printf("%2.7f seconds\n", media(durations, 15));

        int tentativasSucedidas = 0;
        int comparacao;
        cout << endl;
        cout << endl
             << "Tentativas chaves presentes: " << endl;

        // Mostra o número de comparações e a duração das tentativas de pesquisa bem sucedidas na Árvore AVL não ordenada
        while (tentativasSucedidas < 15)
        {

            randomNumber = rand() % (tamanho * 10);

            int start = clock();
            comparacao = PesquisaSequencial(registros, randomNumber, tamanho);
            int finish = clock();

            // Se a comparacao retornar um numero positivo, significa que a pesquisa foi bem sucedida
            if (comparacao > 0)
            {
                comparacoes[tentativasSucedidas] = comparacao;
                tentativasSucedidas++;
                cout << "O numero de comparacoes foi " << comparacao << endl;
                double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
                durations[tentativasSucedidas] = duration;
                cout << "Tempo de Pesquisa: ";
                printf("%2.7f seconds\n", duration);
            }
        }

        cout << endl;
        cout << "Media comparacoes: " << media(comparacoes, 15) << endl;
        cout << "Media tempo de pesquisa: ";
        printf("%2.7f seconds\n", media(durations, 15));
    }
}
