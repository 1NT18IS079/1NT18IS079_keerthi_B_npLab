#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main() {
    printf("Enter the dataword : ");
   	char data[50];
    scanf("%s", data);
    
    printf("Enter the polynomial (divisor): ");
    char divisor[50];
    scanf("%s", divisor);
    
    int divLen = strlen(divisor);
    int dataLen = strlen(data);
    
    
    if(divLen > dataLen){
    	printf("divisor too long\n");
    	return;
    }
    
    int cnt = divLen-1;
    int end = dataLen + cnt;
    
    char temp[end];
    
    for(int i = 0; i<dataLen; i++)temp[i] = data[i];
    
    for(int i = dataLen; i<end; i++)temp[i] = '0';
    
    int left = 0;
    
    while(left+divLen < end){
    	
    	if(temp[left] == '1'){
    		int k = 0;
    		for(int i = left; k<divLen; i++, k++){
    			if(divisor[k] == '1'){
    				if(temp[i] == '1')temp[i] = '0';
    				else temp[i] = '1';
    			}
    			else{
    				if(temp[i] == '1')temp[i] = '1';
    				else temp[i] = '0';
    			}
    		}
    	}
    	left++;
    	
    }
    
    for(int i = end-divLen, k = 0; i<end; i++, k++){
    	if(divisor[k] == '1'){
			if(temp[i] == '1')temp[i] = '0';
			else temp[i] = '1';
		}
		else{
			if(temp[i] == '1')temp[i] = '1';
			else temp[i] = '0';
		}
    }
    
    
    
    char code[end];
    for(int i = 0; i<end; i++){
    	if(i >= (end - (divLen-1))){
    		code[i] = temp[i];
    	}
    	else{
    		code[i] = data[i];
    	}
    }
    
    printf("codeword : ");
    for(int i = 0; i<end; i++)printf("%c", code[i]);
    printf("\n");
    
    
    printf("\nEnter the recieved codeword : ");
    char recieved[50];
    scanf("%s", recieved);
    
    int recLen = strlen(recieved);
    
    if(recLen != end)printf("Recieved codeword has error !!\n");
    else{
    	int miss = 0;
    	for(int i = 0; i<end; i++){
    		if(code[i] != recieved[i]){
    			miss = 1;
    			break;
    		}
    	}
    	
    	if(miss == 1){
    		printf("Recieved codeword has error !!\n");
    	}
    	else{
    		printf("Recieved codeword is correct !!\n");
    	}
    }
    
    return;
}



