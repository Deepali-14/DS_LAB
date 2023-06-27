#include<stdio.h>
#include<math.h>
void arith(float *,float *,float *,float *,float *,float *,float *,float *);
void main()
{
	float a,b;
	float sum=0,sub=0,mul=0,div=0,mod=0,p=0;
	printf("\n Enter values of a and b : ");
	scanf("%f %f",&a,&b);
	arith(&a,&b,&sum,&sub,&mul,&div,&mod,&p);
	printf("\n Addition of %0.2f and %0.2f : %0.2f",a,b,sum);
	printf("\n Subtraction of %0.2f from %0.2f : %0.2f",b,a,sub);
	printf("\n Multiplication of %0.2f and %0.2f : %0.2f",a,b,mul);
	printf("\n Division of %0.2f by %0.2f : %0.2f",a,b,div);
	printf("\n Modulus of %0.2f and %0.2f : %0.2f",a,b,mod);
	printf("\n %0.2f raised to power %0.2f : %0.2f",b,a,p);
}
void arith(float * c,float * d,float * e,float * f,float * g,float * h,float * i,float * j)
{
	*e=(*c)+(*d);
	*f=(*c)-(*d);
	*g=(*c)*(*d);
	*h=(*c)/(*d);
	*i=(int)(*c)%(int)(*d);
	*j=pow((*c),(*d));
}
