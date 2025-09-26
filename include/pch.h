//
// Created by Hosea on 9/21/2025.
//

#ifndef DIVINITYENGINE_PCH_H
#define DIVINITYENGINE_PCH_H
#include <string>
#include <cassert>

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define NOMINMAX
    #define UNICODE
    #define _UNICODE

#include <windows.h>
#include "Platforms/Windows/Win32/helpers.h"

#endif


#endif //DIVINITYENGINE_PCH_H