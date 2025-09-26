//
// Created by Hosea on 9/23/2025.
//

#pragma once
#include "LogicalInputDevice.h"
#include "../Math/Position2D.h"

enum class MouseButton {
    Right,
    Left,
    Middle,
    X1,
    X2,

    Count
};

namespace Core::Input {

    class Mouse final : public LogicalInputDevice<MouseButton> {
    public:
        Mouse() = default;
        ~Mouse() override = default;

        // Extra mouse-specific behavior
        [[nodiscard]] inline Position2D GetPosition() const { return _mousePosition; }
        void SetPosition(const Position2D& pos) { _mousePosition = pos; }

    private:
        Position2D _mousePosition{};
    };

} // namespace Core::Input
