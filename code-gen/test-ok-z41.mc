//OPIS: inkrement u numexp-u
//RETURN: 24

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

    x = y + (x == y) ? x : y + 3;
    return x + y;


}
