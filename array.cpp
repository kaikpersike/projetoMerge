#include <iostream>
using namespace std;

struct PilhaImpar{
    int qtde;
    int elementos[];
};

struct PilhaPar{
    int qtde;
    int elementos[];
};

// ------------------------------------

PilhaImpar* initImpar(){
    PilhaImpar *p = new PilhaImpar;
    p->qtde = 0;
    return p;
}

PilhaPar* initPar(){
    PilhaPar *p = new PilhaPar;
    p->qtde = 0;
    return p;
}

// ------------------------------------

int isEmptyImpar(PilhaImpar *p){
    return (p->qtde == 0);
}

int isEmptyPar(PilhaPar *p){
    return (p->qtde == 0);
}
// ------------------------------------

void freePilhaImpar(PilhaImpar *p) {
	free(p);
}

void freePilhaPar(PilhaPar *p) {
	free(p);
}

// ------------------------------------

int pushImpar(PilhaImpar *pI, int v) {
    
    pI->elementos[pI->qtde++] = v;
    
    return 1;
}

int pushPar(PilhaPar *pP, int v){

    pP->elementos[pP->qtde++] = v;

    return 1;
}

// ------------------------------------

int findImpar(PilhaImpar *p, int v){
    
    return (v>p->elementos[p->qtde-1]);
    
}

int findPar(PilhaPar *p, int v){
    
    return (v>p->elementos[p->qtde-1]);
    
}

// ------------------------------------

int popImpar(PilhaImpar *p) {
	int podeDesempilhar = (p->qtde > 0);
	int v;
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else {
		v = -1;
	}
	return v;
}

int popPar(PilhaPar *p){
    int v;
    if(p->qtde > 0){
        v = p->elementos[p->qtde-1];
        p->qtde--;
    }else{
        v = -1;
    }
    return v;
}

// ------------------------------------

void printImpar(PilhaImpar *p){
    if((p->qtde) > 0){
        cout << " -- Impar : " << p->elementos[p->qtde-1] << endl;
        //p->qtde--;
        popImpar(p);
    }
    
    //cout << "------------------------------------" << endl;
}

void printPar(PilhaPar *p){
    if((p->qtde) > 0){
        cout << " -- Par   : " << p->elementos[p->qtde-1] << endl;
        //p->qtde--;
        popPar(p);
    }
    
    //cout << "------------------------------------" << endl;
}

int main(int argc, char** argv)
{
    PilhaImpar *imparInt;
    imparInt = new PilhaImpar();
    PilhaPar *parInt;
    parInt = new PilhaPar();
    
    int valor;
    
    imparInt = initImpar();
    parInt   = initPar();
    
    cout << "Pilha impar vazia: " << (isEmptyImpar(imparInt)?"SIM":"NAO") << endl;
    cout << "Pilha par vazia: "   << (isEmptyPar(parInt)?"SIM":"NAO")     << endl;
    
    for(int i = 0; i < 3; i++){
        cout << "Digite um numero: " << endl;
        cin >> valor; 
        
        if(valor%2 != 0){
            
            if(findImpar(imparInt, valor) == 1 && findPar(parInt, valor) == 1){
                cout << "E maior" << endl;
                pushImpar(imparInt, valor);
            }

            else{
                cout << "E menor" << endl;
                i--;
            }
            
        }
        else{
            
            if(findImpar(imparInt, valor) == 1 && findPar(parInt, valor) == 1){
                cout << "E maior" << endl;
                pushPar(parInt, valor);
            }else{
                cout << "E menor" << endl;
                i--;
            }
            
        }

    }
    
    cout << "------------------------------------" << endl;
    
    for(int i = 3; i >= 0; i--){
        
        
        if (imparInt->qtde != 0 && parInt->qtde != 0){
            if((imparInt->elementos[imparInt->qtde-1]) > (parInt->elementos[parInt->qtde-1])){
                printImpar(imparInt);
            }else{
                printPar(parInt);
            }
        }else{
            if(imparInt->qtde != 0){
                printImpar(imparInt);
            }else{
                printPar(parInt);
            }
        }

   }
   
    cout << "------------------------------------" << endl;
   
    cout << "Pilha impar vazia: " << (isEmptyImpar(imparInt)?"SIM":"NAO") << endl;
    cout << "Pilha par vazia: "   << (isEmptyPar(parInt)?"SIM":"NAO")     << endl;
    
    freePilhaImpar(imparInt);
    freePilhaPar(parInt);

	return 0;
}
