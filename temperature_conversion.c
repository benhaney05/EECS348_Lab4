#include <stdio.h>
#include <math.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return (celsius + 273.15);
}

float kelvin_to_celsius(float kelvin) {
    return (kelvin - 273.15);
}

float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

void categorize_temperature(float celsius) {
    if (celsius < 0.0) {
        printf("Temperature category: Freezing\n");
        printf("Consider staying inside.\n");
    } else if (celsius < 10.0) {
        printf("Temperature category: Cold\n");
        printf("Wear a jacket.\n");
    } else if (celsius < 25.0) {
        printf("Temperature category: Comfortable\n");
        printf("You should be comfortable.\n");
    } else if (celsius < 35.0) {
        printf("Temperature category: Hot\n");
        printf("Wear some shorts.\n");
    } else if (celsius > 35.0) {
        printf("Temperature category: Extreme Heat\n");
        printf("Don't be out for long.\n");
    }
}

int main() {
    float value, new_temp, c;
    int scale, target;

    printf("Enter the temperature: ");
    scanf("%f", &value);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target);

    if (scale == 1 && target == 2) {
        new_temp = celsius_to_fahrenheit(value);
        c = value;
    } else if (scale == 1 && target == 3) {
        new_temp = celsius_to_kelvin(value);
        c = value;
    } else if (scale == 2 && target == 1) {
        new_temp = fahrenheit_to_celsius(value);
        c = new_temp;
    } else if (scale == 2 && target == 3) {
        new_temp = fahrenheit_to_kelvin(value);
        c = fahrenheit_to_celsius(value);
    } else if (scale == 3 && target == 1) {
        new_temp = kelvin_to_celsius(value);
        c = new_temp;
    } else if (scale == 3 && target == 2) {
        new_temp = kelvin_to_fahrenheit(value);
        c = kelvin_to_celsius(value);
    } else {
        printf("Invalid conversion choice\n");
        return 0;
    }

    printf("Converted temperature: %f\n", new_temp);
    categorize_temperature(c);

    return 0;


}