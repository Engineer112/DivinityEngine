//
// Created by Hosea on 9/20/2025.
//

#ifndef DIVINITYENGINE_WIN32WINDOW_H
#define DIVINITYENGINE_WIN32WINDOW_H

#include "pch.h"


#include "../../../../Core/Windowing/IWindow.h"

namespace Core::Windowing {
    class Win32Window final : public Core::Windowing::IWindow {

    public:
        Win32Window();
        ~Win32Window() override;
        bool Create(const std::wstring &name, int x, int y, int width, int height) override;
        bool Close() override;
        bool Destroy() override;

        bool Show() override;
        bool Hide() override;

        bool Resize(int width, int height) override;

        bool SetPosition(int x, int y) override;

        bool Minimize() override;

        bool Maximize() override;

        bool Restore() override;

    private:
        HWND _hWnd = nullptr;

        [[nodiscard]] bool ValidateHandle() const { return _hWnd != nullptr; }

        static bool RegisterWindowClass();
    };
}

#endif //DIVINITYENGINE_WIN32WINDOW_H
