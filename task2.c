#include <stdio.h>
#include <ctype.h>

int main(void) {
    double temp;
    char fromScale, toScale;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &fromScale);
    fromScale = (char)toupper((unsigned char)fromScale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &toScale);
    toScale = (char)toupper((unsigned char)toScale);

    if ((fromScale != 'C' && fromScale != 'F' && fromScale != 'K') ||
        (toScale != 'C' && toScale != 'F' && toScale != 'K')) {
        printf("Invalid scale entered. Please use C, F, or K.\n");
        return 1;
    }

    /* Reject physically impossible temperatures (below absolute zero) */
    if ((fromScale == 'K' && temp < 0.0) ||
        (fromScale == 'C' && temp < -273.15) ||
        (fromScale == 'F' && temp < -459.67)) {
        printf("Invalid temperature: value is below absolute zero.\n");
        return 1;
    }

    /* Convert input to Celsius as a common intermediate */
    double celsius;
    switch (fromScale) {
        case 'C': celsius = temp; break;
        case 'F': celsius = (temp - 32.0) * 5.0 / 9.0; break;
        case 'K': celsius = temp - 273.15; break;
        default:  celsius = temp; break;
    }

    /* Convert from Celsius to the requested target scale */
    double converted;
    switch (toScale) {
        case 'C': converted = celsius; break;
        case 'F': converted = celsius * 9.0 / 5.0 + 32.0; break;
        case 'K': converted = celsius + 273.15; break;
        default:  converted = celsius; break;
    }

    printf("Converted temperature: %.2f %c\n", converted, toScale);

    /* Categorize using the Celsius value regardless of target scale */
    const char *category;
    const char *advisory;
    if (celsius < 0.0) {
        category = "Freezing";
        advisory = "Bundle up, it's freezing outside!";
    } else if (celsius < 10.0) {
        category = "Cold";
        advisory = "Wear a warm jacket.";
    } else if (celsius < 25.0) {
        category = "Comfortable";
        advisory = "Enjoy the pleasant weather!";
    } else if (celsius < 35.0) {
        category = "Hot";
        advisory = "Drink lots of water!";
    } else {
        category = "Extreme Heat";
        advisory = "Stay indoors and stay hydrated!";
    }

    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}
