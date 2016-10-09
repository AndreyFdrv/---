#include <stdio.h>
#include <string.h>
extern void Step1(char *text);
extern bool isTerminal(char t);
extern void Step2(char *text);
extern bool isLeftBorder(char c);
extern bool isRightBorder(char c);
extern void substr(char *str1, char *str2, int begin, int end);
extern void begin_substr(char *str1, char *str2, int end);
extern void end_substr(char *str1, char *str2, int begin);
extern void Step3(char *text);
extern bool isRuleNew(char *text, char *rule, int right_part_begin);
extern void Step4(char *text);
extern void Step5(char *text);
main(int argc,char *argv[])
{
	FILE* in=fopen(argv[1],"r");
	if(in==NULL)
		printf("File does not exist\n");	
	else
	{
		char text[100]="\0";
		char* str_err;
		char str[50];
		str_err=fgets(str, 50, in);
		while(str_err!=NULL)
		{
			strcat(text, str);
			str_err=fgets(str, 50, in);
		}
		Step1(text);
		Step2(text);
		Step3(text);
		Step4(text);
		Step5(text);
		printf("%s\n", text);
		fclose(in);
	}
}

