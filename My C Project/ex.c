#include <stdio.h>
void swap_addr(int* a, int* b);

int main(void)
{

	int a = 10;
	int b = 20;
	printf("a�� �ּ� : %d\n", &a);
	printf("b�� �ּ� : %d\n", &b);

	printf("(�ּҰ� ����) Swap �Լ� �� => a : %d, b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("(�ּҰ� ����) Swap �Լ� �� => a : %d, b : %d\n", a, b);

	return 0;
}

void swap_addr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(�ּҰ� ����) Swap �Լ� �� => a : %d, b : %d\n", *a, *b);
	printf("(Swap �Լ� ��) a�� �ּ� : %d\n", a);
	printf("(Swap �Լ� ��) b�� �ּ� : %d\n", b);
}