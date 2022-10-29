#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;
    // ":" means that d requires an argument
    // we can really tell that a string is an array of characters ...
    // in the third parameter
    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        switch (ch)
        {
        case 'd':
            // optarg represents the argument for d
            delivery = optarg;
            break;
        
        case 't':
            thick = 1;
            break;
        
        default:
            // commented out as does not print anything adequate
            // fprintf(stderr, "Unknown option: '%s'\n", optarg);
            return 1;
        }
    }
    // adjust command-line inputs. optind provided by unistd
    argc -= optind;
    argv += optind;

    if (thick)
        puts("Thick crust.");

    // the sentinel char must be falsey
    if (delivery[0])
        printf("To be delivered %s.\n", delivery);
    
    // use rest of arguments as ingredients
    puts("Ingredients:");

    for (count = 0; count < argc; count++) {
        puts(argv[count]);
    }
    return 0;
}