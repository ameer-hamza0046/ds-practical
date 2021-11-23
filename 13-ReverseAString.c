#include <stdio.h>

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);

    int length=0;
    for(int i=0;str[i]!='\0';i++)
        length++;
    
    int a=0,b=length-1;
    while(a<b)
    {
        char temp = str[a];
        str[a]=str[b];
        str[b]=temp;

        a++;
        b--;
    }

    printf("Reverse of the string is %s\n",str);
    return 0;
}