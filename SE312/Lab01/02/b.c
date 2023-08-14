#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 40
char revString[MAX_SIZE];

int getLen(char* s);
bool isPalindrome(char* s);
void reverseString(char* src, char* target);


int main(){
	
	char w[MAX_SIZE];
	printf("Enter a string: ");
	scanf("%s", w);
	//printf("Length:%d\n", getLen(w));
	if(isPalindrome(w)) printf("%s is a palindrome!\n", w);
	else printf("%s is not a palindrome!\n", w);
	//reverseString(w, revString);
	//printf("\n%s", revString);
	
	return 0;
}

int getLen(char* s){
	int len = 0;
	while(s[len] != '\0') len++;
	return len;
}


void reverseString(char* src, char* target){
	int i = getLen(src)-1;
	//printf("%d\n", i);
	while(*src){
		target[i--] = *src++;
	}
}	

bool isPalindrome(char* s){
	/*reverseString(s, revString);
	for(int i = 0; s[i] != '\0'; ++i){
		if(s[i] == revString[i]) continue;
		else return false;
	}
	return true;*/
	int i = 0;
	int j = getLen(s)-1;
	
	while(i <= j){
		if(s[i] == s[j]){
			i++;
			j--;
		}else return false;
	}
	return true;
}

