#include <stdio.h>
#include <stdint.h>

#define BASE_ADDR 0x404040

struct Data {
    char a[2][4];
    char *b;
    long c;
};

void dump(void *p, int n) {
    unsigned char *byte = (unsigned char *)p;
    for (int i = 0; i < n; i++) {
        printf("0x%016lx - %02X\n", (unsigned long)(BASE_ADDR + i), byte[i]);
    }
}

int main() {
    struct Data data = {0};
    short *ptr = (short*)&data;

    data.a[1][2] = 0xAA;

    data.b = (char*)(BASE_ADDR - 2);  // simula ponteiro como se fosse a+2

    data.c = (long)data.b ^ (long)ptr[3];  // igual à versão da prova

    dump(&data, sizeof(data));

    return 0;
}
