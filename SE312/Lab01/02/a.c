#include<stdio.h>

int decimalToBinary(int n);
int range(int k);

int main(){
	int k;
	printf("Enter a number: ");
	scanf("%d", &k);  
    for(int i = 0; i < range(k); ++i){
    	printf("%d\t", decimalToBinary(i));
    }
    printf("\n");
    
      
	return 0;  
}  


int decimalToBinary(int n)
{
    int bin=0,rem,place = 1;
    while(n != 0)
    {
         rem = n % 2;
         bin += rem * place;
         place *= 10;
         n /= 2;
    }
    return bin;
}

int range(int k){
	int range = 1;
	for(int i = 1; i <= k; i++){
		range *= 2;
	}
	
	return range;
}
