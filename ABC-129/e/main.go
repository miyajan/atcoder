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

func calc(l string) int64 {
	length := int64(len(l))

	if l == "0" {
		return int64(1)
	} else if l == "1" {
		return int64(3)
	}

	var sum int64

	// length-1 桁まで
	sum += modpow(3, length-1) % mod

	var found bool
	for i := int64(1); i < length; i++ {
		if l[i] == '1' {
			found = true
			sum += 2 * calc(l[i:]) % mod
			break
		}
	}
	if !found {
		sum += 2
	}

	return sum % mod
}

func main() {
	var l string
	fmt.Scan(&l)

	fmt.Println(calc(l))
}
