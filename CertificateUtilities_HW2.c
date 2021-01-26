/*****************************************************
 * 
 * Author:  CYBV310 Students and Instructor
 *
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////
#define RDN_DESC_CN "Common Name"
///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////
char* TrimRight(char* str, const char* trimChars);

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char **argv)
{
	
	const int STRING_BUFFER_SIZE = 256;
	
	const char COMMON_NAME = "CN";
	const char ORGANIZATION = "O";
	const char COUNTRY = "C";
	// homework 2 constants attributes
	const char ORGANIZATION_UNIT = "OU";
	const char STATE = "ST";
	const char LOCALITY = "L";
		
	char commonName[STRING_BUFFER_SIZE];
	char organization[STRING_BUFFER_SIZE];
	char country[STRING_BUFFER_SIZE];
	// homework 2 pointer values
	char organizationUnit[STRING_BUFFER_SIZE];
	char state[STRING_BUFFER_SIZE];
	char locality[STRING_BUFFER_SIZE];

	GetRelativeDistinguishedName(COMMON_NAME, commonName, RDN_DESC_CN);
	GetRelativeDistinguishedName(ORGANIZATION, organization);
	GetRelativeDistinguishedName(COUNTRY, country);
	// homework 2 collects 
	GetRelativeDistinguishedName(ORGANIZATION_UNIT, organizationUnit);
	GetRelativeDistinguishedName(STATE, state);
	GetRelativeDistinguishedName(LOCALITY, locality);
	// homework 2 string print additions
	printf("\r\nThe Distinguished Name (DN) is: CN=%s, O=%s, C=%s, OU=%s, ST=%s, L=%s\r\n", commonName, organization, country, organizationUnit, state, locality);

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char *rdnValue, char *rdndescription)
{
	int result = -1;

	rdnValue[0] = '\0';

	printf("Please enter the value for %s: ", rdnAttribute);
	fgets(rdnValue, 256, stdin);
	if (strlen(rdnValue) > 0 )
	{
		TrimRight(rdnValue, NULL);
		result = 0;
	}

    return result;
}

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
	int i;

	if (trimChars == NULL)
	{
		trimChars = "\t\n\v\f\r ";
	}

	i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL)
	{
		str[i] = '\0';
		i--;
	}

	return str;
}
