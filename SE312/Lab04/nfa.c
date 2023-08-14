#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int numState, numSymbol, numFinal;
char alphabet[36];
char inputString[100];
int len;
bool result = false;
int p = 0;
int store[100];
char looping;

void updateState(char setOfState[numState],char alphabet[numSymbol],char initialState,char finalState,int numTransition[numState][numSymbol],char transitionTable[numState][numSymbol][numState],char steps[100], int index);


int main(){
    printf("Enter no of states: ");
    scanf("%d", &numState);
    printf("Enter no of symbol in alphabet: ");
    scanf("%d", &numSymbol);
    printf("Enter the no of final state: ");
    scanf("%d", &numFinal);
    getchar();

    char setOfState[numState], alphabet[numSymbol], initialState, finalState[numFinal], transitionTable[numState][numSymbol][numState], steps[100];

    for(int i = 0; i < numState; ++i){
        printf("Enter %dth state", i+1);
        scanf("%c", &setOfState[i]);
        getchar();
    }

    printf("Enter the inital state: ");
    scanf("%c", &initialState);
    getchar();

    for(int i = 0; i < numFinal; ++i){
        printf("Enter the %dth final state: ", i+1);
        scanf("%c", &finalState[i]);
        getchar();
    }

    // Initialization
    for(int i = 0; i < numState; ++i){
        for(int j = 0; j < numSymbol; ++j){
            for(int k = 0; k < numState; ++k){
                transitionTable[i][j][k] = '*';
            }
        }
    }

    int numTransition[numState][numSymbol];
    for(int i = 0; i < numState; ++i){
        printf("For %c: \n", setOfState[i]);
        for(int j = 0; j < numSymbol; ++j){
            printf("If the input is %c: \n", alphabet[j]);
            printf("How many transition? : ");
            scanf("%d", &numTransition[i][j]);
            getchar();
            for(int k = 0; k < numTransition[i][j]; ++k){
                scanf("%c", &transitionTable[i][j][k]);
                getchar();
            }
        }
    }

    printf("Enter the string:");
    scanf("%s", inputString);



    return 0;
}


void updateState(char setOfState[numState],char alphabet[numSymbol],char initialState,char finalState,int NumTransition[numState][numSymbol],char transitionTable[numState][numSymbol][numState],char steps[100], int index){
    if(index == len && initialState == finalState){
        result = true;
        store[p++] = initialState;
        for()
    }

    for(int i = 0; i < numSymbol; ++i){
        if(alphabet[i] == inputString[index]) break;
    }

    if(numTransition[initialState - 'a'][i] == 0) return;

    while(){

    }


}
