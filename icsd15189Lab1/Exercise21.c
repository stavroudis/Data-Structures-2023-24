#include <stdio.h>
#include <stdlib.h>

//sunarthsh dimiourgias pinaka N megethous
int* Array(int N)
{
    int *array;
    array=(int *)malloc(N*sizeof(int));
    //an uparxei adunamia desmeushs mnhmhs
    if (array==NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }
    //arxikopoihsh pinaka me taksinomhmenous arithmous
    array[0]=0;
    for(int i=1;i<N;i++)
    {
        array[i]=array[i-1]+i;
    }
    printf("\n");
    //emfanish pinaka
    for(int i=0;i<N;i++)
    {
        printf("%d " ,array[i]);
    }
    //epistrofh pinaka
    return array;
}

//duadikh anazhthsh  me anadromnh
int RecursiveBinarySearch(int k,int* array,int left,int right)
{
   //algorithmos duadikhs anazhthshs
    if (right>=left)
    {
        int mid=left +(right-left)/2;
        
        //an vrethei to kleidi
        if(array[mid]==k)
        {
        printf("\n\nKey:%d",k);
        printf("\nElement found!");
        return mid; // epistrofh theshs tou kleidiou
        }
        //an to kleidi einai mikrotero apo thn timh tou stoixeiou sth thesh mid sunexizei h anazhthsh sto aristero miso tou pinaka
        else if (array[mid]>k)
         return RecursiveBinarySearch(k,array,left,mid - 1);
        //alliws sunexizei sto deksio miso tou pinaka
        else 
         return RecursiveBinarySearch(k,array,mid + 1,right);
       
    }
    //an den vrethei to kleidi epistrefei -1
    else
    {
    printf("\n\nKey:%d",k);
    printf("\nElement not found!");
    return -1;
    }
}

int main()
{
    
    int N,k,result;//result to apotelesma tis sunarthshs dld -1 an den uparxei kleidi h mid dld h thesh pou vrethhke to kleidi ston pinaka
    int* array;
    printf ("Give the size of the array: ");
    scanf("%d",&N);
    array=Array(N);//dimiourgia pinaka megethous N

    //k to kleidi sto opoio dinoume diafores times 
     k=1;
    
     result = RecursiveBinarySearch(k,array,0,N - 1 );//arxikopoihsh tou left me 0 kai tou right me N-1 sti sunarthsh
     //an den vrethei to kleidi
     if (result == -1){
        printf("\nElement is not present in array");
    }
    //an vrethei emfanish ths theshs
    else 
        printf("\nElement is present at index %d", result);

    k=10;
    
    result = RecursiveBinarySearch(k, array,0,N - 1 );
     if (result == -1){
        printf("\nElement is not present in array");
    }
    else 
        printf("\nElement is present at index %d", result);
    
    k=22;
    
    result = RecursiveBinarySearch(k, array,0,N - 1 );
     if (result == -1){
        printf("\nElement is not present in array");
    }
    else 
        printf("\nElement is present at index %d", result);
    
    k=5;
    
    result = RecursiveBinarySearch(k, array,0,N - 1 );
     if (result == -1){
        printf("\nElement is not present in array");
    }
    else 
        printf("\nElement is present at index %d", result);
    
    //apodesmeush mnhmhs
    free(array);
    array =NULL;

    return 0;
    
}


    

