//
// Created by joshua on 09/05/2025.
//

#include "Selector/Selector.h"

#include <cstdlib>
#include <iostream>

using namespace std;
using namespace SelComp;

int main() {
    const Version &version = getVersion();
    cout << "Using Matrix version: " << version.major << '.' << version.minor
         << '.' << version.patch << '\n';

    return EXIT_SUCCESS;
}
