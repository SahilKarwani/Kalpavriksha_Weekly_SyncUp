#include <stdio.h>
int main()
{
    int numOfrows;
    scanf("%d",&numOfrows);
    int spaces = 2 * numOfrows - 2;
    for(int row = 1; row <= numOfrows;row++)
    {
      for(int col = 1;col <= row;col++)
      {
        printf("%d",col);
      }
      for(int s=0;s<spaces;s++)
      {
        printf(" ");
      }
      for(int col =row;col>=1;col--)
      {
        printf("%d",col);
      }
      printf("\n");
      spaces-=2;
    }
    spaces = 2;
    for(int row = numOfrows; row > 0;row--)
    {
      for(int col = 1;col < row;col++)
      {
        printf("%d",col);
      }
      for(int s=0;s<spaces;s++)
      {
        printf(" ");
      }
      for(int col =row-1;col>=1;col--)
      {
        printf("%d",col);
      }
      printf("\n");
      spaces+=2;
    }
    
    
}