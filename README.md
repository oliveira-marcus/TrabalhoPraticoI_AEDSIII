# Busca de Chaves Pesquisa Sequencial, Árvore Binária e Árvore AVL

Esse projeto faz a criação de arquivos com chaves, dados numéricos e palavras aleatórias, além da busca dessas chaves na Pesquisa Sequencial, Árvore Binária e Árvore AVL.

## Compilando o código

Os arquivos foram disponibilizados em formato .cpp e portanto devem ser compilados. Cada arquivo deve ser compilado individualmente gerando  4 arquivos binários. Todos os binários são programas baseados em terminal, portanto sem interface gráfica.

## Executando o gerador de Arquivos

Uma vez executado, o programa requisitará o usuário o nome do arquivo (**IMPORTANTE**: a extensão .txt ou extensões equivalentes devem ser inclusas, caso for desejado), o tamanho (quantidade de linhas) e o tipo de arquivo desejado (ordenado ou não ordenado). Uma vez respondidas tais prompts, o programa fará a criação de tais arquivos em que cada linha tem o formato *[chave dado1 dado2]*.

## Executando Pesquisa Sequencial, Árvore Binária e Árvore AVL

**IMPORTANTE**: os binários suportam apenas arquivos no formato "*Arquivo[TIPO][TAMANHO].txt*". Ex: **ArquivoOrdenado100.txt**, **ArquivoNãoOrdenado1000.txt**, etc.

Ao executar os binários referentes à Pesquisa Sequencial, Árvore Binária ou Árvore AVL, o programa irá requisitar o usuário o tamanho do arquivo e o tipo. Logo após respondidas tais prompts, os arquivos binários farão 15 pesquisas de chaves presentes e 15 pesquisas de chaves não presentes, mostrando a quantidade de comparações e tempo de execução para cada pesquisa. Caso o usuário indicar NÃO ORDENADO como o tipo do arquivo, o programa fará 15 pesquisas de chaves não presentes e sucessivas tentativas até conseguir fazer 15 pesquisa presentes. Após as pesquisas, o programa irá exibir a quantidade média de comparações e o tempo médio de Pesquisa de chaves presentes e não presentes. 
