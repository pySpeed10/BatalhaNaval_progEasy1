#include <iostream>
#include <locale.h>
#include <math.h>
#include <time.h>

#define V 5

using namespace std;

void inicializa(char M[][5], int linha[3], int coluna[3], int qtdL[5], int qtdC[5]);

void palpite(char M[][5], int linha[3], int coluna[3], int qtdL[5], int qtdC[5]);

void mostra(char M[][5]);

char M[V][V] = {{'-', '-', '-', '-', '-'},
               {'-', '-', '-', '-', '-'},
               {'-', '-', '-', '-', '-'},
               {'-', '-', '-', '-', '-'},
               {'-', '-', '-', '-', '-'}};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int linha[3], coluna[3], qtdL[5]={}, qtdC[5]={};
    string nome;

    inicializa(M, linha, coluna, qtdL, qtdC);

    palpite(M, linha, coluna, qtdL, qtdC);

    //cout<<"Nome do Jogador:  ";
    //cin>>nome;
    //system ("Cls");

    //mostra(M);

     for(int r=0; r<3; r++){
       cout<<"Linha: "<<linha[r]+1<<"   ";
       cout<<"Coluna: "<<coluna[r]+1<<"   \n";
    }

}

void mostra(char M[][5]){

    cout<<"     "<<1<<"    "<<2<<"    "<<3<<"    "<<4<<"    "<<5<<"    \n";
    for(int i=0; i<5; i++){
        cout<<i+1<<"    ";
        for(int j=0; j<5; j++){
            cout<<M[i][j]<<"    ";
        } cout<<endl;
    }
}

void inicializa(char M[][5], int linha[3], int coluna[3], int qtdL[5], int qtdC[5]){

    int x=0, i, j, igual;

    srand(time(NULL)); //garantir que a cada vez, troque a sequencia, se baseia no tempo

    do{
            i = rand() % 4; //gera numeros aleatorios      o % 5 representa de 0 a 5
            j = rand() % 4;

            igual = 0;
            //for(int k=0; k<x; k++){
                for(int t=0; t<x; t++){
                if(linha[i]==linha[t] && coluna[j]==coluna[t]){
                    igual = 1;
                }
             // }
            }
                if(igual == 0){
                    linha[x] = i;
                    coluna[x] = j;
                    x++;
                }
    } while(x<3);
}

void palpite(char M[][5], int linha[3], int coluna[3], int qtdL[5], int qtdC[5]){

    int x=0, i, j, tiro, fim=0, tentativa=0, nl=0, nc=0, pos;



    for(int i = 0; i < 3; i++)
  { int aux=0;
     for(int j = 0; j < 3; j++)
     {
         if(linha[i] == linha[j])               // compara as 2 senhas, sem levar em conta a ordem dos termos
         {
            aux += 1; //numeros corretos
         }
     }
     qtdL[linha[i]] = aux;
 }

     for(int i = 0; i < 3; i++)
  { int aux=0;
     for(int j = 0; j < 3; j++)
     {
         if(coluna[i] == coluna[j])               // compara as 2 senhas, sem levar em conta a ordem dos termos
         {
            aux += 1; //numeros corretos
         }
     } qtdC[i] = aux;
 }



 //ver daqui para cima

    while(fim<3){

    do{
     cout<<"Palpite (de 1 a 5): \n";
     cout<<"Linha: ";
     cin>>i;
     cout<<"Coluna: ";
     cin>>j;
    } while(i <= 0 && i > 5 && j <= 0 && j > 5);

    do{
            tiro = 0;
                for(int t=0; t<3; t++){
                if(i-1==linha[t] && j-1==coluna[t] && M[i-1][j-1] != 'X'){
                    M[i-1][j-1] = 'X';
                    tiro = 1;
                    x++;
                    fim++;
                }
              }
                if(tiro == 0){
                    M[i-1][j-1] = '*';
                    x++;
                }

    } while(x<3);

    tentativa++;

    system("CLS");

    cout<<"Dica "<<tentativa<<":    \n";
    cout<<"Linha  "<<i<<" -> "<<qtdL[i-1]<<" navios.\n";
    cout<<"Coluna  "<<j<<" -> "<<qtdC[j-1]<<" navios.\n";
    if(tiro == 1) cout<<"Você acertou o tiro ("<<i<<","<<j<<")\n\n";
    else cout<<"Você não acertou o tiro ("<<i<<","<<j<<")\n\n";

    if(fim == 3) cout<<"Jogo terminado. Você acertou os 3 navios em "<<tentativa<<" tentativas.\n";

    mostra(M);
    cout<<"\n\n";

   }
}
