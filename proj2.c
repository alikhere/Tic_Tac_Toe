#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void Gamerule();
void ShowGame(int [][3]);
void Change(int[][3],char,int*);
int win(int[][3]);
void smart_comp(int[][3]);
void evil_comp(int[][3]);

void Gamerule()
{
    int i,j,a[3][3];
    char c[5];
    printf("\t \t \t \t \t  \t ***TIC TAC TOE***\n\n");
    printf("\t \t \t  \t \t \t\t Rules of Game\n");
    printf("\n1. The game is played on grid that's 3 squares y 3 square .\n");
    printf("2. You are X, your friends(or the computer in this case)  is O. Players take turns putting their marks in empty squares.\n");
    printf("3. The first player to get 3 of her marks in a row (up, down, across.or diagonally) is the winner. \n");
    printf("4. when all 9 squares are full, the game is over. If no player has 3 marks in a row,the game ends in a tie\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j%2==0 && i%2==0)
            a[i][j]='X';
            else
            a[i][j]='O';
        }
    }
    a[1][1]='X';
    a[1][0]='X';
    a[0][2]='O';
    printf("\t \t \t \t \t \t \t Winning Situation \n\n");
    ShowGame(a);
    printf("\n5. You can exit the game at any time by pressing 'E' or 'e'.\n\n");
    printf("Press Enter to start...");
    getch();
    system("cls");


}
void ShowGame(int a[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
           printf("\t \t \t \t \t \t \t");
           printf("     |     |     \n");
           printf("\t \t \t \t \t \t \t");
	       printf("  %c  |  %c  |  %c  \n",a[i][0],a[i][1],a[i][2]);
           printf("\t \t \t \t \t \t \t");
	       printf("_____|_____|_____\n");
    }
}

void New(int a[][3])
{
    int i,j,count=49;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=count;
            count++;
        }
    }
}

void with_player()
{
    int array[3][3],k=0;
    char key;
    New(array);
    while(!win(array))
       {    
            system("cls");
            printf("\t \t \t \t \t   ########## TIC TAC TOE ##########\n\n");
            printf("Player 1: X\n");
            printf("Player 2: O\n");
            ShowGame(array);
            printf("\n\t \t \t \t \t   #####################################\n\n");
            if(k%2==0)
            printf("Player 1. Enter Marking Place: ");
            else
            printf("Player 2. Enter Marking Place: ");
            fflush(stdin);
            key=getch();
            switch(key)
            {
                  case 49:
                  Change(array,key,&k);
                  break;
                  case 50:
                  Change(array,key,&k);
                  break;
                  case 51:
                  Change(array,key,&k);
                  break;
                  case 52:
                  Change(array,key,&k);
                  break;
                  case 53:
                  Change(array,key,&k);
                  break;      
                  case 54:
                  Change(array,key,&k);
                  break;
                  case 55:
                  Change(array,key,&k);
                  break;
                  case 56:
                  Change(array,key,&k);
                  break;  
                  case 57:
                  Change(array,key,&k);
                  break;
                case 'e':
                case 'E':
                   system("cls");
                   printf("\n\n\t \t \t \t \t \t \t***ThankYou for Playing***\n"); 
                   printf("\t \t \t  \t \t \t \t Press Enter to Exit game\n\n");
                   getch();
                   system("cls");
                   exit(0);
                default:
                  printf("\nInvalid Input");      

            }
        }
        system("cls");
        ShowGame(array);
        if(win(array)==-1)
        {
        printf("\n \t \t \t \t \t \t \t    Game Tie\n\n");
        printf("\t \t \t \t \t \t \t Want to play again?\n");
        printf("\t \t \t \t \t  \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
           {
            system("cls");
            exit(0);
           }
        }
        else
        {
        if(k%2!=0)
        printf("\n \t \t \t \t \t \t \t Player 1 Win \n");
        else
        printf("\n \t \t \t \t \t \t \tPlayer 2 Win\n");
        printf("\n\t \t \t \t \t \t \tWant to play again?\n");
        printf("\t \t \t \t \t \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
        {
            system("cls");
            exit(0);
        }
        }


}

void Change(int a[][3], char key, int *p)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==key)
            {
                if((*p)%2==0)
                a[i][j]='X';
                else
                a[i][j]='O';
                (*p)++;
                break;
            }
        }
    }

}

int win(int a[][3])
{   int flag=0;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            if(a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2])
            return 1;
            if(a[j][i]==a[j+1][i] && a[j][i]==a[j+2][i])
            return 1;

        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
         return 1;
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
         return 1;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]!='O'  && a[i][j]!='X')
            {
            flag++;
            break;
            }

        }
    }   
    if(flag)
    return 0;
    return -1;  

}

void with_comp()
{
    int array[3][3],k=0;
    char key;
    New(array);
    while(!win(array))
       {    
            system("cls");
            printf("\t\t\t\t\t \t########## TIC TAC TOE ##########\n\n");
            printf("Player  : X\n");
            printf("Computer: O\n");
            ShowGame(array);
            printf("\n\n\t\t\t\t\t\t##################################\n\n");
            printf("Player 1. Enter Marking Place: ");
            if(k%2==0)
            {
            fflush(stdin);
            key=getch();    
            switch(key)
            {
                  case 49:
                  Change(array,key,&k);
                  break;
                  case 50:
                  Change(array,key,&k);
                  break;
                  case 51:
                  Change(array,key,&k);
                  break;
                  case 52:
                  Change(array,key,&k);
                  break;
                  case 53:
                  Change(array,key,&k);
                  break;      
                  case 54:
                  Change(array,key,&k);
                  break;
                  case 55:
                  Change(array,key,&k);
                  break;
                  case 56:
                  Change(array,key,&k);
                  break;  
                  case 57:
                  Change(array,key,&k);
                  break;
                case 'e':
                case 'E':
                   system("cls");
                   printf("\n\n\t \t \t \t \t \t \t***ThankYou for Playing***\n"); 
                   printf("\t \t \t  \t \t \t \t Press Enter to Exit game\n\n");
                   getch();
                   system("cls");
                   exit(0);
                default:
                  printf("\nInvalid Input");      
            }
            }
            else
            {
                smart_comp(array);
                k++;
            }
        }
        system("cls");
        ShowGame(array);
        if(win(array)==-1)
        {
        printf("\n \t \t \t \t \t \t \t    Game Tie\n\n");
        printf("\t \t \t \t \t \t \t Want to play again?\n");
        printf("\t \t \t \t \t  \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
           {
            system("cls");
            exit(0);
           }
        }
        else
        {
        if(k%2!=0)
        printf("\n \t \t \t \t   \t  \t \t    You Win \n");
        else
        printf("\n \t \t \t \t \t \t \t    You Lose\n");
        printf("\n\t \t \t \t \t \t \tWant to play again?\n");
        printf("\t \t \t \t \t \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
        {
            system("cls");
            exit(0);
        }
        }


}

void smart_comp(int a[][3])
{
    int i,j,temp=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            if(((a[i][j]==a[i][j+1]) && (a[i][j+2]!='X'&&a[i][j+2]!='O')) || ((a[i][j+1]==a[i][j+2]) && (a[i][j]!='X'&&a[i][j]!='O')) || ((a[i][j]==a[i][j+2]) && (a[i][j+1]!='X'&&a[i][j+1]!='O')))
            {
                if(a[i][j]==a[i][j+1])
                a[i][j+2]='O';
                else
                {
                    if(a[i][j+1]==a[i][j+2])
                    a[i][j]='O';
                    else
                    a[i][j+1]='O';
                }
                temp++;
                break;
            }
            if(((a[j][i]==a[j+1][i]) && (a[j+2][i]!='X'&&a[j+2][i]!='O')) || ((a[j+1][i]==a[j+2][i]) && (a[j][i]!='X'&&a[j][i]!='O')) || ((a[j][i]==a[j+2][i]) && (a[j+1][i]!='X'&&a[j+1][i]!='O')))
            {
                if(a[j][i]==a[j+1][i])
                a[j+2][i]='O';
                else
                {
                    if(a[j+1][i]==a[j+2][i])
                    a[j][i]='O';
                    else
                    a[j+1][i]='O';
                }
                temp++;
                break;
            }
        }
        if(temp>0)
        break;
    }
    if(!temp)
    {
       if(((a[0][0]==a[1][1]) && (a[2][2]!='X'&&a[2][2]!='O')) || ((a[1][1]==a[2][2]) && (a[0][0]!='X'&&a[0][0]!='O')) || ((a[0][0]==a[2][2]) && (a[1][1]!='X'&&a[1][1]!='O')))
       {
            if(a[0][0]==a[1][1])
            a[2][2]='O';
            else
            {
                if(a[1][1]==a[2][2])
                a[0][0]='O';
                else
                a[1][1]='O';
            }
            temp++;
       }
       else
       {
       if(((a[0][2]==a[1][1]) && (a[2][0]!='X'&&a[2][0]!='O')) || ((a[1][1]==a[2][0]) && (a[0][2]!='X'&&a[0][2]!='O')) || ((a[0][2]==a[2][0]) && (a[1][1]!='X'&&a[1][1]!='O')))
       {
            if(a[0][2]==a[1][1])
            a[2][0]='O';
            else
            {
                    if(a[1][1]==a[2][0])
                    a[0][2]='O';
                    else
                    a[1][1]='O';
            }
            temp++;
       }
       }
    }
    if(!temp)
    {
       for(i=0;i<3;i++)
       {
        for(j=0;j<3;j++)
           {
               if(a[i][j]!='X' && a[i][j]!='O')
               {
                  a[i][j]='O';
                  temp++;
                  break;
               }

           }
           if(temp>0);
           break;
       }
    }   

}

void with_evilcomp()
{
    int array[3][3],k=0;
    char key;
    New(array);
    while(!win(array))
       {    
            system("cls");
            printf("\t\t\t\t\t \t########## TIC TAC TOE ##########\n\n");
            printf("Player  : X\n");
            printf("Computer: O\n");
            ShowGame(array);
            printf("\n\n\t\t\t\t\t\t##################################\n\n");
            printf("Player 1. Enter Marking Place: ");
            if(k%2==0)
            {
            fflush(stdin);
            key=getch();    
            switch(key)
            {
                  case 49:
                  Change(array,key,&k);
                  break;
                  case 50:
                  Change(array,key,&k);
                  break;
                  case 51:
                  Change(array,key,&k);
                  break;
                  case 52:
                  Change(array,key,&k);
                  break;
                  case 53:
                  Change(array,key,&k);
                  break;      
                  case 54:
                  Change(array,key,&k);
                  break;
                  case 55:
                  Change(array,key,&k);
                  break;
                  case 56:
                  Change(array,key,&k);
                  break;  
                  case 57:
                  Change(array,key,&k);
                  break;
                case 'e':
                case 'E':
                   system("cls");
                   printf("\n\n\t \t \t \t \t \t \t***ThankYou for Playing***\n"); 
                   printf("\t \t \t  \t \t \t \t Press Enter to Exit game\n\n");
                   getch();
                   system("cls");
                   exit(0);
                default:
                  printf("\nInvalid Input");      
            }
            }
            else
            {
                evil_comp(array);
                k++;
            }
        }
        system("cls");
        ShowGame(array);
        if(win(array)==-1)
        {
        printf("\n \t \t \t \t \t \t \t    Game Tie\n\n");
        printf("\t \t \t \t \t \t \t Want to play again?\n");
        printf("\t \t \t \t \t  \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
           {
            system("cls");
            exit(0);
           }
        }
        else
        {
        if(k%2!=0)
        printf("\n \t \t \t \t   \t  \t \t You Win \n");
        else
        printf("\n \t \t \t \t \t \t \t    You Lose\n");
        printf("\n\t \t \t \t \t \t \tWant to play again?\n");
        printf("\t \t \t \t \t \t Press y to play again and e to exit\n");
        fflush(stdin);
        key=getch();
        if(key=='e')
        {
            system("cls");
            exit(0);
        }
        }


}

void evil_comp(int a[][3])
{
    int i,j,temp=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            if(((a[i][j]==a[i][j+1]) && (a[i][j+2]!='X'&&a[i][j+2]!='O')) || ((a[i][j+1]==a[i][j+2]) && (a[i][j]!='X'&&a[i][j]!='O')) || ((a[i][j]==a[i][j+2]) && (a[i][j+1]!='X'&&a[i][j+1]!='O')))
            {
                if(a[i][j]==a[i][j+1])
                a[i][j+2]='O';
                else
                {
                    if(a[i][j+1]==a[i][j+2])
                    a[i][j]='O';
                    else
                    a[i][j+1]='O';
                }
                temp++;
            }
            if(((a[j][i]==a[j+1][i]) && (a[j+2][i]!='X'&&a[j+2][i]!='O')) || ((a[j+1][i]==a[j+2][i]) && (a[j][i]!='X'&&a[j][i]!='O')) || ((a[j][i]==a[j+2][i]) && (a[j+1][i]!='X'&&a[j+1][i]!='O')))
            {
                if(a[j][i]==a[j+1][i])
                a[j+2][i]='O';
                else
                {
                    if(a[j+1][i]==a[j+2][i])
                    a[j][i]='O';
                    else
                    a[j+1][i]='O';
                }
                temp++;
            }
        }
       
    }

       if(((a[0][0]==a[1][1]) && (a[2][2]!='X'&&a[2][2]!='O')) || ((a[1][1]==a[2][2]) && (a[0][0]!='X'&&a[0][0]!='O')) || ((a[0][0]==a[2][2]) && (a[1][1]!='X'&&a[1][1]!='O')))
       {
            if(a[0][0]==a[1][1])
            a[2][2]='O';
            else
            {
                if(a[1][1]==a[2][2])
                a[0][0]='O';
                else
                a[1][1]='O';
            }
            temp++;
       }
       if(((a[0][2]==a[1][1]) && (a[2][0]!='X'&&a[2][0]!='O')) || ((a[1][1]==a[2][0]) && (a[0][2]!='X'&&a[0][2]!='O')) || ((a[0][2]==a[2][0]) && (a[1][1]!='X'&&a[1][1]!='O')))
       {
            if(a[0][2]==a[1][1])
            a[2][0]='O';
            else
            {
                    if(a[1][1]==a[2][0])
                    a[0][2]='O';
                    else
                    a[1][1]='O';
            }
            temp++;
       }
    if(!temp)
    {
       for(i=0;i<3;i++)
       {
        for(j=0;j<3;j++)
           {
               if(a[i][j]!='X' && a[i][j]!='O')
               {
                  a[i][j]='O';
                  temp++;
                  break;
               }
           }
        if(temp>0);
        break;
       }
    }   

}

int main()
{
    int key;
    system("cls");
    Gamerule();
    while(1)
    {
        printf("Enter your Choice\n\n");
        printf("1. Want to play with player\n");
        printf("2. Want to play with smart computer\n");
        printf("3. Want to play with Evil computer\n");
        printf("4. Exit\n");
        fflush(stdin);
        key=getch();
        switch(key)
        {
            case '1':
              with_player();
              break;
            case '2':
              with_comp();
              break;
            case '3':
              with_evilcomp();
              break;  
            case '4':
              system("cls");
              return 0;
           default:
           printf("Invalid input");
        }
    }
    return 0;
}
