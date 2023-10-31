#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//seiriakh anazhthsh mexri na vrethei to kleidi

void linearSearch(int *p,int k,int N) //p o deiktis ,k to kleidi kai N megethos pinaka
{
    printf("\n\t\t\tLinear Search 1\n\n"); 
    int i;
    for (i=0;i<N;i++)
    {
        if (k==p[i]){
            printf("Element found at index: %d\n",i);//ektupwnei th thesh tou pinaka
            printf("Comparisons made to find the element: %d\n",i+1);//ektypwnei ton sunoliko arithmo sugkrisewn
            break; //stamataei molis vrethei to kleidi anazhthshs
        }
    }

//an den uparxei to kleidi ston pinaka
    if (i==N)
    {
        printf("Element not found!\n");
        printf("Comparisons made: %d\n",i);
    }
}

// seiriakh anazhthsh se periptwsh pollaplwn emfanisewn tou kleidiou
void linearSearch2(int *p,int k,int N)
{
    //dhmiourgia enos dunamikou pinaka pou tha apothikeuontai oi theseis pou vrethhke to kleidi
    int *pos,counter=0; 
    pos = (int *) calloc (N ,sizeof (int));
    
    //an den uparxei diathesimh mnhmh
  if (pos == NULL)
    {
    printf ("Memory allocation error");
    exit (1);
    }
    
    printf("\n\t\t\tLinear Search 2\n\n");
    
    int i;
    for (i=0;i<N;i++)
    {
        if (k==p[i]){ //an vrethei kleidi apothikeuetai h thesh kai auksanetai o metrhths emfanisewn tou kleidiou
            pos[i]=i;
            counter++;
        }
    }
    
    if ((i==N) && (counter!=0)){
    printf("Element found %d time(s) at index(es): ",counter);
    
    //ektypwsh twn thesewn tou pinaka pou vrethhke to kleidi
    for (i=0;i<N;i++)
    {
        if (pos[i])
        printf("%d  ",pos[i]);
    }    
    printf("\nComparisons made: %d\n",i);
        }
    //an den vrethei to kleidi    
    else {
    printf("Element not found!\n");
    printf("Comparisons made: %d\n",i);
    }
    //apeleutherwsh mnhmhs gia pinaka kai deikth
    free(pos);
    pos=NULL;
}

int main ()
{
    int N;
    int *p;
    printf ("Give the size of the array: ");
    scanf ("%d", &N);
    //dhmiourgia dunamikou pinaka analoga me to megethos pou edwse o xrhsths
    p = (int *) malloc (N * sizeof (int));
    
    // se periptwsh adunamias desmeushs mnhmhs
  if (p == NULL)
    {
    printf ("Memory allocation error");
    exit (1);
    }
    //arxikopoihsh tou pinaka me tuxaious arithmous apo to 1 mexri to N 
    srand (time (NULL));
  for (int i = 0; i < N; i++)
  {
    p[i] = 1+rand () % N;
  }
  //ektupwsh tou pinaka
   printf("\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d  ",p[i]);
  }

    int k=1+rand() % N; //k enas tuxaios arithmos pou tha xrhsimopoihthei ws kleidi
    printf("\n\nKey: %d\n",k);
    //klhsh twn duo sunarthsewn seiriakhs anazhthshs
    linearSearch(p,k,N);
    linearSearch2(p,k,N);
    //apeleutherwsh mnhmhs 
    free(p);
    p=NULL;
    return 0;
}







