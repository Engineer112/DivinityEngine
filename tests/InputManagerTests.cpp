//
// Created by Hosea on 9/25/2025.
//

#include "gtest/gtest.h"
#include "../include/Core/Input/InputManager.h"

using namespace Core::Input;


class InputManagerTest : public ::testing::Test {
public:
    void SetUp() override {

    }

};

TEST_F(InputManagerTest, CanRetriveKeyboard) {
    InputManager manager;

    EXPECT_EQ(typeid(manager.GetKeyBoard()), typeid(KeyBoard));
}

TEST_F(InputManagerTest, RetrivesMoase) {
    InputManager manager;

    EXPECT_EQ(typeid(manager.GetMouse()), typeid(Mouse));
}

TEST_F(InputManagerTest, UpdatesDevicesCorrectly) {
    InputManager manager;

    manager.GetKeyBoard().SetState(KeyCode::A, true);
    manager.GetMouse().SetState(MouseButton::Middle, true);

    EXPECT_EQ(manager.GetKeyBoard().GetState(KeyCode::A), true);
    EXPECT_EQ(manager.GetMouse().GetState(MouseButton::Middle), true);

    manager.Update();

    EXPECT_EQ(manager.GetMouse().GetState(MouseButton::Middle), false);
    EXPECT_EQ(manager.GetKeyBoard().GetState(KeyCode::A), false);
}