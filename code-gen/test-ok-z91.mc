//OPIS: inkrement u numexp-u
//RETURN: 14

int y;

int main() {
    int x;
    int i;
    i = 0;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    if(x < y++)
      x = 0;

    do {
      x++;
      i++;
    } while( i < 7);

    return x + y;
}
