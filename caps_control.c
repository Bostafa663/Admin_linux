#include <stdio.h>
#include <stdlib.h>

int main() {
    // Path to the Caps Lock brightness control file
    const char *path = "/sys/class/leds/input1::capslock/brightness";

    // Open the file for writing
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Write "0" to turn off the Caps Lock LED
    if (fprintf(file, "0") < 0) {
        perror("Error writing to the file");
        fclose(file);
        return 1;
    }
    fclose(file);

    // Display the current contents of the file
    if (system("cat /sys/class/leds/input1::capslock/brightness") != 0) {
        perror("Error executing system command");
        return 1;
    }

    return 0;
}
