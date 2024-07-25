/*IPS_410_2
Write a C program to print natural numbers in a range by using Functions and control structure.

Test Case : 1

Input: Start value 10

     End Value  15

Output :  

10

11

12

13

14

15

Test Case 2

Input: Start value 30

     End Value  38

Output :  

30

31

32

33

34

35

36

37

38

 */

 #include<stdio.h>
int main()
{
    int start, end, i;
    scanf("%d",&start);
    scanf("%d",&end);
    for (i=start ; i<=end ; i++ ){
        printf("%d\n",i);
    }
    return 0;
}