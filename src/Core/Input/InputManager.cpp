//
// Created by Hosea on 9/22/2025.
//

#include "Core/Input/InputManager.h"

namespace Core::Input {
    void InputManager::Update() {
        _keyBoard.NextFrame();
        _mouse.NextFrame();
    }
}
