#include<stdio.h>
void main(){
    float input1,input2;
    float answer;
    int multiCounting;
    char opt;
    do{
    printf("Welcome to calculator ! \n");
    printf("Enter the Input 1\n");
    scanf("%f",&input1);
    //printf("You have enterd the %d\n thank you\n",input1);
    printf("Enter the Input 2\n");
    scanf("%f",&input2);
    //printf("You have enterd the\nInput-1 %d\t Input-2 %d\n",input1,input2);
    printf("Enter the opration\n");
    printf("Select +  --> Add\t - --> Sub\t * --> Multiply\t /--> Devision\n");
    scanf("\n%c",&opt);//here we added the \n to tell the scanf that you will get \n and accept it with opt do not take as real value 
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
            }
            else{
                answer = input1 / input2;
            
            //printf("The sum is %d\n",Devision);
            break;
            }
            default:
            printf("Invalid operation exiting the program\n");
            

        }
        printf("Result : %f\n",answer);
        printf("Would you like to calculate again (1 : Yes and 2:) No\n");
        scanf("%d",&multiCounting);
    }


        while(multiCounting == 1);
        printf("Thank you for using the calculator !\n");
}



    


