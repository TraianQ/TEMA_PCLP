#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int letter_to_num(char letter)
{
    if(letter>='a' && letter<='z')
        return letter-'a';

    else if(letter>='A' && letter<='Z')
        return letter-'A'+26;

    return -1;
}

char num_to_letter(int digit)
{
    if(digit<26)
        return 'a'+digit;
    return 'A'+digit-26;
}

int main()
{
    char key[14000],text[14000];
    scanf("%s%s",key,text);

    int key_len=strlen(key),text_len = strlen(text);

    char *ans = malloc(text_len*sizeof(char));
    
    if(ans==NULL)
    {
        printf("RIP");
        return 0;
    }

    ans[text_len]='\0';
    for(int i=0;i<text_len;i++)
    {
        char cheie=key[i%key_len];
        char letter=text[i];
        if(letter_to_num(cheie)==-1 || letter_to_num(letter)==-1)
        {
            printf("INVALID\n");
            free(ans);
            return 0;
        }
        else
        {
            int index = letter_to_num(cheie)+letter_to_num(letter);
            index%=52;
            // printf("%c",num_to_letter(index));
            ans[i]=num_to_letter(index);
        }
    }
    // printf("AMOGUS ::: ");
    printf("%s",ans);
    printf("\n");
    free(ans);
    return 0;
}