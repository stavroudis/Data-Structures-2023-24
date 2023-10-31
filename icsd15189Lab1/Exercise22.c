#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//sunarthsh pou elegxei an mia protash einai palindromikh me epanalipsi
bool isPalindrome(char* sentence)
{
    int i;//i to ena akro ths frashs kai j to allo wste na sigkrinontai metaksi tous
    int j= strlen(sentence)-1;//j pairnei tin analogh timh sumfwna me to megethos ths protashs
    
    for (i=0;i<j;i++,j--)
    {
        //an uparxoun xarakthres apo to aristero akro pou den anhkoun sto alfavhto tous paraleiptei
        while(!isalpha(sentence[i]) && i<j)
        {
            i++;
        }
        //an uparxoun mh alfavhtikoi xarakthres apo to deksio akro tous prospernaei
        while(!isalpha (sentence[j]) && i<j)
        {
            j--;
        }
        //se periptwsh pou ena gramma einai kefalaio to kanei pezo prin to sugkrinei kai an den einai idio me to antistoixo tou allou akrou tote h protash den einai palindromikh
        if(tolower(sentence[i]) != tolower(sentence[j]))
        {
            return false;
        }
    
    }
    return true;
}

//sunarthsh pou elegxei an mia protash einai palindromikh me anadromh 
int isPalindrome2(char* sentence,int i,int j)
{
    //sunthikh gia na einai palindromikh ,an diladi elegxthei olh h protash apo ta duo akra mexri th mesh  kai den exei epistrepsei 0
    if (i>=j)
    return 1;//to antistoixo tou true ara h protash einai palindromikh
    
    while(!isalpha(sentence[i]) && i<j)
        {
            i++;
        }
        
        while(!isalpha (sentence[j]) && i<j)
        {
            j--;
        }
        
        if(tolower(sentence[i]) != tolower(sentence[j]))
        {
            return 0;//to antistoixo tou false ara h protash den einai palindromikh
        }
        
        return isPalindrome2(sentence,++i,--j);
}

int main()
{//metavliti pou apothikeuei thn protash h th leksh pou tha elegksoume
    char sentence[100];
    
    //elegxoume gia 5 protaseis/lekseis an einai palindromikes me tous duo algorithmous pou kataskeuasame parapanw
    strcpy(sentence,"Anna");
    bool a=isPalindrome("Anna");
    if (a)//an einai true 
    {
        printf("'%s' is a palindrome!\n",sentence);
    }
    else//an einai false
    {
        printf("'%s' is not a palindrome!\n",sentence);
    }
    
  
    strcpy(sentence,"Banana");
    bool b=isPalindrome("Banana");
    if (b)
    {
       printf("'%s' is a palindrome!\n",sentence);
    }
    else
    {
       printf("'%s' is not a palindrome!\n",sentence);
    }
    
    strcpy(sentence,"Amore, Roma");
    
    int c=isPalindrome2("Amore, Roma",0,strlen(sentence)-1);//0 h arxikopoihsh tou i kai strlen(sentence)-1 tou j sthn anadromikh sunarthsh
    if (c)//an einai logiko 1 ,diladi true
    {
        printf("'%s' is a palindrome!\n",sentence);
    }
    else//an einai logiko 0 , diladi false
    {
       printf("'%s' is not a palindrome!\n",sentence);
    }
    
    strcpy(sentence,"Vive la France");
    int d=isPalindrome2("Vive la France",0,strlen(sentence)-1);
    if (d)
    {
       printf("'%s' is a palindrome!\n",sentence);
    }
    else
    {
        printf("'%s' is not a palindrome!\n",sentence);
    }
    
    strcpy(sentence,"Are we not drawn onward, we few, drawn onward to new era?");
    int e=isPalindrome2("Are we not drawn onward, we few, drawn onward to new era?",0,strlen(sentence)-1);
    if (e)
    {
       printf("'%s' is a palindrome!\n",sentence);
    }
    else
    {
        printf("'%s' is not a palindrome!\n",sentence);
    }
    
    return 0;
}

