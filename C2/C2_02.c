#include <stdio.h>
double fun ( int x[])
{
/************found************/
  double sum = 0.0;          /* 将 sum 改为 double 类型，以便保存小数 */
  int c=0, i=0;

  /* 遍历数组直到遇到0为止，累加所有正整数并统计其个数 */
  while (x[i] != 0)
  { if (x[i] > 0) {
       sum += x[i]; c++; }
    i++;
  }
/************found************/
  sum /= c;                  /* 将反斜杠改为除号 / */

  /* 计算平均值：将总和除以正整数的个数 */

  return sum;
}
int main( )
{  int x[1000];  int i=0;
   printf( "\nPlease enter some data (end with 0): " );
   do
     {  scanf("%d", &x[i]);  }
   while (x[i++] != 0);
   printf("%f\n", fun ( x ));
}

// 程序修改题（二）
//     在主函数中从键盘输入若干个数放入数组中，用0结束输入并放在最后一个元素中。下列给定程序中函数fun的功能是：计算数组元素中所有值为正数的平均值(不包括0)。
//     例如：数组中元素中的值依次为：39，－47,21,2，－8,15,0，则程序的运行结果为19.250000。
