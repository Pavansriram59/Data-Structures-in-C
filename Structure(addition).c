#include <stdio.h>
struct add
{
    int a, b;
} num;
void sum(struct add num)
{
    printf("The sum of two no.s is: %d", num.a + num.b);
}
void main()
{
    printf("Enter the no.s:");
    scanf("%d %d", &num.a, &num.b);
    sum(num);
}
