#include <stdio.h>
#include <math.h>


int signum_d_y(double d_y) {        //check the sigh of complex part of number
	if (d_y < 0)
		return -1;
	else
		return 1;
}
typedef struct complex
{
	double x;
	double y;
} Complex;

Complex add(Complex a, Complex b)
{
	Complex sample;
	sample.x = a.x + b.x;
	sample.y = a.y + b.y;
	return sample;
}

Complex sub(Complex a, Complex b)
{
	Complex sample;
	sample.x = a.x - b.x;
	sample.y = a.y - b.y;
	return sample;
}

Complex mul(Complex a, Complex b)
{
	Complex sample;
	sample.x = a.x * b.x - a.y * b.y;
	sample.y = a.x * b.y + a.y * b.x;
	return sample;
}

Complex divs(Complex a, Complex b)
{
	Complex sample;
	sample.x = (a.x * b.x + a.y * b.y) / (pow(b.x, 2) + pow(b.y, 2));
	sample.y = (b.x * a.y - b.y * a.x) / (pow(b.x, 2) + pow(b.y, 2));
	return sample;
}
Complex num(Complex a, double n)
{
	Complex sample;
	sample.x = a.x * n;
	sample.y = a.y * n;
	return sample;
}

Complex sqrtc(Complex a)
{
	Complex sample;
	sample.x = sqrt((sqrt(a.x*a.x + a.y*a.y) + a.x) / 2);
	sample.y = sqrt((sqrt(a.x*a.x + a.y*a.y) - a.x) / 2)* signum_d_y(a.y);
	return sample;
}



int main()
{
	double a1, b1, a2, b2, a3, b3;
	scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &a2, &b2, &a3, &b3);
	Complex a, b, c, x1, x2, D;
	a.x = a1;
	a.y = b1;
	b.x = a2;
	b.y = b2;
	c.x = a3;
	c.y = b3;

	D = (sub(mul(b, b), num(mul(a, c), 4))); //count discriminant
	Complex sqroot_d;
	sqroot_d = sqrtc(D);  //count the square root of the discriminant

	x1 = divs(sub(sqroot_d, b), num(a, 2));
	x2 = divs(num(add(sqroot_d, b), -1), num(a, 2));
	
	printf("x1 = %lf + %lf *i\n", x1.x, x1.y);
	printf("x2 = %lf + %lf *i\n", x2.x, x2.y);

	return 0;
}
