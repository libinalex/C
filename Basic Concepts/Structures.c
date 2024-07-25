/*
A structure can be declared as:
struct stud {
    int roll;
    char dept_code[25];
    float cgpa;
};

struct  stud  a, b, c;

And the individual structure elements can be accessed as:
a.roll ,  b.roll ,  c.cgpa , etc.

Arrays of Structures
We can define an array of structure records as
    struct   stud   class[100] ;

The structure elements of the individual records can be accessed as:
    class[i].roll
    class[20].dept_code
    class[k++].cgpa

*/

/*
// 1. Sorting a structure by Roll Numbers
#include <stdio.h>
struct stud
{
    int roll;
    char dept_code[25];
    float cgpa;
};

int main()
{
    struct stud class[100], t;
    int j, k, n;

    printf("Enter the no. of students: ");
    scanf("%d", &n);
   
    for (k = 0; k < n; k++) {
        scanf("%d %s %f", &class[k].roll, class[k].dept_code, &class[k].cgpa);
    }

    for (j = 0; j < n-1; j++) {
        for (k = j + 1; k < n; k++)
        {
            if (class[j].roll > class[k].roll)
            {
                t = class[j];
                class[j] = class[k];
                class[k] = t;
            }
        }
    }

    printf("\nThe given structure sorted by roll no. is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Roll. no.: %d \nDepartment code: %s \nCGPA: %f \n\n", class[i].roll, class[i].dept_code, class[i].cgpa);
    }
    
    return 0;
}
*/

/*
You may recall that the name of an array stands for the address of its zero-th element.
It is also true for the names of arrays of structure variables.
Consider the declaration:
struct stud   {
    int    roll;
    char  dept_code[25];
    float  cgpa;
} class[100],  *ptr ;

The name class represents the address of the zero-th element of the structure array.
ptr is a pointer to data objects of the type struct stud.
The assignment
    ptr  =  class ;
will assign the address of class[0] to ptr.
When the pointer ptr is incremented by one (ptr++) :
The value of ptr is actually increased by sizeof(stud).
It is made to point to the next record.

Once ptr points to a structure variable, the members can be accessed as:
    ptr  –>  roll ;
    ptr  –>  dept_code ;
    ptr  –>  cgpa ;

The symbol “ –> ” is called the arrow operator.

When using structure pointers, we should take care of operator precedence.
Member operator “.” has higher precedence than “ * ”.
ptr –> roll    and    (*ptr).roll    mean the same thing.
*ptr.roll   will lead to error.

The operator  “–>”  enjoys the highest priority among operators.
++ptr –> roll    will increment roll, not ptr.
(++ptr) –> roll    will do the intended thing.
*/
/*
#include <stdio.h>

typedef struct
{
    float real;
    float imag;
} _COMPLEX;

void print(_COMPLEX *a)
{
    printf("%f + i%f\n", a->real, a->imag);
}

void swap_ref(_COMPLEX *a, _COMPLEX *b)
{
    _COMPLEX tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    _COMPLEX x = {10.0, 3.0}, y = {-20.0, 4.0};

    print(&x);
    print(&y);
    swap_ref(&x, &y);
    printf("After swapping: \n");
    print(&x);
    print(&y);

    return 0;
}
*/

/*


*/

#include<stdio.h>
#include <stdint.h>
int main() {

    printf("Your input is: %d\n", INT8_MAX);
    return 0;
}