#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//sunarthsh pou dhmiourgei enan pinaka megethous N kai ton arxikophei me vash ton algorithmo ths askhshs
int* Array(int N)
{
    int *array;
    array=(int *)malloc(N*sizeof(int));
    if (array==NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }
    //algorithmos arxikopoihshs
    array[0]=0;
    for(int i=1;i<N;i++)
    {
        array[i]=array[i-1]+i;
    }
    printf("\n");
    return array;//epistrofh pinaka 
}

//algorithmos seiriakhs anazhthshs ston taksinomhmeno pinaka
int linearSearch(int *p,int k,int N)
{
    int i;
    for (i=0;i<N;i++)
    {
        if (k==p[i])//an vrethei to kleidi h anazhthsh stamataei
        { 
            break;
        }
            
        if(k<p[i])//efoson o pinakas einai taksinomhmenos an to stoixeio tou pinaka ginei megalutero apo to kleidi h anazhthsh stamataei
        {
            break;
        }
    }
return (i+1);//o arithmos twn sugkrisewn
}

//algorithmos duadikhs anazhthshs
int binarySearch(int *p,int k,int N)
{
    int i=0;
    int left=0;//1o stoixeio tou  pinaka(aristero akro)
    int right=N-1;//teleutaio stoixeio tou pinaka(deksio akro)
    int mid;//messaio stoixeio tou pinaka
    
    while (left <= right) {
    mid = left + (right - left) / 2;//moirazei ton pinaka sth mesh gia anazhthsh
        if (p[mid] == k) {//an to messaio stoixeio tou pinaka einai iso me to kleidi h anazhthsh stamataei
            break;
        }
        if (p[mid] > k) {//an einai megalutero apo to kleidi h anazhthsh ginetai sto aristero miso tou pinaka
            right = mid - 1;
        }
        else {//an einai mikrotero apo to kleidi h anazhthsh ginetai sto deksio miso tou pinaka
            left = mid + 1;
        }
        i++;
    }
    
return i+1;//arithmos sugkrisewn 
}

//algorithmos seiriakhs anazhthshs se mh taksinomhmeno pinaka
int linearSearch2(int *p,int k,int N)
{
    int i;
    for (i=0;i<N;i++)
    {
        if (k==p[i]){
           
            return i+1;//arithmos sugkrisewn mexri na vrethei to kleidi
            break;
        }
    }
    if (i==N)
    {
        //an den vrethei kleidi ston pinaka epistrefei ton arithmo sugkrisewn 
        return i;
    }
}

int main()
{
    int N,K;//N megethos pinaka ,K eksigeitai parakatw
    int *array;
    int i=0;
    while (i<5){//gia 5 diaforetika megethh pinaka
        
        printf("Give the size of the array: ");
        scanf("%d",&N);
        array=Array(N);//dimiourgia pinaka me vash to megethos pou dwthhke
        K=*(array+(N-1));//to K pairnei ton megalutero(teleutaio) dunato arithmo kathe fora tou pinaka N wste na dimiourgithei tuxaios arithmos k metaksi tou zitoumenou diasthmatos[0,array[N-1]]
        srand (time(NULL));
        int j=0;
        int comparisonsLS=0;//arithmos sugkrisewn me seiriakh anazhthsh se taksinomhmeno pinaka
        int comparisonsBS=0;//arithmos sugkrisewn me duadikh anazhthsh
        int comparisonsLS2=0;//arithmos sugkrisewn me seiriakh anazhthsh se mh taksinomhmeno pinaka
        double timeLS=0,timeBS=0,timeLS2=0;//arxikopoihsh sunolikou xronou
        
        while (j<100){//gia 100 diaforetikes times tou k
            int k= rand()%K;//xrhsh tou K
            clock_t start, end; 
            double elapsed;
           
            start = clock();//enarksi xronometrhshs
            comparisonsLS+=linearSearch(array,k,N);//apothikeush tou arithmou sugkrisewn p eginan
            end = clock();//lhksi xronometrhshs
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;//xronos ekteleshs ths anazhthshs ana deuterolepto(1 anazhthsh)
            timeLS+=elapsed;//apothikeush xronou ekteleshs ths anazhthshs ston sunoliko xrono(gia 100 anazhthseis)
          
            start = clock();
            comparisonsBS+=binarySearch(array,k,N);
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            timeBS+=elapsed;
            
            start = clock();
            comparisonsLS2+=linearSearch2(array,k,N);
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            timeLS2+=elapsed;
            
            j++;
        }
        
            printf("SIZE OF THE ARRAY: %d\n",N);
            printf("\n\t\t\tLINEAR SEARCH (SORTED ARRAY)\n\n");
            printf("AVERAGE NUMBER OF COMPARISONS MADE: %d\n",comparisonsLS/100);//mesos oros sugkrisewn gia 100 anazhthseis
            printf("AVERAGE SEARCHING TIME: %f\n",timeLS/100);//mesos oros xronou anazhthshs gia 100 anazhthseis
            
            printf("\n\t\t\tBINARY SEARCH\n\n");
            printf("AVERAGE NUMBER OF COMPARISONS MADE: %d\n",comparisonsBS/100);
            printf("AVERAGE SEARCHING TIME: %f\n",timeBS/100);
            
            printf("\n\t\t\tLINEAR SEARCH (UNSORTED ARRAY)\n\n");
            printf("AVERAGE NUMBER OF COMPARISONS MADE: %d\n",comparisonsLS2/100);
            printf("AVERAGE SEARCHING TIME: %f\n\n",timeLS2/100);
    
        i++;
    }
    //apeleutherwsh mnhmhs
    free(array);
    array=NULL;
    return 0;
}







