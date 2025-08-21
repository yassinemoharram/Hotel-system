#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {
   
    return a + b;
}
int product(int a, int b) {
    return a * b;
}

int difference(int a, int b) {
    return a - b;
}
float division(int a , int b){
    if (b == 0){
        printf("ERROT :you can not divide by 0");
        return 0;
    }
    return (float)a / b ;
}

int main(){
    int a , b ,c;
    float result;
    char op;
    char again;
    
    
    printf("**************************************\n");
    printf("*         WELCOME TO CALC-GENIUS     *\n");
    printf("**************************************\n");
   
     
    do {
    
    scanf("%d %c %d", &a, &op, &b);
    switch(op){
        case '+':
            result = sum(a,b);
            break;
        case '-' :
            result = difference(a,b);
            break ;
        case '*':
            result = product(a,b);
            brea;
        case '/':
            result = division(a,b);
            break;
        default:
            
            printf("Invalid operator! Please use +, -, *, or ");
             
            continue;
    }


    printf("The result is: %.2f\n", result);
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Thank you for using CALC-GENIUS! Goodbye!\n");
    return 0;
}