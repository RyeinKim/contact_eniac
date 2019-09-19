#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 2048

void filesave(char *a, char *b, char *c);
void fileload();
void filesearch(int num);

int main()
{
	while (1)
	{
		int menu, num1;
		printf("1. ���  2. ��ȸ  3. ����  4. �˻�\n");
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
				printf("�̸�: ");
				scanf("%[^\n]s", &name);

				printf("H.P: ");
				scanf("%s", &pnum);
				getchar();

				printf("�ּ�: ");
				scanf("%[^\n]s", &address);

				filesave(name, pnum, address);
				break;
			}
			case 2:
			{
				fileload();
				break;
			}
			case 4:
			{
				printf("�� �� �˻� : ");
				scanf("%d", &num1);
				filesearch(num1);
				break;
			}
		}
	}
	return 0;
}

void filesave(char *a, char *b, char *c)
{
	FILE *fp = fopen("contact.dll", "a");
	fprintf(fp, "�̸�:\t%s\nH.P:\t%s\n�ּ�:\t%s\n", a, b, c);
	fprintf(fp, "=========================\n");
	fclose(fp);
}

void fileload()
{
	char strTemp[255];
	char *pStr;

	FILE *fp = fopen("contact.dll", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			pStr = fgets(strTemp, sizeof(strTemp), fp);
			printf("%s", strTemp);
		}
		fclose(fp);
	}
	else	{}
}

void filesearch(int num)
{
	char strTemp[255];
	char *pStr;
	char buffer[MAX_LENGTH];
	int count = 0;

	FILE *fp = fopen("contact.dll", "rt");
	if (fp != NULL)
	{
		while (fgets(buffer, MAX_LENGTH, fp) != NULL)
		{
			count++;
			if (count == num)
			{
				printf("%d��° �� : %s\n", count, buffer);
				break;
			}
		}
		pStr = fgets(strTemp, sizeof(strTemp), fp);
		printf("%s", strstr(fp, "�����"));
	}
	else {}
	fclose(fp);
}