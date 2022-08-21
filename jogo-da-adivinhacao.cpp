/*--------------------------------------------------------------------------+
#                                                                           #
#   jogo-da-adivinhacao.cpp                                                   #
#                                                                           #
#   Este programa tem como principal objetivo estudar as funcionalidades    #
#   básicas da linguagem C++. Para tal foi utilizado o conceito do jogo     #
#   de adivinhação, que consiste na geração de um número aleatório entre    #
#   0 e 99 que terá que ser decifrado por meio de tentativas.               #
#                                                                           #
#   Autor: Gabriel Lavarini <lavarinimoreira@gmail.com>                     #
#   github.com/lavarinimoreira                                              #
#                                                                           #
#--------------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Declaração das funções.
int inicia_o_jogo();
void imprime_inicio();
int gera_numero_secreto();
bool compara(int, int);

int main (){
    int jogar_novamente;
    do{
        inicia_o_jogo();
        cout << "1 - Jogar novamente\n2 - Sair" << endl;
        cin >> jogar_novamente;
    }while(jogar_novamente != 2);
    
    return EXIT_SUCCESS;
}

int inicia_o_jogo(){
    imprime_inicio();

    int dificuldade = 0;
    do{
         cout << "Escolha o nível de dificuldade: " << endl;
         cout << "1 - Fácil\n2 - Médio\n3 - Difícil\n";    
        cin >> dificuldade;
        if(dificuldade < 1 || dificuldade > 3){
            cout << "Nível INVÁLIDO." << endl;
        }
    }while(dificuldade < 1 || dificuldade > 3);
    
    int numero_de_tentativas;
    switch (dificuldade){
        case 1: numero_de_tentativas = 15;
            break;
        case 2: numero_de_tentativas = 10;
            break;
        case 3: numero_de_tentativas = 5; 
        default:
            break;
    }

    const int NUMERO_SECRETO = gera_numero_secreto();
    bool condicao = false;
    int tentativas;
    double pontos = 1000.0;

    for(tentativas = 0; tentativas < numero_de_tentativas && !condicao; tentativas++){
        cout << "Tentativa número " << tentativas+1 << endl;
        int chute;
        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs/*absolute*/(chute - NUMERO_SECRETO);
        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;

        condicao = compara(NUMERO_SECRETO, chute);
    }
    
    cout << "\n\nFim de jogo!" << endl;

    if(!condicao){
        cout << "Perdeu =/\n\n";
    }else{
        cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;   
        cout.precision(2); //Definindo quantas casas após a vírgula serão mostradas.
        cout << fixed; //Fixando para não mostrar em notação científica.
        cout << "Sua pontuação foi de " << pontos << " pontos.\n" << endl;
    }

    return EXIT_SUCCESS;
}

void imprime_inicio(){
    cout << "+-------------------------------------+" << endl;
    cout << "| Boas vindas ao Jogo da Adivinhação! |" << endl;
    cout << "+-------------------------------------+" << endl;
}

/*--------------------------------------------------------------+
|   Esta função gera um número inteiro aleatório entre 1 e 99.  |
|   Tem como retorno o número gerado.                           |
|--------------------------------------------------------------*/
int gera_numero_secreto(){
    srand(time(NULL)); // "Semente" para gerar um número aleatório.
    int n = rand() % 100;
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
        cout << "Parabéns! Você acertou o número secreto!\n" << endl;
        return acertou;
    }
    else if (maior){
        cout << "Seu chute foi maior que o número secreto!\n" << endl;
    }
    else {
        cout << "Seu chute foi menor que número secreto!\n" << endl;
    }
    return false;
}
