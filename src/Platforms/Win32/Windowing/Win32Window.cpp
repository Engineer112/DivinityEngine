//
// Created by Hosea on 9/20/2025.
//

#include "Platforms/Windows/Win32/Windowing/Win32Window.h"

#include "pch.h"

namespace Core::Windowing {

//------------------------------------------------------
// Constructor / Destructor
//------------------------------------------------------

Win32Window::Win32Window() {
    // TODO: figure out way for users to know when this fails
    assert(RegisterWindowClass());
}

Win32Window::~Win32Window() {
    if (ValidateHandle()) {
        DestroyWindow(_hWnd);
        _hWnd = nullptr;
    }
}

//------------------------------------------------------
// Window Class Registration (call once per app)
//------------------------------------------------------

bool Win32Window::RegisterWindowClass() {
    static bool registered = false;
    if (registered) return true;

    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;  // Or your custom WndProc
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = L"Win32Window";
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    registered = TryExecute(RegisterClass(&wc) != 0);
    return registered;
}

//------------------------------------------------------
// Creation / Destruction
//------------------------------------------------------
bool Win32Window::Create(const std::wstring& name, const int x, const int y, const int width, const int height) {
    if (ValidateHandle()) return false; // already created

    _hWnd = CreateWindowEx(
        0,                        // extended style
        L"Win32Window",           // class name
        name.c_str(),             // window title
        WS_OVERLAPPEDWINDOW,      // style
        x, y, width, height,      // position & size
        nullptr,                  // parent
        nullptr,                  // menu
        GetModuleHandle(nullptr), // instance
        nullptr                   // user data
    );

    return TryExecute(_hWnd != nullptr);
}

bool Win32Window::Close() {
    if (!ValidateHandle()) return false;
    // Proper Windows close sequence
    return TryExecute(PostMessage(_hWnd, WM_CLOSE, 0, 0));
}

bool Win32Window::Destroy() {
    if (!ValidateHandle()) return false;
    bool result = TryExecute(DestroyWindow(_hWnd));
    if (result) _hWnd = nullptr;
    return result;
}

//------------------------------------------------------
// Visibility
//------------------------------------------------------
bool Win32Window::Show() {
    if (!ValidateHandle()) return false;
    return TryExecute(ShowWindow(_hWnd, SW_SHOWNORMAL));
}

bool Win32Window::Hide() {
    if (!ValidateHandle()) return false;
    return TryExecute(ShowWindow(_hWnd, SW_HIDE));
}

//------------------------------------------------------
// Resize / Move
//------------------------------------------------------
bool Win32Window::Resize(const int width, const int height) {
    if (!ValidateHandle()) return false;

    RECT rc = {0, 0, width, height};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    return TryExecute(SetWindowPos(_hWnd, nullptr, 0, 0,
        rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER));
}

bool Win32Window::SetPosition(const int x, const int y) {
    if (!ValidateHandle()) return false;
    return TryExecute(SetWindowPos(_hWnd, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER));
}

//------------------------------------------------------
// Minimize / Maximize / Restore
//------------------------------------------------------
bool Win32Window::Minimize() {
    if (!ValidateHandle()) return false;
    return TryExecute(ShowWindow(_hWnd, SW_MINIMIZE));
}

bool Win32Window::Maximize() {
    if (!ValidateHandle()) return false;
    return TryExecute(ShowWindow(_hWnd, SW_MAXIMIZE));
}

bool Win32Window::Restore() {
    if (!ValidateHandle()) return false;
    return TryExecute(ShowWindow(_hWnd, SW_RESTORE));
}

} // namespace Core::Windowing


