package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int64, n)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &a[i])
	}

	mod := int64(1000000007)
	beauties := map[int]map[int64]int64{}

	for i := 1; i <= n; i++ {
		beauties[i] = map[int64]int64{}

		var x int64
		for j := 0; j < i; j++ {
			x = x ^ a[j]
		}
		beauties[i][x] += 1

		var y int64
		for j := i-1; j >= 1; j-- {
			y = y ^ a[j]
			beauties[i][y] = (beauties[i][y] + beauties[j][y]) % mod
		}
	}

	var ret int64
	for _, val := range beauties[n] {
		ret = (ret + val) % mod
	}

	fmt.Println(ret)
}
