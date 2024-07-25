/*
1. What's the simplest possible input for the function?   ---->   Base case
2. Play around examples and visualise.
3. Relate hard cases to simpler cases.
4. Generalise the pattern.
5. Write code by combining the recursive pattern with the base case.
*/



// Given a number n, print the sum of all non-negative integers upto n.
/*
#include<stdio.h>

int sum(int num) {

    if (num == 0)       //  ---->  Base case
        return 0;       //  ---->  Explicitly providing answer

    return  num + sum(num - 1);     
}

eg. sum(5)
sum(5) = 5 + sum(4)
sum(4) = 4 + sum(3)
sum(3) = 3 + sum(2)
sum(2) = 2 + sum(1)
sum(1) = 1 + sum(0)
sum(1) = 1 + 0 = 1

sum(2) = 2 + sum(1) = 2 + 1 = 3
sum(3) = 3 + sum(2) = 3 + 3 = 6
sum(4) = 4 + sum(3) = 4 + 6 = 10
sum(5) = 5 + sum(4) = 5 + 10 = 15



int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("The sum of positive integers till the given number %d is: %d", num, sum(num));

    return 0;
}
*/


/* 
2. Write a function that takes two inputs m and n and outputs the number of unique paths from the top 
left corner to bottom right corner of the  m x n  grid. 
Constraints: You can only move down or right 1 unit at a time.
*/
/*
#include<stdio.h>

int UniquePaths(int m, int n) {
    if (m == 1 || n == 1)
        return 1;
    
    return UniquePaths(m , n - 1) + UniquePaths(m-1, n);
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns in the grid: ");
    scanf("%d %d", &m, &n);

    printf("There are a total of %d unique paths from the top left corner to bottom right corner of the  %d x %d  grid.", UniquePaths(m, n), m, n );
}
*/

/*
3. Write a function that counts the number of ways you can partition n objects using parts up to m (assuming m>=0) 
*/
#include<stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of objects and maximum objects in a part: ");
    scanf("%d %d", &m, &n);

    printf("%d objects using parts upto %d can be partitioned in %d no. of ways. ", n, m, );
}