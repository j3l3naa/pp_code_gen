//OPIS: inkrement u numexp-u
//RETURN: 67
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

    for (i = 0; i < 5; i++) {
      for(x = 0; x < 10; x++)
        y++;
    }
    
    return x + y;
}
