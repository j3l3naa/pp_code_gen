//OPIS: 'f' undeclared

int y;

int main() {
    int x;
    int i;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    if(x < y++)
      x = 0;

    iterate f step 1 to 5
      x++;

    return x + y;
}
