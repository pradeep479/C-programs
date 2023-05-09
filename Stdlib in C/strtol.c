//Convert string to long integer
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

int main ()
{
  char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char *pEnd;  // To store remaining characters in szNumbers
  long int li1, li2, li3, li4;
  
  /**
   * Pass the address of pEnd to store remaining char.
   * Terminate until NULL char comes.
   * we are giving base 10 decimal format
  **/
  li1 = strtol (szNumbers,&pEnd,10);    // base 10(DEC)
  printf("1) remaining char:%s\n",pEnd);
  
  li2 = strtol (pEnd,&pEnd,16);        // base 16(HEX)
   printf("2) remaining char:%s\n",pEnd);
   
  li3 = strtol (pEnd,&pEnd,2);         // base 2(BIN)
   printf("3) remaining char:%s\n",pEnd);
   
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  
  return 0;
}

O/P:
1) remaining char: 60c0c0 -1101110100110100100000 0x6fffff
2) remaining char: -1101110100110100100000 0x6fffff
3) remaining char: 0x6fffff

The decimal equivalents are: 2001, 6340800, -3624224 and 7340031.
