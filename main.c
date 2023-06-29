#include <conio.h> // getch();
#include <stdio.h> // printf(); getchar();
#include <windows.h> // system();
#include <stdlib.h> // rand();
#include <time.h>

int main (void)
{
    int x, y; // coords
    int xx = 11, yy = 5; // player coords
    int tx = 8, ty = 5; // goblin coords
    char action;
    char map[21][11];
    int gold_total = 0; // player gold
    int gold = 0; // goblin gold
    char flag_defeat = 0;
    srand(time(NULL));

    action = getch(); // w/a/s/d

    do
    {
        system("cls"); // clear buffer

        // movement checks
        if      (action == 'w' && map[xx][yy - 1] != '#') yy--;
        else if (action == 's' && map[xx][yy + 1] != '#') yy++;
        else if (action == 'a' && map[xx - 1][yy] != '#') xx--;
        else if (action == 'd' && map[xx + 1][yy] != '#') xx++;

        //fight
        if (xx == tx && yy == ty)
        {
            tx = (rand() % 18) +1;
            ty = (rand() % 8) + 1;
            if (xx == tx && yy == ty)
            {
                tx = (rand() % 18) +1;
                ty = (rand() % 8) + 1;
            }
            gold = (rand() % 10) +1;
            gold_total += gold;
            flag_defeat = 1;
        }

        //dungeon building
        for (y = 0; y <= 10; y++)
        {
            for (x = 0; x <= 20; x++)
            {
                if (x == xx && y == yy)
                {
                    printf("@");
                }
                else if (x == tx && y == ty)
                {
                    printf("t");
                }
                
                else if (y == 0 || y == 10)
                {
                    printf("#");
                    map[x][y] = '#';
                    if (x == 20)
                    {
                        printf("\n");
                    }
                }
                else if (x == 0)
                {
                    printf("#");
                    map[x][y] = '#';
                }
                else if (x == 20)
                {
                    printf("#\n");
                    map[x][y] = '#';
                }
                else
                {
                    printf(" ");
                    map[x][y] = ' ';
                }
            }
        }
        if (flag_defeat)
        {
            printf("You've defeted a goblin and found %d gold!", gold);
            printf("\nGold: %d", gold_total);
            flag_defeat = 0;
        }
        else
        {
            printf("\nGold: %d", gold_total);
        }
    }

    while (action = getch());
    
    return 0;
}