#include <stdio.h>

struct Retangulo {
    int Ax, Ay;
    int Bx, By;
    int Cx, Cy;
    int Dx, Dy;
    int Rx, Ry;
} typedef Retangulo;

int main() {
    int N;
    Retangulo r;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &r.Ax, &r.Ay);
        scanf("%d %d", &r.Bx, &r.By);
        scanf("%d %d", &r.Cx, &r.Cy);
        scanf("%d %d", &r.Dx, &r.Dy);
        scanf("%d %d", &r.Rx, &r.Ry);

        if (r.Ax <= r.Rx && r.Dx <= r.Rx &&
            r.Rx <= r.Bx && r.Rx <= r.Cx &&
            r.Ay <= r.Ry && r.By <= r.Ry &&
            r.Ry <= r.Cy && r.Ry <= r.Dy) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
