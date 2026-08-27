/*
A single Screen Cinema hall has one ticket counter . One customer arrives at a time .
The requirements :
1.Add Customers
2.Serve Customers
3.Show "Housefull" if the seats are full
4.Display all the customers

Sample input:
Customer Ids:
100
115
095
086
*/
#define maxQueueSize 20
#include<stdio.h>
#include<stdlib.h>
void enqueue(int que[],int *front,int *rear,int item,int max){
    if(*rear == max-1){
        printf("HouseFull\n");
        return;
    }
    (*rear)++;
    que[*rear]=item;
    return;
}

int dequeue(int que[],int *front,int *rear){
    if(*front == -1 || *front>*rear){
        printf("No customers\n");
        return -1;
    }
    int x=que[*front];
    (*front)++;
    return x;
}

void printQueue(int que[],int front,int rear){
    while(front<=rear){
        printf("%d ",que[front]);
        front++;
    }
    return;
}

int main(){
    int queue[maxQueueSize];
    int front=0;//Points to element to be deleted
    int rear=-1;//Points to last element in queue
    int choice;
    while(1){
        printf("Enter Choice :\n 1:Add Customers \n 2:Serve Customers \n 3:Display Customers \n 4:exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int id;
                printf("Enter Customer ID :");
                scanf("%d",&id);
                enqueue(queue,&front,&rear,id,maxQueueSize);
                break;
            case 2:
                int custId=dequeue(queue,&front,&rear);
                if(custId != -1){
                    printf("Served %d \n",custId);
                }
                break;
            case 3:
                printf("Displaying Customers in queue :\n");
                printQueue(queue,front,rear);
                printf("\n");
                break;
            case 4:
                printf("Exiting Programme...\n");
                exit(0);
        }
    }
    return 0;
}
