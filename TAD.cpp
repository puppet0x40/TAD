#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#define cls system("cls");  //limpa tela
#define pausa getchar();getchar()
//#define pausa system("pause") //

using namespace std;

/// prototipos
bool isCheio( int listra[]);
bool isVazia(int lista[]);
int quantiadeOcupado(int lista[]);
void mostrar(int lista[]);
void inserir(int indice, int elementos, int listra[]);
int procurar(int elementos, int lista[]);
void excluir(int elementos, int lista[]);

void pesquisar(int lista[]);


/// Variavel Global
int lista[20];


/// principal
int main(){
   int opcao;
   setlocale(LC_ALL,"portuguese");
   lista[5] = 99;
   while(true){
      do{
         cls;
         cout << "\t\tTAD\t\t elementos: "<< quantiadeOcupado(lista) <<"/20\n" <<
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
            //inserir();
            break;
         case 3:
            //excluir();
            break;
         case 4:
            pesquisar(lista);
            break;
         default:
            cout << "\t\topcao inválida";
            pausa;
         }
      }while(opcao < 0 || opcao > 4);
   }
}




/// Funcões Primárias
bool isCheio(int lista[]){ //ok
  for(int i =0; i<20; i++){
    if(lista[i] == 0){
      return false;
		}
	}
  return true;
}

bool isVazia(int lista[]){ //ok
   for(int i =0; i < 20; i++){
      if(lista[i] != 0){
         return false;
      }
	}
   return true;
}

int quantiadeOcupado(int lista[]){ //ok
   int contador = 0;
   for(int i=0; i<20; i++){
      if(lista[i] != 0){
         contador++;
      }
   }
   return contador;
}

void mostrar(int lista[]){ //ok
   cls;
   cout << "\t\tlista:\n";
   for(int i=0; i<20; i++){
      cout << "\tElemento " << i+1 << ":\t" << lista[i] << endl;
	}
	pausa;
}

int procurar(int elemento, int lista[]){ //ok
   for(int i=0; i<20; i++){
      if(lista[i] == elemento){
         cout << "\tO valor encontrado!\n";
         cout << "\tO valor é o elemento " << i+1;
         return lista[i];
      }
   }
   cout << "Valor nao encontrado!";
}

void inserir(int indice, int elementos, int listra[]){

}

void excluir(int elementos, int lista[]){

}



/// Funcões Secundárias
void pesquisar(int lista[]){
   int elemento;
   cls;
   cout << "\tValor:";
   cin >> elemento;
   procurar(elemento,lista);
   pausa;
}



/********* TAD *************
*@quantidadeDePontos = 2.0
*@dataDeEntrega = 25/04/19
*@Equipe: Os Bocós
*@Aluno = Saulo Campos
*@aluno =
*@aluno =
*@aluno =
***************************/
