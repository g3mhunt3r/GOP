#include<stdio.h>

#define X 5
#define Y 5

int countn(char grid[X][Y], int i, int j)
{
	int c;
	c=grid[(i-1+X)%X][(j-1+Y)%Y]+				// top left
	grid[i][(j-1+Y)%Y]+							// top
	grid[(i+1)%X][(j-1+Y)%Y]+					// top right
	grid[(i-1+X)%X][j]+							// left
	grid[(i+1)%X][j]+							// right
	grid[(i-1+X)%X][(j+1)%Y]+					// bottom left
	grid[i][(j+1)%Y]+							// bottom
	grid[(i+1)%X][(j+1)%Y];						// bottom right
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
			c=countn(copyg, i, j);
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