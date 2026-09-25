#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter -1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        if (score == -1) {
            break;
        }

        if (score < 0) {
            printf("Invalid score: a negative score is not allowed.\n\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        int found = 0;
        for (int a = 0; 8 * a <= score; a++) {                 /* TD + 2pt (8) */
            for (int b = 0; 8 * a + 7 * b <= score; b++) {     /* TD + FG (7) */
                for (int c = 0; 8 * a + 7 * b + 6 * c <= score; c++) { /* TD (6) */
                    int rem1 = score - 8 * a - 7 * b - 6 * c;
                    for (int d = 0; 3 * d <= rem1; d++) {       /* 3pt FG */
                        int rem2 = rem1 - 3 * d;
                        if (rem2 % 2 == 0) {
                            int e = rem2 / 2;                   /* Safety (2) */
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   a, b, c, d, e);
                            found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No possible combination of scoring plays for this score.\n");
        }

        printf("\n");
    }

    printf("Program terminated.\n");
    return 0;
}
