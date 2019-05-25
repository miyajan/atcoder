package main

import (
	"fmt"
)

const (
	mod = int64(1000000007)
)

func modpow(x int64, y int64) int64 {
	if y == 0 {
		return 1
	} else if y == 1 {
		return x
	} else if y%2 != 0 {
		return x * modpow(x, y-1) % mod
	}
	t := modpow(x, y/2)
	return t * t % mod
}

func main() {
	var n, m, k int64
	fmt.Scan(&n)
	fmt.Scan(&m)
	fmt.Scan(&k)

	a := int64(1)
	b := int64(1)
	for i := int64(0); i < k-2; i++ {
		a *= n*m - 2 - i
		a %= mod
		a *= modpow(i+1, mod-2)
		a %= mod
	}
	num := a / b

	var sum int64
	for i := int64(1); i < m; i++ {
		sum += i * n * n * (m - i) * num
		sum %= mod
	}
	for i := int64(1); i < n; i++ {
		sum += i * m * m * (n - i) * num
		sum %= mod
	}

	fmt.Println(sum)
}
