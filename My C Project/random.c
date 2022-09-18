#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void) {

	//int num = rand() % 어떤 수; (0부터 어떤 수 까지)

	printf("난수 초기화 이전.. \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10 + 1);
	}

	printf("\n");

	srand(time(NULL)); // 난수 초기화
	printf("난수 초기화 이후.. \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10 + 1);
	}

	return 0;
}
