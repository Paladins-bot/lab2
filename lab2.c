#include <stdio.h>
#include <stdlib.h>

int palindrome(int num, int original, int reversed) {
    if (num == 0) {
        return original == reversed;
    }
    return palindrome(num / 10, original, reversed * 10 + num % 10);
}

void checkRange(int start, int end, int first) {
    if (start > end) {
        return;
    }
    
    if (palindrome(start, start, 0)) {
        if (!first) {
            printf(" ");
        }
        printf("%d", start);
        first = 0;
    }
    
    checkRange(start + 1, end, first);
}

int main() {
    int N, M;
    
    printf("Введите два натуральных числа N и M: ");
    scanf("%d %d", &N, &M);
    
    if (N <= 0 || M <= 0) {
        printf("Ошибка: Числа должны быть натуральными.\n");
        return 1;
    }
    
    if (N > M) {
        printf("Ошибка: N должно быть меньше или равно M.\n");
        return 1;
    }
    
    printf("Палиндромы в диапазоне [%d, %d]: ", N, M);
    checkRange(N, M, 1);
    printf("\n");
    
    return 0;
}