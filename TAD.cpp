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
void mostrar(int lista[]);
void inserir(int indice, int elementos, int listra[]);
bool pesquisar(int elementos, int lista[]);
void excluir(int elementos, int lista[]);


/// Variavel Global
int lista[10];

/// principal
int main(){
    int opcao;
    setlocale(LC_ALL,"portuguese");
    while(true){
    do{
        cls;
        cout << "\t\tTAD\n" <<
                "\t1. Mostrar lista\n" <<
                "\t2. Inserir elemento\n" <<
                "\t3. Remover elemento\n" <<
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
            //pesquisar();
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
    for(int i =0; i<10; i++){
        if(lista[i] == 0){
            return false;
		}
	}
    return true;
}

bool isVazia(int lista[]){ //ok
    for(int i =0; i < 10; i++){
        if(lista[i] != 0){
            return false;
        }
	}
    return true;
}

void mostrar(int lista[]){ //ok
    cls;
    cout << "\t\tlista:\n";
    for(int i=0; i<10; i++){
        cout << "\telemento " << i+1 << ":\t" << lista[i] << endl;
	}
	pausa;
}

void inserir(int indice, int elementos, int listra[]){

}

bool pesquisar(int elementos, int lista[]){

}

void excluir(int elementos, int lista[]){

}





/**
*@quantidadeDePontos = 2.0
*@dataDeEntrega = 25/04/19
**/
