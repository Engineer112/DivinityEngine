//
// Created by Hosea on 9/24/2025.
//

#include <gtest/gtest.h>
#include "../include/Core/Input/Mouse.h"

using namespace Core::Input;

class MouseTest : public ::testing::Test {
protected:
    Mouse mouse;

    void press(MouseButton button) { mouse.SetState(button, true); }
    void release(MouseButton button) { mouse.SetState(button, false); }
    void nextFrame() { mouse.NextFrame(); }
};

// --- Button State -------------------------------------------------

TEST_F(MouseTest, ButtonIsUpByDefault) {
    EXPECT_FALSE(mouse.GetState(MouseButton::Left));
}

TEST_F(MouseTest, PressingButtonSetsStateDown) {
    press(MouseButton::Left);

    EXPECT_TRUE(mouse.GetState(MouseButton::Left));
}

TEST_F(MouseTest, ReleasingButtonSetsStateUp) {
    press(MouseButton::Left);
    release(MouseButton::Left);

    EXPECT_FALSE(mouse.GetState(MouseButton::Left));
}

// --- WasPressed / WasReleased -------------------------------------

TEST_F(MouseTest, WasPressedTriggersOnlyOnTransition) {
    press(MouseButton::Left);
    EXPECT_TRUE(mouse.WasPressed(MouseButton::Left));

    nextFrame();
    press(MouseButton::Left); // still down
    EXPECT_FALSE(mouse.WasPressed(MouseButton::Left));
}

TEST_F(MouseTest, WasReleasedTriggersOnlyOnTransition) {
    press(MouseButton::Left);
    nextFrame();

    release(MouseButton::Left);
    EXPECT_TRUE(mouse.WasReleased(MouseButton::Left));

    nextFrame();
    release(MouseButton::Left); // still up
    EXPECT_FALSE(mouse.WasReleased(MouseButton::Left));
}

// --- Multiple Buttons ---------------------------------------------

TEST_F(MouseTest, ButtonsAreIndependent) {
    press(MouseButton::Left);
    press(MouseButton::Right);

    EXPECT_TRUE(mouse.GetState(MouseButton::Left));
    EXPECT_TRUE(mouse.GetState(MouseButton::Right));

    nextFrame();
    release(MouseButton::Left);
    press(MouseButton::Right);

    EXPECT_FALSE(mouse.GetState(MouseButton::Left));
    EXPECT_TRUE(mouse.GetState(MouseButton::Right));
}

// --- Mouse Position -----------------------------------------------

TEST_F(MouseTest, PositionIsSetAndRetrieved) {
    Position2D pos(100, 200);
    mouse.SetPosition(pos);

    auto result = mouse.GetPosition();
    EXPECT_EQ(result.x, 100);
    EXPECT_EQ(result.y, 200);
}
