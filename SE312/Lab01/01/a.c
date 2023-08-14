#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LENGTH 100

char s[5][MAX_LENGTH];

int randomLen();
int getLength(char *str);
void generateRandomString(char* str);


int main(){
	
	for(int i = 0; i < 5; ++i){
		generateRandomString(s[i]);
		printf("String 0%d: %s\n", i+1, s[i]);
		printf("Length: %d\n", getLength(s[i]));
	}		
    return 0;
}


int randomLen(){
	return rand() % MAX_LENGTH + 1;	
}


int getLength(char *str){
	int i = 0;
	while(str[i] != '\0') i++;
	return i;

}


void generateRandomString(char* str){
	int length = randomLen();
	for(int  i = 0; i < length; ++i) str[i] = '0' + rand() % 2;	
} 

