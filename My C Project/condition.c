#include <stdio.h>
#include <time.h>


int main_condition(void)
{
	// ������ ź�ٰ� ����.
	// �л� / �Ϲ������� ���� (�Ϲ��� : 20�� �̻�)
	// if (����) {  } else {  }
	/*int age = 30;
	if (age >= 20)
	{
		printf("�Ϲ����Դϴ�.\n");
	}
	else
	{
		printf("�л��Դϴ�.\n");
	}*/

	// ��(8-13) / ��(14-16) / ��(17-19)�� ���� ���
	// if; if else; else;
	/*int age = 18;
	if (age >= 8 && age <= 13)
	{
		printf("�ʵ��л��Դϴ�.\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("���л��Դϴ�.\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("����л��Դϴ�.\n");
	}
	else
	{
		printf("�л��� �ƴմϴ�.\n");
	}*/

	// break(�ݺ��� Ż��); continue(���� ������ ����);
	// 1�� ~ 30�� �� 1�� ~ 5������ ���� ��ǥ
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6) {
			printf("������ �л��� ���� ������.\n");
			break;
		}
		printf("%d�� �л��� ���� ��ǥ�� �غ��ϼ���.\n", i);
	}*/

	// 1�� ~ 30�� �� 7�� �л� �Ἦ
	// 7���� ������ 6 ~ 10�� ���� ��ǥ
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
				continue;
			}
			printf("%d�� �л��� ���� ��ǥ�� �غ��ϼ���.\n", i);
		}
	}*/

	// &&(and), ||(or)
	/*int a = 10;
	int b = 11;
	int c = 13;
	int d = 13;
	if (a == b || c == d)
	{
		printf("a �� b, Ȥ�� c �� d �� ���� �����ϴ�.\n");
	}
	else
	{
		printf("���� ���� �ٸ��ϴ�.\n");
	}*/

	// ���� 0 ���� 1 �� 2
	/*srand(time(NULL));
	int i = rand() % 3;
	if (i == 0) {
		printf("����\n");
	}
	else if (i == 1) {
		printf("����\n");
	}
	else if (i == 2) {
		printf("��\n");
	}
	else {
		printf("�����\n");
	}*/


	// switch ( ) { case i : --; case j : --; default : --; }
	/*int i = 1;
	switch (i) {
	case 0: printf("����\n");
	case 1: printf("����\n");
	case 2: printf("��\n");
	default:printf("�����\n");
	}*/

	/*srand(time(NULL));
	int i = rand() % 3;
	switch (i) {
	case 0: printf("����\n"); break;
	case 1: printf("����\n"); break;
	case 2: printf("��\n"); break;
	default:printf("�����\n"); break;
	}*/

	/*int age = 8;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("�ʵ��л��Դϴ�.\n"); break;
	case 14:
	case 15:
	case 16:printf("���л��Դϴ�.\n"); break;
	case 17:
	case 18:
	case 19:printf("����л��Դϴ�.\n"); break;
	default:printf("�л��� �ƴմϴ�.\n"); break;
	}*/

	// Up and Down - ������Ʈ
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1~100 ������ ����
	printf("���� : %d\n", num);
	int answer = 0; // ����
	int chance = 5; // ��ȸ
	while (1) { // 1 : ��, 0 : ����
		printf("���� ��ȸ : %d��\n", chance--);
		printf("���ڸ� ���纸����.(1~100) : ");
		scanf_s("%d", &answer);
		if (answer > 0 && answer < 101) {
			if (answer < num) {
				printf("Up\n\n");
			}
			else if (answer > num) {
				printf("Down\n\n");
			}
			else if (answer = num) {
				printf("�����Դϴ�.\n\n");
				break;
			}
			else {
				printf("�����߻�\n\n");
			}
		}
		else {
			printf("1~100���̸� �Է����ּ���.\n\n");
		}

		if (chance == 0) {
			printf("GameOver\n\n");
			break;
		}
	}
	
	return 0;

}