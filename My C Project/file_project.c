#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��й�ȣ �Է�
// �´� ��� �޸��� ��� �� �߰� �Է�
// Ʋ���� ���

#define MAX 10000

int main(void)
{
	// fgets, fputs Ȱ��
	char line[MAX]; // ���Ͽ��� �ҷ��� ���� ����
	char contents[MAX]; // �ϱ��忡 �Է��� ����
	char password[20]; // ��й�ȣ �Է�
	char c; // ��й�ȣ �Է� �� Ű�� Ȯ�ο� (����ŷ)
	
	printf("'��� �޸���'\n");
	printf("��й�ȣ�� �Է��ϼ��� : \n");

	// getchar() : ���ͷ� ���� ����
	// getch() : Ű �Է� �� ���� ����

	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13) // enter -> ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}
		else // ��й�ȣ �Է� ��
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// ��й�ȣ : zz123123
	printf("\n\n ==== ��й�ȣ Ȯ�� �� ... ==== \n\n");
	if (strcmp(password, "zz123123") == 0)
	// ��й�ȣ ��ġ, strcmp(a, b) : ���ڿ� �� -> 0 : ��ġ
	{
		printf(" ==== ��й�ȣ Ȯ�� �Ϸ� ==== \n\n");
		char* fileName = "c:\\file_project.txt";
		FILE* file = fopen(fileName, "a+b"); 
		// ������ ������ ����, ������ append (�ڿ� ���� �߰�)
		if (file == NULL)
		{
			printf("���� ���� ����\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);

		}

		printf("\n\n ������ ��� �ۼ��ϼ���! �����Ͻ÷��� EXIT�� �Է��ϼ���!\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); // �ٹٲ��� ������ ������ ���� (�� ���徿)
			getchar(); // Enter �Է�(\n)�� Flush ó��

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("��� �޸��� �Է��� �����մϴ�\n\n");
				break;
			}
			else if (strcmp(contents, "RESET") == 0)
			{
				file = fopen(fileName, "wb");
				fputs("\0", file);
				printf("\n�޸����� �ʱ�ȭ�մϴ�. \n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);
		}
		fclose(file);
	}
	else
	{
		printf(" ==== ��й�ȣ�� Ʋ�Ƚ��ϴ�. ====\n\n");
	}

	return 0;
}