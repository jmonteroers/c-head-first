/*
This script transforms a CSV file, such as `gpsdata.csv` into a json file in stdout, such as `output.json`
*/

#include <stdio.h>


int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("[");

    // [^\n] meaning up to the end of the line; notice how scanf requires pointers
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if (started) {
            printf(",\n");
        } else {
            started = 1;
        }
        // check latitude
        if ((latitude < -90) || (latitude > 90)){
            fprintf(stderr, "Invalid latitude: %f. Exiting \n", latitude);
            return 2;
        }
        // check longitude
        if ((longitude < -180) || (longitude > 180)){
            fprintf(stderr, "Invalid longitude: %f. Exiting \n", longitude);
            return 2;
        }
        printf("{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\"}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}