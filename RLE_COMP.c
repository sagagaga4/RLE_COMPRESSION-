#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RLE (char *str)
{
    int count = 1, j = 0 , len;
    char *temp;
    len = strlen(str);

    if(str == NULL || len <= 0)
    {
        printf("INPUT ERROR\n");
        return;
    }

    temp = malloc(2 * len * sizeof(char) + 1);
    if(temp == NULL || len <= 0)
    {
        printf("ALLOCATION FAILED\n");
        return;
    }

    for(int i = 0; i < len; i++)
    {
        if(i <= len - 1 && str[i] == str[i+1])
        {
            count++;
        }

        else
        {
            temp[j++] = str[i];
            temp[j++]= '0' + count;
            count = 1;
        }
    }

    temp[j] = '\0';
    printf("%s\n",temp);
    free(temp);
    return;
}

int main()
{
    char *s = "AAAAASSSSSDDD";
    RLE(s);
    printf("done\n");
    return 0;
}

