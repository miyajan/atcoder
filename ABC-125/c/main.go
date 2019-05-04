package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	var minusNums int
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i] < 0 {
			minusNums++
			a[i] = - a[i]
		}
	}

	var ret int64
	if minusNums%2 == 0 {
		for i := 0; i < n; i++ {
			ret += int64(a[i])
		}
	} else {
		sort.Ints(a)
		ret = -int64(a[0])
		for i := 1; i < n; i++ {
			ret += int64(a[i])
		}
	}

	fmt.Println(ret)
}
