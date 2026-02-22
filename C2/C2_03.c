#include  <stdlib.h>
#include  <conio.h>
#include  <stdio.h>
int fun( int m)
{ int i,k;
  for (i=m+1; ;i++)
     { for (k=2;k<i;k++)
/*************found**************/
          if (i%k==0)   // if (i%k!=0) 修改：如果能整除，则不是素数，跳出循环
           break;
/*************found**************/
        if (k==i)        // if (k<i)  修改：如果k等于i，说明循环正常结束，i是素数
         return(i);
     }
}
int main()
{  int n;
   system("CLS");
   printf("\nPlease enter n: ");
   scanf("%d",&n);
   printf ("%d\n",fun(n));
}

// 程序修改题（三）
// 下列给定程序中，函数fun的功能是：找出一个大于给定整数m且紧随m的素数，并作为函数值返回。
// 请改正程序中的错误，使它能得出正确的结果。
// 注意：不要改动main函数，不得增行或删行，也不得更改程序的结构！