#include<stdio.h>
#include<stdlib.h>
int* loadQueue(FILE* file, int queueSize);
int swapCount(int* queue,int queueSize,int currentIndex);
int main(){
    FILE * file;
    file = fopen("input.txt","r");
    int times;
    fscanf(file,"%d",&times);
    while(times >0){
        int queueSize,i,flag = 1;
        fscanf(file,"%d",&queueSize);
        int* queue = loadQueue(file,queueSize);
        int partialSwaps,totalSwaps=0;
        for(i = 0;i < queueSize;i++){
            partialSwaps = swapCount(queue,queueSize,i);
            if(partialSwaps < 0){
                flag = 0;
                break;
            }else{
                totalSwaps += partialSwaps;
            }
        }
        if(flag){
            printf("%d\n",totalSwaps);
        } else{
            printf("Too chaotic \n");
        }
        times--;
    }
    return 0;
}

int* loadQueue(FILE* file, int queueSize){
    int i;
    int* queue = (int*) calloc(queueSize,sizeof(int));
    for(i = 0;i < queueSize;i++){
        fscanf(file,"%d",&queue[i]);
    }
    return queue;
}

int swapCount(int* queue,int queueSize,int currentIndex){
    int swapCount = 0,i;
    for(i = currentIndex+1; i < queueSize;i++){
       if(queue[i] < queue[currentIndex]){
            swapCount++;
       }
       if(swapCount > 2){
        return -1;
       }
    }
    return swapCount;
}
