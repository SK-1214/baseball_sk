#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, TryGame) {
	EXPECT_EQ(1, 1);
	EXPECT_EQ(1, 1);
	EXPECT_EQ(1, 1);
	EXPECT_EQ(2, 2);
	EXPECT_EQ(2, 2);
	EXPECT_EQ(2, 2);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
