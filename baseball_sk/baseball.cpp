#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strike;
	int ball;
};

class Baseball {
public:
	explicit Baseball(const string &question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		
		assertIllegalArgument(guessNumber);

		GuessResult	result{ false,0,0 };

		int strike_count = 0;
		
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (guessNumber[i] == question[j]) {
					strike_count++;
				}
			}
		}

		if (strike_count == 3) result.solved = true;

		result.strike = strike_count;
		result.ball = 3 - strike_count;
		return result;
		/*
		for (char ch : guessNumber) {

		}
		if (guessNumber == question) {
			
			return { true, 3, 0 };
		}

		return { false, 0, 0 };
		*/
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;

			throw invalid_argument("must be number");
		}

		if (IsDuplicateNumber(guessNumber)) {
			throw invalid_argument("same number");
		}
	}
	bool IsDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[2] == guessNumber[1];
	}
private:
	string question;
};