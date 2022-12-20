#define MAX_SIZE 100
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int n = 5, m, k, i, j = 1, sum = 0, r1, r2, r3, r4, code, num, code2 = 0, count = 0, t1, t2;
char text;
int x[MAX_SIZE];
int z[MAX_SIZE]; // 초월증가수열
int B[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE];
int u[MAX_SIZE][MAX_SIZE]; // u1 : u[1][n], u2 : u[2][n]
int H[MAX_SIZE][MAX_SIZE];
int c[MAX_SIZE];
int M[MAX_SIZE][MAX_SIZE];
int SUM[MAX_SIZE];
int y[MAX_SIZE];

int exchange(char x)
{
	if (x == 'a')
		return 1;
	else if (x == 'b')
		return 10;
	else if (x == 'c')
		return 11;
	else if (x == 'd')
		return 100;
	else if (x == 'e')
		return 101;
	else if (x == 'f')
		return 110;
	else if (x == 'g')
		return 111;
	else if (x == 'h')
		return 1000;
	else if (x == 'i')
		return 1001;
	else if (x == 'j')
		return 1010;
	else if (x == 'k')
		return 1011;
	else if (x == 'l')
		return 1100;
	else if (x == 'm')
		return 1101;
	else if (x == 'n')
		return 1110;
	else if (x == 'o')
		return 1111;
	else if (x == 'p')
		return 10000;
	else if (x == 'q')
		return 10001;
	else if (x == 'r')
		return 10010;
	else if (x == 's')
		return 10011;
	else if (x == 't')
		return 10100;
	else if (x == 'u')
		return 10101;
	else if (x == 'v')
		return 10110;
	else if (x == 'w')
		return 10111;
	else if (x == 'x')
		return 11000;
	else if (x == 'y')
		return 11001;
	else if (x == 'z')
		return 11010;
	else if (x == ' ')
		return 11011;
	else if (x == '!')
		return 11100;
	else if (x == '?')
		return 11101;
	else
		return -1;
}

int rechange(int x)
{
	if (x == 1)
		return 'a';
	else if (x == 10)
		return 'b';
	else if (x == 11)
		return 'c';
	else if (x == 100)
		return 'd';
	else if (x == 101)
		return 'e';
	else if (x == 110)
		return 'f';
	else if (x == 111)
		return 'g';
	else if (x == 1000)
		return 'h';
	else if (x == 1001)
		return 'i';
	else if (x == 1010)
		return 'j';
	else if (x == 1011)
		return 'k';
	else if (x == 1100)
		return 'l';
	else if (x == 1101)
		return 'm';
	else if (x == 1110)
		return 'n';
	else if (x == 1111)
		return 'o';
	else if (x == 10000)
		return 'p';
	else if (x == 10001)
		return 'q';
	else if (x == 10010)
		return 'r';
	else if (x == 10011)
		return 's';
	else if (x == 10100)
		return 't';
	else if (x == 10101)
		return 'u';
	else if (x == 10110)
		return 'v';
	else if (x == 10111)
		return 'w';
	else if (x == 11000)
		return 'x';
	else if (x == 11001)
		return 'y';
	else if (x == 11010)
		return 'z';
	else if (x == 10011)
		return ' ';
	else if (x == 11100)
		return '!';
	else if (x == 11101)
		return '?';
	else
		return -1;
}

void printStar()
{
	printf("*\n");
	for (int ps = 0; ps < 15; ps++)
		printf("*****");
	printf("**");
	printf("\n*\n");
}

void printLine()
{
	printf("* ");
	for (int ps = 0; ps < 15; ps++)
		printf("-----");
	printf("\n");
}

int main()
{
	srand((unsigned)time(NULL));

	for (k = 0; k < 15; k++)
		printf("*****");
	printf("**\n");
	printf("* 행렬과 초월증가수열을 이용한 공개키 암호 알고리즘 1\n");
	printf("* - 경산과학고 1학년 강민석, 김화영, 윤창호, 장민 -\n");
	for (k = 0; k < 15; k++)
		printf("*****");
	printf("**\n");

	printf("*\n");
	// 값을 입력받음
	printf("* m값을 입력해주세요 : ");
	scanf("%d", &m);

	printf("* 행렬 x의 자릿수를 입력해주세요 : ");
	scanf("%d", &num);

	printf("* 행렬 x를 입력해주세요(0이 두번 연속으로 사용되지 않도록) : ");
	do
	{
		for (k = 1; k <= num; k++)
			z[k] = 1;
		code = 1;
		z[0] = 0;
		for (k = 1; k <= num; k++)
		{
			scanf("%d", &x[k]);
			if (k > 0 && z[k] == 0 && z[k - 1] == 0)
				code = -1;
		}
		if (code == -1)
			printf("*    0이 두번 연속으로 사용되었습니다. 다시 입력해주세요. : ");
	} while (code == -1);

	printf("* 사용할 초월증가수열 z를 입력해주세요 : ");
	do
	{
		for (k = 1; k <= n; k++)
			z[k] = 0;
		code = 1;
		sum = 0;
		for (k = 1; k <= n; k++)
		{
			scanf("%d", &z[k]);
			if (sum >= z[k])
				code = -1;
			sum += z[k];
		}
		if (code == -1)
			printf("*    초월증가수열이 아닙니다. 다시 입력해주세요. : ");
	} while (code == -1);

	// 행렬 B 생성
	sum = 0;
	for (k = 1; k <= n; k++)
	{
		SUM[k] = 0;
		for (i = 1; i < num; i++)
		{
			B[i][k] = rand() % m;
			SUM[k] += B[i][k] * x[i];
		}
		for (i = 0; i <= m; i++)
		{
			B[num][k] = i;
			if ((SUM[k] + i * x[num]) % m == z[k])
				break;
		}
	}

	// 행렬 u 생성
	for (k = 1; k < num; k++)
	{
		SUM[k] = 0;
		for (i = 1; i < num; i++)
		{
			u[k][i] = rand() % m;
			SUM[k] += u[k][i];
		}
		for (i = 0; i <= m; i++)
		{
			u[k][num] = i;
			if ((SUM[k] + x[num] * u[k][num]) % m == 0)
				break;
		}
		if (k >= 2)
		{
			code = 0;
			for (i = k - 1; i >= 1; i--)
			{
				if (u[k][1] / u[i][1] == u[k][2] / u[i][2])
					code = -1;
			}
		}
		if (code == -1)
		{
			k--;
		}
	}

	printLine();
	printf("* 준비 완료\n");
	printLine();

	printf("* 행렬 B(공개) : \n");
	for (k = 1; k <= num; k++)
	{
		printf("*    ");
		for (i = 1; i < n; i++)
			printf("%2d ", B[k][i]);
		printf("\n");
	}

	for (k = 1; k <= num - 1; k++)
	{
		printf("* 행렬 u%d(공개) : (", k);
		for (i = 1; i <= num; i++)
			printf("%3d", u[k][i]);
		printf(")\n");
	}

	printLine();

	printf("* 초월증가수열 z(비공개) : ( ");
	for (k = 1; k <= n; k++)
		printf("%d ", z[k]);
	printf(")\n");

	printf("* n(비공개) = %d, m(비공개) = %d\n", n, m);
	printStar();

	printf("* 평문을 입력해주세요 : ");

	while (1)
	{
		// 평문 입력받음
		scanf("%c", &text);
		if (text == '\n')
		{
			if (code2 == -1)
				break;
			else
			{
				code2 = -1;
				continue;
			}
		}

		printLine();

		M[j][1] = exchange(text) / 10000;
		M[j][2] = (exchange(text) % 10000) / 1000;
		M[j][3] = (exchange(text) % 1000) / 100;
		M[j][4] = (exchange(text) % 100) / 10;
		M[j][5] = exchange(text) % 10;

		// 행렬 H 생성
		for (i = 1; i <= 5; i++)
		{
			for (k = 1; k <= num; k++)
			{
				t1 = rand();
				t2 = rand();
				H[k][i] = (u[1][k] * t1 + u[2][k] * t2) % m;
			}
		}

		// 암호문 c 생성
		for (k = 1; k <= num; k++)
		{
			c[k] = 0;
			for (i = 1; i <= n; i++)
			{
				c[k] = c[k] + (B[k][i] + H[k][i]) * M[j][i];
			}
			c[k] = c[k] % m;
		}

		printf("* 메시지 : %c\n", text);
		printf("* 평문 : ");
		for (k = 1; k <= 5; k++)
			printf("%d", M[j][k]);

		printf("\n* 행렬 H(비공개)\n");
		for (k = 1; k <= num; k++)
		{
			printf("*    ");
			for (i = 1; i <= n; i++)
				printf("%2d ", H[k][i]);
			printf("\n");
		}
		printf("* 비공개 : 암호문 c (");
		for (k = 1; k <= 1; k++)
			printf("% 2d", c[k]);
		printf(" )\n");

		// y값 생성
		y[j] = 0;
		for (k = 1; k <= num; k++)
			y[j] += x[k] * c[k];
		y[j] = y[j] % m;

		j++;
	}

	// 암호 해독 결과 출력

	printStar();

	printf("* 암호 해독 결과\n");
	printLine();

	for (k = 1; k < j; k++)
	{
		printf("* y(비공개) = %d\n", y[k]);
		printf("* 메시지 : %c\n", rechange(10000 * M[k][1] + 1000 * M[k][2] + 100 * M[k][3] + 10 * M[k][4] + M[k][5]));
		printLine();
	}

	for (k = n; k <= 1; k--)
	{
		if (y[j] >= M[j][k])
		{
			M[j][k] = 1;
			y[j] = y[j] - b[k];
		}
		else
			M[j][k] = 0;
	}

	printf("* 최종 메시지 : ");
	for (k = 1; k <= j - 1; k++)
	{
		printf("%c", rechange(10000 * M[k][1] + 1000 * M[k][2] + 100 * M[k][3] + 10 * M[k][4] + M[k][5]));
	}
	printf("\n");
	printStar();
	printf("* 암호 해독이 완료되었습니다. 종료하려면 아무 키나 입력해주세요. ");
	scanf("%c", &text);
}
