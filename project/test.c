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
	//read mode 로file open
	fp = fopen("input.txt", "r");
	if (!fp) {
		printf("file open 에러\n");
		return;
	}
	//파일에서모든데이터를data에로딩
	count = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d", data[count].name, &data[count].jumsu);
		printf("%s %d\n", data[count].name, data[count].jumsu);
		count++;
	}
	//찾을이름입력
	printf("이름 입력: ");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		//파일에서읽은데이터(data[i].name)와찾는이름(name) 비교
		//strcmp 함수를통해비교하고같을때== 0 이다.
		if (strcmp(data[i].name, name) == 0) {
			printf("%s %d\n", data[i].name, data[i].jumsu);
		}
	}
}