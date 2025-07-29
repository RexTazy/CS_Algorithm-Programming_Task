#include <stdio.h>

union convert {
    unsigned int number;
    struct {
        unsigned int unit0 : 4;
        unsigned int unit1 : 4;
        unsigned int unit2 : 4;
        unsigned int unit3 : 4;
        unsigned int unit4 : 4;
        unsigned int unit5 : 4;
        unsigned int unit6 : 4;
        unsigned int unit7 : 4;
    } bits;
};

char toHex(int unit) {
    return (unit < 10) ? '0' + unit : 'A' + unit - 10;
}

int main() {
    union convert converter;
    
    printf("Enter unsigned integer: ");
    scanf("%u", &converter.number);
    
    printf("Hexadecimal: 0x");
    printf("%c", toHex(converter.bits.unit7));
    printf("%c", toHex(converter.bits.unit6));
    printf("%c", toHex(converter.bits.unit5));
    printf("%c", toHex(converter.bits.unit4));
    printf("%c", toHex(converter.bits.unit3));
    printf("%c", toHex(converter.bits.unit2));
    printf("%c", toHex(converter.bits.unit1));
    printf("%c", toHex(converter.bits.unit0));
    printf("\n");
    
    return 0;
}