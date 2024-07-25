// Grammar

// E → E + T | T
// T → T * F | F
// F → (E) | [a-z]

// a+b*c+d$
// a*c+*d$
// )a+b*c$
// ((a+b)*c$

// Eliminate Left Recursion
//  E -> TE'
//  E'-> +TE' | e
//  T -> FT'
//  T'-> *FT' | e
//  F -> (E) | [a-z]

/*
#include <stdio.h>
char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();


int main()
{
    printf("Enter the string to be processed\n");
    scanf("%s", input);
    if(E())
    {
        if (input[i] == '$')
            printf("\nString is accepted\n");
        else
            printf("\nString is not accepted");
    }
    else
        printf("\nString is not accepted\n");
}

int E()
{
    if (T())
    {
        if (EP())
        {
            printf("E -> TE'\n");
            return (1);
        }

        else
            return (0);
    }
    else
        return (0);
}

int EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
        {
            if(EP())
            {
                printf("E' -> +TE'\n");
                return (1);
            } 
            else
                return(0);
        }
    }
    else
        return (1);
}

int T()
{
    if (F())
    {
        if (TP())
        {
            printf("T -> FT'\n");
            return (1);
        }
        else
            return (0);
    }
    else
        return (0);
}

int TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
        {
            if (TP())
            {
                printf("T' -> *FT'\n");
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                printf("F -> (E)\n");
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }

    else
    {
        if (input[i] >= 'a' && input[i] <= 'z' ||
            input[i] >= 'A' && input[i] <= 'Z')
        {
            printf("F -> %c\n", input[i]);
            i++;
            return (1);
        }
        else
            return (0);
    }
}
*/

// a+b*c+d$
// a*c+*d$
// )a+b*c$
// ((a+b)*c$


// Q2. 

// Grammar
// E -> E # T | T
// T -> T & F | F
// F -> ! F | ( E ) | [a-z]


// Eliminating Left Recursion
//  E -> TE'
//  E'-> #TE' | e
//  T -> FT'
//  T'-> &FT' | e
//  F -> ! F | ( E ) | [a-z]

#include <stdio.h>
char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("Enter the string to be parsed: ");
    scanf("%s", input);
    if (E())
    {
        if (input[i] == '$')
            printf("\nString is accepted\n");
        else
            printf("\nString is not accepted");
    }
    else
        printf("\nString is not accepted\n");
}

int E()
{
    if (T())
    {
        if (EP())
        {
            printf("E -> TE'\n");
            return (1);
        }

        else
            return (0);
    }
    else
        return (0);
}

int EP()
{
    if (input[i] == '#')
    {
        i++;
        if (T())
        {
            if (EP())
            {
                printf("E' -> #TE'\n");
                return (1);
            }
            else
                return (0);
        }
    }
    else
        return (1);
}

int T()
{
    if (F())
    {
        if (TP())
        {
            printf("T -> FT'\n");
            return (1);
        }
        else
            return (0);
    }
    else
        return (0);
}

int TP()
{
    if (input[i] == '&')
    {
        i++;
        if (F())
        {
            if (TP())
            {
                printf("T' -> &FT'\n");
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                printf("F -> (E)\n");
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else if (input[i] == '!')
    {
        i++;
        if (F())
        {
            printf("F -> !F\n");
            return (1);
        }
        else
            return (0);        
    }

    else
    {
        if (input[i] >= 'a' && input[i] <= 'z' ||
            input[i] >= 'A' && input[i] <= 'Z')
        {
            printf("F -> %c\n", input[i]);
            i++;
            return (1);
        }
        else
            return (0);
    }
}


// a#b&!c$
// a&#b$
// a#b&!c)$
// (a#b)&c)$