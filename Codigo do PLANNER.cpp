#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;



struct funcionario{
    string tarefa;
    int d,m,a;
};
struct gestor{
    string envTaf;
    int d,m,a;
};

struct elemento{
    struct funcionario dados;
    struct gestor dados2;
    struct elemento *prox;

};
typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* lista_cria(){
    //Lista *li;
    Lista* li = (Lista*) malloc(sizeof(Lista)+1);
    if(li!=NULL)
        *li = NULL;
    return li;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL) return -1;
    if(*li == NULL) return 1;
    return 0;
}

void lista_imprime_mat(Lista* li){
    cout << "== TAREFAS DA LISTA ==" << endl;
    Elem *no = *li;
    while(no != NULL){
        cout << no->dados.tarefa << "  ------ Data Limite --> ";
        cout << no->dados.d << "/";
        cout << no->dados.m << "/";
        cout << no->dados.a << endl;
        no = no->prox;
    }
    cout <<"=============FIM=============" << endl;
    cout << endl;
}
void lista_imprime_mat2(Lista* li){
    Elem *no = *li;
    while(no != NULL){
        cout << no->dados2.envTaf << "  ------ Data Limite --> ";
        cout << no->dados2.d << "/";
        cout << no->dados2.m << "/";
        cout << no->dados2.a << endl;
        no = no->prox;
    }
    cout <<"=============FIM=============" << endl;
    cout << endl;
}

int lista_insere_inicio(Lista* li, struct funcionario alunoX){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem)+1);
    if(no == NULL) return 0;

    no->dados = alunoX;
    no->prox = (*li);
    *li = no;
    return 1;
}


int lista_insere_final(Lista* li, struct funcionario alunoX){
        if(li == NULL) return 0;
        Elem* no = (Elem*) malloc(sizeof(Elem)+1);
        if(no == NULL) return 0;

        no->dados = alunoX;
        no->prox = NULL;

        if((*li) == NULL)
            *li = no;
        else{
            Elem *aux = *li;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = no;
        }

     return 1;
    }
int lista_insere_final2(Lista* li, struct gestor al){
        if(li == NULL) return 0;
        Elem* no = (Elem*) malloc(sizeof(Elem)+1);
        if(no == NULL) return 0;

        no->dados2 = al;
        no->prox = NULL;

        if((*li) == NULL)
            *li = no;
        else{
            Elem *aux = *li;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = no;
        }

     return 1;
    }
 int lista_remove_ordenada(Lista* li, string mat){
    if(li == NULL) return 0;

    Elem *ant = *li, *no = *li;
    while(no != NULL && no->dados.tarefa != mat){
        ant = no;
        no = no->prox;
    }

    if(no == NULL) return 0;
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);
    return 1;
 }

int lista_remove_inicio(Lista* li){
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);

    return 1;
}
int lista_remove_final(Lista* li){
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;

    Elem *ant = *li, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);

    return 1;
}

int lista_consulta_pos(Lista* li, int pos, struct funcionario *alunoX){
    if(li == NULL || pos <=0) return 0;

    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if(no == NULL)
        return 0;
    else{
        *alunoX = no->dados;
        return 1;
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");

    struct funcionario fu;
    struct gestor ge;

    Lista *li;
    Lista *listaF;
    Lista *listaG;
    listaF = lista_cria();
    listaG = lista_cria();

    int escolha;
    int x=0,j=0,l=0;;
    int sair = 1;

    while( sair != 2){
    cout << "========Bem-vindo========" << endl;
    cout << "=== Escolha entre a lista Funcionario e Gestor ===" << endl << endl;
    cout << "!!! São 3 dados no total contando a lista Funcionario e a lista Gestor !!!" << endl << endl;
    cout << "Digite 1 - Para Funcionario"<< endl;
    cout << "Digite 3 - Para Gestor" << endl;
    cout << "======================================" <<endl;
    cout << "Digite 10 - Para Imprimir a lista Funcionario: " << endl;
    cout << "Digite 15 - Para imprimir a lista Gestor: " << endl;
    cout << "======================================" << endl;
    cout << "Digite 2 - Para sair" << endl;
    cout << "______________________________________" << endl;
    cout << "Opção: ";
    cin >> escolha;
    cout << endl;

    switch(escolha){
    case 2:
        sair = 2;
        break;

        case 1:
            cout << "== LISTA FUNCIONARIO ==" << endl;
            cout << "Digite 4 - Para escrever suas tarefas diarias na lista" << endl;
            cout << "Digite 10 - Para acessar tarefas escritas pelo GESTOR" << endl;
            cout << "Digite 2 - Para sair" << endl;
            cin >> j;
            cout << endl;
                while(j == 4){
                    cout << "== LISTA DE TAREFAS ==" << endl;
                    cin.ignore( 1000, '\n' );
                    getline(cin,(fu.tarefa));

                    cout << "Escreva a data LIMITE da entrega" << endl;
                    cout << "Dia: ";
                    cin >> fu.d;
                    cout << "Mês: ";
                    cin >> fu.m;
                    cout << "Ano: ";
                    cin >> fu.a;
                    lista_insere_final(listaF, fu);

                    cout << endl;
                    lista_imprime_mat(listaF);
                    cout << "Voce deseja inserir outra tarefa ?"; cout << "== MAXIMO DE 3 TAREFAS POR LISTA ==" << endl;
                    cout << "Digite 4 - Para inserir novamente" << endl;
                    cout << "Digite 2 - Para sair da lista" << endl;
                    cout << "Digite 6 - Para remover uma tarefa" << endl;
                    cin >> j;
                    cout << endl;
                 }if( j == 10 ){
                    lista_imprime_mat2(listaG);
                    system("pause");
                    break;
                 }
                 if(j == 6){
                    cout << "============================================" << endl;
                    cout << "Escreva 1- para remover a primeira tarefa" << endl;
                    cout << "Escreva 2- para remover a ultima tarefa" << endl;
                    cin >> j;
                    if(j == 1){
                        lista_remove_inicio(listaF);
                        lista_imprime_mat(listaF);
                    }
                    if(j == 2){
                        lista_remove_final(listaF);
                        lista_imprime_mat(listaF);
                    }
                 }
            break;

        case 3:
            cout << "== LISTA DO GESTOR ==" << endl;
            cout << "Digite 4 - Para escrever a tarefa para o funcionario" << endl;
            cout << "Digite 15 - Para acessar as tarefas do funcionario" << endl;
            cout << "Digite 2 - Para sair" << endl;
            cin >> j;
                while(j == 4){
                    cout << endl;
                    cout << "== LISTA DO GESTOR ==" << endl;
                    cin.ignore( 1000, '\n' );
                    getline(cin,(ge.envTaf));

                    cout << "Escreva a data LIMITE da entrega" << endl;
                    cout << "Dia: ";
                    cin >> ge.d;
                    cout << "Mês: ";
                    cin >> ge.m;
                    cout << "Ano: ";
                    cin >> ge.a;
                    lista_insere_final2(listaG, ge);

                    cout << endl;
                    lista_imprime_mat2(listaG);
                    cout << "Voce deseja inserir outra tarefa ?"; cout << "== MAXIMO DE 3 TAREFAS POR LISTA ==" << endl;
                    cout << "Digite 4 - Para inserir novamente" << endl;
                    cout << "Digite 6 - Para remover uma tarefa" << endl;
                    cout << "Digite 2 - Para sair da lista" << endl;

                    cin >> j;
                    cout << endl;
                }if(j == 6){
                    cout << "============================================" << endl;
                    cout << "Escreva 1- para remover a primeira tarefa" << endl;
                    cout << "Escreva 2- para remover a ultima tarefa" << endl;
                    cin >> l;
                    if(l == 1){
                        lista_remove_inicio(listaG);
                        lista_imprime_mat(listaG);
                    }
                    if(l == 2){
                        lista_remove_final(listaG);
                        lista_imprime_mat(listaG);
                    }
                 }
                if(j == 15){
                    cout << "== TAREFAS DO FUNCIONARIO ==" << endl;
                    cout << "________________________" << endl;
                    lista_imprime_mat(listaF);
                    system("pause");
                    break;
                 }


                if(j == 6){
                cout << "============================================" << endl;
                cout << "Escreva 1- para remover a primeira tarefa" << endl;
                cout << "Escreva 2- para remover a ultima tarefa" << endl;
                cin >> j;
                if(j == 1){
                    lista_remove_inicio(listaG);
                    lista_imprime_mat2(listaG);
                    system("pause");
                    break;
                }
                if(j == 2){
                    lista_remove_final(listaG);
                    lista_imprime_mat2(listaG);
                    system("pause");
                break;
                }
                }
            break;
        case 10:
             cout << "== LISTA DO FUNCIONARIO ==" << endl;
                cout << "===========================" << endl;
                lista_imprime_mat(listaF);
                system("pause");
                break;
        case 15:
            cout << "== LISTA DO GESTOR ==" << endl;
                cout << "________________________" << endl;
                lista_imprime_mat(listaG);
                system("pause");
                break;
        }
    }
    return 0;
 }




















