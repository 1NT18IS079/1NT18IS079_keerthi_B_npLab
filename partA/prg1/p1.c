//Design and implement c program in which sender module should count the number of bits in the frame and receiver module should display  each frame 

#include<stdio.h>

void receiver(int n,int fr[]){

	printf("Data received!!\n");

	for(int j=0;j<n;j++)
	{
		printf("\nFrame %d is %d",j+1,fr[j]);
	}
	
}


void sender(int num_of_frames,int frame[]){
	
	int n;
	int total_bits=0;
	for(int i=0;i<num_of_frames;i++){
		int count=0;
		n = frame[i];
		
		while(n!=0){
			n=n/10;
			count++;
		}
		
		printf("Number of bits in frame %d is %d\n", i+1, count);
		total_bits+=count;
	}
	
	printf("The total number of bits is %d\n",total_bits);
	printf("Sending data....\n\n");
	
	receiver(num_of_frames,frame);
}

void main(){
	int n;
	
	printf("Enter the number of frames : ");
	scanf("%d",&n);
	
	int frame[n];
	printf("Enter the pattern for each frame\n");
	
	for(int i=0; i<n; i++){
		printf("Frame %d: ", i+1);
		scanf("%d",&frame[i]);
	}
	
	sender(n, frame);
	printf("\n");
}


















