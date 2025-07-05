
#include <stdio.h> 
struct student  
{  
  
  char a;   // 1 byte
  int b;    // 4 bytes
  char c;   // 1 byte
}stud;
int main()
{
    printf("%ld",sizeof(stud));

    return 0;
}
/*
Offset | Member | Size
----------------------
0      | a      | 1 byte
1-3    | (pad)  | 3 bytes (to align int)
4-7    | b      | 4 bytes
8      | c      | 1 byte
9-11   | (pad)  | 3 bytes (to align struct size to 4-byte boundary)
----------------------
Total Size: 12 bytes
*/

/*====================== STRUCT USING ARRAYS ==============================*/
struct Example3 {
  char a;        // 1 byte
  char b[3];     // 3 bytes
  int c;         // 4 bytes
  short d[3];    // 6 bytes
};

int main() {
  printf("Size of struct Example3: %lu bytes\n", sizeof(struct Example3));
  return 0;
}

/*
Offset | Member | Size
----------------------
0      | a      | 1 byte
1-3    | b[3]   | 3 bytes
4-7    | c      | 4 bytes (naturally aligned)
8-13   | d[3]   | 6 bytes
14-15  | (pad)  | 2 bytes (to align struct to 4-byte boundary)
----------------------
Total Size: 16 bytes
*/

/*===================================================================================================================================*/
									//***USING PRAGMA***

#include <stdio.h>
#pragma pack(1)  
struct student  
{  
  
  int c; // 4 bytes  
  char a; // 1 byte  
  char b; // 1 byte  
}stud;
int main()
{
    printf("%ld",sizeof(stud));

    return 0;
}

//O/P: 6

/*=========================== ASSIGN BIT WISE PAD ===============================*/
#include <stdio.h>

struct pad {
    int c : 8;  // 8-bit integer (can store -128 to 127 if signed)
    char a : 4; // 4-bit integer (can store 0 to 15 if unsigned)
    char b : 4; // 4-bit integer (can store 0 to 15 if unsigned)
} padding;

int main() {
    padding.c = 127;  // Max for 8-bit signed
    padding.a = 10;   // 4-bit field (valid: 0 to 15)
    padding.b = 5;    // 4-bit field (valid: 0 to 15)

    printf("c = %d, a = %d, b = %d\n", padding.c, padding.a, padding.b);
    printf("Size of struct: %d\n", sizeof(padding));

    return 0;
}

/*
OUTPUT:
c = 127, a = 10, b = 5
Size of struct: 4

Address	    Data
0 - 3	      c (4 bytes, only 1 byte used)
4	          a (4 bits) + b (4 bits)
5 - 7	      Padding to align struct to 4 bytes

✅ Bit-fields optimize memory usage but still follow alignment rules.
✅ Size is likely 4 bytes due to int alignment.
✅ Bit-fields are stored compactly but can't be accessed via pointers (&padding.a is not valid).
✅ Best used for flag-type variables (e.g., status registers).
*/

/*=============== STRUCT WITH DOUBLE ======================*/
struct Example4 {
  char a;    // 1 byte
  double b;  // 8 bytes
  int c;     // 4 bytes
};

int main() {
  printf("Size of struct Example4: %lu bytes\n", sizeof(struct Example4));
  return 0;
}

/*
Offset | Member | Size
----------------------
0      | a      | 1 byte
1-7    | (pad)  | 7 bytes (to align double)
8-15   | b      | 8 bytes
16-19  | c      | 4 bytes
20-23  | (pad)  | 4 bytes (to align struct to 8-byte boundary)
----------------------
Total Size: 24 bytes

*/