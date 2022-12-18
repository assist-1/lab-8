#include <cmath>
#include <iostream>
#include <vector>

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
            if (i >= n) primes[i - n] = false;
	}
	
	return primes;
}

bool is_suitable(int n, std::vector<bool>& primes, uint64_t lower_border, uint64_t prev_n = 0) {
        if (!primes[n - lower_border]) return false;

        int line = get_line_number(n);
        bool is_first = n == get_first_number_in_line(line); 
        bool is_last = n == (get_first_number_in_line(line + 1) - 1); 
        bool is_near_last = n == (get_first_number_in_line(line + 1) - 2); 
        int delta_prev = 0;

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
                if (primes[n - delta - lower_border] && n - delta != prev_n) {
                    if (delta_prev) return true;
                    if (prev_n) return true;
                    delta_prev = delta;
                    }
                }

        if (!delta_prev) return false;
        else return is_suitable(n - delta_prev, primes, lower_border, n);
}

uint64_t B(int n) {
    uint64_t result = 0;
	uint64_t lower_border = get_first_number_in_line(n - 2);
        uint64_t top_border = get_first_number_in_line(n + 3) - 1;
        std::vector<bool> primes = eratosthenes(lower_border, top_border);

        for (uint64_t i = get_first_number_in_line(n); i < get_first_number_in_line(n + 1); ++i) {
                if (is_suitable(i, primes, lower_border)) {
                        result += i;
                }
        }
    return result;
}

int main() {
    int n1 = 5678027;
    int n2 = 7208785;
    uint64_t b_n1 = B(n1);
    uint64_t b_n2 = B(n2);
    std::cout << b_n1 + b_n2 << std::endl;
    return 0;
}

