package main

import (
	"fmt"
)

func main() {
	var w, h, x, y float64
	fmt.Scan(&w)
	fmt.Scan(&h)
	fmt.Scan(&x)
	fmt.Scan(&y)

	fmt.Print(w * h / 2)
	fmt.Print(" ")
	if x*2 == w && y*2 == h {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}
