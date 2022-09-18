#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 비밀번호 입력
// 맞는 경우 메모장 출력 및 추가 입력
// 틀리면 경고

#define MAX 10000

int main(void)
{
	// fgets, fputs 활용
	char line[MAX]; // 파일에서 불러온 내용 저장
	char contents[MAX]; // 일기장에 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력 때 키값 확인용 (마스킹)
	
	printf("'비밀 메모장'\n");
	printf("비밀번호를 입력하세요 : \n");

	// getchar() : 엔터로 동작 실행
	// getch() : 키 입력 시 동작 실행

	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13) // enter -> 비밀번호 입력 종료
		{
			password[i] = '\0';
			break;
		}
		else // 비밀번호 입력 중
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// 비밀번호 : zz123123
	printf("\n\n ==== 비밀번호 확인 중 ... ==== \n\n");
	if (strcmp(password, "zz123123") == 0)
	// 비밀번호 일치, strcmp(a, b) : 문자열 비교 -> 0 : 일치
	{
		printf(" ==== 비밀번호 확인 완료 ==== \n\n");
		char* fileName = "c:\\file_project.txt";
		FILE* file = fopen(fileName, "a+b"); 
		// 파일이 없으면 생성, 없으면 append (뒤에 내용 추가)
		if (file == NULL)
		{
			printf("파일 열기 실패\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);

		}

		printf("\n\n 내용을 계속 작성하세요! 종료하시려면 EXIT를 입력하세요!\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); // 줄바꿈이 나오기 전까지 읽음 (한 문장씩)
			getchar(); // Enter 입력(\n)을 Flush 처리

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("비밀 메모장 입력을 종료합니다\n\n");
				break;
			}
			else if (strcmp(contents, "RESET") == 0)
			{
				file = fopen(fileName, "wb");
				fputs("\0", file);
				printf("\n메모장을 초기화합니다. \n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);
		}
		fclose(file);
	}
	else
	{
		printf(" ==== 비밀번호가 틀렸습니다. ====\n\n");
	}

	return 0;
}