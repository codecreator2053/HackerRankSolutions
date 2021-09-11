#include <stdio.h>

void update(int *a,int *b) {
    int temp = *a;
    *a = *a + *b;
    int final_ = temp-*b>0?temp-*b:*b-temp;
    *b = final_;
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}