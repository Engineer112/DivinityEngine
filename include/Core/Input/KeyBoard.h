#pragma once
#include "../Input/LogicalInputDevice.h"

enum class KeyCode : int {
    Unknown = 0,
    A, B, C, D, // ...
    Count
};

namespace Core::Input {

    class KeyBoard : public LogicalInputDevice<KeyCode> {
    public:
        KeyBoard() = default;
        ~KeyBoard() override = default;

        // Inherits all behavior from LogicalInputDevice
    };

}