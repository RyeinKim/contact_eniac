#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	int  jumsu;
}stdata;

void main()
{
	FILE *fp;
	int   i, count;
	char  name[20];
	stdata data[200];
	//read mode ��file open
	fp = fopen("input.txt", "r");
	if (!fp) {
		printf("file open ����\n");
		return;
	}
	//���Ͽ�����絥���͸�data���ε�
	count = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d", data[count].name, &data[count].jumsu);
		printf("%s %d\n", data[count].name, data[count].jumsu);
		count++;
	}
	//ã���̸��Է�
	printf("�̸� �Է�: ");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		//���Ͽ�������������(data[i].name)��ã���̸�(name) ��
		//strcmp �Լ������غ��ϰ�����== 0 �̴�.
		if (strcmp(data[i].name, name) == 0) {
			printf("%s %d\n", data[i].name, data[i].jumsu);
		}
	}
}