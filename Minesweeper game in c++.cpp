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

// Function to initialize the game boards
void intialise(char realboard[][maxside], char myboard[][maxside])
{
    srand(time (NULL)); // Seed for random number generation
    for (int i=0; i<side; i++)
    {
        for (int j=0; j<side; j++)
        {
            myboard[i][j] = realboard[i][j] = '-'; // Initialize both boards with empty cells
        }
    }
    return;
}

// Function to place mines randomly on the real board
void placemines(int mines[][2],char realboard[][maxside])
{
    bool mark[maxside*maxside];
    memset (mark, false, sizeof (mark)); // Mark array to keep track of placed mines
    for (int i=0; i<mine; )
    {
        int random = rand() % (side*side);
        int x = random / side;
        int y = random % side;
        if (mark[random] == false)
        {
            mines[i][0]= x;
            mines[i][1] = y;
            realboard[mines[i][0]][mines[i][1]] = '*'; // Place a mine at (x, y) on the real board
            mark[random] = true; // Mark the cell as containing a mine
            i++;
        }
    }
    return;
}

// Function to print the game board
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
            printf ("%c ",myboard[i][j]); // Print each cell of the board
        printf ("\n");
    }
    return ;
}

// Function to get user move
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

// Function to check if a cell contains a mine
bool ismine(int x,int y,char realboard[][maxside])
{
    if(realboard[x][y]=='*')
    {
        return true;
    }
    return false;
}

// Function to replace the first mine if it's in the first move
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

// Function to check if a cell is within the board bounds
bool isValid(int row,int col)
{
    return (row >= 0) && (row < side) && (col >= 0) && (col < side);
}

// Function to count adjacent mines to a given cell
int countadjacentmines(int row,int col,char realboard[][maxside])
{
    int count=0;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < 8; i++)
    {
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(isValid(nx, ny) && realboard[nx][ny] == '*')
        {
            count++;
        }
    }
    return count;
}

// Function to play the Minesweeper game
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
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        continue;
                    }
                    int nx = row + i;
                    int ny = col + j;
                    if(isValid(nx, ny) && myboard[nx][ny] == '-')
                    {
                        playminesweeper(myboard, realboard, mines, nx, ny, moveleft);
                    }
                }
            }
        }
    }
    return false;
}

// Function to allow the user to choose the difficulty level
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

// Main function
int main()
{
    choosedifficultylevel(); // Choose the difficulty level
    playminesweeper(); // Start the game
    return 0;
}
