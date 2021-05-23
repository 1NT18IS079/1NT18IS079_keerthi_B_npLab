#include<stdio.h>
#include<string.h>


void main(){
	char in[50];
	printf("Enter the frame : ");
	scanf("%s", in);
	int len = strlen(in);

	char res[50];
	
	int i;
	for(i = 0; i<8; i++){
		if(i == 0 || i == 7){
			res[i] = '0';
		}	
		else{
			res[i] = '1';
		}
	}
	
	for(int j = 0; j<len; j++, i++){
		res[i] = in[j];
	}
	
	for(int j = 0; j<8; j++, i++){
		if(j == 0 || j == 7){
			res[i] = '0';
		}	
		else{
			res[i] = '1';
		}
	}
	
	printf("\nFrame after stuffing : ");
	for(int i = 0; i<len+16; i++)printf("%c", res[i]);
	
	char unstuffed[len], j = 0;
	for(int i = 8; i<(len+8); i++){
		unstuffed[j++] = res[i];
	}
	
	printf("\nFrame after unstuffing : ");
	for(int i = 0; i<len; i++)printf("%c", unstuffed[i]);
	printf("\n");
}




