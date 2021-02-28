#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
///structure for regestration
struct reges
{
    char name[30], fname[30], email[40], qual[20];
    int age;
} x;
///regestration function using file hand
int regestration()
{
    FILE *play_name;
    char finame[20];
    printf("\n\n\n\nEnter the players's file name : ");
    gets(finame);
    gets(finame);
    play_name = fopen(finame, "w");

    printf("enter name\n");
    gets(x.name);

    printf("enter age\n");
    scanf("%d", &x.age);

    printf("enter father's name\n");

    gets(x.fname);
    gets(x.fname);
    printf("enter email\n");
    gets(x.email);

    printf("enter qualification\n");
    gets(x.qual);
    fprintf(play_name, "\n%s\n%d\n%s\n%s\n%s", x.name, x.age, x.fname, x.email, x.qual);

    printf("\nPlayer registered Successfully\n");
    return 0;
}
///login
void login()
{
    int a = 0, i = 0;
    char user[10], c = ' ';
    char pass[10];
    do
    {

        printf("\n  *LOGIN*\n  ");
        printf(" \n                   ENTER USERNAME: ");
        scanf("%s", user);
        printf(" \n                   ENTER PASSWORD: ");
        while (i < 10)
        {
            pass[i] = getch();
            c = pass[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pass[i] = '\0';

        i = 0;

        if (strcmp(user, "s") == 0 && strcmp(pass, "s") == 0)
        {
            printf("  \n\n\n       WELCOME TO the aptitude quiz !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to start the quiz...\n\n");
            getch();
            qr1();
            ///quiz questions

            break;
        }
        else
        {
            printf("\n      login abort");
            a++;

            getch();
            system("cls");
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\ninitiating lock down");
    }
    getch();
    system("cls");
}
void instruct() ///instructions convert to file
{
    printf("1: There are two rounds()\n");
    printf("2: Both rounds have 5 questions each. \n");
    printf("3: Of the 2 rounds. In mentioned above, the first is called the Warm-up Round; the second is the Challenge round.\n");
    printf("4: In the warm-up round, the player is asked a total of 5 simple questions and they must be able to answer at 3 two of them correctly to enter the next round. If the player is not capable of doing that, he is not permitted to proceed further.\n");
    printf("5: In the second and more interesting round of this quiz game in C, the player will be asked questions continuously, and for each right answer given, they will earn $100.000\n");
    printf("6: The game ends when the player's cash prize piles up to $1 million. For each question asked, there are 4 options, namely A, B, C and D. There are no negative markings, so the player's accumulated cash money won't be deducted for wrong answers to the questions\n");
}

///title screen

void title()
{
    printf("\t\t\t\t\t\t\t\t   ____  __  ___________\n");
    printf("\t\t\t\t\t\t\t\t  / __ \\/ / / /  _/__  /\n");
    printf("\t\t\t\t\t\t\t\t / / / / / / // /   / /\n");
    printf("\t\t\t\t\t\t\t\t/ /_/ / /_/ // /   / /__\n");
    printf("\t\t\t\t\t\t\t\t\\___\\_\\____/___/  /____/\n");
    printf("\t\t\t\t\bPress any key to continue.\n");
    getch();
    ;
}
///switch used to give choices
void choice(int a)
{
    switch (a)
    {
    case 1:
    {
        printf("login\n");
        login();
        break;
    }
    case 2:
    {
        printf("regestration\n");
        regestration();
        break;
    }
    case 3:
    {
        printf("instructions\n");
        instruct();
        break;
    }
    case 4:
    {
        printf("exit\n");
        getch();
        break;
    }
    default:
    {
        printf("wrong choice chose again\n");
        getch();
    }
    }
}
///question are read from a file and answers are matched and score is maintained
int qr1()
{

    char line[256], a[2], ans[1];
    int ques, s, score, r;

    for (ques = 1; ques <= 5; ques++)
    {
        system("cls");
        s = 0;
        FILE *file = fopen("qr1.txt", "r");
        while (fgets(line, sizeof(line), file))
        {
            if (s >= 6 * (ques - 1) && s <= 6 * (ques - 1) + 5)
            {
                printf("%s", line);
            }
            s++;
        }
        fclose(file);

        printf("ANSWER : ");

        scanf("%s", ans); ///scanf, why you no work???

        r = 0;
        FILE *file2 = fopen("ans.txt", "r");
        while (fgets(a, sizeof(a), file2))
        {
            if (r == ques - 1)
            {
                if (strcmp(ans, a) == 0)
                {
                    ///correct answer ping
                    score++;
                }
            }
            r++;
        }
        fclose(file2);
    }
}

///main fuction
int main()
{

    title();
    system("cls");
    int ch;
    scanf("%d", &ch);
    choice(ch);
    return 0;
}
