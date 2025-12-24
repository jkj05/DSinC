#include<stdio.h>
#define SIZE 100

int getHashVal(int key,int probe){
return (key+probe)%SIZE;
}

void insert(int table[]){
    int val;
    printf("Enter employee ID: ");
    scanf("%d",&val);
    for(int probe=0;probe<SIZE;probe++){
        int index=getHashVal(val,probe);
        if(table[index]==-1){
            table[index]=val;
            printf("Inserted %d at %d\n",val,index);
            return;
        }
    }
    printf("hash table full\n");
}

void delete(int table[]){

    int val;
    printf("Enter employee ID to delete: ");
    scanf("%d",&val);
    for(int probe=0;probe<SIZE;probe++){
        int index=getHashVal(val,probe);
        if(table[index]==val){
            table[index]=-1;
            printf("Deleted %d from index %d\n",val,index);
            return;
        }
    }
    printf("value not found\n");
}

void display(int table[]){
    for(int i=0;i<SIZE;i++){
        printf("[%d]=%d\n",i,table[i]);
    }
}

int main(){
    int table[SIZE];
    for(int i=0;i<SIZE;i++)
        table[i]=-1;
    int choice;
    while(1)
    {
        printf("\n0.Exit \n1.Insert \n2.Delete \n3.Display\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: return 0;
            case 1: insert(table); break;
            case 2: delete(table); break;
            case 3: display(table); break;
            default: printf("Invalid Choice\n");
        }
    }

}
