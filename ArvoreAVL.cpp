#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Node
{
    int key;
    int dado1;
    string dado2;
    Node *left;
    Node *right;
    int height;
};

// Função para criar um novo nó
Node *newNode(int key, int dado1, string dado2)
{
    Node *node = new Node();
    node->key = key;
    node->dado1 = dado1;
    node->dado2 = dado2;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // A nova altura é inicializada como 1
    return node;
}

// Função para calcular a altura de um nó
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para realizar uma rotação para a direita
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retorna o novo nó raiz
    return x;
}

// Função para realizar uma rotação para a esquerda
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retorna o novo nó raiz
    return y;
}

// Função para inserir um novo nó na árvore AVL
Node *insert(Node *node, int key, int dado1, string dado2)
{
    // Realiza a inserção normal de uma árvore binária de busca
    if (node == nullptr)
        return newNode(key, dado1, dado2);

    if (key < node->key)
        node->left = insert(node->left, key, dado1, dado2);
    else if (key > node->key)
        node->right = insert(node->right, key, dado1, dado2);
    else // Chaves iguais não são permitidas em árvores AVL
        return node;

    // Atualiza a altura do nó pai
    node->height = 1 + max(height(node->left), height(node->right));

    // Obtém o fator de balanceamento deste nó para verificar se ele se tornou
    // desbalanceado
    int balance = getBalance(node);

    // Se o nó se tornou desbalanceado, então há quatro casos

    // Caso esquerda-esquerda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso direita-direita
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso esquerda-direita
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso direita-esquerda
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Se o nó estiver balanceado, retorna o próprio nó sem alterações
    return node;
}

// Função para realizar a pesquisa em uma árvore AVL
Node *search(Node *root, int key, int *contador)
{
    // Caso base: a árvore é vazia ou a chave não está presente na árvore
    if (root == nullptr)
    {
        cout << endl
             << "Erro: Chave não está presente na árvore" << endl;
        return nullptr;
    }

    // Chave encontrada na raiz
    if (root->key == key)
    {
        cout << endl
             << "Chave encontrada" << endl;
        return root;
    }

    // A chave é maior que a chave na raiz, então pesquise à direita
    if (root->key < key)
    {
        *contador = *contador + 1;
        return search(root->right, key, contador);
    }
    // A chave é menor que a chave na raiz, então pesquise à esquerda
    *contador = *contador + 1;
    return search(root->left, key, contador);
}

// Função utilitária para imprimir a árvore em ordem
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->key << " " << endl;
        inorderTraversal(root->right);
    }
}

// Função para dividir uma string em várias substrings a parir de espaços em branco
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

    // Lê o arquivo, faz o split e insere os valores na árvore AVL
    ifstream MyReadFile(nomeArquivo);
    string frase;
    string palavras[3];
    Node *root = nullptr;

    while (getline(MyReadFile, frase))
    {
        int size = frase.length();
        split(frase, size, palavras);

        int chave = stoi(palavras[0]);
        int dado1 = stoi(palavras[1]);
        string dado2 = palavras[2];

        root = insert(root, chave, dado1, dado2);
    }

    // Faz o print da Árvore AVL em ordem
    cout << endl;
    cout << "Árvore AVL em ordem: " << endl;
    inorderTraversal(root);
    cout << endl;

    // Mostra o número de comparações e a duração das pesquisas
    srand(time(NULL));
    double comparacoes[15];
    double durations[15];
    int randomNumber;
    int c; // C é o contador de comparações

    // Caso o usuário escolher o tipo de arquivo ordenado
    if (tipo == 1)
    {
        cout << endl
             << "Chaves não presentes: " << endl;
        for (int i = 0; i < 15; i++)
        {
            c = 0;
            randomNumber = (tamanho * 10 + 1) + (rand() % tamanho * 12);

            int start = clock();
            search(root, randomNumber, &c);
            int finish = clock();

            comparacoes[i] = c;
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
            c = 0;
            randomNumber = rand() % tamanho;

            int start = clock();
            search(root, randomNumber, &c);
            int finish = clock();

            comparacoes[i] = c;
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

        cout << endl
             << "Chaves não presentes: " << endl;
        for (int i = 0; i < 15; i++)
        {
            c = 0;
            randomNumber = (tamanho * 10 + 1) + (rand() % tamanho * 12);

            int start = clock();
            search(root, randomNumber, &c);
            int finish = clock();

            comparacoes[i] = c;
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
        Node *result;
        cout << endl;
        cout << endl
             << "Tentativas chaves presentes: " << endl;

        // Mostra o número de comparações e a duração das tentativas de pesquisa bem sucedidas na Árvore AVL não ordenada
        while (tentativasSucedidas < 15)
        {
            c = 0;
            randomNumber = rand() % (tamanho * 10);

            int start = clock();
            result = search(root, randomNumber, &c);
            int finish = clock();

            // Se o resultado um ponteiro não nulo, significa que a pesquisa foi bem sucedida
            if (result != nullptr)
            {
                comparacoes[tentativasSucedidas] = c;
                tentativasSucedidas++;
                cout << "O numero de comparacoes foi " << c << endl;
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
