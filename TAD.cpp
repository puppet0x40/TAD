#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
///
#define cls system("cls");          /// limpa (cmd) Prompt de Comando
#define pausa getchar();getchar()   /// pausa Prompt de Comando
const int TAMANHO = 20;             /// fixar o TAMANHO do vetor e da condicional do for
using namespace std;

int test = 0;

/// prototipos
bool isCheio(int listra[]);                           /// verifica se a lista está cheia
bool isVazia(int lista[]);                            /// verifica se a lista está vazia
int quantidadeOcupado(int lista[]);                   /// verifica a quantidades de elementos que estao ocupados
void troca(int &a,int &b);                            /// troca valores entre duas variaveis
int pularElementosParaDireita(int lista[]);           /// pula os todos elementos um casa para direita se proximo elemento for zero
int pularElementosParaEsquerda(int lista[]);           /// pula os todos elementos um casa para esquerda se anterior elemento for zero
void mostrar(int lista[]);                            /// mostra toda elementos lista!
int procurar(int elemento, int lista[]);              /// funcao: procura um elemento específico na lista
void pesquisar(int lista[]);                          /// interface: procura um elemento específico na lista que usuario digitou

/// prototipos em desenvolvimento
void inserir(int indice, int elemento, int listra[]); /// funcao: inserir elemento específico na lista
void excluir(int elemento, int lista[]);              ///
void adicionar(int lista[]);                          /// interface: inserir elemento específico na lista que usuario digitou

///besteira
void Equipe();


/// Variavel Global
int lista[TAMANHO];


/// principal
int main(){
   int opcao;
   setlocale(LC_ALL,"portuguese");
   system("color 2"); // setar cor de o texto e fundo
   /** zona de teste ** zona de teste ** zona de teste ****
   //for(int i=0; i<TAMANHO; i++){lista[i] = 1;}
   lista[5] = 1;
   lista[8] = 2;
   lista[19] = 3;
   lista[0] = 4;
   lista[13] = 5;
   lista[15] = 6;
   /** zona de teste ** zona de teste ** zona de teste ***/
   do{
      cls;
      cout << "\t\tTAD\t\t"<< quantidadeOcupado(lista) << "/"<<TAMANHO<<"\n" <<
              "\t1. Inserir elemento\n" <<
              "\t2. *Remover elemento*\n" <<
              "\t3. procurar elemento\n" <<
              "\t4. Mostrar lista\n" <<
              "\t5. Ordenar lista\n" <<
              "\t0. sair\n" <<
              "\tOpcao: ";
      cin >> opcao;
      switch(opcao){
      case 0:
         Equipe();                                    /// mostra nome da equipe e dos integrante
         exit(true);                                  /// fecha o programa
      case 1:
          adicionar(lista);                           /// abre a interface de inserir elementos
         break;
      case 2:
         //remove                                        /// abre interface de remove elementos
         break;
      case 3:
         pesquisar(lista);                            /// abre interface de busca de elementos na lista
         break;
      case 4:
         mostrar(lista);                              /// mostra toda lista
         break;
      case 5:
         Equipe();                                    /// extra
         break;
      default:
         cout << "\t\topcao inválida";                ///
         pausa;
      }
   }while(true); /// coloque sempre verdade no do-while, pois ja  tenho uma verificaçao interna com switch com exit(true);
}




/// Funcões Primárias
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


void troca(int &a, int &b){               /// ! passagem por enderenço ! usa-se & no mone da variavel para dizer que vamos passa o endereço dele
   int aux = a;                           /// antes de modifica  fiz backup do  valor do A
   a = b;                                 /// A pega valor de B
   b = aux;                               /// B pega valor do A que tava salvo na aux
}

int pularElementosParaDireita(int lista[]){ //ok
   //int aux;
   for(int i=0; i<TAMANHO; i++){                      /// varredura para 0 a TAMANHO-1
      if(lista[0] == 0){                              /// verifica se se primeiro igual a 0
         break;                                       /// se for verdade para o for
      }else{                                          /// se nao entao
         if(lista[i] == 0){                           /// verifica lista[i] igual a zero
            troca(lista[i],lista[i-1]);               /// troca entre anterior com atual
            i=0;                                      /// reinicia a varredura
         }
      }
	}
}

int pularElementosParaEsquerda(int lista[]){ //ok
   //int aux;
   for(int i=TAMANHO-1; i>0; i--){                    /// varredura para 0 a TAMANHO-1
      if(lista[TAMANHO-1] == 0){                      /// verifica se se primeiro igual a 0
         break;                                       /// se for verdade para o for
      }else{                                          /// se nao entao
         if(lista[i] == 0){                           /// verifica lista[i] igual a zero
            troca(lista[i],lista[i+1]);               /// troca entre anterior com atual
            i=TAMANHO-1;                              /// reinicia a varredura
         }
      }
	}
}



void mostrar(int lista[]){ //ok
   cls;
   cout << "\tPosição\tElementos \n\n";
   for(int i=0; i<TAMANHO; i++){
      cout << "\t" << i+1 << "º\t" <<  lista[i] << endl;
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

/**!                 em desenvolvimento                        !**/
void inserir(int indice, int elemento, int lista[]){ //
   int proximoValor,AnteriorValor,antigoValor,aux;
   if(isCheio(lista)){                                /// verifica se a lista esta cheia
      cout << "lista cheia!";                         /// entao mostra messagem e aborta a inserção
      pausa;                                          /// pausa para ver a messagem
   }else{                                             /// se nao
      if(indice == 0){                          /// se o indice for zero é para coloca o elemento no inicio lista
         if(lista[0] == 0){                           /// verifica se lista[0] da lista está vazio
            lista[0] = elemento;                      /// entao lista[0] = elemento
         }else{                                       /// se nao
            pularElementosParaDireita(lista);         /// pula todo elemento um casa a direita
            lista[0] = elemento;                      /// coloque lista[0] = elemento
         }
      }else if(indice == TAMANHO-1){              /// se o indice for TAMANHO-1 é para coloca no final da lista
         if(lista[TAMANHO-1] == 0){
            lista[TAMANHO-1] = elemento;
         }else{
            pularElementosParaEsquerda(lista);
            lista[TAMANHO-1] = elemento;
         }

      }

   }

}

void excluir(int elemento, int lista[]){ //

}



/// Funcões Secundárias(interfaces);
void pesquisar(int lista[]){ //ok
   int elemento;
   do{
      cls;
      cout << "\t\tProcura\n" <<
              "\telemento: ";
      cin >> elemento;
      if(elemento == 0){
         cout << "\telemento inválida tente novamente";
         pausa;
      }
   }while(elemento == 0);

   if (procurar(elemento,lista) != -1){
      cout << "\tvalor " << elemento << " encontrado !\n";
      cout << "\tPosicão: " << procurar(elemento,lista)+1 << "º";
   }else{
      cout << "\tvalor " << elemento << " não emcontrado!";
   }
   pausa;
}

void adicionar(int lista[]){
   int elemento,indice,opcao;
      cls;
      cout << "\tvalor do elemento:";
      cin >> elemento;

      do{
            cls;
            cout << "\tinserir elemento: "<< elemento << "\n" <<
                    "\t1. No inicio da lista\n" <<
                    "\t2. *No meio da lista*\n" <<
                    "\t3. No final da lista\n" <<
                    "\t0. Cancelar Operação\n" <<
                    "\tOperação:";
            cin >> opcao;
      switch(opcao){
      case 0:
            break;
      case 1:
            inserir(0,elemento,lista);
         break;
      case 2:
            //inserir()
         break;
      case 3:
            inserir(TAMANHO-1,elemento,lista);
         break;
      default:
         cout << "opcao inválida";
         pausa;
      }

      }while(opcao < 0 || opcao > 3);

}




void Equipe(){
   cls;
   cout << "\t\t\t Equipe Cyber Bullets\n\n" <<
         "\tnome:............. Saulo Campos(Puppet0x40)\n" <<
         "\tnome:............. G           (GUI)\n" <<
         "\tnome:............. A           (Mogli)\n" <<
         "\tnome:............. J           (???)\n" <<
         "\tprofessor:........ Raiol\n " <<
   endl;
   pausa;
}

/********* TAD *************
*@quantidadeDePontos = 2.0
*@dataDeEntrega = 25/04/19
*@Equipe: Cyber Bullets
*@Aluno = Saulo Campos
*@aluno =
*@aluno =
*@aluno =
***************************/

