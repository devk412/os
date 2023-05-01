#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct block {
    int index;
    int size;
};
void sort(int n,struct block b[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(b[j+1].size < b[j].size){
                struct block temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
}
void display(int n,struct block b[]){
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\n",b[i].index,b[i].size);
    }
}
void main(){
    int b,p;
    printf("Enter number of blocks: ");
    scanf("%d",&b);
    printf("Enter number of processes: ");
    scanf("%d",&p);
    struct block bk[b];
    int processes[p];
    printf("Enter block sizes:");
    for(int i=0;i<b;i++){
        scanf("%d",&bk[i].size);
         bk[i].index = i;
    }
    sort(b,bk);
    printf("Enter process sizes:");
    for(int i=0;i<p;i++){
        scanf("%d",&processes[i]);
    }
    for(int i=0;i<p;i++){
        int flag = 0;
        for(int j=0;j<b;j++){
            if(processes[i]<bk[j].size){
                printf("Process %d is in block %d\n",i+1,(bk[j].index+1));
                bk[j].size = bk[j].size - processes[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("Process %d not allocated\n",i+1);
        }
    }
}