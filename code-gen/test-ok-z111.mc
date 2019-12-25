//OPIS: inkrement u numexp-u
//RETURN: 13

int y;

int main() {
    int x;
    x = 2;
    y = 6;

    if(x++ == y) {
      x = 2;
    }

    iterate x step 1 to 5
      x++;

    return x + y;
}
