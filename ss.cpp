#include "StdAfx.h"
int symbol[][4]=
{
	1,	1,	1,	0,
	1,	0,	0,	1,
	0,	1,	1,	0,
	1,	0,	0,	1
};
int symbol_type( char s)
{
	if( s>='0' && s<='9')
		return 0;
	else if ( s=='+' || s=='-' || s=='*' || s=='/')
		return 1;
	else if ( s=='(')
		return 2;
	else if ( s==')')
		return 3;
	else
		return 4;
}
void process(char *expr)
{
	
	int LB = 0;
	char *head = expr;
	int lastType = symbol_type(*head++);
	if(lastType == 2)
		LB++;
	while (*head != '\0')
	{
		int t = symbol_type(*head);
		if (t == 2)
			LB++;
		else if (t == 3)
		{
			if(--LB<0)
			{
				printf("unmatched bracket,pos:	%d\n",head-expr);
				return;
			}
		}

		else if(t == 4)
		{
			printf("illeagal chracter: %c\n",*head);
			return;
		}
		if(symbol[t][lastType])
		{
			lastType = t;
			head++;
		}
		else
		{
			printf("illeagal sequence: %c%c\n",*(head-1),*head);
			return;
		}
	}
	if(LB)
	{
		printf("unmatched bracket,pos:	%d\n",head-expr);
		return;
	}
	if(lastType == 1)
	{
		printf("illeagal sequence: %c%c\n",*(head-2),*(head-1));
		return;
	}
	printf("correct!\n");
	return;
}
int main(void)
{
    char *s="(1-5/5564+455-*(4+1))";
	process(s);
	char *c = new char[100];
	scanf(c);
    return 0;
}