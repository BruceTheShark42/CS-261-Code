#include <iostream>
#include <limits>

constexpr unsigned int errorPhraseCount = 5;
constexpr const char* errorPhrases[errorPhraseCount]
{
	"That wasn't a number!\n",
	"C'mon man, you're not making this easy on me. :(\n",
	"If you keep doing this... I will have no choice but to remove you... >:( \n",
	"This is your final warning.\n",
	"Good riddance.\n"
};

constexpr unsigned int normalPhraseCount = 11;
constexpr const char* normalPhrases[normalPhraseCount]
{
	"Thank you for choosing a valid number. Not very many people do. :)\n",
	"Wow, you did it again? Awesome!\n",
	"I have no words to describe how much this means to me.\n",
	"I can't take this much positivity, it's making me too happy. :)))))))))\n",
	"Please, no more.\n",
	"That's enough.\n",
	"No, don't, just stop.\n",
	"I don't know what to do.\n",
	"Carrie, my wife, I'm sorry, but I won't be coming home for dinner.\n",
	"aaaaaaaaaaAAaaaAAAaAAAAaaAAaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA---\n",
	"what have you done...\n"
};

int main()
{
	bool running = true;
	unsigned int errorCount = 0;
	unsigned int normalCount = 0;


	while (running)
	{
		// The entity, as I'm calling it, has no control
		// over any code, but if they did and you weren't
		// entering numbers, they would disable this line.
		std::cout << "Enter a number: ";
		double number;
		std::cin >> number;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			std::cout << errorPhrases[errorCount++];
			if (errorCount == errorPhraseCount)
				running = false;
			if (normalCount != 0)
				normalCount--;
		}
		else if (errorCount != errorPhraseCount)
		{
			std::cout << normalPhrases[normalCount++];
			if (normalCount == normalPhraseCount)
				running = false;
			if (errorCount != 0)
				errorCount--;
		}
	}

	return 0;
}
