#include <cmath>
#include <iostream>
#include <vector>

uint64_t b_n = 0;

int get_line_number(uint64_t n) {
        return std::ceil((-1 + std::sqrt(1 + 8 * n)) / 2);
}

uint64_t get_first_number_in_line(int c) {
        return c * (c - 1) / 2 + 1;
}

std::vector<bool> eratosthenes(uint64_t n, uint64_t k) {
    std::vector<bool> primes(k - n, true);
	
	for (uint64_t p = 2; p * p <= k; p++) {
		for (uint64_t i = p * p; i <= k; i += p)
			primes[i - n] = false;
	}
	
	return primes;
}



bool is_suitable(int n, std::vector<bool>& primes, uint64_t first_number, int delta_prev = 0) {
        if (!primes[n - first_number]) return false;

        int line = get_line_number(n);
        bool is_first = n == get_first_number_in_line(line); 
        bool is_last = n == (get_first_number_in_line(line + 1) - 1); 
        bool is_near_last = n == (get_first_number_in_line(line + 1) - 2); 
 
        std::vector<int> deltas; 
        if (is_first) { 
                deltas = {line - 1, line - 2, -line, -line - 1}; 
        } else if (is_near_last) { 
                deltas = {line, line - 1, -line + 1, -line, -line - 1}; 
        } else if (is_last) {
                deltas = {line, -line + 1, -line, -line - 1};
        } else {
                deltas = {line, line - 1, line - 2, -line + 1, -line, -line - 1};
        }

        for (int delta: deltas) {
                if (primes[n - delta - first_number]) {
                        if (delta_prev and (n - delta != n - delta_prev)) {
				return true;}
                        delta_prev = delta;
                        }
                }
  
        if (!delta_prev) return false;
        else return is_suitable(n - delta_prev, primes, first_number, delta_prev);
}

void B(int n) {
	uint64_t lower_border = get_first_number_in_line(n - 2);
        uint64_t top_border = get_first_number_in_line(n + 3) - 1;
        std::vector<bool> primes = eratosthenes(lower_border, top_border);

        for (uint64_t i = get_first_number_in_line(n); i < get_first_number_in_line(n + 1); ++i) {
                if (is_suitable(i, primes, lower_border)) {
                        b_n += i;
                }
        }
}

int main() {
    int n;
	std::cin >> n;
    B(n);
    std::cout << b_n << std::endl;
	return 0;
}

