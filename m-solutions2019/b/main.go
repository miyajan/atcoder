package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)

	size := len(s)
	var win int
	for _, c := range s {
		if c == 'o' {
			win++
		}
	}

	if win+15-size >= 8 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
