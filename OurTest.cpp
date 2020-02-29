/**
 * Bull Pgia Competition
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"

using namespace bullpgia;

RandomChooser randy;
SmartGuesser smarty;

int score_per_length(int length) {
	const int max_moves = 999;
	cout << "Playing at length " << length << " for " << max_moves << " moves" << endl;
	int sum = 0;
	for (uint i=0; i<100; ++i) {
		int score_per_game = play(randy, smarty, length, max_moves);
		std::cout << "score: " << score_per_game << std::endl;
		sum += score_per_game;
	}
	return sum;
}

int main() {
	int score = 0;
	badkan::TestCase testcase;
	int signal = setjmp(badkan::longjmp_buffer);
	srand(235+47+345+26483+2345+12498537);
	if (signal == 0) {
		score += score_per_length(10);
		score += score_per_length(7);
		score += score_per_length(4);
		score += score_per_length(3);
	} else {
		testcase.print_signal(signal);
		score = 999999999;
	}
	cout << "Your score: " << score << endl;
  cout <<  score << " " << "asdfasdghw54yj344lj6h" << endl;
	return 0;
}
