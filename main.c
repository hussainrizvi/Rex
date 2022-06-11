#define LINE_WIDTH 16

#include <stdio.h>


int main(int argc, char *argv[]) {
    
    if (argc == 1) {
        printf("Please enter the name of the file.\nUsage Example: rex {filename}\n\n");
        return 0;
    }

    
    char *name = argv[1];
    FILE* file = fopen(name, "rb");

    int c = 0;
    int col_number = 0;
    int arr[LINE_WIDTH] = {0};

    printf("\n%12s", "");
    for (int i = 0; i < 16; i++)
        printf("%02X ", i);
    printf(" Decoded Text\n");
   
    while ((c = getc(file)) != EOF) {
        if ((col_number++ % LINE_WIDTH) == 0) {
            printf("\n 0x%08X ", col_number - 1);
        }

        arr[(col_number - 1) % LINE_WIDTH] = c;
        printf("%02X ", c);

        if ((col_number % LINE_WIDTH) == 0) {
            printf("  ");
            for (int i = 0; i < LINE_WIDTH; i++) {
                if (arr[i] == 0x0d || arr[i] == 0x0a || arr[i] == 0x0b)
                    printf("  ");
                else
                    printf("%c ", arr[i]);
            }
        }
    }

    fclose(file);
    printf("\n File Size: %d KB\n", col_number/1000);
}