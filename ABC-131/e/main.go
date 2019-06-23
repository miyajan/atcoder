package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	max := (n - 1) * (n - 2) / 2

	if k > max {
		fmt.Println("-1")
		return
	}

	var ms [][]int
	for i := 2; i <= n; i++ {
		ms = append(ms, []int{1, i})
	}

	c := max - k

	for i := 2; i < n; i++ {
		if c == 0 {
			break
		}
		for j := i + 1; j <= n; j++ {
			ms = append(ms, []int{i, j})
			c--
			if c == 0 {
				break
			}
		}
	}

	fmt.Println(len(ms))
	for i := 0; i < len(ms); i++ {
		fmt.Printf("%d %d\n", ms[i][0], ms[i][1])
	}
}
