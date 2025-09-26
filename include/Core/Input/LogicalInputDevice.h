//
// Created by Hosea on 9/24/2025.
//

#pragma once
#include <bitset>

namespace Core::Input {

    template<typename TEnum>
    class LogicalInputDevice {
    public:
        LogicalInputDevice() = default;
        virtual ~LogicalInputDevice() = default;

        // --- Query functions ---
        inline bool GetState(TEnum input) const {
            return _states[_currentIndex].test(static_cast<int>(input));
        }

        inline bool WasPressed(TEnum input) const {
            return _states[_currentIndex].test(static_cast<int>(input)) &&
                   !_states[_previousIndex].test(static_cast<int>(input));
        }

        inline bool WasReleased(TEnum input) const {
            return !_states[_currentIndex].test(static_cast<int>(input)) &&
                   _states[_previousIndex].test(static_cast<int>(input));
        }

        inline bool IsDown(TEnum input) const { return GetState(input); }
        inline bool IsUp(TEnum input) const { return !GetState(input); }

        // --- Update functions ---
        inline void SetState(TEnum input, bool pressed) {
            _states[_currentIndex].set(static_cast<int>(input), pressed);
        }

        // Call at the start of each frame
        virtual void NextFrame() {
            std::swap(_currentIndex, _previousIndex);
            _states[_currentIndex].reset(); // clear current
        }

    protected:
        std::bitset<static_cast<int>(TEnum::Count)> _states[2];
        int _currentIndex = 0;
        int _previousIndex = 1;
    };

} // namespace Core::Input
