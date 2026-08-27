/*
Bank account keeping the transaction amount as it is processed by customers .
The transaction amount of last customer is stored at top position .
After Completion of all transaction,the manager pull the amount one by one and
display the amount and find total_transaction_amount to print .
Define following function
push() : to insert amount in
pop() : to remove amount
dosum() : find the sum of all transaction amount
Amount inserted in following order
1050,2090,3000,6000,5500,8900
*/
#define stackSize 20
#include<stdio.h>
#include<stdlib.h>
void push(int st[],int max,int* top,int item){
    if(*top==max-1){
        printf("Stack Overflow !");
        return;
    }
    (*top)++;
    st[*top]=item;
}
void printTransactionHistory(int st[],int top){
    if(top==-1){
        printf("No Previous Transaction ! \n");
        return;
    }
    while(top>-1){
        printf("Transaction %d amount : %d",top+1,st[top]);
        printf("\n");
        top--;
    }
    return;
}

int pop(int st[],int* top){
    if(*top==-1){
        printf("Underflow !\n");
        return -1;
    }
    int x=st[*top];
    (*top)--;
    return x;
}

int doSum(int st[],int top){
    int total_transaction_amount=0;
    while(top>-1){
        total_transaction_amount+=st[top];
        top--;
    }
    return total_transaction_amount;
}

int main(){
    int tr_amount=0;
    int choice;
    int stack[stackSize];
    int top=-1;
    while(1){
        printf("Enter Your choice :\n 1:Push \n 2:pop \n 3:sum of all transaction amount \n 4:Show Transaction History \n 5:exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("Enter transaction amount to be pushed :");
                scanf("%d",&tr_amount);
                push(stack,10,&top,tr_amount);
                break;
            case 2 :
                int x=pop(stack,&top);
                if(x != -1){
                    printf("Popped %d \n",x);
                }
                break;
            case 3 :
                printf("Total_transaction_amount : %d",doSum(stack,top));
                printf("\n");
                break;
            case 4 :
                printf("Printing Previous Transactions :\n");
                printTransactionHistory(stack,top);
                break;
            case 5 :
                printf("Exiting programme ...");
                printf("\n");
                exit(0);

        }
    }
    return 0;
}
