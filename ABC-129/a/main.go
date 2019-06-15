package main

import (
	"fmt"
)

func main() {
	var p, q, r int
	fmt.Scan(&p)
	fmt.Scan(&q)
	fmt.Scan(&r)

	if p+q <= q+r && p+q <= r+p {
		fmt.Println(p + q)
	} else if q+r <= p+q && q+r <= r+p {
		fmt.Println(q + r)
	} else {
		fmt.Println(r + p)
	}
}
