#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *deleted_data = fopen(argv[1], "r");
    int img_count = 0;
    BYTE buffer[512];
    FILE *img = NULL;
    char *filename = malloc(8);
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    while (fread(buffer, 1, 512, deleted_data) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img_count == 0)
            {
                sprintf(filename, "%03i.jpg", img_count);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                img_count++;
            }
            else if (img_count > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", img_count);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                img_count++;
            }
        }
        else if (img_count > 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    free(filename);
    fclose(deleted_data);
    fclose(img);
}
