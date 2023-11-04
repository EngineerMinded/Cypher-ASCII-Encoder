// C program to implement
// the above approach
#include <stdio.h>
 
// Driver code
int main()
{
    FILE* ptr = fopen("abc.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
 
    /* Assuming that test.txt has content 
       in below format
    NAME AGE CITY
    abc     12 hyderbad
    bef     25 delhi
    cce     65 bangalore */
    char buf3[100], buf2[100], buf[100];
    while ((fscanf(ptr, "%s %*s",buf) == 1) && (fscanf(ptr, "%s", buf2) == 1))
        printf("%s %s\n", buf, buf2);
 
    return 0;
}