#include <stdio.h>

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);

    int length=0;
    for(int i=0;str[i]!='\0';i++)
        length++;
    
    int i=0,j=length-1;

    int palindrome=1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            printf("Not a palindrome.\n");
            palindrome=0;
            break;
        }
        i++;
        j--;
    }

    if(palindrome==1)
    {
        printf("The entered string is a palindrome.\n");
    }
    return 0;
}