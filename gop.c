#include<stdio.h>

#define X 5
#define Y 5

/*void update(int grid[][])
{

}*/

void readgrid(char grid[X][Y])
{
	for(int i=0;i<X;i++)
	{
		for(int j=0;j<Y;j++)
		{
			scanf("%hhd",&grid[i][j]);
		}
	}
}

void printgrid(char grid[X][Y])
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
	readgrid(grid);
	printgrid(grid);

}