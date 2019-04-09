package main

import (
	"math"
)

func getNumberFromChar(b byte) int {
	switch b {
	case ' ':
		return 0
	case '+':
		return 0
	case '-':
		return 0
	case '0':
		return 0
	case '1':
		return 1
	case '2':
		return 2
	case '3':
		return 3
	case '4':
		return 4
	case '5':
		return 5
	case '6':
		return 6
	case '7':
		return 7
	case '8':
		return 8
	case '9':
		return 9
	default:
		return -1
	}
}

func isNumber(b byte) bool {
	if getNumberFromChar(b) >= 0 {
		return true
	}
	return false
}

func myAtoi(str string) int {
	sum := 0
	isNegative := false
	isPositive := false
	s := []byte{}

	// filter
	for i := range str {
		if str[i] == ' ' {
			if len(s) > 0 {
				break
			}
			continue
		} else if str[i] == '-' || str[i] == '+' || isNumber(str[i]) {
			if str[i] == '-' {
				if len(s) > 0 {
					break
				}
				isNegative = true
			} else if str[i] == '+' {
				if len(s) > 0 {
					break
				}
				isPositive = true
			}
			if isNegative && isPositive {
				return 0
			}
			s = append(s, str[i])
		} else {
			break
		}
	}

	for i := range s {
		ch := s[i]

		nextNum := getNumberFromChar(ch)
		if sum == math.MaxInt32/10 {
			if isNegative && nextNum >= 8 {
				return -math.MaxInt32 - 1
			} else if !isNegative && nextNum >= 7 {
				return math.MaxInt32
			}
		} else if sum > math.MaxInt32/10 {
			if isNegative {
				return -math.MaxInt32 - 1
			} else {
				return math.MaxInt32
			}
		}
		sum = sum*10 + nextNum

	}

	if isNegative {
		return -1 * sum
	}

	return sum
}
