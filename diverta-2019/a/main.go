package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	ret := n - k + 1
	if n == 0 {
		ret = 0
	}
	if k > n {
		ret = 0
	}

	fmt.Println(ret)
}
