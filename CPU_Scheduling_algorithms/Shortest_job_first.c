#include<stdio.h>
#include<stdlib.h>

void drawGanttChart();
int noOfprocess,*processNo,totalCPUBurstTime,*arrivalTime,*burstTime,minimumArrivalTime;
float averageWaitingTime=0,averageTurnAroundTime=0;

int main(){
    int i,j,temp;
    printf("Enter the no. of process : ");
    scanf("%d",&noOfprocess);
    arrivalTime=(int*)malloc(sizeof(int)*noOfprocess);
    burstTime=(int*)malloc(sizeof(int)*noOfprocess);
    processNo=(int*)malloc(sizeof(int)*noOfprocess);

    minimumArrivalTime=2147483647;
    for(i=0;i<noOfprocess;i++){
        processNo[i]=i;
        printf("\nEnter the data for process no. %d\n",i);
        printf("Arrival Time   :");
        scanf("%d",&arrivalTime[i]);
        printf("CPU Burst time :");
        scanf("%d",&burstTime[i]);
        totalCPUBurstTime+=burstTime[i];
        if(minimumArrivalTime>arrivalTime[i])
        minimumArrivalTime=arrivalTime[i];
    }
    // implementing bubble sort algorithm
    for(i=1;i<noOfprocess;i++){
        for(j=1;j<noOfprocess-1;j++){
            if(burstTime[j]>burstTime[j+1]){
                temp=arrivalTime[j];
                arrivalTime[j]=arrivalTime[j+1];
                arrivalTime[j+1]=temp;

                temp=burstTime[j];
                burstTime[j]=burstTime[j+1];
                burstTime[j+1]=temp;

                temp=processNo[j];
                processNo[j]=processNo[j+1];
                processNo[j+1]=temp;
            }
        }
    }
    for(i=0;i<noOfprocess;i++){
        printf("P%d->%d,%d\n",processNo[i],arrivalTime[i],burstTime[i]);
    }
    drawGanttChart();
}

void drawGanttChart(){
    const int maxWidth=100;
    int scalingFactor,i,counter,tempi,currentTime;
    printf("\nThe Gantt Chart for the given process is: \n\n");
    scalingFactor=maxWidth/totalCPUBurstTime;
    for(i=0;i<scalingFactor*totalCPUBurstTime+2+noOfprocess;i++){
        printf("-");
    }
    printf("\n|");
    counter=0,tempi=0;
    for(i=0;i<scalingFactor*totalCPUBurstTime;i++){
        if(i==burstTime[counter]*scalingFactor+tempi){
            counter++;
            tempi=i;
            printf("|");
        }
        else if(i==(burstTime[counter]*scalingFactor)/2+tempi){
            printf("P%d",processNo[counter]);
        }
        else{
            printf(" ");
        }
    }
    printf("|");
    printf("\n");
    for(i=0;i<scalingFactor*totalCPUBurstTime+2+noOfprocess;i++){
        printf("-");
    }
    printf("\n");
    // printing time labels of gantt chart
    counter=0,tempi=0;
    currentTime=minimumArrivalTime;
    printf("%d",currentTime);
    for(i=0;i<scalingFactor*totalCPUBurstTime;i++){
        if(i==burstTime[counter]*scalingFactor+tempi){
            tempi=i;
            currentTime+=burstTime[counter];
            averageWaitingTime+=currentTime;
            counter++;
            printf("%2d",currentTime);
        }    
        else{
            printf(" ");
        }
    }
    currentTime+=burstTime[counter];

    printf("%2d\n\n",currentTime);
    averageWaitingTime=averageWaitingTime/noOfprocess;
    averageTurnAroundTime=averageWaitingTime+totalCPUBurstTime/noOfprocess;

    printf("Average waiting time    : %f\n",averageWaitingTime);
    printf("Average turn around time: %f\n",averageTurnAroundTime);

}