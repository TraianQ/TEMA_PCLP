#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int nr_digits(int nr)
{
    int cnt=0;
    do
    {
        cnt++;
        nr/=10;
    } while (nr);
    return cnt;
}
char * itoa(int nr)
{
    int nr_d = nr_digits(nr),digit_index=0;
    int power=1;
    for(int i=1;i<nr_d;i++)
        power*=10;

    char *rez = calloc(nr_d,sizeof(char));
    do
    {
        rez[digit_index++] = (nr/power%10)+'0';
        power/=10;
    } while (power);
    return rez;
}
char* codificare1(char *password,char new_char)
{
    char *res=calloc(1000,sizeof(char));
    static int fr[130]={0};

    int i;

    res[0]=new_char;
    strcat(res,itoa(fr[new_char]));
    fr[new_char]++;
    res[strlen(res)]='\0';
    return res;
}
int nr_biti_setati(int nr)
{
    int cnt=0;
    while(nr)
    {
        cnt+=nr%2;
        nr/=2;
    }
    return cnt;
}
char* codificare2(char new_char)
{
    char *rez = calloc(2,sizeof(char));
    int i;
    {
        char ch = new_char;
        ch^=(1<<3);
        ch^=(1<<6);

        int nr_biti = nr_biti_setati(ch);
        ch|=32; 
        ch-=ch%2;
        rez[i*2]=ch;
        rez[i*2+1]=(nr_biti+'0');
    }
    return rez;
}
char swap_letter_case(char ch)
{
    if(ch>='a' && ch<='z')
        return ch-32;
    else if(ch>='A' && ch<='Z')
        return ch+32;
    return ch;
}
char* codificare3(char new_char)
{

    char *rez = calloc(1,sizeof(char));
    int i;
    rez[0]=swap_letter_case(new_char);
    return rez;
}
int main()
{
    int seed,L;
    scanf("%d%d",&seed,&L);


    char *generated_array=malloc(L*sizeof(char));
    char codified_array[10000];

    srand(seed);
    char chars[]={')','\\','F','C'};
    int steps[]={0,2,2,1};
    for(int i=0;i<L;i++)
    {
        char c = chars[i];
        // char c = rand()%(125-32)+32;
        int codif = steps[i];
        char *codification;
        switch(codif)
        {
            case 0:
                codification = strdup(codificare1(generated_array,c));
                break;
            case 1:
                codification = strdup(codificare2(c));
                break;
            case 2:
                codification = strdup(codificare3(c));
                break;
            default:
                break;
        }
        // printf("%s ",codification);
        strcat(codified_array,codification);
        generated_array[i]=c;
    }
    printf("%s",generated_array);
    return 0;
}