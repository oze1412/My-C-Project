#include <stdio.h>
#include <time.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아 같은 동물을 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 종료시 실패 횟수 고지

int animalArray[4][5]; // 카드 지도 (20장)
int checkAnimal[4][5];
char* strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
void printAnimals();
void printQuestion();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
int foundAllAnimals();


int main_m_array_project(void)
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; // 실패 횟수

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		printAnimals();
		printQuestion();
		printf("\n뒤집을 카드 2개를 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
		{
			printf("\n\n 중복된 카드입니다. \n\n");
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어 확인
		// (x, y)로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// 같은 동물인 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&&(animalArray[firstSelect_x][firstSelect_y]
				== animalArray[secondSelect_x][secondSelect_y]))
		{
			printf("\n\n 빙고! %s 발견 \n\n", strAnimal[animalArray[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		//중복 카드인 경우
		else if (checkAnimal[firstSelect_x][firstSelect_y] == 1
			|| checkAnimal[secondSelect_x][secondSelect_y] == 1)
		{
			printf("\n 이미 선택된 카드가 있습니다. \n\n");

			failCount++;
		}
		// 다른 동물인 경우
		else
		{
			printf("\n 땡!! 틀렸습니다! \n");
			printf("%d : %s\n", select1, strAnimal[animalArray[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[animalArray[secondSelect_x][secondSelect_y]]);
			
			failCount++;
		}

		if (foundAllAnimals() == 1)
		{
			printf("\n 축하합니다! 모든 동물을 다 찾았습니다! \n");
			printf("\n 지금까지 총 %d 번 실수하였습니다.\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			animalArray[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "펭귄";
	strAnimal[1] = "고양이";
	strAnimal[2] = "강아지";
	strAnimal[3] = "원숭이";
	strAnimal[4] = "하마";
	strAnimal[5] = "악어";
	strAnimal[6] = "돼지";
	strAnimal[7] = "코끼리";
	strAnimal[8] = "기린";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
	// □□□□□
	// □□□□□
	// □□□□□
	// □□□□□

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			animalArray[x][y] = i;
		}
	}
}

// 빈 좌표 찾기
int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20; // 0~19 사이 숫자 반환
		// 19 -> (3, 4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (animalArray[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5; 
	// y를 5로 나눈 나머지 값
}

void printAnimals()
{
	printf("\n=============================================\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[animalArray[i][j]]);
		}
		printf("\n");
	}

}

void printQuestion()
{
	printf("\n\n(문제)\n\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[animalArray[i][j]]);
			}
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}