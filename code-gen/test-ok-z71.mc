//OPIS: inkrement na vise mesta
//RETURN: 6

int y;

int main() {
    int x;
    int z;
    x = 0;
    y = 3;
    z = x++ + y++ + 42;
    z = 1;

    switch(x) {
      case 1:
        z = 1;
        break;
      case 2:
        z = 5;
      default:
        z = 6;
    }
    return x + y + z;
}
