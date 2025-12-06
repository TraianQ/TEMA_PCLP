#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *field;
    char *value;
} pair;
void resize_char_array(char *a,int *calculated_len,int new_len)
{
    if(*calculated_len>=new_len)
    {
        *calculated_len*=2;
        a = realloc(a,*calculated_len);
    }
}
int main()
{
    int n;
    char *field,*value,*input,*output;
    
    field = malloc(100*sizeof(char));
    value = malloc(100*sizeof(char));
    input = malloc(11000*sizeof(char));

    scanf("%d",&n);
    pair *Perechi_Cuvinte = malloc(n*sizeof(pair));

    for(int i=0;i<n;i++)
    {
        scanf("%s%s",field,value);
        Perechi_Cuvinte[i].field = strdup(field);
        Perechi_Cuvinte[i].value = strdup(value);
    }

    getchar();
    fgets(input,11000,stdin);
    output = malloc(2*strlen(input)*sizeof(char));

    char *start = input;
    while(start!=NULL)
    {
        int found = 0,chosen_word=0;

        char *minPointer = start+1000000;

        for(int i=0;i<n;i++)
        {
            char *pos = strstr(start,Perechi_Cuvinte[i].field);
            if(pos==NULL)
                continue;
            if(pos<minPointer)
            {
                chosen_word = i;
                minPointer = pos;
                found = 1;
            }
        }
        if(found)
        {
            strncat(output,start,minPointer-start);
            strcat(output,Perechi_Cuvinte[chosen_word].value);
            start = minPointer+strlen(Perechi_Cuvinte[chosen_word].field);
        }
        else
        {
            strncat(output,start,minPointer-start);
            break;
        }
    }
    printf("%s",output);
    free(field);
    free(value);
    free(input);
    free(Perechi_Cuvinte);
    free(output);
    return 0;
}