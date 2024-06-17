#include<stdio.h>
void main()
{
  int temp,i,j,min,p[20],bt[20],wt[20],tat[20],totalwt=0,totaltat=0,n;
  float avgwt,avgtat;
  printf("Enter the no of process");
  scanf("%d",&n);
  printf("Enter the burst time for process");
  for(i=0;i<n;i++)
  {
   printf("\np[%d]",i+1);
   printf("\nburst time");
   scanf("%d",&bt[i]);
   p[i]=i+1;
   }
for(i=0;i<n;i++)
{
  min=i;
  for(j=i+1;j<n;j++)
  {
    if(bt[j]<bt[min])
    {
      min=j;
      }
      }
   temp=bt[i];
   bt[i]=bt[min];
   bt[min]=temp;
   
   temp=p[i];
   p[i]=p[min];
   p[min]=temp;
  } 
 wt[0]=0;
 for(i=1;i<n;i++)
 {
   wt[i]=wt[i-1]+bt[i-1];
  }
 printf("\nPROCESS\tBURSTTIME\tWAITINGTIME\tTURNAROUNDTIME\n");
 for(i=0;i<n;i++)
 {
   tat[i]=bt[i]+wt[i];
   totalwt+=wt[i];
   totaltat+=tat[i];
   printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
   }
 avgwt=(float)totalwt/n;
 avgtat=(float)totaltat/n;
 printf("\nAverage waiting time is %f",avgwt);
 printf("\nAverage turaround time is %f",avgtat);
 }
