#include<bits/stdc++.h>
using namespace std;
#define easy 0
#define medium 1
#define hard 2
#define maxside 25
#define maxmines 99
#define maxmoves 526 //25*25-99
int side;
int mine;
void intialise(char realboard[][maxside], char myboard[][maxside])
{
    srand(time (NULL));
    for (int i=0; i<side; i++)
    {
        for (int j=0; j<side; j++)
        {            myboard[i][j] = realboard[i][j] = '-';
        }
    }
    return;
}
void placemines(int mines[][2],char realboard[][maxside])
{
    bool mark[maxside*maxside];
    memset (mark, false, sizeof (mark));
    for (int i=0; i<mine; )
     {
        int random = rand() % (side*side);
        int x = random / side;
        int y = random % side;
        if (mark[random] == false)
        {
            mines[i][0]= x;
            mines[i][1] = y;
            realboard[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }
    return;
}
void printboard(char myboard[][maxside])
{
    int i, j;
    cout<<"    ";
    for (i=0;i<side;i++)
        printf ("%d ",i);
    printf ("\n");
    for (i=0;i<side;i++)
    {
        printf ("%d   ", i);
        for (j=0; j<side;j++)
            printf ("%c ",myboard[i][j]);
        printf ("\n");
    }
    return ;
}
void makemove(int &x,int &y)
{
    while(true)
    {
        cout<<"enter your move:"<<endl;
        cout<<"enter x and y value:";
        cin>>x>>y;
        if(x>side || y>side)
        {
            cout<<"your values are out of range please enter the values in a range\n";
        }
        else
        {
            break;
        }
    }
    return ;
}
bool ismine(int x,int y,char realboard[][maxside])
{
    if(realboard[x][y]=='*')
    {
        return true;
    }
    return false;
}
void replacemine(int x,int y,char realboard[][maxside])
{
    for (int i=0; i<side; i++)
    {
        for (int j=0; j<side; j++)
            {
                if (realboard[i][j] != '*')
                {
                    realboard[i][j] = '*';
                    realboard[x][y] = '-';
                    return;
                }
            }
    }
    return;
}
bool isValid(int row,int col)
{
    return (row >= 0) && (row < side) && (col >= 0) && (col < side);
}
int countadjacentmines(int row,int col,char realboard[][maxside])
{
    int i=0;
    int count=0;
        if(isValid (row-1, col) == true)
        {
               if (ismine(row-1, col, realboard)==true)
               count++;
        }
        if(isValid(row+1,col)==true)
        {
               if (ismine(row+1,col,realboard)==true)
               count++;
        }
        if(isValid (row, col+1) == true)
        {
            if (ismine (row, col+1, realboard) == true)
               count++;
        }
        if (isValid (row, col-1) == true)
        {
               if (ismine (row, col-1, realboard) == true)
               count++;
        }
        if (isValid (row-1, col+1) == true)
        {
            if (ismine (row-1, col+1, realboard) == true)
               count++;
        }
        if (isValid (row-1, col-1) == true)
        {
             if (ismine (row-1, col-1, realboard) == true)
               count++;
        }
        if (isValid (row+1, col+1) == true)
        {
               if (ismine (row+1, col+1, realboard) == true)
               count++;
        }
        if (isValid (row+1, col-1) == true)
        {
            if (ismine (row+1, col-1, realboard) == true)
               count++;
        }
    return (count);
}
bool playminesweeper(char myboard[][maxside], char realboard[][maxside],int mines[][2], int row, int col, int *moveleft)
{
    if(myboard[row][col]!='-')
    {
        return false;
    }
    if(realboard[row][col]=='*')
    {
        myboard[row][col]='*';
        for(int i=0;i<mine;i++)
        {
            myboard[mines[i][0]][mines[i][1]]='*';
        }
        printboard(myboard);
        cout<<"Your lost";
        return true;
    }
    else
    {
        int count=countadjacentmines(row,col,realboard);
        (*moveleft)--;
        myboard[row][col]=count+'0';
        if(!count)
        {
            if (isValid (row-1, col) == true)
            {
                   if (ismine (row-1,col,realboard)==false)
                   playminesweeper(myboard, realboard, mines, row-1, col, moveleft);
            }
            if (isValid (row+1, col) == true)
            {
                   if (ismine(row+1, col, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row+1, col, moveleft);
            }
            if (isValid (row, col+1) == true)
            {
                if (ismine (row, col+1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row, col+1, moveleft);
            }
            if (isValid (row, col-1) == true)
            {
                   if (ismine (row, col-1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row, col-1, moveleft);
            }
            if (isValid (row-1, col+1) == true)
            {
                if (ismine (row-1, col+1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row-1, col+1, moveleft);
            }
            if (isValid (row-1, col-1) == true)
            {
                 if (ismine (row-1, col-1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row-1, col-1, moveleft);
            }
            if (isValid (row+1, col+1) == true)
            {
                 if (ismine (row+1, col+1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row+1, col+1, moveleft);
            }
            if (isValid (row+1, col-1) == true)
            {
                if (ismine (row+1, col-1, realboard) == false)
                    playminesweeper(myboard, realboard, mines, row+1, col-1, moveleft);
            }
        }
    }
    return false;
}
void playminesweeper()
{
    bool gameover=false;
    char realboard[maxside][maxside],myboard[maxside][maxside];
    int moveleft=side*side-mine,x,y;
    int mines[maxmines][2];
    intialise(realboard,myboard);
    placemines(mines,realboard);
    int curmoveindex=0;
    while(gameover==false)
    {
        cout<<"current status of board"<<endl;
        printboard(myboard);
        makemove(x,y);
        if(curmoveindex==0)
        {
            if(ismine(x,y,realboard)==true)
            {
                replacemine(x,y,realboard);
            }
        }
        curmoveindex++;
        gameover=playminesweeper(myboard,realboard,mines,x,y,&moveleft);
        if(gameover==false && moveleft==0)
        {
            cout<<"you won "<<endl;
            gameover=true;
        }
    }
    return ;
}
void choosedifficultylevel()
{
    cout<<"select the level of Game:"<<endl;
    cout<<"0:easy level"<<endl;
    cout<<"1:medium level"<<endl;
    cout<<"2:medium level"<<endl;
    while(true)
    {
    int level;
    cin>>level;
    if(level==easy)
    {
        side=9;
        mine=10;
        break;
    }
    else if(level==medium)
    {
        side=16;
        mine=40;
        break;
    }
    else if(level==hard)
    {
        side=24;
        mine=99;
        break;
    }
    else
    {
        cout<<"your selected invalid level"<<endl;
        cout<<"please select valid option:"<<endl;
    }
    }
}
int main()
{
    choosedifficultylevel();
    playminesweeper();
    return 0;
}