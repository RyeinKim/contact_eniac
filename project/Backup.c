#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*typedef struct
{
	char name[25];
	int pnum;
	char address[256];
}Contact;*/

void filesave(char *a, char *b, char *c);
void fileload();

int main()
{
	while (1)
	{
		int menu;
		printf("1. 등록  2. 조회\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
		{
			int num;
			char name[25];
			char pnum[30];
			char address[1024];

			getchar();
			printf("이름: ");
			scanf("%[^\n]s", &name);

			printf("H.P: ");
			scanf("%s", &pnum);
			getchar();

			printf("주소: ");
			scanf("%[^\n]s", &address);

			filesave(name, pnum, address);
		}
		case 2:
		{
			fileload();
		}
		}
	}
	return 0;
}

void filesave(char *a, char *b, char *c)
{
	FILE *fp = fopen("contact.txt", "a");
	fprintf(fp, "이름:\t%s\nH.P:\t%s\n주소:\t%s\n", a, b, c);
	fprintf(fp, "=========================\n");
	fclose(fp);
}

void fileload()
{
	char strTemp[255];
	char *pStr;

	FILE *fp = fopen("contact.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			pStr = fgets(strTemp, sizeof(strTemp), fp);
			printf("%s", strTemp);
			//printf("%s", pStr);
		}
		fclose(fp);
	}
	else {}
}
/*
void filesave(char *a, char *b, char *c)
{
	FILE *fp = fopen("contact.txt", "a");
	fprintf(fp, "%s %s %s\n", a, b, c);
	fclose(fp);
}

void fileload()
{
	char s1[25], s2[30], s3[1024];
	FILE *fp = fopen("contact.txt", "r");
	fscanf(fp, "%s %s %s", s1, s2, s3);
	printf("이름: %s\H.P: %s\n주소: %s\n", s1, s2, s3);
	fclose(fp);
}
*/