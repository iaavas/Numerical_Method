#include <stdio.h>
#define N 4

float fxn(float x)
{
	return 2 * x;
}

void main()
{

	float x[N], y[N], b, a, h, s;

	printf("Enter upper and lower limit: ");
	scanf("%f%f", &b, &a);

	h = (b - a) / N;

	s = fxn(a) + fxn(b);

	for (float i = a + h; i < b; i = i + h)
	{
		s += 2 * fxn(i);
	}
	s = s * h / 2;

	printf("%f", s);
}