// CE2.1. perror
#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("nonexistent.txt", "r");

    if (file == NULL) {
        perror("Error"); // Prints errno based error message
    }
    return 0;
}
