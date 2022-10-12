#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr, i , m1, m2;
  printf("Enter size: ");
  scanf("%d", &m1);

  ptr = (int*) malloc(m1 * sizeof(int));

  printf("Addresses of previously allocated memory:\n");
  for(i = 0; i < m1; ++i)
    printf("%pc\n",ptr + i);

  printf("\nEnter new size: ");
  scanf("%d", &m2);

  // rellocating the memory
  ptr = realloc(ptr, m2 * sizeof(int));

  printf("Addresses of newly allocated memory:\n");
  for(i = 0; i < m2; ++i)
    printf("%pc\n", ptr + i);
  
  free(ptr);

  return 0;
}