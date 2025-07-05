#include <stdio.h>
#include <stdint.h>

// Define packed frame structure
typedef struct {
    uint8_t head;
    uint8_t data[2];
    uint8_t tail;
} __attribute__((packed)) frame_t;

// Reverse byte order (32-bit)
uint32_t revBytes(uint32_t x) {
    return ((x & 0x000000FF) << 24) |
           ((x & 0x0000FF00) << 8)  |
           ((x & 0x00FF0000) >> 8)  |
           ((x & 0xFF000000) >> 24);
}

// Check if frame head/tail match expected values and extract data
int checkData(const uint32_t* x, frame_t* f) {
    f->head = (*x >> 24) & 0xFF;
    f->tail = (*x) & 0xFF;

    if (f->head == 0xFE && f->tail == 0xFF) {
        f->data[0] = (*x >> 16) & 0xFF; // Age
        f->data[1] = (*x >> 8) & 0xFF;  // Status
        printf("Head & Tail matched\n");
        return 0;
    }

    printf("Head & Tail match fail\n");
    return 1;
}

int main() {
    const uint32_t hex = 0xFF0119FE;
    uint32_t revHex = revBytes(hex);
    frame_t hexStruct;

    printf("Reversed Data: 0x%08X\n", revHex);

    if (!checkData(&revHex, &hexStruct)) {
        printf("Age: %d\n", hexStruct.data[0]);
        printf("Status: %d\n", hexStruct.data[1]);
    }

    return 0;
}
