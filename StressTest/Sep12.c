#include <stdio.h>

int main (void) {
    for (int x = 0; x < 10; x++) {
		printf("hello world\n");
    }
    // With the increase in the number of 0s the chances of failure also increases.
    for (float x = 0.01; x < 0.1; x = x + 0.01) {
		printf("hello world\n");
    }   
}