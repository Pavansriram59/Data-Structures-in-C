#include <stdio.h>
struct student
{
    char name[20];
    int rno;
    int s1, s2, s3;
} s[10];
void read(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter student %d details:\n", i + 1);
        printf("Enter name:");
        scanf("%s", s[i].name);
        printf("Enter the rno.:");
        scanf("%d", &s[i].rno);
        printf("Enter the student marks:");
        scanf("%d %d %d", &s[i].s1, &s[i].s2, &s[i].s3);
    }
}
void display(struct student s[], int n)
{
    printf("The student details are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s %d\n", s[i].name, s[i].rno);
        printf("The marks of student %d are:%d %d %d\n", i + 1, s[i].s1, s[i].s2, s[i].s3);
    }
}
void main()
{
    int n;
    printf("Enter the no of students:");
    scanf("%d", &n);
    read(s, n);
    display(s, n);
}
