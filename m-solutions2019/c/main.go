package main

import (
	"fmt"
)

const (
	mod = 1000000007
)

func pow(x, y int64) int64 {
	if y == 0 {
		return 1
	}
	if y == 1 {
		return x
	}
	if y%2 == 0 {
		x2 := x * x % mod
		return pow(x2, y/2) % mod
	}
	return x * pow(x, y-1) % mod
}

func divide(x, y int64) int64 {
	return x * pow(y, mod-2) % mod
}

func main() {
	var n, a, b, c int64
	fmt.Scan(&n)
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	x := make([]int64, n)
	y := make([]int64, n)

	var expected int64
	for i := int64(0); i < n; i++ {
		if i == 0 {
			x[i] = 1
			y[i] = 1
		} else {
			x[i] = x[i-1] * (n - 1 + i) % mod
			y[i] = y[i-1] * i % mod
		}
		comb := divide(x[i], y[i])

		anp := pow(divide(a, a+b), n) * pow(divide(b, a+b), i) % mod
		anp = anp * comb % mod
		anp = anp * (n + i) % mod
		bnp := pow(divide(b, a+b), n) * pow(divide(a, a+b), i) % mod
		bnp = bnp * comb % mod
		bnp = bnp * (n + i) % mod
		x := (anp + bnp) * 100 % mod
		x = divide(x, a+b)
		expected = (expected + x) % mod
	}

	fmt.Println(expected)
}
