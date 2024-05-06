#include <cs50.h>
#include <stdio.h>
int get_height();

int main(void)
{
    int height = get_height();
    int gh = height + 1;
    for (int i = 0; i < height; height--)
    {
        for (int f = 0; f < height - 1; f++)
        {
            printf(" ");
        }
        for (int f = gh; f > height; f--)
        {
            printf("#");
        }

        printf("\n");
    };
    return 0;
}
int get_height()
{
    while (1)
    {
        int n;
        printf("height: ");
        if (scanf("%d", &n) != 1)
        {
            printf("not integer\n");
            continue;
        }
        if (n > 0 && n < 9)
        {
            return n;
        }
    }
}
