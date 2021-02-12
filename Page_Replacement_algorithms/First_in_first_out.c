#include<stdio.h>

int main(){
    int i,j,n,no,k,avail,count=0;
    printf("Enter no. of pages :");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the page numbers :");
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter no. of frames :");
    scanf("%d",&no);
    int frame[no];
    for(i=0;i<no;i++)
        frame[i]=-1;    //frame initialisation
    j=0;
    printf("Reference string\tPage frame\n");
    for(i=1;i<=n;i++){
        printf("\t%d\t\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
        if(frame[k]==a[i])     //to check whether the page is already present
        avail=1;
        if(avail==0){
            frame[j]=a[i];
            j=(j+1)%no;
            count++;              
            for(k=0;k<no;k++)       //finally, printing the frame
            printf("%d  ",frame[k]);
        }
        printf("\n");    
    }
    printf("\nPage Fault is %d",count);
}