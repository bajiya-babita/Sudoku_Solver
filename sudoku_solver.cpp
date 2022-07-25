
#include <iostream>
using namespace std;

bool safe(int s[][9],int r, int c, int NO,int N)
{
    //check for row and column
    for(int i=0;i<N;i++)
    {
        if(s[i][c]== NO || s[r][i]==NO)
        {
            return false;
        }
    }
    //check for subgrid
    int sx=(r/3)*3;
    int sy=(c/3)*3;
    for(int x= sx; x<(sx+3);x++)
    {
      for(int y= sy; y<(sy+3);y++)
      {
          if(s[x][y]==NO)
          {
              return false;
          }
      }  
    }
 return true;
}
bool sudoku_Solver(int s[][9], int r, int c, int N)
{
    //Base case
    if(r==N)
    {
        for(int r=0; r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                cout<<s[r][c]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(c==N)
    {
    return sudoku_Solver(s, r+1, 0, N);
    }
    //skip prefilled cell
    if(s[r][c]!=0)
    {
       return sudoku_Solver(s,r,c+1,N);
    }
    //cell to be filled
    for(int NO=1;NO<=N;NO++)
    {
        if(safe(s,r,c,NO,N))
        {
            s[r][c]=NO;
            bool solve_subproblem= sudoku_Solver(s,r,c+1,N);
        
            if(solve_subproblem == true)
            {
            return true;
            }
        }

    }
    s[r][c]=0;
    return false;
}
int main() {
	// your code goes here
    int N=9;
    int s[9][9]={{1,0,0,0,0,0,8,2,0},
                 {0,7,0,1,0,0,0,4,9},
                 {0,0,9,2,7,6,5,3,1},
                 {3,2,0,7,0,1,0,0,6},
                 {4,5,7,0,0,0,0,0,0},
                 {9,0,1,0,0,2,0,0,3},
                 {0,0,0,0,0,0,9,0,0},
                 {0,0,0,3,0,7,1,8,5},
                 {0,1,0,8,2,9,0,7,4}};

    if(!sudoku_Solver(s,0,0,N))
    {
        cout<<"NO solution exist!";
    }
	return 0;
}

