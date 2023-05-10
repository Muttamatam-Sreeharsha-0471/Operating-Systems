#include<stdio.h>
#include<conio.h>
int main()
{
    int n,tracks[20],head,i,j,distance=0;
    float avg_distance;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d",&n);
    printf("Enter the track positions: ");
    for(i=0;i<n;i++)
        scanf("%d",&tracks[i]);
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    printf("\nFCFS Disk Scheduling Algorithm\n");
    printf("Order of track positions visited: %d",head);
    for(i=0;i<n;i++)
    {
        distance+= abs(tracks[i]-head);
        head=tracks[i];
        printf(" -> %d",head);
    }
    avg_distance=(float)distance/n;
    printf("\nAverage head movement: %.2f",avg_distance);
    return 0;
}
