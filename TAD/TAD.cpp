#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#define cls system("cls");          /// limpa (cmd) Prompt de Comando
#define pausa getchar();getchar()   /// pausa Prompt de Comando
const int TAMANHO = 20;             /// fixar o TAMANHO do vetor e da condicional do for
using namespace std;

/// prototipos
bool isCheio(int listra[]);                           /// verifica se a lista est� cheia
bool isVazia(int lista[]);                            /// verifica se a lista est� vazia
int quantidadeOcupado(int lista[]);                   /// verifica a quantidades de elementos que estao ocupados
void troca(int &a,int &b);                            /// troca valores entre duas variaveis
int pularElementosParaDireita(int lista[]);           /// pula os todos elementos um casa para direita se proximo elemento for zero
int pularElementosParaEsquerda(int lista[]);           /// pula os todos elementos um casa para esquerda se anterior elemento for zero
void mostrar(int lista[]);                            /// mostra toda elementos lista!
int procurar(int elemento, int lista[]);              /// funcao: procura um elemento espec�fico na lista
void pesquisar(int lista[]);                          /// interface: procura um elemento espec�fico na lista que usuario digitou

/// prototipos em desenvolvimento
void inserir(int indice, int elemento, int listra[]); /// funcao: inserir elemento espec�fico na lista
bool excluir(int elemento, int lista[]);              /// fun�ao: excluir elemento especifico na lista
void atualizaElemento(int elemento, int lista[]);     /// fun�ao: atualiza elemento especifico na lista
void adicionar(int lista[]);                          /// interface: inserir na lista que usuario digitou
void remover(int lista[]);                            /// interface: remover na lista que usuario digitou

///Extra
void OrdenarElemento(int lista[]);
void Equipe();

/// Variavel Global
int lista[TAMANHO];

/// principal
int main(){
   int opcao;
   setlocale(LC_ALL,"portuguese");
   system("mode con:cols=55 lines=40"); // fixa tamanho do cmd com 50 colunas e 40 linhas
   system("color 2"); // setar cor de o texto e fundo
   system("title TAD::LISTA vers�o GOLD"); // setar o titulo do programa
   do{
      cls;
      cout << "\t\tTAD\t\t\t" << quantidadeOcupado(lista) << "/" << TAMANHO << "\n" <<
              "\t1. Inserir elemento\n" <<
              "\t2. Remover elemento\n" <<
              "\t3. procurar elemento\n" <<
              "\t4. Mostrar lista\n";
              if(isCheio(lista)){cout << "\t5. Ordenar lista  (Bubble Sort)\n";}
      cout << "\t0. sair\n" <<
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
         remover(lista);                                        /// abre interface de remove elementos
         break;
      case 3:
         pesquisar(lista);                            /// abre interface de busca de elementos na lista
         break;
      case 4:
         mostrar(lista);                              /// mostra toda lista
         break;
      case 5:
         if(isCheio(lista)){
            OrdenarElemento(lista);                      /// extra
            mostrar(lista);
         }
         break;
      case 6:
         system("mode con:cols=50 lines=15");
      default:
         cout << "\t\topcao inv�lida";                ///
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


void troca(int &a, int &b){               /// ! passagem por enderen�o ! usa-se & no mone da variavel para dizer que vamos passa o endere�o dele
   int aux = a;                           /// antes de modifica  fiz backup do  valor do A
   a = b;                                 /// A pega valor de B
   b = aux;                               /// B pega valor do A que tava salvo na aux
}


int pularElementosParaDireita(int lista[]){ //ok
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
   cout << "\tPosi��o\tElementos \n\n";
   for(int i=0; i<TAMANHO; i++){
      cout << "\t" << i+1 << "�\t" <<  lista[i] << endl;
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


bool excluir(int elemento, int lista[]){
	for(int i=0; i<TAMANHO; i++){
		if(elemento == lista[i]){
			lista[i] = 0;
			return true;
		}
	}
	return false;
}


void inserir(int indice, int elemento, int lista[]){ //
   int proximoValor,AnteriorValor,antigoValor,aux;
   if(isCheio(lista)){                                /// verifica se a lista esta cheia
      cout << "\t\tLista Cheia!";                         /// entao mostra messagem e aborta a inser��o
      pausa;                                          /// pausa para ver a messagem
   }else{                                             /// se nao
      if(indice == 0){                    /// se o indice for zero � para coloca o elemento no inicio lista
         if(lista[0] == 0){                           /// verifica se lista[0] da lista est� vazio
            lista[0] = elemento;                      /// entao lista[0] = elemento
         }else{                                       /// se nao
            pularElementosParaDireita(lista);         /// pula todo elemento um casa a direita
            lista[0] = elemento;                      /// coloque lista[0] = elemento
            cout << "\t elemento inserido com sucesso!";
         }
      }else if(indice == TAMANHO-1){      /// se o indice for TAMANHO-1 � para coloca no final da lista
         if(lista[TAMANHO-1] == 0){
            lista[TAMANHO-1] = elemento;
         }else{
            pularElementosParaEsquerda(lista);
            lista[TAMANHO-1] = elemento;
            cout << "\t elemento inserido com sucesso!";
         }
      }else if(indice == TAMANHO/2 ){     /// se o indice for  TAMANHO/2 � para coloca no meio da lista
         if(lista[TAMANHO/2] == 0){                         /// verifica se lista[TAMANHO/2] da lista est� vazio
            lista[TAMANHO/2] = elemento;                    /// entao lista[TAMANHO/2] = elemento
         }else{                                             /// se nao
            for(int i=TAMANHO/2; i<TAMANHO; i++){           /// varredura do TAMANHO/2  para final
               if(lista[TAMANHO/2] == 0){                   /// verifica se se primeiro igual a 0
                  break;                                    /// se for verdade saia do for
               }else{                                       /// se nao entao
                  if(lista[i] == 0){                        /// verifica lista[i] igual a zero
                  troca(lista[i],lista[i-1]);               /// troca entre anterior com atual
                  i=TAMANHO/2;                              /// reinicia a varredura
                  }
               }
            }
            for(int i=(TAMANHO/2); i>0; i--){         /// varredura do TAMANHO/2  para inicio
               if(lista[(TAMANHO/2)] == 0){                   /// verifica se se TAMANHO/2 igual a 0
                  break;                                    /// se for verdade para o for
               }else{                                       /// se nao entao
                  if(lista[i] == 0){                        /// verifica lista[i] igual a zero
                     troca(lista[i],lista[i+1]);            /// troca entre anterior com atual
                     i=(TAMANHO/2);                           /// reinicia a varredura
                  }
               }
            }
            lista[TAMANHO/2] = elemento;                      /// coloque lista[0] = elemento
            cout << "\t elemento inserido com sucesso!";
         }
      }
   }
}


void atualizaElemento(int elemento, int lista[]){ //ok
   int posicao, antigo,busca;
   do{
      cls;
      cout << "\tPosi��o\tElementos \n\n";
      for(int i=0; i<TAMANHO; i++){
        (lista[i] != 0)? cout << "\t" << i+1 << "�\t" << lista[i] << "\n" : cout << "" ;
      }
      cout << "\tQual elemento quer atualiza por "<< elemento << "\n\t0. para cancelar"
      << "\n\telemento:";
      cin >> busca;
      if(busca == 0){
         cout << "Opera�ao Cancelada";
         pausa;
         break;
      }
      posicao = procurar(busca,lista);
      if(posicao != -1){
         antigo = lista[posicao];
         lista[posicao] = elemento;
         cout <<  "\tElemento "<< antigo <<" na "<< posicao+1 <<"� posi��o "<< endl <<
                  "\tElemento foi atualizado para : " << elemento << endl <<
                  "\t\tOpera�ao feita com sucesso!";
         pausa;
      }else{
         cout << "\telemento nao encotrado tente novamente";
         pausa;
      }
   }while(posicao == -1);
}

/// Func�es Secund�rias(interfaces);
void pesquisar(int lista[]){ //ok
   int elemento;
   do{
      cls;
      cout << "\t\tProcura\n" <<
              "\telemento: ";
      cin >> elemento;
      if(elemento == 0){
         cout << "\telemento inv�lida tente novamente";
         pausa;
      }
   }while(elemento == 0);
   if (procurar(elemento,lista) != -1){
      cout << "\tvalor " << elemento << " encontrado !\n";
      cout << "\tPosic�o: " << procurar(elemento,lista)+1 << "�";
   }else{
      cout << "\tvalor " << elemento << " n�o emcontrado!";
   }
   pausa;
}


void adicionar(int lista[]){ //ok
   int elemento,indice,opcao;
   cls;
   cout << "\t\t adiciona elemento na lista\n";
   cout << "\telemento:";
   cin >> elemento;
   do{
      cls;
      cout <<  "\tinserir elemento: "<< elemento << "\n" <<
               "\t1. No inicio da lista\n" <<
               "\t2. No meio da lista\n" <<
               "\t3. No final da lista\n" <<
               "\t4. Atualizar elemento\n"<<
               "\t0. Cancelar Opera��o\n" <<
               "\tOpera��o:";
      cin >> opcao;
      switch(opcao){
      case 0:
         break;
      case 1:
         inserir(0,elemento,lista);
         break;
      case 2:
         inserir(TAMANHO/2,elemento,lista);
         break;
      case 3:
         inserir(TAMANHO-1,elemento,lista);
         break;
      case 4:
         atualizaElemento(elemento,lista);
         break;
      default:
         cout << "\t\tOpera��o inv�lida";
         pausa;
      }
   }while(opcao < 0 || opcao > 4);
}


void remover(int lista[]){ //ok
   int elemento,opcao;
   do{
      cls;
      cout <<  "\t\tRemover: \n" <<
               "\t1. Um elemento\n" <<
               "\t2. Todos os Elementos\n" <<
               "\t0. Cancelar Opera��o\n" <<
               "\tOpera��o:";
      cin >> opcao;
      switch(opcao){
      case 0:
         break;
      case 1:
         cls;
         cout << "\tPosi��o\tElementos \n\n";
         for(int i=0; i<TAMANHO; i++){
            (lista[i] != 0)? cout << "\t" << i+1 << "�\t" << lista[i] << "\n" : cout << "" ;
         }
         do{
            cout<<"\n\tQual elemento quer excluir?\n\tElemento: ";
            cin>>elemento;
            if(elemento == 0){
               cout << "\telemento inv�lida tente outra vez";
               pausa;
            }

         }while(elemento == 0);
         if(excluir(elemento, lista)){
            cout << "\tElemento apagado com sucesso\n";
         }else{
            cout << "\tElemento n�o est� lista\n";
         }
         break;
      case 2:
         for(int i=0; i<TAMANHO; i++){
            lista[i] = 0;
         }
         cout << "\t\tlista limpa!\n";
         break;
      default:
         cout << "\t\tOpera��o inv�lida";
         pausa;
      }
   }while(opcao < 0 || opcao > 4);
	pausa;
}


void OrdenarElemento(int lista[]){
   for(int elemento = 0; elemento < TAMANHO-1; elemento++ ){
        for(int elemento = 0; elemento < TAMANHO-1; elemento++ ){
            if(lista[elemento] > lista[elemento+1]){
               troca(lista[elemento],lista[elemento+1]);
            }
        }
    }
}


void Equipe(){
   cls;
   cout << "\t\t Equipe Cyber Bullets\n\n" <<
         " Aluno:........ Saulo Campos Campos        (Puppet0x40)\n" <<
         " Aluno:........ Guilherme dos Santos Rocha (Cuphead)\n" <<
         " Aluno:........ Anderson Lucas Duarte      (Jamel�o)\n" <<
         " Aluno:........ Jo�o Gabriel Sabino        (Odin)\n" <<
         " Professor:.... Raiol \n " <<
   endl;
   pausa;
}
