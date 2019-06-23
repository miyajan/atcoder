package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)

	var prev byte
	for i := 0; i < len(s); i++ {
		if i != 0 && s[i] == prev {
			fmt.Println("Bad")
			return
		}
		prev = s[i]
	}
	fmt.Println("Good")
}
