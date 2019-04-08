#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#define cls system("cls");  //limpa tela
#define pausa getchar();getchar()
//#define pausa system("pause") //
const int TAMANHO = 20; // fixa o tamnho do vetor e da condicional do for

using namespace std;

/// prototipos
bool isCheio(int listra[]);
bool isVazia(int lista[]);
int quantidadeOcupado(int lista[]);
void mostrar(int lista[]);
void inserirInicio(int elemento,int lista[]);
void inserir(int indice, int elemento, int listra[]);
int procurar(int elemento, int lista[]);
void excluir(int elemento, int lista[]);

void pesquisar(int lista[]);
void adicionar(int lista[]);


/// Variavel Global
int lista[TAMANHO];


/// principal
int main(){
   int opcao;
   setlocale(LC_ALL,"portuguese");
   /** zona de teste ** zona de teste ** zona de teste ***/
   //for(int i=0; i<TAMANHO; i++){lista[i] = 1;}
   lista[5] = 987;
   lista[8] = 65400;
   lista[19] = 321;
   lista[1] = 123;
   lista[13] = 0;
   lista[15] = 9999;
   /** zona de teste ** zona de teste ** zona de teste ***/
   while(true){
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
      }while(opcao < 0 || opcao > 4);
   }
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

bool isVazia(int lista[]){ //ok
   for(int i =0; i<TAMANHO; i++){
      if(lista[i] != 0){
         return false;
      }
	}
   return true;
}

int quantidadeOcupado(int lista[]){ //ok
   int contador = 0;
   for(int i=0; i<TAMANHO; i++){
      if(lista[i] != 0){
         contador++;
      }
   }
   return contador;
}

void inserirInicio(int elemento,int lista[]){


}

void mostrar(int lista[]){ //ok
   cls;
   cout << "\tPosi��o\tElementos\n\n";
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
   return 0;
}

void inserir(int indice, int elemento, int listra[]){
   if(isCheio(lista)){
      cout << "lista cheia!";
      pausa;
   }
   lista[indice] = elemento;

}

void excluir(int elemento, int lista[]){

}



/// Func�es Secund�rias
void pesquisar(int lista[]){
   int elemento;
   cls;
   cout << "\n\n\tValor:";
   cin >> elemento;
   if (procurar(elemento,lista)){
      cout << "\tvalor " << elemento << " encontrado !\n";
      cout << "\tPosic�o: " << procurar(elemento,lista)+1;
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
            inserirInicio(elemento,lista);
         break;
      case 2:

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

