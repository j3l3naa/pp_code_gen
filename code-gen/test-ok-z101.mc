//OPIS: inkrement u numexp-u
//RETURN: 16

int y;

int main() {
    int x;
    int i;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    for i = 0 to 5 step 1
      x++;
    next;

    if(x < y++)
      x = 0;

    return x + y;
}
