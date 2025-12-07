#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *field;
    char *value;
} pair;

void FindFirstOccurence(char *start,pair *pairs,int n,char **minPos,int *word_index)
{
    *word_index=-1;
    int found = 0;
    for(int i=0;i<n;i++)
    {
        char *occurence = strstr(start,pairs[i].field);
        if(occurence==NULL)
            continue;
        // printf("%s %d\n",pairs[i].field,occurence-start);
        if(occurence<*minPos || found==0)
        {
            *minPos=occurence;
            *word_index=i;
            found = 1;
        }
    } 
}
int main()
{
    int n;
    scanf("%d",&n);
    char field[100], value[100], *output, input[11000];

    pair *PAIRS = malloc(n*sizeof(pair));
    if(PAIRS==NULL)
    {
        printf("RIP");
        return 1;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%s %s",field,value);
        PAIRS[i].field = strdup(field);
        PAIRS[i].value = strdup(value);
    }
    
    getchar();
    fgets(input,11000,stdin);
    
    char *start = input;
    char ans[10000];
    while(start!=NULL)
    {
        char *minPOS = NULL;
        int word_index = -1;
        FindFirstOccurence(start,PAIRS,n,&minPOS,&word_index);
        if(minPOS)
        {
            printf("%s - %s - %d\n",PAIRS[word_index].field,PAIRS[word_index].value,minPOS-start);
            strncat(ans,start,minPOS-start);
            strcat(ans,PAIRS[word_index].value);
            start = minPOS+strlen(PAIRS[word_index].field);
        }
        else
        {
            strcat(ans,start);
            break;
        }
    }
    printf("%s",ans);
    free(output);
    free(PAIRS);
    return 0;
}