// I have written the main of two diffferent codes and put them under one file, playing around with pointers.
// Pointers and arrays
#include <stdio.h>
int main() {

  int i, x[8], sum = 0;

  printf("Enter 8 numbers: ");

  for(i = 0; i < 8; ++i) {
  // Equivalent to scanf("%d", &x[i]);
      scanf("%d", x+i);

  // Equivalent to sum += x[i]
      sum += *(x+i);
  }

  printf("Sum = %d", sum);

  return 0;
}

// Arrays and pointers
#include <stdio.h>
int main() {

  int x[7] = {1, 2, 3, 4, 5, 9, 11};
  int* ptr;

  // ptr is assigned the address of the third element
  ptr = &x[2]; 

  printf("*ptr = %d \n", *ptr);   // 3
  printf("*(ptr+1) = %d \n", *(ptr+1)); // 4
  printf("*(ptr-1) = %d", *(ptr-1));  // 2

  return 0;
}