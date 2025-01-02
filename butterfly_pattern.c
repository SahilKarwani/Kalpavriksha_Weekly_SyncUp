#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int spaces = 2 * x - 2;
    for(int i = 1; i <= x;i++)
    {
      for(int j = 1;j <= i;j++)
      {
        printf("%d",j);
      }
      for(int j=0;j<spaces;j++)
      {
        printf(" ");
      }
      for(int j =i;j>=1;j--)
      {
        printf("%d",j);
      }
      printf("\n");
      spaces-=2;
    }
    spaces = 2;
    for(int i = x; i > 0;i--)
    {
      for(int j = 1;j < i;j++)
      {
        printf("%d",j);
      }
      for(int j=0;j<spaces;j++)
      {
        printf(" ");
      }
      for(int j =i-1;j>=1;j--)
      {
        printf("%d",j);
      }
      printf("\n");
      spaces+=2;
    }
    
    
}