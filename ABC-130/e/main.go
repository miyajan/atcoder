package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	mod = int64(1000000007)
)

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	s := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i], _ = strconv.Atoi(scanner.Text())
	}
	t := make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		t[i], _ = strconv.Atoi(scanner.Text())
	}

	dp := make([][]int64, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int64, m+1)
		for j := 0; j <= m; j++ {
			if i == 0 || j == 0 {
				dp[i][j] = 1
				continue
			}

			if s[i-1] == t[j-1] {
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod
			} else {
				dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod
			}
		}
	}

	fmt.Println((dp[n][m] + mod) % mod)
}
