#include <stdio.h>

// This experiment shows how static vars work

void fun() {
	 int num1 = 10;
  static int num2 = 10;

	 num1 += 10;
	 num2 += 10;

	 printf("num1 is %d - num2 is %d\n", num1, num2);
}

int main() {
	for(int i = 0; i < 10; i++)
	fun();
}
