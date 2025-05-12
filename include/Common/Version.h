//
// Created by joshua on 09/05/2025.
//

#ifndef SELECTOR_H
#define SELECTOR_H

#include <cstddef> /// for size_t

namespace ResumeEditor {

    /// The Version struct is used to carry around the major, minor and patch level.
    struct Version
    {
        unsigned major; //< The major version level.
        unsigned minor; //< The minor version level.
        unsigned patch; //< The patch level.
    };

    /// Get the Matrix library version information.
    const Version &getVersion();

    /// Immediately terminates the application with \p reason as the error message
    /// and the EXIT_FAILURE error code. It will also print the file name (\p
    /// fileName) and line number (\p lineNumber) that caused that application to
    /// exit.
    [[noreturn]] void die(const char *fileName, size_t lineNumber,
                          const char *reason);
} // ResumeEditor

#endif //SELECTOR_H
