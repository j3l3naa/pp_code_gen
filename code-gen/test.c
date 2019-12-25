#include <stdio.h>
int y;

int main() {
    int x;
    int i;
    int j;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    for(i = 0; i <= 5; i++) {
        x++;
    }

    if(x < y++)
      x = 0;

      printf("%d", x + y);
    return x + y;




}
