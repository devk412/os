#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    } 
}
void main(){
    int n, ttl_head_mvt, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n+1];
    printf("Enter the requests in their sequence:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("head position: ");
    scanf("%d", &head);
    requests[n] = head;
    sort(requests,n+1);
    display(requests,n+1);
    int head_ind;
    for(int i = 0;i<n;i++){
        if(requests[i] == head){
            printf("Head at index:%d",i);
            head_ind = i;
        }
    }
    printf("\nLEFT:\n");
    for(int i=head_ind-1;i>=0;i--){
        ttl_head_mvt += abs(head - requests[i]);
        printf("%d\t",requests[i]);
        head = requests[i];
    }
    for(int i=head_ind+1;i<=n;i++){
         ttl_head_mvt += abs(head - requests[i]);
        printf("%d\t",requests[i]);
        head = requests[i];
    }
    printf("TTL H MVT: %d",ttl_head_mvt);
    ttl_head_mvt = 0;
    printf("\nRIGHT:\n");
    for(int i=head_ind+1;i<=n;i++){
        ttl_head_mvt += abs(head - requests[i]);
        printf("%d\t",requests[i]);
        head = requests[i];
    }
    for(int i=head_ind-1;i>=0;i--){
        ttl_head_mvt += abs(head - requests[i]);
        printf("%d\t",requests[i]);
        head = requests[i];
    }
    printf("TTL H MVT: %d",ttl_head_mvt);
}
