#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char s1[10];
	int num1;

	FILE *fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기.
	fscanf(fp, "%s %d", s1, &num1);   // 서식을 지정하여 파일에서 문자열 읽기
	printf("%s %d\n", s1, num1);      // Hello 100: 파일에서 읽은 값을 출력
	fclose(fp);    // 파일 포인터 닫기\
	return 0;
}