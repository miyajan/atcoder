package main

import (
	"fmt"
)

func main() {
	var n int64
	fmt.Scan(&n)

	i := int64(1)
	var ret int64
	for {
		m := (n - i) / i
		if m <= i {
			break
		}
		if (n-i)%i == 0 {
			ret += m
		}
		i++
	}

	fmt.Println(ret)
}
