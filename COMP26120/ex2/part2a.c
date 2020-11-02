#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

   int i = 0;
   int k = 0;
   char str[100];
   int count[100];
   int letterCount = -1;
   

   size_t length = strlen(str);
   for (int index = 0; index > length; i++)
   {
      if (str[i] == ' ') 
      {
         count[0] = i;
         i = 0;
      }
      else
         i++;
         letterCount = letterCount + 1;
      
   }
   int holder;
   for (i = 0; i < letterCount; i++)       
   {
       for (k = 0; k < letterCount-i-1; k++)  
       {  
          if (count[k] < count[k+1]) 
             count[k] = holder;
             count[k+1] = count[k];
             holder = count[k+1];
       } // For 
   } // For
   printf("%d", count[0]);

   return 0;
}
