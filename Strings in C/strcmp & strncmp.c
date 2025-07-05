
// strcmp() in C
#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "abcd", str2[] = "abcdef", str3[] = "abcd";
  int result;

  // comparing strings str1 and str2
  result = strcmp(str1, str2);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = strcmp(str1, str3);
  printf("strcmp(str1, str3) = %d\n", result);

  return 0;
}

O/P: 

strcmp(str1, str2) = -101
strcmp(str1, str3) = 0


// *******************  strncmp() in C *******************************

#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "abcdef");
   strcpy(str2, "accd");

   ret = strncmp(str1, str2, 4);
printf("%d\n",ret);
   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}

O/P:
-1
str1 is less than str2