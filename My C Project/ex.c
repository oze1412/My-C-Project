#include <stdio.h>
void swap_addr(int* a, int* b);

int main(void)
{

	int a = 10;
	int b = 20;
	printf("a의 주소 : %d\n", &a);
	printf("b의 주소 : %d\n", &b);

	printf("(주소값 전달) Swap 함수 전 => a : %d, b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("(주소값 전달) Swap 함수 후 => a : %d, b : %d\n", a, b);

	return 0;
}

void swap_addr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달) Swap 함수 내 => a : %d, b : %d\n", *a, *b);
	printf("(Swap 함수 내) a의 주소 : %d\n", a);
	printf("(Swap 함수 내) b의 주소 : %d\n", b);
}