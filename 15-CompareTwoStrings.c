#include <stdio.h>

int main()
{
    char str1[20],str2[20];
    printf("Enter first string: ");
    scanf("%s",str1);
    printf("Enter second string: ");
    scanf("%s",str2);

    int length1=0,length2=0;
    for(int i=0;str1[i]!='\0';i++)
        length1++;
    for(int i=0;str2[i]!='\0';i++)
        length2++;
    
    if(length1!=length2)
    {
        printf("The strings are not equal\n");
        return 0;
    }

    for(int i=0;i<length1;i++)
    {
        if(str1[i]!=str2[i])
        {
            printf("Strings are not equal\n");
            return 0;
        }
    }

    printf("Strings are equal\n");
    return 0;
}