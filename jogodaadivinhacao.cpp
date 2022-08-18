/*--------------------------------------------------------------------------+
#                                                                           #
#   jogodaadivinhacao.cpp                                                   #
#                                                                           #
#   Este programa tem como principal objetivo estudar as funcionalidades    #
#   básicas da linguagem C++. Para tal foi utilizado o conceito do jogo     #
#   de adivinhação, que consiste na geração de um número aleatório entre    #
#   0 e 100 que terá que ser decifrado por meio de tentativas.              #
#                                                                           #
#   Autor: Gabriel Lavarini <lavarinimoreira@gmail.com>                     #
#   github.com/lavarinimoreira                                              #
#                                                                           #
#--------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

//Declaração das funções.
int inicia_o_jogo();
void imprime_inicio();
int gera_numero_secreto();
bool compara(int, int);

int main (){
    inicia_o_jogo();
}

int inicia_o_jogo(){

    imprime_inicio();
    int numero_secreto = gera_numero_secreto();
    bool condicao = false;
    int tentativas = 0;

    while (!condicao){
        tentativas++;
         int chute;
         cout << "Qual o seu chute? ";
         cin >> chute;

         cout << "O valor do seu chute é: " << chute << endl;

         condicao = compara(numero_secreto, chute);
    }
    
    cout << "\n\nFim de jogo!" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;   

    return EXIT_SUCCESS;
}

void imprime_inicio(){
    cout << "+-------------------------------------+" << endl;
    cout << "| Boas vindas ao Jogo da Adivinhação! |" << endl;
    cout << "+-------------------------------------+" << endl;
}

/*--------------------------------------------------------------+
|   Esta função gera um número inteiro aleatório entre 0 e 100. |
|   Tem como retorno o número gerado.                           |
|--------------------------------------------------------------*/
int gera_numero_secreto(){
    int n = 42;
    return n;
}

/*--------------------------------------------------------------+
|   Esta função recebe como parâmetro o número secreto          |
|   e a tentativa do usuário. Retorna TRUE caso a tentativa     |
|   corresponda ao número secreto e FALSE caso seja diferente.  |
+--------------------------------------------------------------*/
bool compara(int numero_secreto, int chute){
    bool acertou = chute == numero_secreto;
    bool maior = chute > numero_secreto;

     if (acertou){
        cout << "Parabéns! Você acertou o número secreto!" << endl;
        return acertou;
    }

    else if (maior){
        cout << "Seu chute foi maior que o número secreto!" << endl;
        return false;
    }

    else {
        cout << "Seu chute foi menor que número secreto!" << endl;
        return false;
    }
}