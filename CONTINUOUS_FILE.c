#include<stdio.h>
#include<stdlib.h>
void recurse(int files[]){
    int sb,len,j,k,flag = 0,ch;
    printf("Enter the starting block of the file and length of file: ");
    scanf("%d%d",&sb,&len);
    for(j=sb;j<sb+len;j++){
        if(files[j] == 0)
            flag++;
    }
    if(flag == len){
        for(k=sb;k<sb+len;k++){
            if(files[k] == 0){
                files[k] = 1;
                printf("%d\t\t%d\n",k,files[k]);
            }
        }
        if(k !=sb+len-1)
            printf("File allocated."); 
    }
    else
    printf("The file is not allocated to the disk\n");
    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files);
    else
        exit(0);
    return;
}
void main(){
    int files[50],i;
    for(int i=0;i<50;i++){
        files[i] = 0;
    }
    printf("Contiguous file allocation: \n");
    recurse(files);
}