#include <stdio.h>

void rec(int x)
{
    if (x == 0){
        return;
    }
    printf("%d", x);
    x--;
    rec(x);
}

int main (){
    rec(4);
    return 0;
}