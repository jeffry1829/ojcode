#include <iostream>
#define N 5
int __S[] = {0, 0, 1};

int __D[] = {1, 2, 0};
bool counter = false;
int Initialize() {
  if (counter == true) {
    std::cout << "_exit(0)\n";
    std::cout.flush();
    _exit(0);
  }
  counter = true;
  return 3;
}
int tryCombination(int s[]) {
  int front = 3;
  for (int i = 0; i < 3; i++)
    if (s[i] != __S[__D[i]]) front = std::min(front, __D[i]);
  return front == 3 ? -1 : front;
}
int answer(int s[], int d[]) {
  std::cout << "s: ";
  for (int i = 0; i < 3; i++)
    std::cout << s[i] << ", ";
  std::cout << "d: ";
  for (int i = 0; i < 3; i++)
    std::cout << d[i] << ", ";
}