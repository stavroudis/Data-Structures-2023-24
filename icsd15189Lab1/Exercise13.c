#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//synarthsh pou dhmiourhei dunamiko pinaka analoga me to megethos N pou dinei o xrhsths
int *array(int N,int randSize)
{
    int *arr;
    arr = (int *) malloc (N * sizeof(int));
    //periptwsh adunamias desmeushs mnhmhs
    if (arr==NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }
    int i;
    //arxikopoihsh pinaka me tuxaies times metaksi 0 kai 10
    for (i=0;i<N;i++)
    {
        *(arr+i)= rand()%randSize;
    }
    //emfanish pinaka
    for (i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    return arr;
}
//sunarthsh eureshs tou pio suxna emfanizomenou arithmou ston pinaka me xronikh poluplokothta O(n^2)
int mostFrequentNumber(int* array,int N,int* freq)
{
    int maxFreq=0,mostFreqNum=0;//maxFreq krataei thn megaluterh syxnothta emfanishs enos arithmou ,h mostFreqNum thn timh tou
    
    for (int i=0;i<N;i++) {
        int count=0;//metrhths suxnothtas emfanishs enos arithmou gia na sugkrinetai me ton metrhth megaluterhs suxnothtas emfanishs 
        
        for (int j=0;j<N;j++) {
            if (array[j] == array[i]) {//katametrhsh suxnothtas emfanisewn enos arithmou 
                count++;
            }
        }
        
        if (count>maxFreq) {//an exei emfanistei perissoteres fores apo ton mexri tote MaxFreq
            maxFreq=count;//h timh megaluterhs syxnothtas emfanishs arithmou auksanetai 
            mostFreqNum=array[i];//o arithmos me th megaluterh syxnothta emfanishs apothikeuetai
        }
    }
    *freq=maxFreq;//pernaei ton metrhth suxnothtas me th megisth timh ston deikth freq 
    return mostFreqNum;//epistrefei ton arithmo me th megaluterh suxnothta emfanishs ston pinaka
}
//sunarthsh eureshs tou pio suxna emfanizomenou arithmou ston pinaka me xronikh poluplokothta O(n)
int mostFreqNumber(int* array,int N,int* freq)
{
    int maxNum=0;//h megaluterh timh pou uparxei ston pinaka array,tha xrhsimopoihthei sthn calloc argotera
    for (int i=0;i<N;i++)
    {
        if (array[i]>maxNum)
        maxNum=array[i];
    }//diaforetika anti gia maxNum+1 mporoume na orisoume to 11 sthn calloc meta

    int* freqTable;//o pinakas pou periexei tis suxnothtes emfanishs twn arithmwn
    
    freqTable= (int* )calloc (maxNum+1,sizeof(int));//arxikopoiume me calloc enan pinaka maxNum thesewn,oses diladi o megaluteros arithmos p tha emfanistei ston pinaka
    if (freqTable==NULL)
    {
        printf("Memory allocation error!");
        exit(1);
    }
    
    int num;//metavlith pou pairnei tis times tou prwtou pinaka
    int mostFreqNum=0;//metavlith pou tha emfanizei ton arithmo me th megaluterh suxnothta emfanishs tou prwtou pinaka
    int maxFreq=0;//metavlith pou metraei tis emfaniseis enos arithmou 
    for(int i=0;i<N;i++)
    {
        num=array[i];
        freqTable[num]++;//katametrhsh suxnothtas emfanishs enos arithmou tou prwtou pinaka ston deutero pinaka (o logos pou xrhsimipoihthhke calloc kai maxNum)
        
        if(freqTable[num]>maxFreq)//an enas arithmos exei emfanistei perissoteres fores apo ton mexri tote arithmo me thn megisth suxnothta emfanishs
        {
            maxFreq=freqTable[num];//h megisth timh suxnothtas emfanishs arithmou auksanetai me vash thn kainourgia
            mostFreqNum=num;//apothikeush tou arithmou me th megaluterh suxnothta emfanishs
        }
    }
    *freq=maxFreq;//pernaei ton metrhth suxnothtas emfanishs me th megisth timh ston deikth freq
    //apodesmeush mnhmhs
    free(freqTable);
    freqTable=NULL;

    return mostFreqNum;//epistrofh tou arithmou me th megaluterh suxnothta emfanishs
}


int main()
{
  srand(time(NULL));  
  int N;
  int freq;//metavlith freq h opoia tha periexei to maxFreq 
  int randSize=10;
  printf("Give the size of the array: ");
  scanf("%d",&N);
  int* arr=array(N,randSize);//dimiourgia pinaka arr megethous N
  int a=mostFrequentNumber(arr,N,&freq);//emfanish tou arithmou me thn megaluterh suxnothta emfanishs kai twn forwn pou proekupse(O(n^2))
  int b=mostFreqNumber(arr,N,&freq);//emfanish tou arithmou me thn megaluterh suxnothta emfanishs kai twn forwn pou proekupse (O(n))
  printf("\n\n\t\t\tTime Complexity: O(n^2)\n");
  printf("\nThe most frequent number is: %d",a);
  printf("\nNumber of occurrences: %d",freq);
  printf("\n\n\t\t\tTime Complexity: O(n)\n");
  printf("\nThe most frequent number is: %d",b);
  printf("\nNumber of occurrences: %d",freq);
  //apodesmeush mnhmhs 
  free(arr);
  arr=NULL;
  
  return 0;
}




