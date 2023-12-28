#include<stdio.h>

struct process { 
   int id;
   int brust; 
}; 

typedef struct process proc;
int main() {
   int n; 
   printf("Enter the number of processs: "); 
   scanf("%d", &n); 
   proc p[n], temp; 
   int i,j; 
   for(i=0;i<n;i++) { 
      p[i].id=i; 
      printf("Enter the brust time of process P%d :", i);
      scanf("%d", &p[i].brust); 
   } 

   for(i=0;i<n-1;i++) { 
 	 for(j=i+1;j<n;j++) { 
 	 	 if(p[j].brust < p[i].brust){ 
	 	 	 temp.id = p[j].id; 
 	 	 	 temp.brust = p[j].brust;  	 	 	 	
                   p[j].id = p[i].id;  	 	 	 	
                   p[j].brust = p[i].brust;
                   p[i].id = temp.id; 
                   p[i].brust = temp.brust; 
	 	 } 
	 } 
    } 
    int wt=0; 
    int twt=0; 
    printf("\nScheduling Information \n");
    for(i=0;i<n;i++) { 
	 twt = twt+wt; 
	 printf("Process ID: %d \t Wating Time: %d \n",p[i].id, wt ); 
	 wt=wt+p[i].brust; 
    } 
    printf("\n Average Waiting Time: %1.2f :", ((float)twt/n));
    return 0; 
} 