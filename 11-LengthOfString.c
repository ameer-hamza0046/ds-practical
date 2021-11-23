#include <stdio.h>

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);

    int length=0,i;
    
    for(i=0;str[i]!='\0';i++)
        length++;

    printf("Length of the string is %d\n",length);
    return 0;
}