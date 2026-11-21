#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::random_device, std::mt19937

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1. Obtain a random seed from the hardware
    std::random_device rd;

    // 2. Seed the Mersenne Twister generator
    std::mt19937 gen(rd());

    // 3. Shuffle the container in-place
    std::shuffle(numbers.begin(), numbers.end(), gen);

    for (int n : numbers) {
        std::cout << n << " ";
    }
    return 0;
}
