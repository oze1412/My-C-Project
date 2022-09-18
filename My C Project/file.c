#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 10000

int main_file(void) 
{
	// 파일 입출력
	// 파일에 특정 데이터 저장 및 불러오기

	// fputs, fgets -> 문자열 저장
	/*char line[MAX]; // char line[10000];
	// 파일 쓰기
	FILE* file = fopen("c:\\test1.txt", "wb");
	// r : 읽기전용, w : 쓰기전용, a : 이어쓰기; 
	// t : 텍스트, b : 바이너리;
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fputs("fputs를 이용해서 글을 적어봅니다.\n", file);
	fputs("잘 적히는지 확인해주세요.\n", file);*/

	// 파일 읽기
	/*FILE* file = fopen("c:\\test1.txt", "rb");
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	while (fgets(line, MAX, file) != NULL) // fgets는 파일을 한줄씩 읽어옴
	{
		printf("%s", line);
	}*/

	// 파일을 열고 닫지 않은 상태에서 프로그램에 문제가 생기면
	// 데이터 손실 발생 -> 항상 파일을 닫아주는 습관 필요
	/*fclose(file);*/

	// fprintf, fscanf -> 정형화 입출력
	// printf("%d, %d ... ");
	// scanf("%d, %d ... ");
	int num[6] = {0,0,0,0,0,0}; // 로또 추첨번호
	int bonus = 0; // 보너스 번호
	char str1[MAX];
	char str2[MAX];

	// 파일 쓰기
	/*FILE* file = fopen("c:\\text2.txt", "wb");
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}*/

	// 로또 추첨 번호 저장
	/*fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
	fprintf(file, "%s %d\n", "보너스번호", 7);*/

	// 파일 읽기
	FILE* file = fopen("c:\\text2.txt", "rb");
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fscanf(file, "%s %d %d %d %d %d %d\n", str1,
		&num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1,
		num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d\n", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0;
}