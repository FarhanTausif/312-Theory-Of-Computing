#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int numStates,numSymbol,numFinal;
    
bool ans = false;

char inputString[100];
int len, t = 0;
char store[100];
char revolving;

void nfa(char *setofstate,char *alphabet,char initialstate,char finalstate,char transition[numStates][numSymbol][numStates],int numTransition[numStates][numSymbol],int index){

    if(index==len && initialstate == finalstate){
        
        ans = true;
        
        store[t++] = initialstate;
        
        for(int j=0; j<t; j++)
            printf("%c ",store[j]);
        
        printf("\n");
        return;
    
    }

    if( index == len && initialstate != finalstate){
    
        t--;
        revolving= initialstate;
        return;
    
    }

    int i;
    
    for(i=0; i<numSymbol; i++){
    
        if(alphabet[i] == inputString[index]) break;
    
    }

    if( numTransition[initialstate-'a'][i] == 0 ) return; // no transitions
    
    int k = 0;
    store[t++] = initialstate;
    
    while( k < numTransition[initialstate-'a'][i] && !ans ){
    
        nfa(setofstate,alphabet,transition[initialstate-'a'][i][k],finalstate,transition,numTransition,index+1);
        k++;
    
    }

    return;

}

int main(){

    printf("Enter the number of states: ");
    scanf("%d",&numStates);
    
    printf("Enter the number of symbol in alphabet: ");
    scanf("%d",&numSymbol);
    
    printf("Enter the number of final state: ");
    scanf("%d",&numFinal);
    getchar();
    
    char setOfState[numStates],alphabet[numSymbol],initialState,finalStates[numFinal],transitionTable[numStates][numSymbol][numStates],steps[100];
    
    for(int i=0; i<numStates; i++){
        
        printf("Enter %dth state: ",i+1);
        scanf("%c",&setOfState[i]);
        getchar();
    
    }
    
    printf("\n\n");
    
    for(int i=0; i<numSymbol; i++){
    
        printf("Enter %dth symbol of alphabet: ",i+1);
        scanf("%c",&alphabet[i]);
        getchar();
    
    }
    
    printf("Enter the initial state: ");
    scanf("%c",&initialState);
    getchar();
    
    for(int i=0; i<numFinal; i++){
        printf("Enter %dth final state: ",i+1);
        scanf("%c",&finalStates[i]);
        getchar();
    }
    
    for(int i=0; i<numStates; i++){
        for(int j=0; j<numSymbol; j++){
            for(int k=0; k<10; k++){
                transitionTable[i][j][k] = '*';
            }
        }
    }
    
    int numTransition[numStates][numSymbol];
    
    for(int i=0; i<numStates; i++){
        
        printf("For %c: \n",setOfState[i]);
        
        for(int j=0; j<numSymbol; j++){
            
            printf("For input %c : \n",alphabet[j]);
            printf("How many transitions? : ");
            scanf("%d",&numTransition[i][j]);
            getchar();
            printf("Enter the transitions: ");
            
            for(int k=0; k<numTransition[i][j]; k++){
                scanf("%c",&transitionTable[i][j][k]);
                getchar();
            }
            
            printf("\n");
        
        }
    
    }
    
    printf("Enter the string: ");
    
    scanf("%s",inputString);
    
    len = strlen(inputString);
    
    nfa(setOfState,alphabet,initialState,finalStates[0],transitionTable,numTransition,0);
    
    (ans == true) ? printf("A/C\n") : printf("Rejected as looping in %c\n"), revolving;

    return 0;
}