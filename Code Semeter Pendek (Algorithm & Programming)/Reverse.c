#include <stdio.h>
#include <string.h>

void reverseStr(char* str, int awal, int akhir) { // Recursive function untuk membalikkan string
    if (awal >= akhir) { // Best case: jika awal >= akhir, berarti string sudah dibalik
        return;
    }

    char temp = str[awal];
    str[awal] = str[akhir];
    str[akhir] = temp;

    reverseStr(str, awal + 1, akhir - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        char str[1001];
        scanf("%s", str);
        int len = strlen(str);

        reverseStr(str, 0, len - 1);
        
        printf("Case #%d: %s\n", i, str); // Print result
    }
    
    return 0;
}