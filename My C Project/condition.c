#include <stdio.h>
#include <time.h>


int main_condition(void)
{
	// 버스를 탄다고 가정.
	// 학생 / 일반인으로 구분 (일반인 : 20세 이상)
	// if (조건) {  } else {  }
	/*int age = 30;
	if (age >= 20)
	{
		printf("일반인입니다.\n");
	}
	else
	{
		printf("학생입니다.\n");
	}*/

	// 초(8-13) / 중(14-16) / 고(17-19)로 나뉠 경우
	// if; if else; else;
	/*int age = 18;
	if (age >= 8 && age <= 13)
	{
		printf("초등학생입니다.\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("중학생입니다.\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("고등학생입니다.\n");
	}
	else
	{
		printf("학생이 아닙니다.\n");
	}*/

	// break(반복문 탈출); continue(다음 순서로 번지);
	// 1번 ~ 30번 중 1번 ~ 5번까지 조별 발표
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6) {
			printf("나머지 학생은 집에 가세요.\n");
			break;
		}
		printf("%d번 학생은 조별 발표를 준비하세요.\n", i);
	}*/

	// 1번 ~ 30번 중 7번 학생 결석
	// 7번을 제외한 6 ~ 10번 조별 발표
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d번 학생은 결석입니다.\n", i);
				continue;
			}
			printf("%d번 학생은 조별 발표를 준비하세요.\n", i);
		}
	}*/

	// &&(and), ||(or)
	/*int a = 10;
	int b = 11;
	int c = 13;
	int d = 13;
	if (a == b || c == d)
	{
		printf("a 와 b, 혹은 c 와 d 의 값이 같습니다.\n");
	}
	else
	{
		printf("값이 서로 다릅니다.\n");
	}*/

	// 가위 0 바위 1 보 2
	/*srand(time(NULL));
	int i = rand() % 3;
	if (i == 0) {
		printf("가위\n");
	}
	else if (i == 1) {
		printf("바위\n");
	}
	else if (i == 2) {
		printf("보\n");
	}
	else {
		printf("몰라요\n");
	}*/


	// switch ( ) { case i : --; case j : --; default : --; }
	/*int i = 1;
	switch (i) {
	case 0: printf("가위\n");
	case 1: printf("바위\n");
	case 2: printf("보\n");
	default:printf("몰라요\n");
	}*/

	/*srand(time(NULL));
	int i = rand() % 3;
	switch (i) {
	case 0: printf("가위\n"); break;
	case 1: printf("바위\n"); break;
	case 2: printf("보\n"); break;
	default:printf("몰라요\n"); break;
	}*/

	/*int age = 8;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("초등학생입니다.\n"); break;
	case 14:
	case 15:
	case 16:printf("중학생입니다.\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생입니다.\n"); break;
	default:printf("학생이 아닙니다.\n"); break;
	}*/

	// Up and Down - 프로젝트
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1~100 사이의 숫자
	printf("숫자 : %d\n", num);
	int answer = 0; // 정답
	int chance = 5; // 기회
	while (1) { // 1 : 참, 0 : 거짓
		printf("남은 기회 : %d번\n", chance--);
		printf("숫자를 맞춰보세요.(1~100) : ");
		scanf_s("%d", &answer);
		if (answer > 0 && answer < 101) {
			if (answer < num) {
				printf("Up\n\n");
			}
			else if (answer > num) {
				printf("Down\n\n");
			}
			else if (answer = num) {
				printf("정답입니다.\n\n");
				break;
			}
			else {
				printf("오류발생\n\n");
			}
		}
		else {
			printf("1~100사이를 입력해주세요.\n\n");
		}

		if (chance == 0) {
			printf("GameOver\n\n");
			break;
		}
	}
	
	return 0;

}