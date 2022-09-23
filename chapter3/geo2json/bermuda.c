#include <stdio.h>

int main() 
{
    float latitude;
    float longitude;
    char info[80];
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        // if not on bermuda, skip
        if ((latitude <= 26) || (latitude >= 34)) {
            continue;
        }
        if ((longitude <= -76) || (longitude >= -64)) {
            continue;
        }
        printf("%f,%f,%s\n", latitude, longitude, info);
    }
}