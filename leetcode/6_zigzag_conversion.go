package main

import (
	"fmt"
)

func convert(s string, numRows int) string {
	var sBytes []byte

	if len(s) <= 1 || numRows <= 1 {
		return s
	}

	for n := 0; n < numRows; n++ {
		for i, index := 0, 0; ; i++ {
			if i == 0 {
				index = n
			} else {
				if i%2 == 0 {
					index = index + 2*n
					if n == 0 && i != 0 {
						continue
					}
				} else {
					index = index + 2*(numRows-n-1)
					if n == numRows-1 {
						continue
					}
				}
			}

			if index < len(s) {
				sBytes = append(sBytes, s[index])
			} else {
				break
			}
		}
	}

	return string(sBytes)
}

func main() {
	fmt.Println(convert("", 3))
}
