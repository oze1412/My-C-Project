#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void) {

	//int num = rand() % � ��; (0���� � �� ����)

	printf("���� �ʱ�ȭ ����.. \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10 + 1);
	}

	printf("\n");

	srand(time(NULL)); // ���� �ʱ�ȭ
	printf("���� �ʱ�ȭ ����.. \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10 + 1);
	}

	return 0;
}
