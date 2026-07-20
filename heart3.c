#include <stdio.h>

int main() {
    int i, j;
    int height = 12;
    int width = 29;
    char text[] = "I'm Sorry";
    int textStart = 10;   // controls horizontal position of text
    int textRow = 5;      // controls vertical position of text

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            // 1️⃣ Print text FIRST (important)
            if (i == textRow && 
                j >= textStart && 
                j < textStart + 9) {

                printf("%c", text[j - textStart]);
            }

            // 2️⃣ Print heart border
            else if (
                (i == 0 && (j >= 4 && j <= 8 || j >= 20 && j <= 24)) ||
                (i == 1 && (j == 3 || j == 9 || j == 19 || j == 25)) ||
                (i >= 2 && i <= 5 && (j == 2 || j == 10 || j == 18 || j == 26)) ||
                (i >= 6 && i <= 10 && (j == i - 3 || j == width - (i - 2)))
            ) {
                printf("*");
            }

            // 3️⃣ Empty space inside
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}