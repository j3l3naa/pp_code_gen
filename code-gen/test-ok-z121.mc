//OPIS: inkrement u numexp-u
//RETURN: 12
int y;

int main() {
    int x;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    if(x < y++)
      x = 0;

    for (int i = 0; i < 5; i++) {
      for(int j = 1; j < 2; j++)
          y++;
    }
    return x + y;
}
