#include <stdio.h>
#include <time.h>

// ����Ⱑ 6������ �ִ�.
// �縷 �� ��� ���׿� ��� �ִ�.
// ���� ���� ���� �����Ѵ�.
// ���� �� �����ϱ� ���� ���׿� ���� ����Ѵ�.
// ������ �ð��� ���� ���� ���� Ŀ����.

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
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð� (�ֱ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �� ������
	initData();

	cursor = arrayFish; // cursor = cursor[0]

	startTime = clock(); // ����ð��� 1/1000��(millisecond) ������ ��ȯ
	printf("  ======= ����� ���ֱ� ���� =======\n");
	printf("  level : %d\n", level);
	while (1)
	{

		printfFishes();
		printf("  �� �� ���׿� ���� �ֽðڳ���? ");
		scanf_s("%d", &num);

		// ������ �� ���� (����)
		decreaseWater(totalElapsedTime);

		// �Է°� üũ
		if (num < 1 || num > 6)
		{
			printf("\n  �Է°��� �߸��Ǿ����ϴ�.\n");
			continue;
		}

		// ���� ��
		// 1. ������ ���� 0�̸� ���� ���� ����
		if (cursor[num - 1] <= 0)
		{
			printf("\n  %d �� ������ �̹� �׾����ϴ�.\n", num);
		}
		// 2. ������ ���� 0�� �ƴ� ��� ���� �� (��, 100�� ���� �ʴ� ��츸)
		else if (cursor[num - 1] < 100)
		{
			// ���� �ش�
			printf("\n  %d �� ���׿� ���� �ݴϴ�.\n", num);
			cursor[num - 1] += 1;
		}

		// ���м�
		printf("\n  --------------------------------\n");

		// �������� �� ���� Ȯ�� (�������� 10�ʸ��� �� ��)
		if (totalElapsedTime / 10 > level - 1)
		{
			while (totalElapsedTime / 10 > level - 1)
			{
				level++;
				printf("  ******    ������!!  %d -> %d    ******\n\n", level - 1, level);
				if (level == 5)
				{
					break;
				}
			}

			// ���� ���� : 5
			if (level >= 5)
			{
				printf("  level : %d\n", level);
				totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // �ʴ����� ��ȯ
				printf("\n  �� ��� �ð� : %ld ��", totalElapsedTime);
				prevElapsedTime = totalElapsedTime - prevElapsedTime;
				printf("\n  �ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);
				printfFishes();
				pointFish(); // ����ִ� ����� ������ �� ����
				printf("  **** ���ִ� ��⸦ ������ϴ�~~ ****\n");
				printf("  ****      score :    %3d       ****\n", level * pt + (level * (totalElapsedTime - prevElapsedTime)));
				exit(0);
			}
		}

		// ����
		printf("  level : %d\n", level);

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // �ʴ����� ��ȯ
		printf("\n  �� ��� �ð� : %ld ��", totalElapsedTime);

		// ������ ���� �ְ� �� �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("\n  �ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

		
		
		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			printf("\n  ��� ����Ⱑ �׾����ϴ�..\n");
			printfFishes();
			pointFish(); // ����ִ� ����� ������ ��
			printf("  ****      score :    %3d       ****\n", level * pt + (level * (totalElapsedTime - prevElapsedTime)));
			exit();
		}
		else
		{
			printf("\n  ����ִ� ����Ⱑ �ֽ��ϴ�!!\n");
		}
		prevElapsedTime = totalElapsedTime;

	}
	
	return 0;
}

void initData()
{
	level = 1; // ���� ���� (1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // ������ �� ���� (0 ~ 100)
	}
}

void printfFishes()
{
	printf("\n%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
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
		arrayFish[i] -= (((float)elapsedTime + level) * 50); // 50�� ���̵� ������
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
			return 1; // ��
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
