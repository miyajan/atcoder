package main

import (
"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)

	var i int
	var ret int
	var aSeq int
	for i < len(s)-2 {
		if s[i:i+3] == "ABC" {
			ret += aSeq + 1
			s = "A" + s[i+3:]
			i = 0
		} else {
			if s[i] == 'A' {
				aSeq++
			} else {
				aSeq = 0
			}
			i++
		}
	}
	fmt.Println(ret)
}
