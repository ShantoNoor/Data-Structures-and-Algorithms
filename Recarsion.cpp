#include <iostream>

using namespace std;

// Head recurtion
void fun(int n)
{
	if(n > 0)
	{
		fun(n-1);
		cout << n << " ";
	}
}

// Tail recurtion
void tfun(int n)
{
	if(n > 0)
	{
		cout << n << " ";
		tfun(n-1);
	}
}

// staric Tail recurtion
int stfun(int n)
{
	static int x = 0;
	if(n > 0)
	{
		x++;
		cout << n << " " << x << " " << endl;
		return stfun(n-1)+x;
	}
}


// global Tail recurtion
int gx = 0;
int gtfun(int n)
{
	if(n > 0)
	{
		gx++;
		cout << n << " " << gx << " " << endl;
		return gtfun(n-1)+gx;
	}
}

// Tree recurtion
void treefun(int n)
{
	if(n > 0)
	{
		treefun(n-1);
		cout << n << " ";
		treefun(n-1);
	}
}

void funB(int n);
void funA(int n)
{
	if(n>0)
	{
		printf("%d ",n);
		funB(n-1);
	}
}
void funB(int n)
{
	if(n>1)
	{
		printf("%d ",n);
		funA(n/2);
	}
}

int nfun(int n)
{
	if(n>100)
		return n-10;
	return nfun(nfun(n+11));
}

int sum(int n)
{
	if(n==0)
		return 0;
	return n+sum(n-1);
}

int pow(int n, int m)
{
	if(m == 1)
		return n;
	return n*pow(n, m-1);
}

int power1(int m,int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return power1(m*m,n/2);
	return m * power1(m*m,(n-1)/2);
}

int fact(int n)
{
	if(n == 0)
		return 1;
	return n*fact(n-1);
}

double exp(int x, int n)
{
	if(n == 0)
		return 1;
	double s = 0;
	s += pow(x, n);
	s /= fact(n);
	return s+exp(x, n-1);
}


double expp(int x, int n)
{
	if(n == 0) return 1;
	static int p = 1, d = 1;
	double r = expp(x, n-1);
	p *= x;
	d *= n;
	return r+((double)p/d);
}

double exx(int x, int n)
{
	static double res = 1;
	if(n == 0) return res;
	res = 1 + (double)x*res/n;
	return exx(x, n-1);
}

int fib(int n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	return fib(n-1)+fib(n-2);
}

int NCR(int n, int r)
{
	if(n == r || r == 1) return 1;
	return NCR(n-1, r) + NCR(n-1, r-1);
}

double exppp(double x, double n)
{
	static double i = 1;
	if(n == 0)
		return 1.0;
	double r = (double)x/i;
	i++;
	return 1+r*exppp(x, n-1);
}

int main()
{
	cout << exppp(1, 4) << endl;
	cout << expp(1, 4) << endl;
	cout << exp(1, 4) << endl;
	cout << exx(1, 4) << endl;
	

	return 0;
}