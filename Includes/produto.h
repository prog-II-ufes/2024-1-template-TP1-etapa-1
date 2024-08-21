#ifndef _PRODUTO_H
#define _PRODUTO_H

// Definição do apelido do TAD tProduto
typedef struct Produto tProduto;

// Faz include de avaliacoes.h porque existe um vetor de avaliações para cada produto cadastrado em uma loja.
#include "avaliacao.h"

// Definição de todos os ponteiros de função que serão executados por Callback por diferentes produtos
typedef void (*func_ptr_imprimeFisico)(void *dado, int qtd);
typedef void (*func_ptr_imprimeDigital)(void *dado, char *email, int qtd);
typedef void (*func_ptr_libera)(void *dado);
typedef float (*func_ptr_valor)(void *dado);
typedef char *(*func_ptr_codProduto)(void *dado);
typedef char *(*func_ptr_nomeProduto)(void *dado);
typedef char (*func_ptr_tipoProduto)(void *dado);
typedef char *(*func_ptr_descProduto)(void *dado);
typedef int (*func_ptr_disponibilidade)(void *dado, int qtd);
typedef void (*func_ptr_atualizaDisponibilidade)(void *dado, int qtd);
typedef void (*func_ptr_printaProduto)(void *dado);

/*
Função que realiza a criação de produtos e retorna o produto criado ao sistema. Quando invocada,
    são passados como parâmetros o dado (do tipo genérico) e todas as funções de Callback que este dado
    pode executar.

@param dado: ponteiro do tipo genérico para um produto a ser armazenado em produto
@param imprimeFisico: ponteiro de função do tipo void que tem como parâmetro um ponteiro do tipo genérico
    para um dado (void *)
@param imprimeDigital: ponteiro de função do tipo void que tem como parâmetros um ponteiro do tipo genérico
    para um dado (void *) e uma string (char *)
@param libera: ponteiro de função do tipo void que tem como parâmetro um ponteiro do tipo genérico
    para um dado (*void)
@param valor: ponteiro de função do tipo float (retorna um float) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)
@param codProduto: ponteiro de função do tipo string (retorna um char*) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)
@param nomeProduto: ponteiro de função do tipo string (retorna um char*) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)
@param tipoProduto: ponteiro de função do tipo char (retorna um char) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)
@param descProduto: ponteiro de função do tipo string (retorna um char*) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)
@param disponibilidade: ponteiro de função do tipo inteiro (retorna um int) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *) e um inteiro (int)
@param diminuiDisponibilidade: ponteiro de função do tipo void que tem como parâmetro um ponteiro do tipo genérico
    para um dado (void *) e um inteiro (int)
@param printaProduto: ponteiro de função do tipo genérico (void) que tem como parâmetro um ponteiro do
    tipo genérico para um dado (void *)

@return tProduto *: Ponteiro do tipo tProduto criado.
*/
tProduto *criaProduto(void *dado, func_ptr_imprimeFisico imprimeFisico, func_ptr_imprimeDigital ImprimeDigital,
                      func_ptr_libera libera, func_ptr_valor valor, func_ptr_codProduto codProduto,
                      func_ptr_nomeProduto nomeProduto, func_ptr_tipoProduto tipoProduto,
                      func_ptr_descProduto descProduto, func_ptr_disponibilidade disponibilidade,
                      func_ptr_atualizaDisponibilidade atualizaDisponibilidade, func_ptr_printaProduto printaProduto);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade liberar a memória alocada para o produto criado. Após, deve-se verificar se as avaliações
    do produto são diferentes de NULL, e em caso positivo, deve-se liberar a memória alocadas. Por fim, deve-se liberar
    a memória alocada para produto.
@param tProduto *prod: ponteiro do tipo tProduto.
*/
void liberaProduto(tProduto *prod);

/*
Função que realiza a inserção de uma avaliação em um produto cadastrado. Recebe como parâmetros o ponteiro para
    o produto e um ponteiro para a avaliação que precisa ser associada ao produto.

@param tProduto *prod: ponteiro do tipo tProduto.
@param tAvaliacao * avaliacao: ponteiro do tipo tAvaliacao.
*/
void insereAvaliacaoProduto(tProduto *prod, tAvaliacao *avaliacao);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade imprimir a nota física do produto comprado.

@param tProduto *prod: ponteiro do tipo tProduto.
@param int qtd: inteiro com a quantidade de produtos que devem ser impressos.
*/
void imprimeFisico(tProduto *prod, int qtd);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade imprimir a digital do produto comprado, encaminhada a um e-mail passado como parâmetro.

@param tProduto *prod: ponteiro do tipo tProduto.
@param char *email: string que deve constar na nota digital.
@param int qtd: inteiro com a quantidade de produtos que devem ser impressos.
*/
void imprimeDigital(tProduto *prod, char *email, int qtd);

/*
Função que retorna o item genérico armazenado em um produto.

@param tProduto *prod: ponteiro do tipo tProduto.
@return void *: ponteiro do tipo genérico armazenado em um produto.
*/
void *getItemProduto(tProduto *prod);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar o valor do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@return float: valor real referente ao preço do produto cadastrado por uma loja.
*/
float getValorProduto(tProduto *prod);


/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar o código único de cadastro do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@return char*: string referente ao código único do produto cadastrado por uma loja.
*/
char *getCodProduto(tProduto *prod);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar o nome de cadastro do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@return char*: string referente ao nome do produto cadastrado por uma loja.
*/
char *getNomeProduto(tProduto *prod);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar a descrição do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@return char*: string referente a descrição do produto cadastrado por uma loja.
*/
char *getDescProduto(tProduto *prod);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar o tipo do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@return char: caractere referente ao tipo do produto cadastrado por uma loja.
*/
char getTipoProduto(tProduto *prod);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade recuperar a disponibilidade do produto genérico cadastrado por uma loja.

@param tProduto *prod: ponteiro do tipo tProduto.
@param int qtd: inteiro com a quantidade de produtos que deve-se verificar a disponibilidade.
*/
int getDisponibilidadeProduto(tProduto *prod, int qtd);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade atualizar a disponibilidade do produto genérico cadastrado por uma loja, retirando o
    valor do parâmetro quantidade a este produto.

@param tProduto *prod: ponteiro do tipo tProduto.
@param int qtd: inteiro com a quantidade de produtos que devem ser subtraídos da disponibilidade.
*/
void alteraDisponibilidadeProduto(tProduto *prod, int qtd);

/*
Função que imprime todas as avaliações de um produto e no final imprime a média das avaliações.

@param tProduto *produto: ponteiro do tipo tProduto.
*/
void printaAvaliacoesProduto(tProduto *produto);

/*
Função que realiza a execução da função de Callback passada como parâmetro na criação do tProduto. Esta função
    tem como finalidade imprimir informações (como código, descrição, etc.) do produto genérico cadastrado por
    uma loja. Mais detalhes nos casos de teste fornecidos.

@param tProduto *prod: ponteiro do tipo tProduto.
*/
void printaProduto(tProduto *prod);

#endif