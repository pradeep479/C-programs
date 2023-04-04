
/*
@brief:  strncpy() function in C
We can also use strncpy() function in C to copy the substring from a given input string. 
It takes 3 parameters which are the destination string, source string along with starting index and length of the substring 
which we need to copy.

@syntax: strncpy(destination_string,input_string+pos,len);

Here pos is the starting index and len is the length of the substring which we want to copy.
*/

#include <stdio.h>
#include <string.h>

// Driver code
int main()
{
	int pos, len;

	// Testcase1
	char string[14] = "geeksforgeeks";
	char substring[14];

	// Initialize pos, len i.e., starting
	// index and len upto which we have to
	// get substring respectively.
	pos = 6;
	len = 5;
	printf("String: %s ", string);
	printf("\nsubstring is: ");

	// Using strncpy function to
	// copy the substring
	strncpy(substring,string+(pos-1),len); // or strncpy(substring,string,len) both indicating 0th index in char
	printf(substring);
	return 0;
}

O/P:
String: geeksforgeeks 
substring is: forge



// Testcase2
int main()
{
    int pos,len;
	char string2[] = "abcd,efgh,ijkl";
	char substring2[10];
	
	pos = 5;
	len = 4;
	printf("\nString: %s ", string2);
	printf("\nsubstring is: ");

	// Using strncpy function to
	// copy the substring
	strncpy(substring2,string2+(pos),len);
	printf(substring2);
	return 0;
}

O/P:
String: abcd,efgh,ijkl 
substring is: efgh