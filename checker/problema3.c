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
char* codificare1(char *password)
{
    char *res=calloc(1000,sizeof(char));
    // printf("%d",strlen(res));
    int fr[130]={0};

    int i;
    for(i=0;password[i]!='\0';i++)
    {

        int len = strlen(res);
        res[len] = password[i];
        strcat(res,itoa(fr[password[i]]));
        fr[password[i]]++;
    }
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
char* codificare2(char *password)
{
    char *rez = calloc(2*strlen(password),sizeof(char));
    int i;
    for(i=0;password[i]!='\0';i++)
    {
        char ch = password[i];
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
char* codificare3(char *password)
{

    char *rez = calloc(2*strlen(password),sizeof(char));
    int i;
    for(i=0;password[i]!='\0';i++)
        rez[i]=swap_letter_case(password[i]);
    return rez;
}
int main()
{
    char *a = "Pula Mea";
    printf("%s\n",codificare3(a));
    return 0;
}