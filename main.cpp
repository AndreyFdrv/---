#include <stdio.h>
#include <string.h>
void Step1(char *text)
{
	char nonterminal=text[0];
	bool IsRightStartNonterminal=false;
	for(int i=3; text[i]!='\n'; i++)
	{
		if(text[i]==nonterminal)
			IsRightStartNonterminal=true;
	}
	if(!IsRightStartNonterminal)
		return;
	char StartNonterminal[100]="S->";
	char oldStartNonterminal[2];
	oldStartNonterminal[0]='A';
	oldStartNonterminal[1]='\0';
	strcat(StartNonterminal, oldStartNonterminal);
	strcat(StartNonterminal, "\n");
	for(int i=0; (text[i]!='\n')&&(text[i]!='\0'); i++)
		if(text[i]==nonterminal)
			text[i]='A';
	strcat(StartNonterminal, text);
	strcpy(text, StartNonterminal);
}
bool isTerminal(char t)
{
	if((t>='a')&&(t<='z'))
		return true;
	if((t=='(')||(t==')'))
		return true;
	if((t=='+')||(t=='*'))
		return true;
	if((t>='0')&&(t<='9'))
		return true;
	return false;
}
void Step2(char *text)
{
	for(int i=0; text[i]!='\n'; i++);	
}
main(int argc,char *argv[])
{
	FILE* in=fopen(argv[1],"r");
	if(in==NULL)
		printf("File does not exist\n");	
	else
	{
		char text[100];
		fread(text, 100, 1, in);
		Step1(text);
		Step2(text);
		printf("%s", text);
		fclose(in);
	}
}

