#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#define cls system("cls");  //limpa tela
#define pausa getchar();getchar() //#define pausa system("pause");
const int TAMANHO = 20; // fixa o tamnho do vetor e da condicional do for
using namespace std;

int test = 0;

/// prototipos
bool isCheio(int listra[]);
bool isVazia(int lista[]);
int quantidadeOcupado(int lista[]);
int MoveProximo(int indiceAntecessor,int lista[]);
void mostrar(int lista[]);
int procurar(int elemento, int lista[]);
void inserir(int indice, int elemento, int listra[]);
void excluir(int elemento, int lista[]);

void pesquisar(int lista[]);
void adicionar(int lista[]);


/// Variavel Global
int lista[TAMANHO];


/// principal
int main(){
   int opcao;
   setlocale(LC_ALL,"portuguese");
   system("color 2"); // setar cor de o texto e fundo
   /** zona de teste ** zona de teste ** zona de teste ***/
   //for(int i=0; i<TAMANHO; i++){lista[i] = 1;}
   lista[5] = 987;
   lista[8] = 65400;
   lista[19] = 321;
   lista[0] = 123;
   lista[13] = 0;
   lista[15] = 9999;
   /** zona de teste ** zona de teste ** zona de teste ***/
   do{
      cls;
      cout << "\t\tTAD\t\t"<< quantidadeOcupado(lista) << "/"<<TAMANHO<<"\n" <<
              "\t1. Mostrar lista\n" <<
              "\t2. *Inserir elemento*\n" <<
              "\t3. *Remover elemento*\n" <<
              "\t4. procura elemento\n" <<
              "\t0. sair\n" <<
              "\tOpcao: ";
      cin >> opcao;
      switch(opcao){
      case 0:
         exit(true);
      case 1:
         mostrar(lista);
         break;
      case 2:
         adicionar(lista);
         break;
      case 3:
         //excluir();
         break;
      case 4:
         pesquisar(lista);
         break;
      default:
         cout << "\t\topcao inv�lida";
         pausa;
      }
   }while(true); /// coloque sempre verdade no do-while, pois ja  tenho uma verifica�ao interna com switch com exit(true);
}




/// Func�es Prim�rias
bool isCheio(int lista[]){ //ok
  for(int i =0; i<TAMANHO; i++){
    if(lista[i] == 0){
      return false;
		}
	}
  return true;
}

bool isVazia(int lista[]){ //ok otimizado
   for(int i =0; i<TAMANHO; i++){
      if(lista[i] != 0){
         return false;
      }
	}
   return true;
}

int quantidadeOcupado(int lista[]){ //ok otimizado
   int contador = 0;
   for(int i=0; i<TAMANHO; i++){
      if(lista[i] != 0){
         contador++;
      }
   }
   return contador;
}

int moveProximo(int indiceAntecessor,int lista[]){
   int indiceSucessor = indiceAntecessor+1;
   int elementoAntecessor;
   if(lista[indiceSucessor] == 0){
      cout << "sucesso = zero  sucesso pega valor antecesor  : indece A: " << indiceAntecessor <<" S: "<< indiceSucessor << endl;
      cout << "sucesso = zero  sucesso pega valor antecesor  : valor A: " << lista[indiceAntecessor] <<" S: "<< lista[indiceSucessor] << endl;
      lista[indiceSucessor] = lista[indiceAntecessor];
      cout << "atualizado: indece A: " << indiceAntecessor << " S: " << indiceSucessor << endl;
      cout << "atualizado: valor A: " << lista[indiceAntecessor] << " S: " << lista[indiceSucessor] << endl;
      cout << test++;
      pausa;
   }else
      moveProximo(indiceSucessor,lista);
      lista[indiceAntecessor] = 0;
}



void mostrar(int lista[]){ //ok
   cls;
   cout << "\tPosi��o\tElementos \n\n";
   for(int i=0; i<TAMANHO; i++){
      cout << "\t" << i+1 << "�\t" << lista[i] << endl;
	}
	pausa;
}

int procurar(int elemento, int lista[]){ //ok
   for(int i=0; i<TAMANHO; i++){
      if(lista[i] == elemento){
         return i;
      }
   }
   return -1;
}

//!                 em desenvolvimento                        !//
void inserir(int indice, int elemento, int lista[]){ //
   int proximoValor,AnteriorValor,antigoValor,aux;
   if(isCheio(lista)){
      cout << "lista cheia!";
      pausa;
   }else{
      if(indice == 0){                                /// se for no inicio da lista
         if(lista[0] == 0){                           /// verifica se primeiro indice est� vazio
            lista[0] = elemento;                      /// se estive coloque o valor no inicio
         }else{                                       /// se nao tive
            moveProximo(0,lista);
            lista[0] = elemento;
         }
      }

   }

}

void excluir(int elemento, int lista[]){ //

}



/// Func�es Secund�rias
void pesquisar(int lista[]){ //ok
   int elemento;
   cls;
   cout << "\n\n\tValor:";
   cin >> elemento;
   if (procurar(elemento,lista) != -1){
      cout << "\tvalor " << elemento << " encontrado !\n";
      cout << "\tPosic�o: " << procurar(elemento,lista)+1 << "�";
   }else{
      cout << "valor " << elemento << " n�o emcontrado!";
   }
   pausa;
}

void adicionar(int lista[]){
   int elemento,indice,opcao;
      cls;
      cout << "\tvalor do elemento:";
      cin >> elemento;
      /*cout << "\tEm qual posic�o: ";
      cin >> indice;*/
      do{
            cout << "\t\tinserir:\n" <<
                    "\t1. No inicio\n" <<
                    "\t2. No meio\n" <<
                    "\t3. No final\n" <<
                    "\topcao:";
            cin >> opcao;
      switch(opcao){
      case 1:
            inserir(0,elemento,lista);
         break;
      case 2:
            //inserir()
         break;
      case 3:

         break;
      default:
         cout << "opcao inv�lida";
         pausa;
      }

      }while(opcao < 1 || opcao > 3);

}

/********* TAD *************
*@quantidadeDePontos = 2.0
*@dataDeEntrega = 25/04/19
*@Equipe: Os Boc�s
*@Aluno = Saulo Campos
*@aluno =
*@aluno =
*@aluno =
***************************/

