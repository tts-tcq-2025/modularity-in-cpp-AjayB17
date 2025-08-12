#include "TelCoColorCoder.h"
#include <stdexcept>

namespace TelCoColorCoder {

    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };

    ColorPair::ColorPair(MajorColor major, MinorColor minor)
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() const {
        return minorColor;
    }

    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if (pairNumber < 1 || pairNumber > numberOfMajorColors * numberOfMinorColors) {
            throw std::out_of_range("Invalid pair number");
        }
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor major = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(major, minor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        if (major < 0 || major >= numberOfMajorColors || minor < 0 || minor >= numberOfMinorColors) {
            throw std::out_of_range("Invalid color");
        }
        return major * numberOfMinorColors + minor + 1;
    }

}
