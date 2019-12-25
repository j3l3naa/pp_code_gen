//OPIS: inkrement u numexp-u
//RETURN: 28

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

    for i = 0 to 5 step 1
      for j = 10 downto 5 step 2
        x++;
        next;
    next;

    if(x < y++)
      x = 0;

    return x + y;
}
