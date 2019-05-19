package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var tailA int
	var headB int
	var both int
	var ret int
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		ret += strings.Count(s, "AB")
		if s[0] == 'B' && s[len(s)-1] == 'A' {
			both++
		} else if s[0] == 'B' {
			headB++
		} else if s[len(s)-1] == 'A' {
			tailA++
		}
	}

	if both > 0 {
		ret += both - 1
		if tailA > 0 {
			ret++
			tailA--
		}
		if headB > 0 {
			ret++
			headB--
		}
	}

	if tailA > headB {
		ret += headB
	} else {
		ret += tailA
	}

	fmt.Println(ret)
}
