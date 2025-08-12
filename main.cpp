#include <iostream>
#include <cassert>
#include "TelCoColorCoder.h"

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
