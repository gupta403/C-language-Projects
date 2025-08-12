#include<stdio.h>
void main(){
    float input1,input2;
    float answer;
    char multiCounting;
    char opt;
    int not_valid,div_by_zero;
    do{// this for multiple calculaion
    printf("Welcome to calculator ! \n");
    printf("Enter the Input 1\n");
    scanf("%f",&input1);
    printf("Enter the Input 2\n");
    scanf("%f",&input2);
    div_by_zero = 0;
    do{//this loop for invalid opt
    printf("Enter the opration\n");
    printf("Select +  --> Add\t - --> Sub\t * --> Multiply\t /--> Devision\n");
    scanf("\n%c",&opt);//here we added the \n to tell the scanf that you will get \n and accept it with opt do not take as real value 
    not_valid = 0;
    switch(opt){
            case '+':
            answer= input1 + input2;
            break;
            case'-':
            answer = input1 - input2;
            break;
            case '*':
            answer = input1 * input2;
            break;
            case '/':
            if(input2 == 0){
                printf("We can not devide by zero\n");
                div_by_zero = 1;
            }
            else{
            
                answer = input1 / input2;
            }
            
            //printf("The sum is %d\n",Devision);
            break;
            
            default:
            printf("Invalid operation exiting the program\n");
            not_valid = 1;
        }
        if(div_by_zero ==1){//to break the while loop 
            break;
        }
    }
    while(not_valid == 1 );
     if(div_by_zero ==1){
        multiCounting = 'y';//to run the program from starting 
            continue;
        }
        printf("Result : %.2f\n",answer);
        printf("Would you like to calculate again (y : Yes and n: No)\n");
        scanf("\n%c",&multiCounting);
    }
    while(multiCounting == 'y');
        printf("Thank you for using the calculator !\n");
}



    


