#include <stdio.h>

int maxPieces(int ropeLength) {
    if (ropeLength == 0) {
        return 0;
    }
    
    if (ropeLength < 0) {
        return -1;
    }

    
    int cut1 = maxPieces(ropeLength - 1);
    int cut2 = maxPieces(ropeLength - 2);
    int cut3 = maxPieces(ropeLength - 3);

    
    int maxCut = (cut1 > cut2 ? cut1 : cut2);
    maxCut = (maxCut > cut3 ? maxCut : cut3);

    
    if (maxCut >= 0) {
        return maxCut + 1;
    }
    
   
    return -1;
}

int main() {
    int ropeLength = 5;
    printf("Maximum number of pieces for rope of length %d: %d\n", ropeLength, maxPieces(ropeLength));
    return 0;
}

