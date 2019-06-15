package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	mod = 1000000007
)

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	a := make(map[int]bool)
	for i := 0; i < m; i++ {
		scanner.Scan()
		aa, _ := strconv.Atoi(scanner.Text())
		a[aa] = true
	}

	dp := make([]int, n+1)
	dp[0] = 1
	if a[1] {
		dp[1] = 0
	} else {
		dp[1] = 1
	}

	for i := 2; i <= n; i++ {
		if a[i] {
			dp[i] = 0
		} else {
			dp[i] = (dp[i-1] + dp[i-2]) % mod
		}
	}

	fmt.Println(dp[n])
}
