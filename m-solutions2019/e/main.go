package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	mod = int64(1000003)
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
	var q int
	fmt.Scan(&q)

	factorial := make([]int64, mod)
	factorial[0] = 1
	for i := int64(1); i < mod; i++ {
		factorial[i] = factorial[i-1] * i % mod
	}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	for i := 0; i < q; i++ {
		scanner.Scan()
		xi, _ := strconv.Atoi(scanner.Text())
		x := int64(xi)
		scanner.Scan()
		di, _ := strconv.Atoi(scanner.Text())
		d := int64(di)
		scanner.Scan()
		ni, _ := strconv.Atoi(scanner.Text())
		n := int64(ni)

		if x == 0 {
			fmt.Println(0)
			continue
		}
		if d == 0 {
			fmt.Println(pow(x, n))
			continue
		}

		xdd := divide(x, d) % mod
		if xdd+n-1 >= mod {
			fmt.Println(0)
			continue
		}
		ret := divide(factorial[xdd+n-1], factorial[xdd-1]) % mod
		ret = ret * pow(d, n) % mod
		fmt.Println(ret)
	}
}
