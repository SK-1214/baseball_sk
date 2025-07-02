#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();			
		}
		catch(exception e){

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedMatchNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strike);
	EXPECT_EQ(0, result.ball);
}

TEST_F(BaseballFixture, strike2ball1) {
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strike);
	EXPECT_EQ(1, result.ball);
}

TEST_F(BaseballFixture, strike1ball2) {
	GuessResult result = game.guess("145");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strike);
	EXPECT_EQ(2, result.ball);
}

TEST_F(BaseballFixture, strike0ball3) {
	GuessResult result = game.guess("456");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strike);
	EXPECT_EQ(3, result.ball);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
