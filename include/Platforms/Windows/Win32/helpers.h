//
// Created by Hosea on 9/21/2025.
//

#ifndef DIVINITYENGINE_HELPERS_H
#define DIVINITYENGINE_HELPERS_H

#include <windows.h>

inline bool TryExecute(const bool operation) {
    if (!operation) {
        // TODO: add Logging
        return false;
    }
    return true;
}


#endif //DIVINITYENGINE_HELPERS_H