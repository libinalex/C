#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

struct symbol
{
    char value[INT8_MAX];
    char type[INT8_MAX];
} symbols[INT8_MAX];

bool tablecheck(char *check, int count)
{
    for (int i = 0; i < count; i++)
        if (strcmp(symbols[i].value, check) == 0)
            return true;
            
    return false;
}

bool isKeyword(char *check)
{
    char keyword[37][10] = {
        "auto", "double", "int", "struct", "break", "else", "long", "switch", "case",
        "enum", "register", "typedef", "char", "extern", "return", "union", "const",
        "float", "short", "then", "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "voltile", "do", "if", "static", "while", "print", "printf", "main",
        "scanf"};
    for (int i = 0; i < 37; i++)
        if (strcmp(check, keyword[i]) == 0)
            return true;

    return false;
}

bool isArithmeticOperator(char check)
{
    if (check == '+' || check == '-' || check == '*' || check == '/' || check == '%')
        return true;

    return false;
}

bool isRelationalOperator(char check)
{
    if (check == '>' || check == '<')
        return true;

    return false;
}

int main()
{
    FILE *ptr;
    char str[INT16_MAX];
    int i = 0;
    ptr = fopen("input.txt", "r");
    char temp = fgetc(ptr);
    while (temp != EOF)
    {
        if (temp == '\t')
        {
            temp = fgetc(ptr);
            continue;
        }
        str[i++] = temp;
        temp = fgetc(ptr);
    }
    str[i] = '\n';
    fclose(ptr);

    int count = 0;
    printf("\n\n###\t\tPARSE TREE\t\t###\n");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            continue;
        else if (str[i] == '#')
        {
            char str2[INT8_MAX];
            int j = 0;
            while (str[i] != '\n')
            {
                str2[j] = str[i];
                i++;
                j++;
            }
            str2[i] = '\0';
            for (int x = 0; str[x]; x++)
                str2[x] = tolower(str2[x]);
            printf("%-30sPreprocessor Directive\n", str2);
            memset(str2, 0, strlen(str2));
            i--;
        }
        else if (isalpha(str[i]) != 0)
        {
            char str2[INT8_MAX];
            int j = 0;
            while (isalpha(str[i]) || isdigit(str[i]) || str[i] == '_')
            {
                str2[j] = str[i];
                i++;
                j++;
            }
            str2[i] = '\0';
            for (int x = 0; str[x]; x++)
                str2[x] = tolower(str2[x]);
            if (isKeyword(str2))
            {
                printf("%-30sKeyword\n", str2);
                
            }
            else
            {
                printf("%-30sIdentifier\n", str2);
                if (tablecheck(str2, count) == false)
                {
                    strcpy(symbols[count].type, "Id");
                    strcpy(symbols[count].value, str2);
                    count += 1;
                }
            }
            memset(str2, 0, strlen(str2));
            i--;
        }
        else if (isdigit(str[i]))
        {
            char str2[INT8_MAX];
            int j = 0;
            while (isdigit(str[i]))
            {
                str2[j] = str[i];
                i++;
                j++;
            }
            str2[i] = '\0';
            printf("%-30sConstant\n", str2);
            if (tablecheck(str2, count) == false)
            {
                strcpy(symbols[count].type, "num");
                strcpy(symbols[count].value, str2);
                count += 1;
            }
            memset(str2, 0, strlen(str2));
            i--;
        }
        else if (str[i] == '"')
        {
            char str2[INT8_MAX];
            int j = 0;
            i++;
            while (str[i] != '"')
            {
                str2[j] = str[i];
                i++;
                j++;
            }
            str2[i] = '\0';
            printf("%-30sString Constant\n", str2);
            memset(str2, 0, strlen(str2));
        }
        else if (isArithmeticOperator(str[i]))
        {
            if (str[i + 1] == '=')
            {
                i++;
                printf("%-30c%cAssignment Operator\n", str[i - 1], str[i]);
            }
            else if (isArithmeticOperator(str[i + 1]))
            {
                i++;
                printf("%c%-29cIncrement/Decrement Operator\n", str[i - 1], str[i]);
            }
            else
                printf("%-30cArithmetic Operator\n", str[i]);
        }
        else if (str[i] == '=')
        {
            if (str[i + 1] == '=')
            {
                i++;
                printf("%c%-29cRelational Operator\n", str[i - 1], str[i]);
            }
            else
                printf("%-30cAssignment Operator\n", str[i]);
        }
        else if (isRelationalOperator(str[i]))
        {
            if (str[i + 1] == '=')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("%-29cRelational Operator\n", str[i]);
        }
        else if (ispunct(str[i]))
        {
            printf("%-30cSpecial Character\n", str[i]);
        }
    }
    printf("\n\n###\t\tSYMBOL TABLE\t\t###\n");
    for (int i = 0; i < count; i++)
        printf("%-30s%s\n", symbols[i].value, symbols[i].type);
}
