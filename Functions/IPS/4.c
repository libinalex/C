/*
C program to read and print an employee's detail using the structure. 
( employee’s details like name, employee id, and salary )

Inout:

Jaya

15096

138900

Output:

Jaya 15096 138900.000000
*/

#include <stdio.h>
 
struct employee{
    char    name[30];
    int     empId;
    float   salary;
};
 
int main()
{
    struct employee emp;
    scanf("%s",emp.name);
    scanf("%d",&emp.empId);
    scanf("%f",&emp.salary);
     
    printf("%s %d %f", emp.name, emp.empId, emp.salary);

    return 0;
}