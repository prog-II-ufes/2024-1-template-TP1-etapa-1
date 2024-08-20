#ifndef _AVALIACAO_H
#define _AVALIACAO_H

typedef struct Avaliacao tAvaliacao;

/*
Função que cria uma nova avaliação a ser associada a um produto cadastrado por uma loja.
    Deve-se criar um ponteiro do tipo tAvaliacao, ler os atributos de uma avaliação (comentário
    e nota) e deve-se associar o CPF passado como parâmetro à avaliação criada. Retorna-se o 
    ponteiro de tAvaliacao criado.

@param char *cpf: CPF do usuário criando a avaliação.
@return tAvaliacao*: ponteiro para o tipo tAvaliacao criado.
*/
tAvaliacao * criaAvaliacao(char * cpfUsuario);

/*
Função que retorna a string comentario da Avaliação passada como parâmetro. 

@param tAvaliacao *a: ponteiro do tipo tAvaliacao que deseja-se recuperar o comentário.
*/
char * getComentarioAvaliacao(tAvaliacao * a);


/*
Função que retorna a nota da Avaliação passada como parâmetro.

@param tAvaliacao *a: ponteiro do tipo tAvaliacao que deseja-se recuperar a nota.
*/
int getNotaAvaliacao(tAvaliacao * a);

/*
Função que retorna o CPF do cliente que realizou a avaliação.

@param tAvaliacao *a: ponteiro do tipo tAvaliacao que deseja-se recuperar o CPF do cliente.
*/
char * getCpfClienteAvaliacao(tAvaliacao * a);

/*
Função que libera espaço de memória alocado para uma avaliação. Se a avaliação for diferente de NULL,
    deve-se liberar o espaço alocado para ela.

@param tAvaliacao *a: ponteiro do tipo tAvaliacao a ser liberado.
*/
void liberaAvaliacao(tAvaliacao * a);

#endif