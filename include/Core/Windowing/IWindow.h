//
// Created by Hosea on 9/20/2025.
//

#pragma once

#include "../Math/Rect.h"
#include "../Math/Position2D.h"
#include <string>

namespace Core::Windowing {
    class IWindow {
    public:
        IWindow();

        virtual ~IWindow();

        virtual bool Create(const std::wstring &name, int x, int y, int width, int height) = 0;
        virtual bool Close() = 0;
        virtual bool Destroy() = 0;

        virtual bool Show() = 0;
        virtual bool Hide() = 0;

        virtual bool Resize(int width, int height) = 0;
        virtual bool SetPosition(int x, int y) = 0;

        virtual bool Minimize() = 0;
        virtual bool Maximize() = 0;
        virtual bool Restore() = 0;

    private:
        Rect _rect;
        Position2D _position;
    };
}