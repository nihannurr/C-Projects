#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;//nodeun icindeki sayi
    int indegree;//kendisine kac ok geldigi
}vertex;

struct node queue[10];
int a, i,j, indegree=0;
int *head=0, *tail=0, *temp1=0, *temp2=0;

int adjencency[10][10]={{1,5,-1,-1,-1,-1,-1,-1,-1,-1},{7,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{2,4,7,8,-1,-1,-1,-1,-1,-1},
                        {8,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                        {0,1,2,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,7,-1,-1,-1,-1,-1,-1,-1,-1},{4,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

void printTable(){
    printf("Adjencency list representation of graph :)");
    for(i=0;i<10;i++){
        printf("\n%d:\t\t",i);
        for (j=0;j<10;j++){
            printf("%d\t",adjencency[i][j]);
        }
    }
    printf("\n\n");
}
int calculateIndegree(){
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            for(a=0;a<10;a++){
                if(adjencency[i][j]==a){
                queue[a].indegree=(queue[a].indegree)+1;
                }
            }
        }
    }
    return queue[a].indegree;
}
void printNodes(){
    printf("Baslangic durumlari:\n");
    for(a=0;a<10;a++){
        queue[a].index=a;
        printf("%d. node'un--> indexi: %d  indegreesi: %d\n", a, queue[a].index,queue[a].indegree);
    }
    printf("\n\n\n");
}
int x,y;
void enqueue(x,y){
    head = &queue[a].index;
    tail = &queue[a].index;
    printf("%d\tKUYRUGA EKLENDI\n",queue[a].index);
}
int k,l;
void dequeue(k,l){
    head = temp1;
    temp1 = tail;
    printf("%d\tKUYRUKTAN CIKARTILDI\n",k);
}

int t,u,gecici;
int y,z;
void bastirAsama(y,z){
    for(a=0;a<10;a++){
        //queue[a].index=a;
        printf("%d. node'un--> indexi: %d  indegreesi: %d\n", a, queue[a].index,queue[a].indegree);
    }
    printf("\n\n");
}
void updateIndegree(t,u){
    for(i=0;i<10;i++){
        gecici = adjencency[t][i];
        queue[gecici].indegree = (queue[gecici].indegree -1);
    }
    printf("Indegreeler guncellendi:\n");
    bastirAsama(t,u);
}

int main()
{
    printTable();
    calculateIndegree();
    printNodes();

    //BIRINCI ASAMA
    for(a=0; a<10;a++){
        if(queue[a].indegree==0){
            if(head != 0){
                if(temp1 != 0){
                    enqueue(queue[a].index,queue[a].indegree);
                    dequeue(queue[a].index,queue[a].indegree);
                    updateIndegree(queue[a].index,queue[a].indegree);
                }else{
                    enqueue(queue[a].index,queue[a].indegree);
                    dequeue(queue[a].index,queue[a].indegree);
                    updateIndegree(queue[a].index,queue[a].indegree);
                }
            }else{
                enqueue(queue[a].index,queue[a].indegree);
                dequeue(queue[a].index,queue[a].indegree);
                updateIndegree(queue[a].index,queue[a].indegree);
            }
        }
    }
    //printf("head: %d\t\ttemp: %d\t\ttail: %d\n",*head,*temp1,*tail);

    return 0;
}
