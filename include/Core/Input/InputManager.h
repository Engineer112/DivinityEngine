//
// Created by Hosea on 9/22/2025.
//

#pragma once
#include "KeyBoard.h"
#include "Mouse.h"

namespace Core::Input {
    class InputManager {
    public:
        InputManager() = default;
        ~InputManager() = default;

        [[nodiscard]] KeyBoard& GetKeyBoard() { return _keyBoard; }
        [[nodiscard]] Mouse& GetMouse() { return _mouse; }
        void Update();
    private:
        // TODO: add dynamic device addition and detection when needed
        KeyBoard _keyBoard;
        Mouse _mouse;

        // TODO: add more input options when needed
        // TODO: add actions
    };
}