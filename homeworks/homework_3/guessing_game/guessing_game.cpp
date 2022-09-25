#include <iostream>
#include <random>
#include <vector>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  cout << "Welcome to the GUESSING GAME!" << endl;
  cout << "I will generate a number and you will guess it!" << endl;

  // ask for user inputs
  int min = 0;
  int max = 100;
  cout << "Please provide the smallest number: ";
  cin >> min;
  cout << "Please provide the largest number: ";
  cin >> max;

  // generating random number
  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_int_distribution<int> uniform(min, max);
  float number = 0;
  number = uniform(random_engine);
  cout << "I've generated a number. Try to guess it!" << endl;

  // Ask for user guess and check
  int guess = 0;
  int tentatives = 0;
  while (true) {
    tentatives++;
    cout << "Please provide the next guess: ";
    cin >> guess;
    if (guess < number) {
      cout << "Your number is too small. Try again!" << endl;
    } else if (guess > number) {
      cout << "Your number is too big. Try again!" << endl;
    } else if (guess == number) {
      cout << "You've done it! You guessed the number " << number << " in "
           << tentatives << " guesses !" << endl;
      break;
    }
  }
}