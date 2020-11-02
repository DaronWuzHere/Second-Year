#include <stdio.h>
#include <string.h>
int main(void) {

   int i;
   char string[100];
   int upperCount = 0;
   int lowerCount = 0;
   int spaceCount = 0;

   printf("Enter something thing to convert :");

   fgets(string, 100, stdin);
   size_t length = (strlen(string)-1);

   for (i = 0; i < length; i++){
      if (string[i] != 32) {
         if (string[i] >= 'A' && string[i] <= 'Z' && string[i] != 32){
            string[i] = tolower(string[i]);
            upperCount++;
         }
         else{
            string[i] = toupper(string[i]);
            lowerCount++;
         }
      }
      else 
         spaceCount = spaceCount + 1;
   }
   length = length - spaceCount;
   printf("%s", string);
   printf("Read %zd characters in total.\n", length);
   printf("%d converted to uppercase,", lowerCount); 
   printf(" %d converted to lowercase.\n", upperCount);
}
