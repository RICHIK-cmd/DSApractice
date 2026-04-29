#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    float x, y;
    char text[] = "I'm Sorry";
    int textLen = strlen(text);

    for (y = 1.5; y > -1.5; y -= 0.1) {
        for (x = -1.5; x < 1.5; x += 0.05) {

            float equation = pow(x*x + y*y - 1, 3) - x*x*y*y*y;

            if (equation <= 0) {

                // Print text roughly in center
                if (y > -0.1 && y < 0.1 && x > -0.6 && x < 0.6) {
                    int index = (int)((x + 0.6) * textLen / 1.2);
                    if (index >= 0 && index < textLen)
                        printf("%c", text[index]);
                    else
                        printf(" ");
                } else {
                    printf("*");
                }

            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}