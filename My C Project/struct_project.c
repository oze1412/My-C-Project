#include <stdio.h>
#include <time.h>

// 5������ ����̰� �ִ�
// �ƹ� Ű�� ������ �������� ����̸� �̵�
// 5���� ��� �����ؾ� ������ ����!
// �ߺ� �߻� ����

// �����
// �̸�, ����, ����, Ű��� ���̵�(����)

typedef struct
{
	char* name;
	int age;
	char* character;
	int level;
} Cat;

void initCats(); // ����� ���� �ʱ�ȭ
void printCat(int selected);

// ������� ������ �����
int collection[5] = { 0,0,0,0,0 };

// ��ä ����� ����Ʈ
Cat cats[5];

int main_struct_project(void)
{
	srand(time(NULL));

	initCats();

	while (1)
	{
		printf("��� ������� ���簡 �ɱ��? \n�ƹ� Ű�� ������ Ȯ���ϼ���!");
		getchar();

		int selected = rand() % 5;
		printCat(selected); // ����� ���� ���
		collection[selected] = 1; // ����� �̱� ó��

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
	cats[0].name = "����";
	cats[0].age = 3;
	cats[0].character = "�ֱ� ����";
	cats[0].level = 3;

	cats[1].name = "���";
	cats[1].age = 3;
	cats[1].character = "���Ҷ�";
	cats[1].level = 0;

	cats[2].name = "���";
	cats[2].age = 1;
	cats[2].character = "�糪��";
	cats[2].level = 5;

	cats[3].name = "����";
	cats[3].age = 5;
	cats[3].character = "�¼���";
	cats[3].level = 9;

	cats[4].name = "ȣ��";
	cats[4].age = 9;
	cats[4].character = "Ȱ����";
	cats[4].level = 4;
}

void printCat(int selected)
{
	printf("\n\n==== ����� �� ������� ���簡 �Ǿ����! ====\n\n");
	printf("  �̸�   : %s\n", cats[selected].name);
	printf("  ����   : %d\n", cats[selected].age);
	printf("  ����   : %s\n", cats[selected].character);
	printf("  ����   : ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "��");
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. ���� ������ ����� ��� ���
	// 2. �� ��Ҵ��� ��ȯ
	int collectAll = 1;

	printf("\n\n ==== ������ ����� ����Դϴ�. ==== \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) //����� ���� x
		{
			printf("%10s", "(��ڽ�)");
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
		printf("\n\n �����մϴ�! ��� ����̸� �� ��ҽ��ϴ�!\n");
	}

	return collectAll;
}