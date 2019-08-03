package main

import (
	"fmt"
)

func isPalindromeWithStringFormat(x int) bool {
	reversed := ""

	if x < 0 {
		return false
	}

	s, y := x, 0
	for {
		y = s % 10
		s = s / 10

		reversed += fmt.Sprintf("%d", y)

		if s == 0 {
			break
		}
	}

	if fmt.Sprintf("%d", x) == reversed {
		return true
	}

	return false
}

func isPalindrome(x int) bool {
	reversed := 0

	if x < 0 || (x >= 10 && x%10 == 0) {
		return false
	}

	for {
		y := x % 10
		x = x / 10

		reversed = reversed*10 + y

		if x <= reversed {
			break
		}
	}

	return reversed == x || reversed/10 == x
}

func main() {
	var a int
	fmt.Scan(&a)
	fmt.Println(isPalindrome(a))
}
