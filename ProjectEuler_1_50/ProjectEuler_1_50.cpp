// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "..\..\MonteCarlo\MonteCarlo\Chronology.h"
#include "three_or_five.h"
#include "fibonacci_even_sum.h"
#include "prime_factor.h"
#include "largest_palindrome_product.h"
#include "lcm_1_20.h"
#include "sum_square_diff.h"
#include "ith_prime.h"
#include "max_prod_13_adj.h"
#include "spec_pythag_triple.h"
#include "sum_primes_2M.h"
#include "max_prod_grid.h"
#include "triangle_nr_gt_500_div.h"
#include "large_sum.h"
#include "max_collatz.h"
#include "count_paths_thru_grid.h"
#include "two_pow_1000.h"
#include "four_digit_3_prime_seq.h"
#include "pandigital_largest_prime.h"
#include "sundays_first_of_month.h"
#include "prime_sum_lt_million.h"
#include "amicable.h"
#include "pandigital_multiples.h"
#include "primes_circular.h"
#include "letter_counts.h"
#include "name_score.h"
#include "lex_order.h"
#include "rational_expansion.h"
#include "spiral_diagonal.h"
#include "distinct_powers.h"
#include "digit_5_powers.h"
#include "coin_sums.h"
#include "digit_fractions.h"
#include "digit_factorial.h"
#include "double_base_palindromes.h"
#include "primes_truncatable.h"
#include "integer_right_triangles.h"
#include "champernownes.h"
#include "coded_triangle_numbers.h"
#include "substring_divisibility.h"
#include "pentagon_add_sub.h"
#include "tri_pen_hex.h"
#include "goldbach_other.h"
#include "prime_factors_4.h"
#include "self_powers.h"
#include "triangle_path_sum.h"
#include "non_abundant_sums.h"
#include "quadratic_primes.h"

using u64 = uint64_t;

int main()
{
	char c = '0';
	while (c != 'x')
	{
		std::cout << "\n1. Coin Sums";
		std::cout << "\n2. Digit Cancelling Fractions";
		std::cout << "\n3. Three or five sum";
		std::cout << "\n4. Fibonacci even numbers sum";
		std::cout << "\n5. Largest Prime Factor";
		std::cout << "\n6. Largest Palindrome Product of two 3-digit numbers";
		std::cout << "\n7. Smallest Number divisible by 1 throuh 20";
		std::cout << "\n8. Sum Square Difference";
		std::cout << "\n9. Get 10,001st Prime";
		std::cout << "\na. Maximum Product of 13 Adjacent Digits";
		std::cout << "\nb. Special Pythagorean Triple Product (based on sum = 1000)";
		std::cout << "\nc. Sum of Primes less that 2,000,000";
		std::cout << "\nd. Maximum Product from 4 Consecutive Elements in Grid";
		std::cout << "\ne. Least Triangle Number with over 500 Divisors";
		std::cout << "\nf. 10 Most Significant Digits of Large Sum";
		std::cout << "\ng. Maximum Collatz Sequence for Numbers < 1,000,000";
		std::cout << "\nh. Count Paths through 20x20 Grid";
		std::cout << "\ni. Two Power 1000 Sum Digits";
		std::cout << "\nj. Four Digit 3 Prime in Arithmetic Sequence";
		std::cout << "\nk. Largest Pandigital Prime";
		std::cout << "\nl. Number of Sundays 1st of Month during 20th Century";
		std::cout << "\nm. Longest Number of Primes Summing to Prime less that One Million";
		std::cout << "\nn. Amicable Numbers less than 10,000";
		std::cout << "\no. Pandigital Multiples";
		std::cout << "\np. Number of Circular Primes less than a million";
		std::cout << "\nq. Total Letter Count for 1-1000 inclusive";
		std::cout << "\nr. Name Score";
		std::cout << "\ns. Lex Order";
		std::cout << "\nt. Repeating Rational Expansion";
		std::cout << "\nu. Spiral Diagonal";
		std::cout << "\nv. Distinct Powers";
		std::cout << "\nw. Digit 5 Powers";
		std::cout << "\ny. Digit Factorial";
		std::cout << "\nz. Double Base Palindromes";
		std::cout << "\nA. Truncatable Primes";
		std::cout << "\nB. Integer Right Triangles";
		std::cout << "\nC. Champernowne's Constant";
		std::cout << "\nD. Coded Triangle Numbers";
		std::cout << "\nE. SubString Divisibility";
		std::cout << "\nF. Pentagon Add Sub";
		std::cout << "\nG. Tri-Pen-Hex";
		std::cout << "\nH. Goldbach's Other Conjecture";
		std::cout << "\nI. Four Consecutive Numbers with 4 Distinct Prime Factors";
		std::cout << "\nJ. Last 10 digits of self power series";
		std::cout << "\nK. Triangle Path Sum Max 1";
		std::cout << "\nL. Non-Abundant Sums";
		std::cout << "\nM. Quadratic Primes";
		std::cout << "\nx. Exit\n";

		std::cin >> c;

		switch (c)
		{
		case '1':
			// ID 31
			coin_sums();
			break;
		case '2':
			// ID 33
			digit_fractions();
			break;
		case '3':
			// ID 1
			three_or_five_sum_1();
			break;
		case '4':
			// ID 2
			fibo_even_sum_2();
			break;
		case '5':
			// ID 3
			largest_prime_factor_3();
			break;
		case '6':
			// ID 4
			std::cout << "Largest Palindrome that is a product of two 3 digit numbers = " << largest_pal_3x3_product() << '\n';
			break;
		case '7':
			// ID 5
			std::cout << "Smallest Number divisible by 1 through 20 = " << lcm_1_20() << '\n';
			break;
		case '8':
			// ID 6
			std::cout << "Sum Square Difference for 100 sequence = " << sum_sqr_diff(100) << '\n';
			break;
		case '9':
			// ID 7
			std::cout << "10,001st Prime = " << get_ith_prime(10'001) << '\n';
			break;
		case 'a':
			// ID 8
			std::cout << "Maximum Product of 13 Adjacent Digits = " << max_prod_13_adj() << '\n';
			break;
		case 'b':
			// ID 9
			std::cout << "Special Pythagorean Triple Product (based on sum = 1000) = " << special_pythagorean_triple(1000) << '\n';
			break;
		case 'c':
			// ID 10
			std::cout << "Sum of Primes less that 2,000,000 = " << sum_primes_lt_2M() << '\n';
			break;
		case 'd':
			// ID 11
			std::cout << "Maximum Product in Grid = " << max_prod_grid() << '\n';
			break;
		case 'e':
			// ID 12
		{
			auto [triangle_nr, count] = triangle_nr_gt_500_div();
			std::cout << "Triangle Number Divisor Count = " << count << "  for number " << triangle_nr << '\n';
		}
		break;
		case 'f':
			// ID 13
			most_significant_10_digits();
			break;
		case 'g':
			// ID 14
			max_collatz_sequence_at();
			break;
		case 'h':
			// ID 15
		{
			StopWatch s;
			traverse_grid(0, 0);
			show_grid_count();
			s.stop();
		}
		break;
		case 'i':
			// ID 16
			two_to_1000_digit_sum();
			break;
		case 'j':
			// ID 49
			four_digit_3_prime_seq();
			break;
		case 'k':
			// ID 41
			pandigital_largest_prime();
			break;
		case 'l':
			// ID 19
			sundays_1st_of_month_century20();
			break;
		case 'm':
			// ID 50
			prime_sum_lt_million();
			break;
		case 'n':
			// ID 21
			amicable_lt_10000();
			break;
		case 'o':
			// ID 38
			pandigital_multiples();
			break;
		case 'p':
			// ID 35
			primes_circular();
			break;
		case 'q':
			// ID 17
			letter_counts();
			break;
		case 'r':
			// ID 22
			token_example();
			break;
		case 's':
			// ID 24
			lex_order();
			break;
		case 't':
			// ID 26
			rational_expansion();
			break;
		case 'u':
			// ID 28
			spiral_diagonal();
			break;
		case 'v':
			// ID 29
			distinct_powers();
			break;
		case 'w':
			// ID 30
			digit_5_powers();
			break;
		case 'y':
			// ID 34
			digit_factorial();
			break;
		case 'z':
			// ID 36
			double_base_palindromes();
			break;
		case 'A':
			// ID 37
			truncatable_primes();
			break;
		case 'B':
			// ID 39
			integer_right_triangles();
			break;
		case 'C':
			champernownes();
			break;
		case 'D':
			// ID 42
			coded_triangle_numbers();
			break;
		case 'E':
			substring_divisibility();
			break;
		case 'F':
			pentagon_add_sub();
			break;
		case 'G':
			tri_pen_hex();
			break;
		case 'H':
			goldback_other();
			break;
		case 'I':
			prime_factors_4();
			break;
		case 'J':
			self_powers();
			break;
		case 'K':
			// ID 18
			max_sum_path();
			break;
		case 'L':
			// ID 23
			non_abundant_sums();
			break;
		case 'M':
			// ID 
			longest_sequence_primes();
			break;
		case 'x':
			break;
		default:
			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
