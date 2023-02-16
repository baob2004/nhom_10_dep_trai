#include <stdio.h>
#include <conio.h>

void Into_bit(int *a, int n);

int main(){
    int a[100];
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    Into_bit(a, n);
    getch();
}

void Into_bit(int *a, int n){
    int dem = 0;
    for(int i = 0; n > 0; i++){
        a[i] = n%2;
        n/=2;
        if(n>0) dem++;
    }
    for(int i = 0; i <= dem/2; i++){
        int t = a[i];
            a[i] = a[dem - i];
            a[dem - i] = t;
    }
    for(int i = 0; i <= dem; i++){
        printf("%d ", a[i]);
    }
}