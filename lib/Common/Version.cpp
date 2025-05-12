//
// Created by joshua on 09/05/2025.
//

#include "../../include/Common/Version.h"

#include <iostream>

namespace
{
    constexpr ResumeEditor::Version version = {.major = 0, .minor = 1, .patch = 0};
}

namespace ResumeEditor {
    const Version &getVersion() { return version; }

    void die(const char *fileName, const size_t lineNumber, const char *reason)
    {
        std::cerr << "Fatal: " << reason << " from " << fileName << '.'
                  << lineNumber << 'n';
        std::exit(EXIT_FAILURE);
    }
} // SelComp