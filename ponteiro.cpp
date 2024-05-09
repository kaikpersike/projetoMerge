/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

struct  No {
    int dado;
    No *prox;
};

struct PilhaImpar {
    No *topo;
};

struct PilhaPar{
    No *topo;
};

// ------------------------------------

PilhaImpar* initImpar(){
    PilhaImpar *p = new PilhaImpar;
    p->topo = NULL;
    return p;
}

PilhaPar* initPar(){
    PilhaPar *p = new PilhaPar;
    p->topo = NULL;
    return p;
}

// ------------------------------------

int isEmptyImpar(PilhaImpar *p){
    return(p->topo == NULL);
}

int isEmptyPar(PilhaPar *p){
    return(p->topo == NULL);
}

// ------------------------------------

void freePilhaImpar(PilhaImpar *p) {
    No *no;
	no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}	
	free(p);
}

void freePilhaPar(PilhaPar *p) {
    No *no;
	no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}	
	free(p);
}

// ------------------------------------

void pushImpar(PilhaImpar *p, int v){
    No *no = new No;
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

void pushPar(PilhaPar *p, int v){
    No *no = new No;
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

// ------------------------------------

No* findImpar(PilhaImpar *p, int v){
    No *no;
    no = p->topo;
    
    while(no != NULL && no->dado < v){
        no = no->prox;
    }
    
    return no;
}

No* findPar(PilhaPar *p, int v){
    No *no;
    no = p->topo;
    
    while(no != NULL && no->dado < v){
        no = no->prox;
    }
    
    return no;
}

// ------------------------------------

int popImpar(PilhaImpar *p){
    int v;
    if(p->topo != NULL){
        No *no = p->topo;
        v = no->dado;
        p->topo = no->prox;
        free(no);
    }else{
        v = -1;
    }
    return v;
}

int popPar(PilhaPar *p){
    int v;
    if(p->topo != NULL){
        No *no = p->topo;
        v = no->dado;
        p->topo = no->prox;
        free(no);
    }else{
        v = -1;
    }
    return v;
}

// ------------------------------------

void printImpar(PilhaImpar *p){
    No *no;
    no = p->topo;
    
    if(no != NULL){
        cout << "Impar: " << no->dado << endl;
        no = no->prox;
        popImpar(p);
    }
    
    cout << "------------------------------------" << endl;
    
}

void printPar(PilhaPar *p){
    No *no;
    no = p->topo;
    
    if(no != NULL){
        cout << "Par: " << no->dado << endl;
        no = no->prox;
        popPar(p);
    }
    
    cout << "------------------------------------" << endl;
}

int main()
{
    PilhaImpar *imparInt;
    PilhaPar *parInt;
    
    int valor;
    
    
    imparInt = initImpar();
    parInt   = initPar();
    
    
    for(int i = 0; i < 3; i++){
        cout << "Digite um numero: " << endl;
        cin >> valor; 
        
        if(valor%2 != 0){
            
            if(findImpar(imparInt, valor) == NULL && findPar(parInt, valor) == NULL){
                cout << "E maior" << endl;
                pushImpar(imparInt, valor);
            }else{
                cout << "E menor" << endl;
                i--;
            }
            
        }
        else{
            
            if(findImpar(imparInt, valor) == NULL && findPar(parInt, valor) == NULL){
                cout << "E maior" << endl;
                pushPar(parInt, valor);
            }else{
                cout << "E menor" << endl;
                i--;
            }
            
        }
        

    }

    cout << "Pilha impar vazia: " << (isEmptyImpar(imparInt)?"SIM":"NAO") << endl;
    cout << "Pilha par vazia: "   << (isEmptyPar(parInt)?"SIM":"NAO")     << endl;

    cout  << "------------------------------------" << endl;
    
    for(int i = 0; i < 3; i++){
        if (imparInt->topo != NULL && parInt->topo != NULL){
            if((imparInt->topo->dado) > (parInt->topo->dado)){
                printImpar(imparInt);
            }else{
                printPar(parInt);
            }
        }else{
            if(imparInt->topo != NULL){
                printImpar(imparInt);
            }else{
                printPar(parInt);
            }
        }

    }
    freePilhaImpar(imparInt);
    freePilhaPar(parInt);
    return 0;
}


