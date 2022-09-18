#include <stdio.h>
#include <time.h>

// 물고기가 6마리가 있다.
// 사막 한 가운데 어항에 살고 있다.
// 물이 아주 빨리 증발한다.
// 물이 다 증발하기 전에 어항에 물을 줘야한다.
// 물고기는 시간이 지날 수록 점점 커진다.

int level;
int arrayFish[6];
int* cursor;
int pt = 0;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
void pointFish();

int main_pointer_project(void)
{
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (최근 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지
	initData();

	cursor = arrayFish; // cursor = cursor[0]

	startTime = clock(); // 현재시간을 1/1000초(millisecond) 단위로 반환
	printf("  ======= 물고기 물주기 게임 =======\n");
	printf("  level : %d\n", level);
	while (1)
	{

		printfFishes();
		printf("  몇 번 어항에 물을 주시겠나요? ");
		scanf_s("%d", &num);

		// 어항의 물 감소 (증발)
		decreaseWater(totalElapsedTime);

		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("\n  입력값이 잘못되었습니다.\n");
			continue;
		}

		// 물은 줌
		// 1. 어항의 물이 0이면 물을 주지 않음
		if (cursor[num - 1] <= 0)
		{
			printf("\n  %d 번 물고기는 이미 죽었습니다.\n", num);
		}
		// 2. 어항의 물이 0이 아닌 경우 물을 줌 (단, 100을 넘지 않는 경우만)
		else if (cursor[num - 1] < 100)
		{
			// 물을 준다
			printf("\n  %d 번 어항에 물을 줍니다.\n", num);
			cursor[num - 1] += 1;
		}

		// 구분선
		printf("\n  --------------------------------\n");

		// 레벨업을 할 건지 확인 (레벨업은 10초마다 한 번)
		if (totalElapsedTime / 10 > level - 1)
		{
			while (totalElapsedTime / 10 > level - 1)
			{
				level++;
				printf("  ******    레벨업!!  %d -> %d    ******\n\n", level - 1, level);
				if (level == 5)
				{
					break;
				}
			}

			// 최종 레벨 : 5
			if (level >= 5)
			{
				printf("  level : %d\n", level);
				totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 초단위로 변환
				printf("\n  총 경과 시간 : %ld 초", totalElapsedTime);
				prevElapsedTime = totalElapsedTime - prevElapsedTime;
				printf("\n  최근 경과 시간 : %ld 초\n", prevElapsedTime);
				printfFishes();
				pointFish(); // 살아있는 물고기 어항의 물 총합
				printf("  **** 맛있는 고기를 얻었습니다~~ ****\n");
				printf("  ****      score :    %3d       ****\n", level * pt + (level * (totalElapsedTime - prevElapsedTime)));
				exit(0);
			}
		}

		// 레벨
		printf("  level : %d\n", level);

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 초단위로 변환
		printf("\n  총 경과 시간 : %ld 초", totalElapsedTime);

		// 직전에 물을 주고 난 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("\n  최근 경과 시간 : %ld 초\n", prevElapsedTime);

		
		
		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("\n  모든 물고기가 죽었습니다..\n");
			printfFishes();
			pointFish(); // 살아있는 물고기 어항의 물
			printf("  ****      score :    %3d       ****\n", level * pt + (level * (totalElapsedTime - prevElapsedTime)));
			exit();
		}
		else
		{
			printf("\n  살아있는 물고기가 있습니다!!\n");
		}
		prevElapsedTime = totalElapsedTime;

	}
	
	return 0;
}

void initData()
{
	level = 1; // 게임 레벨 (1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물 높이 (0 ~ 100)
	}
}

void printfFishes()
{
	printf("\n%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (((float)elapsedTime + level) * 50); // 50은 난이도 조절용
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1; // 참
		}
		return 0;
	}
}

void pointFish()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			pt += arrayFish[i];
		}
	}
}
