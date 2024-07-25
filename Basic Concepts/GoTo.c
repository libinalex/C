/*
The control is unconditionally transferred to the statement associated with the label specified
in the goto statement. The form of a goto statement is  
goto label_name;


The following program is used to find the factorial of a number.
*/

#include <stdio.h>
int main()
{
    int n, c;
    long int f = 1;
    printf("\n Enter the number: ");
    scanf("%d", &n);
    if (n < 0)
        goto end;
    for (c = 1; c <= n; c++)
        f *= c;
    printf("\n FACTORIAL IS % ld", f);

end:
    return 0;
}
