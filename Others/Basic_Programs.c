/*
// 1. Basic Arithematic operations on two numbers:
#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter number a: ");
    scanf("%f", &a);

    printf("Enter number b: ");
    scanf("%f", &b);

    printf("The sum is %f\n", a+b);
    printf("The difference is %f\n", a-b);
    printf("The product is %f\n", a*b);
    printf("The quotient is %f\n", a/b);         // here cannot use modulus operaion as it works only on       
    printf("The exponent a^b is %f\n", pow(a,b));         //integer values whereas here we use float
    


    return 0;
}

// 2. Program to calculate area of a square 
#include <stdio.h>

int main()
{
    float a;
    printf("Enter the side of the square: ");
    scanf("%f",&a);
    printf("The area of the square of given side is: %f", a*a);
   
    return 0;
}
*/
/*
// 3. Program to calculate area of circle
#include <stdio.h>

int main()
{
    float pi=3.14, r;
    printf("Enter the radius of the circle: ");
    scanf("%f",&r);
    printf("The area of the circle of given radius is: %f", pi*r*r );
   
    return 0;
}
*/
/*
// 4. Program to check whether a number is even or odd.
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num%2 == 0 ) {
        printf("The given number is even.\n");
    }
    else{
        printf("The given number is odd.");
    }
   
    return 0;
}
*/
/*
// 5. Program to check if a candidate is eligible to vote.

#include<stdio.h>

int main()
{
    int num;
    printf("Enter your age: ");
    scanf("%d", &num);
    if (num>=18)
        printf("You can vote!");
    else
        printf("You cannot vote!");

    return 0;
}
*/
/*
// 6. C Program to Find Prime Factors of a Numbers
#include<stdio.h>
int main()
{
    int num, i, j ;
    printf("Enter the number you want prime factors of:\n");
    scanf("%d",&num);
    for (i=2 ; i<num ; i++){
        if ( num%i == 0 ){
            for (j=2 ; j=i-1 ; j++){
                if (i%j == 0){
                    continue
                printf("%d ",i);
                }
            }
            
        }
    }

    return 0;
}

*/