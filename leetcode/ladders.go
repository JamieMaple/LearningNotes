package main

import (
	"fmt"
)

func calculateLadders(n int) int {
	if n == 1 {
		return 1
	}

	if n == 1 {
		return 2
	}

	fi, fj := 1, 2

	for i := 3; i < n; i++ {
		temp := fi + fj
		fi = fj
		fj = temp
	}

	return fi + fj
}

func main() {
	n := 0
	fmt.Scan(&n)
	fmt.Println(calculateLadders(n))
}
