#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    float x, y;
    char text[] = "I'm Sorry";
    int textLen = strlen(text);

    for (y = 1.5; y > -1.5; y -= 0.08) {
        for (x = -1.5; x < 1.5; x += 0.04) {

            float eq = pow(x*x + y*y - 1, 3) - x*x*y*y*y;

            // Border thickness control
            if (eq <= 0 && eq > -0.02) {
                printf("*");   // Only print border
            }
            else if (y > -0.1 && y < 0.1 && x > -0.7 && x < 0.7) {
                // Print text inside hollow area
                int index = (int)((x + 0.7) * textLen / 1.4);
                if (index >= 0 && index < textLen)
                    printf("%c", text[index]);
                else
                    printf(" ");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}