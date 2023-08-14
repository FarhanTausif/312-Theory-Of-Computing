#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 50

bool identifyBitString(char *s);


int main(){
	char w[MAX_SIZE];
	printf("Enter a string: ");
	scanf("%s",w);
	if(identifyBitString(w)) printf("w is from the alphabet!\n");
	else printf("w is not from the alphabet!\n");		
}


bool identifyBitString(char *s){
	while(*s){
		if(*s == '0' || *s == '1') s++;
		else return false;
	}
	return true;
}
