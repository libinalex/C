
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    int sum  = 0, marks[n];
    float average;
    for(int i=0; i<n; i++){
        printf("Enter the marks scored by %d student: \n",i+1);
        scanf("%d",&marks[i]);
        sum += marks[i];
    }
    average = sum/n;
    printf("The average marks by students is: %f\n",average);
    return 0;
}
