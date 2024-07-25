/*
#include<stdio.h>

int main()
{
printf("%x\n", -1>>1);
return 0;

}
*/
/* print the numbers in the following format upto a given number and that number is entered by the keyboard:
2 4 6 8 …………………….. up to that given number

#include<stdio.h>

int main()
{
    int num,i;
    printf("Enter the number:");
    scanf("%d",&num);
    for(i=2 ; i<=num ; i+=2)
    {
        printf("%d ",i);
    }
    return 0;
}
*/

// #include<stdio.h>
// void name();
// int main()
// {
//     name();
//     return 0;
// }

// void name()
// {
//     printf("My name is Libin Alex.");
// }
/*

#include <stdio.h>
int main()
{
 register int a = 10;
 ++a;
 printf("Value of a : %d\n", a);
 printf("Enter a value: \n");
 scanf("%d" , a);
 --a;
 printf("Value of a : %d", a);
 return 0;


}

Write a c program to calculate total no. of vovels and consonants
*/
/*
//exit(0);
// Factorial using recursions
#include <stdio.h>

unsigned long long int factorial(unsigned int i) {

   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int  main() {
   int i = 6;
   printf("Factorial of %d is %d\n", i, factorial(i));
   return 0;
}
*/
/*
// call by value
#include <stdio.h>
#include <string.h>

struct patient
{
   int ID;
   char name[10];
   char gender;
};
// function that accepts a structure variable as arguments.

void passbyValue(struct patient p)
{
   p.ID = 102;
   printf("The patient's ID is: %d\n",p.ID);
   printf("The patient's name is: %s\n",p.name);
   printf("The patient's gender is: %c\n",p.gender);
}

int main()
{
   struct patient P1;
   P1.ID = 101;
   strcpy(P1.name,"ABC");
   P1.gender = 'M';
   passbyValue(P1);
   printf( "\nThe original value of ID is: %d\n\n",P1.ID);
   return 0;
}

// call by reference

#include <stdio.h>
#include <string.h>

struct patient
{
   int ID;
   char name[10];
   char gender;
};
// function that accepts a structure variable as arguments.

void passbyValue(struct patient *p)
{
   p->ID = 102;
   printf("The patient's ID is: %d\n",p->ID);
   printf("The patient's name is: %s\n",p->name);
   printf("The patient's gender is: %c\n",p->gender);
}

int main()
{
   struct patient P1;
   P1.ID = 101;
   strcpy(P1.name,"ABC");
   P1.gender = 'M';
   passbyValue(&P1);
   printf( "\nThe original value of ID is: %d\n\n",P1.ID);
   return 0;
}
*/
/*
#include <stdio.h>
struct rectangle
{
   int length, breadth, height;
};
int main()
{
   struct rectangle r1 ={.breadth=10, .height=5, .length=6};
   // struct rectangle r2 ={.breadth=20};
   printf("The values of r1 are:\n");
   printf("length=%d, breadth=%d, height=%d\n, r1.length, r1.breadth, r1.height");
   return 0;
}


#include <stdio.h>

// structure definition

struct Student

{

    // data members

    char name[10];

    int marks;

};

// declare an array of the structure Student.

struct Student stu[3];

int i, j;

// function to read the values

// from the user and print them.

void print()

{

    // read input from the user.

    for (i = 0; i < 3; i++)

    {

        printf("\nEnter the record of Student %d\n", i + 1);

        printf("\nStudent name: ");

        scanf("%s", stu[i].name);

        printf("Enter Marks: ");

        scanf("%d", &stu[i].marks);

    }

    // print the details of each student.

    printf("\nDisplaying Student record\n");

    for (i = 0; i < 3; i++)

    {

        printf("\nStudent name is %s", stu[i].name);

        printf("\nMarks is %d", stu[i].marks);

    }

}

int main()

{

    // function call

    print();

    return 0;

}
*/
/*
#include <stdio.h>
struct cricketer
{
   int runs, wickets;
   char name[25];
} player[100], t;

void main()
{
   int i, j, n;
   printf("Enter the no of cricket players\n");
   scanf("%d", &n);
   printf("Enter player info as name , wickets taken , runs scored\n");
   for (i = 0; i < n; i++)
   {
      scanf("%s %d %d", player[i].name, &player[i].wickets, &player[i].runs);
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n - 1; j++)
      {
         if (player[j].runs > player[j + 1].runs)
         {
            t = player[j];
            player[j] = player[j + 1];
            player[j + 1] = t;
         }
      }
   }

   printf("\nCricketer info in terms of runs scored from lowest to highest\n");
   printf("\nNAME\t\tWICKETS\t\tRUNS_SCORED\n");
   printf("---------------------------------------------------------\n");

   for (i = 0; i < n; i++)
   {
      printf("%s\t\t%d\t\t%d\n", player[i].name, player[i].wickets, player[i].runs);
   }
}
*/
/*
#include<stdio.h>
int main()
{
   int arr[5] = {1, 2, 3, 4, 5};
   int length = sizeof(arr);
   printf("%d",length);
   return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

void Traveresal(struct Node *ptr) {
   while (ptr != NULL)
   {
      printf("Element: %d\n", ptr->data);
      ptr = ptr->next;
   }

}

int main() {
   struct Node *head = (struct Node *)malloc(sizeof(struct Node));
   struct Node *second = (struct Node *)malloc(sizeof(struct Node));
   struct Node *third = (struct Node *)malloc(sizeof(struct Node));
   struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

   head->data = 12;
   head->next = second;

   second->data = 14;
   second->next = third;

   third->data = 17;
   third->next = fourth;

   fourth->data = 20;
   fourth->next = NULL;

   Traveresal(head);
}
*/

/* common elements in 2 linked lists
#include <stdio.h>
#include <malloc.h>
struct node
{
   int data;
   struct node *next;
};
struct node1
{
   int data1;
   struct node *next1;
};
int main()
{
   struct node *head, *newnode, *prev, *temp;
   int n;
   scanf("%d", &n);
   head = NULL;
   for (int i = 0; i < n; i++)
   {
      newnode = (struct node *)malloc(sizeof(struct node));
      scanf("%d", &newnode->data);
      newnode->next = NULL;
      if (head == NULL)
      {
         head = prev = newnode;
      }
      else
      {
         prev->next = newnode;
         prev = newnode;
      }
   }
   temp = head;
   while (temp != NULL)
   {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");


   struct node1 *head1, *newnode1, *prev1, *temp1;
   int n1;
   scanf("%d", &n1);
   head1 = NULL;
   for (int i = 0; i < n1; i++)
   {
      newnode1 = (struct node1 *)malloc(sizeof(struct node1));
      scanf("%d", &newnode1->data1);
      newnode1->next1 = NULL;
      if (head1 == NULL)
      {
         head1 = prev1 = newnode1;
      }
      else
      {
         prev1->next1 = newnode1;
         prev1 = newnode1;
      }
   }
   temp1 = head1;
   while (temp1 != NULL)
   {
      printf("%d ", temp1->data1);
      temp1 = temp1->next1;
   }
   printf("test1 \n");
   struct node *a;
   a = head;
   struct node1 *b;

   while (a != NULL)
   {
      b = head1;
      while (b != NULL)
      {
         if (b->data1 == a->data)
         {
            printf("%d ", a->data);
         }
         b = b->next1;
      }
      a = a->next;
   }
   return 0;
}

*/
/*
#include <stdio.h>
#include <malloc.h>
struct node
{
   int data;
   struct node *next;
};
struct node *top, *newnode, *temp;

void push(int x)
{

   newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = x;
   newnode->next = NULL;
   if (top == NULL)
   {
      top = newnode;
   }
   else
   {
      newnode->next = top;
      top = newnode;
   }
}
void pop()
{
   temp = top;
   top = top->next;
   printf("%d", temp->data);
}
void peek()
{
   printf("%d", top->data);
}
void display()
{
   struct node *tmp = top;
   while (tmp != NULL)
   {
      printf("%d ", tmp->data);
      tmp = tmp->next;
   }
}
int main()
{
   int x;
   // scanf("%d",&n);
   top = NULL;
   int choice;
   do
   {
      printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         scanf("%d", &x);
         push(x);
         break;
      case 2:
         pop();
         break;
      case 3:
         peek();
         break;
      case 4:
         display();
         break;
      case 5:
         break;
      }
   }

   while (choice != 5);
   return 0;
}
*/
/*
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

   // make two process which run same
   // program after this instruction
   fork();

   printf("Hello world!\n");
   return 0;
}

*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;

    printf("Enter the number of lines: ");
    scanf("%d", &m);

    // iterate over each line
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &n);

        char **words = malloc(n * sizeof(char *)); // allocate memory for n words

        // iterate over each word in the line
        for (int j = 0; j < n; j++)
        {
            words[j] = malloc(50 * sizeof(char)); // allocate memory for each word
            scanf("%s", words[j]);  // take input for each word
        }

        // print the line
        printf("Line %d: ", i + 1);
        for (int k = 0; k < n; k++)
        {
            printf("%s ", words[k]);
            free(words[k]); // free memory for each word
        }
        printf("\n");
    }

    return 0;
}
*/


