//
// Created by Hosea on 9/24/2025.
//

#include "gtest/gtest.h"
#include "../include/Core/Input/KeyBoard.h"

using namespace Core::Input;


class KeyboardTest : public ::testing::Test {
protected:
    KeyBoard keyboard;

    void SetUp() override {
        // Each test starts with a fresh KeyBoard
    }

    void PressKey(KeyCode key) {
        keyboard.SetState(key, true);
    }

    void ReleaseKey(KeyCode key) {
        keyboard.SetState(key, false);
    }

    void NextFrame() {
        keyboard.NextFrame();
    }
};

// --- Basic State Tests ---

TEST_F(KeyboardTest, KeyStartsUp) {
    EXPECT_FALSE(keyboard.GetState(KeyCode::A));
    EXPECT_TRUE(keyboard.IsUp(KeyCode::A));
}

TEST_F(KeyboardTest, PressingKeyIsDetected) {
    PressKey(KeyCode::A);
    EXPECT_TRUE(keyboard.GetState(KeyCode::A));
    EXPECT_TRUE(keyboard.IsDown(KeyCode::A));
    EXPECT_FALSE(keyboard.IsUp(KeyCode::A));
}

// --- Frame Transition Tests ---

TEST_F(KeyboardTest, WasPressedTriggersOnce) {
    // Frame 1: press A
    PressKey(KeyCode::A);
    EXPECT_TRUE(keyboard.WasPressed(KeyCode::A));
    NextFrame();

    // Frame 2: keep A pressed
    PressKey(KeyCode::A);
    EXPECT_FALSE(keyboard.WasPressed(KeyCode::A)); // no longer "newly pressed"
}

TEST_F(KeyboardTest, WasReleasedTriggersOnce) {
    // Frame 1: press A
    PressKey(KeyCode::A);
    NextFrame();

    // Frame 2: release A
    ReleaseKey(KeyCode::A);
    EXPECT_TRUE(keyboard.WasReleased(KeyCode::A));
    NextFrame();

    // Frame 3: still released
    ReleaseKey(KeyCode::A);
    EXPECT_FALSE(keyboard.WasReleased(KeyCode::A));
}

// --- Multiple Keys ---

TEST_F(KeyboardTest, MultipleKeysIndependent) {
    PressKey(KeyCode::A);
    PressKey(KeyCode::B);

    EXPECT_TRUE(keyboard.GetState(KeyCode::A));
    EXPECT_TRUE(keyboard.GetState(KeyCode::B));

    NextFrame();

    ReleaseKey(KeyCode::A);
    PressKey(KeyCode::B);

    EXPECT_FALSE(keyboard.GetState(KeyCode::A));
    EXPECT_TRUE(keyboard.GetState(KeyCode::B));
}

// --- Edge Case ---

TEST_F(KeyboardTest, UnknownKeyIsAlwaysFalseUnlessSet) {
    EXPECT_FALSE(keyboard.GetState(KeyCode::Unknown));
    PressKey(KeyCode::Unknown);
    EXPECT_TRUE(keyboard.GetState(KeyCode::Unknown));
}