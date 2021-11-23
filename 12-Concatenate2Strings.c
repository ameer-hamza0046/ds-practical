#include <stdio.h>

int main()
{
    char str1[20],str2[20],str3[40];
    printf("Enter first string: ");
    scanf("%s",str1);

    printf("Enter second string: ");
    scanf("%s",str2);

    int length1=0,length2=0;

    for(int i=0;str1[i]!='\0';i++)
        length1++;

    for(int i=0;str2[i]!='\0';i++)
        length2++;

    int i=0,j,k;
    //copying first string to str3
    for(j=0;j<length1;i++,j++)
        str3[i]=str1[j];

    //concatenating second string to str3
    for(k=0;k<length2;i++,k++)
        str3[i]=str2[k];
    
    //null character at the end of str3

    str3[i]='\0';

    printf("Concatenated string is %s\n",str3);
    return 0;
}