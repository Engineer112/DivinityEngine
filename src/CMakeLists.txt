# List all source files manually (paths relative to src/)
set(SRC_FILES
        #abstractions
        Core/Input/InputManager.cpp
        Core/Windowing/IMessageQueue.cpp

        #windows implementation
        Platforms/Win32/Windowing/Win32Window.cpp
        # add more as needed
)

add_library(DivinityEngine STATIC ${SRC_FILES})

target_include_directories(DivinityEngine
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)