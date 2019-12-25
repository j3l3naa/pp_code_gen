//OPIS: inkrement u numexp-u
//RETURN: 43

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

    while(i < 5)
    {
      while (y < 25) {
        x++;
        i++;
        y++;
      }
    }
    
    return x + y;
}
