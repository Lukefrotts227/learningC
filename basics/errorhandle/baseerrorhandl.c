#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int divide(int a, int b) {
    if (b == 0) {
        errno = EDOM; // Division by zero error
        return -1;
    }
    return a / b;
}

int main() {
    int a = 10, b = 0, result;
    result = divide(a, b);
    if (result == -1) {
        perror("Error");
    } else {
        printf("Result: %d\n", result);
    }
    return 0;
}
