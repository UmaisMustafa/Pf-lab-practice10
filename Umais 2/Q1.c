#include <stdio.h>
#include <stdlib.h>


struct Box {
    int weight; 
    int isItem; 
    struct Box** contents; 
    int contentCount; 
};


int calculateTotalWeight(struct Box* box) {
   
    if (box->isItem) {
        return box->weight;
    }

    
    int totalWeight = 0;
    for (int i = 0; i < box->contentCount; i++) {
        totalWeight += calculateTotalWeight(box->contents[i]);
    }

    return totalWeight;
}

int main() {
    
    struct Box box1 = {10, 1, NULL, 0}; 
    struct Box box2 = {5, 1, NULL, 0};  

   
    struct Box* contents[] = {&box1, &box2};

   
    struct Box box3 = {0, 0, contents, 2};

    printf("Total weight of box3: %d\n", calculateTotalWeight(&box3)); 

    return 0;
}

