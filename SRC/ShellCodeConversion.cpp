/* ShellCodeConversion 0.1 by Saoud Khalifah
   -----------------------------------------
   Converts from ASCII to Shellcode and vice versa
*/

#include "stdafx.h"
#include <windows.h>
#include <iostream.h>
#include <stdlib.h>
char *tableASCII[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
					  "l", "m", "n", "o", "p", "q", "r", "s", "t", "v", "u",
					  "w", "x", "y", "z"};
char *tableShellCode[] = {"\\x61", "\\x62", "\\x63", "\\x64", "\\x65", "\\x66", "\\x67", "\\x68", "\\x69", "\\x6A", "\\x6B",
					    "\\x6C", "\\x6D", "\\x6E", "\\x6F", "\\x70", "\\x71", "\\x72", "\\x73", "\\x74", "\\x75", "\\x76",
					    "\\x77", "\\x78", "\\x79", "\\x7A"};
char* convertcharASCII(char *c)
{
	for(int i=0; i < 26; i++){
		if(!strcmp(c, tableASCII[i])){
			return tableShellCode[i];
		}
	}
	return "\x90";
}
char *convertASCIItoShellCode(char *buffer)
{
	char *tmp = (char*) malloc(strlen(buffer));
	char *ret = (char*) malloc(strlen(buffer));
	char c[] = "\x90";
	sprintf(tmp, "");
	for(long i = strlen(buffer) -1;i > -1; i--){
		strncpy(c, &buffer[i], 1);
		sprintf(tmp, "%s%s", tmp, convertcharASCII(c));	
	}
	sprintf(ret, "");
	for(i = strlen(buffer) -1;i > -1; i--){
		strncpy(c, &tmp[i], 1);
		sprintf(ret, "%s%s", tmp, ret);	
	}
	return ret;
}
int main(int argc, char* argv[])
{
	char *ASCII = NULL, *shellcode = NULL, buffer[] = "\x90";
	printf("ShellCode Conversion by SkD\n");
	printf("---------------------------\n");
	printf("Your shellcode\\ASCII:\n");
	cin >> buffer;
	printf("ShellCode:\n%s\n", convertASCIItoShellCode(buffer));
	//printf("\n%s\n", tableShellCode[1]);



	return 0;
}
