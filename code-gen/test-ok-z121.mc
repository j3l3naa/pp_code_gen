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
        y++;
    }

    return x + y;
}
