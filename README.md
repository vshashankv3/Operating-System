#include <stdio.h>
#include<stdlib.h>


int current[5][5], maximum_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
 
int main()
{	
	printf("\n\n\t\t\t******** Welcome To Operating System Project ********\n");
	printf(" \t\t\t\t\tShashank Vishwakarma\n \t\t\t\t\t Roll no: B35\n\n\n\n");
	//getch();
	//system("cls");
    printf("\nEnter number of processes: ");
        scanf("%d", &processes);
 
        for (i = 0; i < processes; i++) 
    {
            running[i] = 1;
            counter++;
        }
 
        printf("\nEnter number of resources: ");
        scanf("%d", &resources);
 
        printf("\nEnter Request Vector:");
        for (i = 0; i < resources; i++) 
    { 
            scanf("%d", &maxres[i]);
        }
 
       printf("\nEnter Allocated Resource Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
              scanf("%d", &current[i][j]);
            }
        }
 
        printf("\nEnter Maximum Request Table:\n");
        for (i = 0; i < processes; i++) 
    {
            for(j = 0; j < resources; j++) 
        {
                    scanf("%d", &maximum_claim[i][j]);
            }
        }
