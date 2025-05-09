//
// Created by joshua on 09/05/2025.
//

#include "Selector/Selector.h"

#include <iostream>

namespace
{
    constexpr SelComp::Version version = {.major = 0, .minor = 1, .patch = 0};
}

namespace SelComp {
    const Version &getVersion() { return version; }

    void die(const char *fileName, const size_t lineNumber, const char *reason)
    {
        std::cerr << "Fatal: " << reason << " from " << fileName << '.'
                  << lineNumber << 'n';
        std::exit(EXIT_FAILURE);
    }
} // SelComp