#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    _Bool play = 1;
    char restart = 'y';
    int lives, guess, x;
    time_t t;

    while (play)
    {
        //random  szam generalas
        srand((unsigned) time(&t));
        x = rand() % 21;

        lives = 5;
        printf("%d\n", x);
        //maga a jatek felutatasa
        while (lives > 0)
        {
            printf("\nYou have %d more tries", lives);
            printf("\nYour guess: ");
            scanf("%d", &guess);
            if (guess == x)
            {
                printf("Congratulations you got the number %d in %d guesses\n", x, 6 - lives);
                break;
            }
            if (guess > x)
                printf("The number is smaller than %d\n", guess);
            if (guess < x)
                printf("The number is bigger than %d\n", guess);
            lives--;
        }
        //vesztes eseteben
        if (lives == 0)
            printf("\n YOU LOST \n The number was %d\n", x);
        //restart vagy lealitas
        while(play)
        {
            printf("\nAnother try? (y/n)\n");
            scanf(" %c", &restart);

            if (restart == 'n')
            {
                play = 0;
                break;
            }
            if (restart == 'y')
                break;
            if (restart != 'y' && restart != 'n')
                    printf("Invalid command choose y / n");

        }
    }
    return 0;
}
