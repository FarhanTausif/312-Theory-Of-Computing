#include<stdio.h>

#define MAX_SIZE 50

void concatString(char *src1, char *src2, char *target);

int main(){

	char x[MAX_SIZE];
	char y[MAX_SIZE];
	char z[MAX_SIZE];
	printf("Enter two strings:\n");
	scanf("%s%s", x, y);
	concatString(x,y,z);
	printf("x: %s\ny: %s \nConcatenated String: %s\n",x, y, z); 
}



void concatString(char *src1, char *src2, char *target){
	while(*src1) *target++ = *src1++;
	while(*src2) *target++ = *src2++;
	*target = '\0';
}
