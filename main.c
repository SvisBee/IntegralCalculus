#include <locale.h>
#include <stdio.h>
#include <math.h>

#define n 1000

double Left_Rect(double a, double b)
{
  double h = (b - a) / n;
  double Slr = 0;

  for (int i = 0; i <= n - 1; i++)
  {
    Slr += h * sin(a + i * h);
  }

  return Slr;
}

double Middle_Rect(double a, double b)
{
  double h = (b - a) / n;
  double Smr = h * sin(0) / 2 + h * sin(n) / 2;

  for (int i = 1; i <= n - 1; i++)
  {
    Smr += h * sin(a + i * h);
  }

  return Smr;
}

double Right_Rect(double a, double b)
{
  double h = (b - a) / n;
  double Srr = 0;

  for (int i = 1; i <= n; i++)
  {
    Srr += h * sin(a + i * h);
  }

  return Srr;
}

double Trapeze(double a, double b)
{
  double h = (b - a) / n;
  double Slr = h * (sin(a) + sin(b)) / 2;

  for (int i = 1; i <= n - 1; i++)
  {
    Slr += h * sin(a + i * h);
  }

  return Slr;
}

double Sympsone(double a, double b)
{
  int k, N = 2 * n;

  double h = (b - a) / N;
  double Ss = h/3 * (sin(a) + sin(b));

  for (int i = 1; i <= N - 1; i++)
  {
    k = 2 + 2 * (i % 2);
    Ss += h/3 * k * sin(a + i * h);
  }

  return Ss;
}

int main()
{
    setlocale(LC_ALL, "Rus");

  double a, b;

  printf("Enter the left border of integration a = ");
  scanf("%lf", &a);
  printf("\nEnter the right border of integration b = ");
  scanf("%lf", &b);

  printf("\nThe method of left rectangles: %lf", Left_Rect(a, b));
  printf("\nThe method of medium rectangles: %lf", Middle_Rect(a, b));
  printf("\nThe right rectangle method: %lf", Right_Rect(a, b));
  printf("\nTrapezoid Method: %lf", Trapeze(a, b));
  printf("\nSimpson 's method: %lf", Sympsone(a, b));

  return(0);
}