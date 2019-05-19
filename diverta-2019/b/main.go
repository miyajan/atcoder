package main

import (
	"fmt"
)

func main() {
	var r, g, b, n int
	fmt.Scan(&r)
	fmt.Scan(&g)
	fmt.Scan(&b)
	fmt.Scan(&n)

	var ret int
	for i := 0; i*r <= n; i++ {
		for j := 0; i*r+j*g <= n; j++ {
			if (n-(i*r+j*g))%b == 0 {
				ret++
			}
		}
	}

	fmt.Println(ret)
}
