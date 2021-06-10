#include <stdio.h>

int main() {
    int storage;
    printf("Enter bucket size :");
    scanf("%d", &storage);
    int filled = 0, leak;
    
    printf("Enter leak rate: ");
    scanf("%d", &leak);
    
    printf("Enter no of seconds :");
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++){
        int input;
        printf("Enter input buffer at %d second:", i);
        scanf("%d", &input);
        
        if((storage - filled) >= input){
            filled += input;
            printf("Bucket filled upto %d\n", filled);
        }
        else{
            printf("Input size too high ");
            int leftOut = storage - filled;
            printf("Buffer of size %d dropped\n", input - leftOut);
            filled = storage;
        }
        
        filled -= leak;
        filled = filled < 0? 0: filled; //Ensuring no negative amount is filled and minimum filled will be  0
        printf("leaked %d size\n bucket filled with %d buffer\n", leak, filled);
        printf("------------------------\n\n");
        
    }
    
    
    return 0;
}
