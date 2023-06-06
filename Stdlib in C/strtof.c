/* Convert string to float example */
//************************************  TYPE 1 **********************************

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */

int main ()
{
  char szOrbits[] = "686.97 365.24"; //without array format
  char* pEnd;
  float f1, f2;
  f1 = strtof (szOrbits, &pEnd); // In "pEnd" the 2nd val 365.24 will be there as string format
  f2 = strtof (pEnd, NULL);
  printf ("One martian year takes %.2f Earth years.\n", f1/f2);
  return 0;
}

O/P:

One martian year takes 1.88 Earth years.


//************************************  TYPE 2 **********************************
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */

int main ()
{
  char *szOrbits[2] = {"686.97","365.24"}; //with array format
  float f1, f2;
  
  f1 = strtof (szOrbits[0], NULL);
  f2 = strtof (szOrbits[1], NULL);
  
  printf ("One martian year takes %.2f Earth years.\n", f1/f2);
  return 0;
}

// =====================================================================================================================================
// **************************** Convert Celcius to Farenhiet ***************
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float degC,Fah;
    char  getC[2]; //array is must
    
    printf("Enter the Temperature: ");
    scanf("%s",getC);    //get as String
    
    degC = strtof(getC,NULL);  //Convert String to float
    Fah = (degC*9/5)+32;     // Formula: (0°C x 9/5) + 32 = 32°F
    
    printf("Farenhiet is: %0.2f\n",Fah);
    return 0;
}

O/P:

Enter the Temperature: 23
Farenhiet is: 73.40

