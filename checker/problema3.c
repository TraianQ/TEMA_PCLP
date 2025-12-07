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
int main()
{
    char *a = "nnan";
    printf("%s\n",codificare1(a));
    // printf("%d %s",nr_digits(15),itoa(15));
    return 0;
}