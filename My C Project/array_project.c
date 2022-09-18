#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_array_project(void)
{
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 === \n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; // 발모제 선택 (0~3)

	int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
	int prevCntShowBottle = 0; // 앞 게임에 보여준 병 갯수

	// 3번의 기회
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0, 0, 0, 0 };
		do
		{
			cntShowBottle = rand() % 2 + 2; // 보여줄 병 갯수 (2~3)
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;
	
		int isIncluded = 0; // 보여줄 병 가운데 발모제가 포함 되었는지
		printf(" > %d 번째 시도 : ", i);

	// 보여줄 병 종류 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			// 선택되지 않은 병이면 선택 처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// 선택된 병이면 다시 선택
			else
			{
				j--;
			}
		}
		
		//사용자에게 문제 표시
		for(int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d 번 ", k + 1);
			}
		}
		printf(" 물약을 머리에 바릅니다.\n\n");

		if (isIncluded == 1)
		{
			printf(" >> 성공!! \n");
		}
		else
		{
			printf(" >> 실패!! \n");
		}

		printf("\n... 계속 하려면 아무키나 누르세요 ...\n");
		getchar();
	}

	printf("\n\n발모제는 몇 번일까요?");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다! \n");
	}
	else
	{
		printf("\n >> 땡! 틀렸습니다! 정답은 %d 입니다.\n", treatment + 1);
	}


	return 0;

}