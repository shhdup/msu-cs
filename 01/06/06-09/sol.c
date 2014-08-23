#include<stdio.h>

int main(void) {
    FILE *bin = fopen("input.bin", "rb");
    FILE *bout = fopen("output.bin", "wb");
    unsigned char buff[4];
    int a[1000000];
    int n = 0;
    while (fread(buff, 4, 1, bin) != 0) {
        int cur = (buff[0]) | (buff[1] << 8) | (buff[2] << 16) | (buff[3] << 24);
        a[n++] = cur;
    }
    int le = 1;
    int ge = 1;
    for (int i = 1; i < n; ++i) {
        le &= (a[i] >= a[(i-1)/2]);
        ge &= (a[i] <= a[(i-1)/2]);
    }
    char LE[4] = "\x01\0\0\0";
    char GE[4] = "\xff\xff\xff\xff";
    char NO[4] = "\0\0\0\0";
    if (le) {
        fwrite(LE, sizeof(char), 4, bout);
    } else if (ge) {
        fwrite(GE, sizeof(char), 4, bout);
    } else {
        fwrite(NO, sizeof(char), 4, bout);
    }
    fclose(bin); fclose(bout);
    return 0;
}
