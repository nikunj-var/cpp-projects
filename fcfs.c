#include<stdio.h>

int main(){
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("enter total no of processes(max 20");
    scanf("%d",&n);
    printf("enter process burst time");
    for(i=0;i<n;i++){
        printf("p[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    printf("\nProcess burst time waiting time and turn around time");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("nP[%d]tt%dtt%dtt%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\naverage waiting time %d",avwt);
    printf("\naverage turn around time %d",avtat);
    return 0;
}