#include <stdio.h>
#include<stdlib.h>


int curr[5][5], max_request[5][5], available[5],allocation[5] = {};
int maximum_resources[5], running[5], safe = 0,c = 0, i, j, exec, resources;
int processes, k = 1;
 
int main()
{	
	printf("\n\n\t\t\t******** Welcome To Operating System Project ********\n");
	printf(" \t\t\t\t\t   Shashank Vishwakarma\n \t\t\t\t\t       Roll no: B35\n\t\t\t\t\t Registration no : 11603723 \n\n\n\n");
	//printf(" \t\t\t\t\t   Shashank Vishwakarma\n \t\t\t\t\t       Roll no: B35\n\n\n\n");
	//getch();
	//system("cls");
    printf("\nEnter number of processes: ");
        scanf("%d", &processes);
 
        for (i = 0; i < processes; i++) 
    	{
            running[i] = 1;
            c++;
        }
 
        printf("\nEnter number of resources: ");
        scanf("%d", &resources);
 
        printf("\nEnter Request Vector:");
        for (i = 0; i < resources; i++) 
    	{ 
            scanf("%d", &maximum_resources[i]);
        }
 
       printf("\nEnter Allocated Resource Table:\n");
        for (i = 0; i < processes; i++) 
    	{
            for(j = 0; j < resources; j++) 
        {
              scanf("%d", &curr[i][j]);
        }
        }
 
        printf("\nEnter Maximum Request Table:\n");
        for (i = 0; i < processes; i++) 
    	{
            for(j = 0; j < resources; j++) 
        {
                    scanf("%d", &max_request[i][j]);
        }
        }
 
    printf("\nThe Avliable Resource is: ");
        for (i = 0; i < resources; i++) 
    	{
            printf("\t%d", maximum_resources[i]);
    	}
 
        printf("\nThe Allocated Resource Table:\n");
        for (i = 0; i < processes; i++) 
    	{
            for (j = 0; j < resources; j++) 
        {
                    printf("\t%d", curr[i][j]);
        }
        printf("\n");
        }
 
        printf("\nThe Maximum Request Table:\n");
        for (i = 0; i < processes; i++) 
    	{
            for (j = 0; j < resources; j++) 
        {
                printf("\t%d", max_request[i][j]);
        }
            printf("\n");
        }
 
        for (i = 0; i < processes; i++) 
    	{
            for (j = 0; j < resources; j++) 
        {
                    allocation[j] = allocation[j] + curr[i][j];
        }
        }
 
        printf("\nAllocated resources:");
        for (i = 0; i < resources; i++) 
    	{
            printf("\t%d", allocation[i]);
        }
 
        for (i = 0; i < resources; i++) 
    	{
            available[i] = maximum_resources[i] - allocation[i];
    	}
 
        printf("\nAvailable resources:");
        for (i = 0; i < resources; i++) 
    	{
            printf("\t%d", available[i]);
        }
        printf("\n");
 
        while (c != 0) 
    {
            safe = 0;
            for (i = 0; i < processes; i++) 
        {
                    if (running[i]) 
            {
                        exec = 1;
                        for (j = 0; j < resources; j++) 
                {
                                if (max_request[i][j] - curr[i][j] > available[j]) 
                    {
                                    exec = 0;
                                    break;
                                }
                        }
                        if (exec) 
                {
                                printf("\nProcess%d is executing\n", i + 1);
                                running[i] = 0;
                                c--;
                                safe = 1;
 
                                for (j = 0; j < resources; j++) 
                    {
                                    available[j] += curr[i][j];
                                }
                            break;
                        }
                    }
            }
            if (!safe) 
        {
                    printf("\nThe processes are in unsafe state.\n");
                    break;
            } 
        else 
        {
                    printf("\nThe process is in safe state");
                    printf("\nAvailable vector:");
 
                    for (i = 0; i < resources; i++) 
            {
                        printf("\t%d", available[i]);
                    }
 
                printf("\n");
            }
        }
        return 0;
}
