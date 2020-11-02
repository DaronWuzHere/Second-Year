#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]){
 
   char *filename1 = argv[1];
   char *filename2 = argv[2];
   char c;
   FILE *fileptr1, *fileptr2;

   fileptr1 = fopen(filename1, "r");
   if (fileptr1 == NULL) 
   {
     fprintf(stderr, "Can't open %s for reading\n", filename1);
     exit(0);
   }// If

   fileptr2 = fopen(filename2, "w");
   if (fileptr2 == NULL)
   {
     fprintf(stderr, "Can't open %s for writing\n", filename2);
     exit(0);
   }// If

   //Count in the For loops
   int i = 0;
  
   //Char array or string
   char string[100];
   
   //Counts for spaces, letters converted to lowercase and uppercase 
   int upperCount = 0;
   int lowerCount = 0;
   int spaceCount = 0;

   c = fgetc(fileptr1);
   while (c != EOF)
   {
      string[i] = c;
      printf("%c\n", string[i]);
      c = fgetc(fileptr1);
      i = i + 1;
   } //While
  
   //The length of the input string
   size_t length = (strlen(string)-1);
   
   for (i = 0; i < length; i++)
   {
      if (string[i] != 32) 
      {
         if (string[i] >= 'A' && string[i] <= 'Z' && string[i] != 32)
         {
            upperCount++;
         }//If
         else
         {
            string[i] = toupper(string[i]);
            lowerCount++;
         }//Else
      }//If
      else 
         spaceCount = spaceCount + 1;
   }//For

   length = length - spaceCount;

   for (i = 0; i < length; i++) 
   {
      fputc(string[i], fileptr2);
   }// For
   
   fprintf(fileptr2, "%s", string);
   fprintf(fileptr2, "%s %zd %s", "Read", length, "characters in total.\n");
   fprintf(fileptr2, "%d %s", lowerCount, "converted to uppercase,"); 
   fprintf(fileptr2, "%d %s", upperCount, "converted to lowercase.\n");
  
   fclose(fileptr1);
   fclose(fileptr2);
}
