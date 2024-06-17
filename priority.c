#include<stdio.h>
void main()
{
int min,temp,i,n,prio[10],p[10],bt[10],wt[10],tat[10],j,totalwt=0,totaltat=0;
float avgwt,avgtat;
printf("Enter the number of process");
scanf("%d",&n);
printf("Enter the burst time and priority of processes");
for(i=0;i<n;i++)
{
  printf("\np[%d]:",i+1);
  printf("burst time");
  scanf("\n%d",&bt[i]);
  printf("priority");
  scanf("\n%d",&prio[i]);
  p[i]=i+1;
  }
for(i=0;i<n;i++)
{
  min=i;
  for(j=i+1;j<n;j++)
  {
    if(prio[j]<prio[min])
    {
      min=j;
      }
      }
    temp=prio[i];
    prio[i]=prio[min];
    prio[min]=temp;  
      
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
 wt[i]=0;
 for(j=0;j<i;j++)
 {
   wt[i]+=bt[j];
  }
 }
 printf("\n\tPROCESS \tBURST TIME\tTURNAROUND TIME\t WAITING TIME");
 for(i=0;i<n;i++)
 {
   tat[i]=wt[i]+bt[i];
   totaltat+=tat[i];
   totalwt+=wt[i];
   printf("\n\tp[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
   }
  avgwt=(float)totalwt/n;
  avgtat=(float)totaltat/n;
  printf("\nAverage waiting time is %f",avgwt);
   printf("\nAverage turn around time is %f",avgtat);
  }

