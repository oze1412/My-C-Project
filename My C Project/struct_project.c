#include <stdio.h>
#include <time.h>

// 5마리의 고양이가 있다
// 아무 키나 눌러서 랜덤으로 고양이를 뽑되
// 5마리 모두 수집해야 끝나는 게임!
// 중복 발생 가능

// 고양이
// 이름, 나이, 성격, 키우기 난이도(레벨)

typedef struct
{
	char* name;
	int age;
	char* character;
	int level;
} Cat;

void initCats(); // 고양이 정보 초기화
void printCat(int selected);

// 현재까지 보유한 고양이
int collection[5] = { 0,0,0,0,0 };

// 전채 고양이 리스트
Cat cats[5];

int main_struct_project(void)
{
	srand(time(NULL));

	initCats();

	while (1)
	{
		printf("어느 고양이의 집사가 될까요? \n아무 키나 눌러서 확인하세요!");
		getchar();

		int selected = rand() % 5;
		printCat(selected); // 고양이 정보 출력
		collection[selected] = 1; // 고양이 뽑기 처리

		int collectAll = checkCollection();
		if (collectAll == 1)
		{
			break;
		}

	}

	return 0;
}

void initCats()
{
	cats[0].name = "나비";
	cats[0].age = 3;
	cats[0].character = "애교 많음";
	cats[0].level = 3;

	cats[1].name = "까미";
	cats[1].age = 3;
	cats[1].character = "무뚝뚝";
	cats[1].level = 0;

	cats[2].name = "사랑";
	cats[2].age = 1;
	cats[2].character = "사나움";
	cats[2].level = 5;

	cats[3].name = "보미";
	cats[3].age = 5;
	cats[3].character = "온순함";
	cats[3].level = 9;

	cats[4].name = "호두";
	cats[4].age = 9;
	cats[4].character = "활발함";
	cats[4].level = 4;
}

void printCat(int selected)
{
	printf("\n\n==== 당신은 이 고양이의 집사가 되었어요! ====\n\n");
	printf("  이름   : %s\n", cats[selected].name);
	printf("  나이   : %d\n", cats[selected].age);
	printf("  성격   : %s\n", cats[selected].character);
	printf("  레벨   : ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "☆");
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. 현재 보유한 고양이 목록 출력
	// 2. 다 모았는지 반환
	int collectAll = 1;

	printf("\n\n ==== 보유한 고양이 목록입니다. ==== \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) //고양이 수집 x
		{
			printf("%10s", "(빈박스)");
			collectAll = 0;
		}
		else
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n==================================\n\n");

	if (collectAll)
	{
		printf("\n\n 축하합니다! 모든 고양이를 다 모았습니다!\n");
	}

	return collectAll;
}