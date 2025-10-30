#include <stdio.h>

int main(void) {
    int X, C;
    scanf("%d %d", &X, &C);

    int p_max = X / (1000 + C);
    int ans = p_max * 1000;

    printf("%d\n", ans);
    return 0;
}

