#include<stdio.h>
#include<math.h>

#define f(x) x*x*x - 2*x - 5

int main()
{
    float x1, x2, m, f1, f2, fm, e;
    int step = 1;

    printf("Enter two initial guesses:\n");
    scanf("%f%f", &x1, &x2);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        return 1;
    }

    m = (x1 + x2) / 2;
    fm = f(m);

    printf("\nStep\t\tx1\t\tx2\t\tm\t\tf(m)\n");
    do
    {
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x1, x2, m, fm);

        if (f1 * fm < 0)
        {
            x2 = m;
            f2 = fm;
        }
        else
        {
            x1 = m;
            f1 = fm;
        }

        m = (x1 + x2) / 2;
        fm = f(m);

        step = step + 1;
    } while (fabs(fm) > e);

    printf("\nRoot is: %f\n", m);
    return 0;
}
