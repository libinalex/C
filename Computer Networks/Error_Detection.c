// Checksum:

/*
#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    int i,parity;
    char data[20];
    printf("Enter Data: ");
    scanf("%s",&data);
    int l=strlen(data);
    printf("Choose parity 0:Even\t1:Odd");
    scanf("%d",&parity);

    for(i=0;i<l;i++) {
        if(data[i]=='1')
            count++;
    }
    if(parity==0 && count%2==0)
        printf("No error detected\n");

    else if(parity==1&&count%2==1)
        printf("No error detected\n");

    else
        printf("Error detected!!!\n");

    return 0;
}

*/
/*

// CRC

#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
   int i, j, keylen, msglen;
   char input[100], key[30], temp[30], quot[100], rem[30], key1[30];
   printf("Enter Data: ");
   gets(input);
   printf("Enter Key: ");
   gets(key);
   keylen = strlen(key);
   msglen = strlen(input);
   strcpy(key1, key);
   for (i = 0; i < keylen - 1; i++)
      input[msglen + i] = '0';

   for (i = 0; i < keylen; i++)
      temp[i] = input[i];

   for (i = 0; i < msglen; i++)
   {
      quot[i] = temp[0];
      if (quot[i] == '0')
         for (j = 0; j < keylen; j++)
            key[j] = '0';
      else
         for (j = 0; j < keylen; j++)
            key[j] = key1[j];
      for (j = keylen - 1; j > 0; j--)
      {
         if (temp[j] == key[j])
            rem[j - 1] = '0';
         else
            rem[j - 1] = '1';
      }
      rem[keylen - 1] = input[i + keylen];
      strcpy(temp, rem);
   }
   strcpy(rem, temp);
   printf("\nQuotient is ");
   for (i = 0; i < msglen; i++)
      printf("%c", quot[i]);
   printf("\nRemainder is ");
   for (i = 0; i < keylen - 1; i++)
      printf("%c", rem[i]);
   printf("\nFinal data is: ");
   for (i = 0; i < msglen; i++)
      printf("%c", input[i]);
   for (i = 0; i < keylen - 1; i++)
      printf("%c", rem[i]);
   getch();
}

*/

// Hamming Code:

#include <stdio.h>
#include <math.h>

int main() {
    int data[7], parity[4], codeword[11];
    int i, j, k, error_pos = 0;

    printf("Enter 4 bits of data:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate parity bits
    parity[0] = data[0] ^ data[1] ^ data[3];
    parity[1] = data[0] ^ data[2] ^ data[3];
    parity[2] = data[1] ^ data[2] ^ data[3];

    // Combine data and parity bits to form codeword
    k = 0;
    for (i = 0; i < 4; i++) {
        codeword[k++] = data[i];
    }
    for (j = 0; j < 3; j++) {
        codeword[k++] = parity[j];
    }

    printf("Codeword: ");
    for (i = 0; i < 7; i++) {
        printf("%d", codeword[i]);
    }

    printf("\nEnter received codeword:\n");
    for (i = 0; i < 7; i++) {
        scanf("%d", &codeword[i]);
    }

    // Calculate syndrome
    int syndrome[3];
    syndrome[0] = codeword[3] ^ codeword[4] ^ codeword[5] ^ codeword[6];
    syndrome[1] = codeword[1] ^ codeword[2] ^ codeword[5] ^ codeword[6];
    syndrome[2] = codeword[0] ^ codeword[2] ^ codeword[4] ^ codeword[6];

    // Calculate error position
    for (i = 0; i < 3; i++) {
        error_pos += syndrome[i] * (int)pow(2, i);
    }
    error_pos = 8 - error_pos;
    
    if (error_pos == 0) {
        printf("No error detected\n");
    } else {
        printf("Error at bit position: %d\n", error_pos);
        // Correct error
        if (codeword[7-error_pos] == 0) {
            codeword[7-error_pos] = 1;
        } else {
            codeword[7-error_pos] = 0;
        }
        printf("Corrected codeword: ");
        for (i = 0; i < 7; i++) {
            printf("%d", codeword[i]);
        }
    }

    return 0;
}

