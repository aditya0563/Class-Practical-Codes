#include <stdio.h>
int main() {
  int i, n;
  int x1=0, x2=1;
  int nt=x1+x2;
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  printf("Fibonacci Series: %d, %d,",x1,x2);
  for (i=3; i<=n;++i) {
    printf("%d,",nt);
    x1=x2;
    x2=nt;
    nt=x1+x2;
  }
  return 0;
}