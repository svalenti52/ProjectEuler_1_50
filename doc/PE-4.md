## 4 Largest Palindrome Product

> A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
9009 = 91 x 99.

> Find the largest palindrome made from the product of two
3-digit numbers.

1. Set largest_palindrome to 0.
2. Loop over i from 100 to 999 inclusive.
	1. Loop over j from 100 to 999 inclusive.
		1. Set is_pal = i * j.
		2. Test for palindrome property of is_pal and if is_pal > largest_palindrome
			1. If test succeeds set largest_palindrome = is_pal.
3. Largest palindrome is contained in largest_palindrome.
