#include <algorithm>
#include <stdio.h>
#define SIZEOF(T) (sizeof(T)) / (sizeof(T[0]))
void print_arr(int *arr, int n);

void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
}

int main() {
  int arr[] = {9, 2, 5, 7, 3, 1, 8, 4, 6};
  int n = SIZEOF(arr);
  bubbleSort(arr, n);
  print_arr(arr, n);
  return 0;
}

void print_arr(int *arr, int n) {
  printf("排序结果\n");
  for (int i = 0; i != n; i++) {
    printf("%d ", arr[i]);
  }
}
