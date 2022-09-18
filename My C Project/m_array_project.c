#include <stdio.h>
#include <time.h>

// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾� ���� ������ ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// ����� ���� Ƚ�� ����

int animalArray[4][5]; // ī�� ���� (20��)
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

	int failCount = 0; // ���� Ƚ��

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		printAnimals();
		printQuestion();
		printf("\n������ ī�� 2���� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
		{
			printf("\n\n �ߺ��� ī���Դϴ�. \n\n");
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������ Ȯ��
		// (x, y)�� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// ���� ������ ���
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&&(animalArray[firstSelect_x][firstSelect_y]
				== animalArray[secondSelect_x][secondSelect_y]))
		{
			printf("\n\n ����! %s �߰� \n\n", strAnimal[animalArray[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		//�ߺ� ī���� ���
		else if (checkAnimal[firstSelect_x][firstSelect_y] == 1
			|| checkAnimal[secondSelect_x][secondSelect_y] == 1)
		{
			printf("\n �̹� ���õ� ī�尡 �ֽ��ϴ�. \n\n");

			failCount++;
		}
		// �ٸ� ������ ���
		else
		{
			printf("\n ��!! Ʋ�Ƚ��ϴ�! \n");
			printf("%d : %s\n", select1, strAnimal[animalArray[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[animalArray[secondSelect_x][secondSelect_y]]);
			
			failCount++;
		}

		if (foundAllAnimals() == 1)
		{
			printf("\n �����մϴ�! ��� ������ �� ã�ҽ��ϴ�! \n");
			printf("\n ���ݱ��� �� %d �� �Ǽ��Ͽ����ϴ�.\n", failCount);
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
	strAnimal[0] = "���";
	strAnimal[1] = "�����";
	strAnimal[2] = "������";
	strAnimal[3] = "������";
	strAnimal[4] = "�ϸ�";
	strAnimal[5] = "�Ǿ�";
	strAnimal[6] = "����";
	strAnimal[7] = "�ڳ���";
	strAnimal[8] = "�⸰";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal()
{
	// ������
	// ������
	// ������
	// ������

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

// �� ��ǥ ã��
int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20; // 0~19 ���� ���� ��ȯ
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
	// y�� 5�� ���� ������ ��
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
	printf("\n\n(����)\n\n");
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