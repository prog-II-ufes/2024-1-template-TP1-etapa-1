#ifndef _INDUSTRIALIZADO_H
#define _INDUSTRIALIZADO_H

// Definição do TAD industrializado
typedef struct Industrializado tIndustrializado;

/*
Função que cria um produto industrializado a ser oferecido. Deve-se alocar memória e
    criar um ponteiro para o tipo tIndustrializado e ler seus respectivos atributos.
    O atributo tipo de um produto industrializado é definido pelo caracter 'I'. 
    
*/
tIndustrializado* criaIndustrializado();


/*
Função que imprime a nota fiscal física de um Industrializado a ser comprado por um cliente. 
    As informações impressas são: nome do industrializado, id do industrializado, descrição 
    do industrializado, valor do industrializado, a quantidade comprada e o valor final da 
    compra do industrializado. 
    Mais informações da impressão na especificação e nos exemplos de testes.

@param void *dado: ponteiro do tipo genérico de um dado a constar na impressão da NF física.
@param int qtd: inteiro com a quantidade de produtos industrializados a serem comprados.
*/
void imprimeFisicoIndustrializado(void *dado, int qtd);

/*
Função que imprime a nota fiscal física de um Industrializado a ser comprado por um cliente. 
    As informações impressas são: e-mail de envio do usuário, nome do industrializado, id do 
    industrializado, descrição do industrializado, valor do industrializado, a quantidade comprada 
    e o valor final da compra do industrializado.  
    Mais informações da impressão na especificação e nos exemplos de testes.

@param void *dado: ponteiro do tipo genérico de um dado a constar na impressão da NF digital.
@param char *email: string a constar na impressão da NF digital.
@param int qtd: inteiro com a quantidade de produtos industrializados a serem comprados.
*/
void imprimeDigitalIndustrializado(void *dado, char *email, int qtd);

/*
Função que retorna o valor de um Industrializado (preço).

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar o preço.
@return float: valor do preparo de um Industrializado.
*/
float getValorIndustrializado(void *dado);

/*
Função que retorna o código único de identificação de um Industrializado.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar o id.
@return char*: string com o código único do Industrializado.
*/
char* getCodIndustrializado(void *dado);

/*
Função que retorna a descrição de um Industrializado.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar a descrição.
@return char*: string com a descrição do Industrializado.
*/
char* getDescIndustrializado(void *dado);

/*
Função que retorna o tipo de um produto industrializado.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar o tipo.
@return char: caractere com o tipo do produto industrializado.
*/
char getTipoIndustrializado(void *dado);

/*
Função que retorna o nome de um produto industrializado.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar o nome.
*/
char * getNomeIndustrializado(void *dado);

/*
Função que retorna a disponibilidade de um produto industrializado.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se recuperar a disponibilidade.
@param int qtd: inteiro com a quantidade de produtos industrializados disponíveis.
@return int: inteiro com a disponibilidade do produto industrializado.
*/
int getDisponibilidadeIndustrializado(void *dado, int qtd);

/*
Função que atualiza a disponibilidade de um produto industrializado. Para isso, é necessário subtrair a quantidade
    recebida como parâmetro da quantidade de industrializados disponíveis.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se atualizar a disponibilidade.
@param int qtd: inteiro com a quantidade que deseja-se subtrair da disponibilidade.
*/
void alteraDisponibilidadeIndustrializado(void *dado, int qtd);

/*
Função que imprime os atributos de um Industrializado. As informações do Industrializado a serem impressas são:
    nome, código único, descrição, tipo do industrializado, tipo do produto, e preço do industrializado.
    Mais detalhes nos exemplos/especificação.

@param void *dado: ponteiro do tipo genérico do Industrializado que deseja-se imprimir os atributos.
*/
void printaIndustrializado(void *dado);

/*
Função que libera espaço de memória alocado para um produto industrializado. Se o industrializado for diferente
    de NULL, deve-se liberar a memória alocada para ele.

@param void *dado: ponteiro do tipo genérico de um dado a ser liberado.
*/
void liberaIndustrializado(void * industrializado);

#endif