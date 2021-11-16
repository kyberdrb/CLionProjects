#include <target/AbstractPlug.h>
#include <adaptee/AbstractSwitchBoard.h>
#include <adaptee/SwitchBoard.h>
#include <target/Plug.h>
#include <adapter/Adapter.h>
#include "gtest/gtest.h"

class ExampleTestSuite : public ::testing::Test {};

TEST(ExampleTestSuite, adapt_plug_to_switchboard) {
    std::unique_ptr<AbstractSwitchBoard> switchBoard(new SwitchBoard());
    std::unique_ptr<AbstractPlug> plug(new Plug());
    std::unique_ptr<Adapter> adapter(new Adapter(*switchBoard));

    EXPECT_EQ(switchBoard->pinCount(), adapter->pinCount());
    EXPECT_EQ(switchBoard->flatPin(), adapter->roundPin());
}