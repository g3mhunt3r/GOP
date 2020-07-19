#include<stdio.h>

#define X 5
#define Y 5

int countn(char grid[X][Y], int i, int j)
{
	int c;
	c=grid[(i-1)%X][(j-1)%Y]+grid[i][(j-1)%Y]+grid[(i+1)%X][(j-1)%Y]+grid[(i-1)%X][j]+grid[(i+1)%X][j]+grid[(i-1)%X][(j+1)%Y]+grid[i][(j+1)%Y]+grid[(i+1)%X][(j+1)%Y];
	return c;
}

void updateg(char grid[X][Y])
{
	char copyg[X][Y];
	int c;
	for(int i=0;i<X;i++)
	{   
		for(int j=0;j<Y;j++)
		{
			copyg[i][j]=grid[i][j];
		}
	}
	for(int i=0;i<X;i++)
	{   
		for(int j=0;j<Y;j++)
		{	
			countn(copyg, i, j);
			if(c==3)
				grid[i][j]=1;
			else if(c>3||c<2)
				grid[i][j]=0;
		}
	}
}

void readg(char grid[X][Y]) 
{
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			scanf("%hhd",&grid[i][j]);
		}
	}
}

void printg(char grid[X][Y])
{
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char grid[X][Y];
	readg(grid);
	updateg(grid);
	printg(grid);
	return 0;
}