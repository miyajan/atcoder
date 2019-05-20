package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scan(&s)

	n, _ := strconv.Atoi(s)

	a := n / 100
	b := n % 100

	var ret string
	if (1 <= a && a <= 12) && (1 <= b && b <= 12) {
		ret = "AMBIGUOUS"
	} else if 1 <= a && a <= 12 {
		ret = "MMYY"
	} else if 1 <= b && b <= 12 {
		ret = "YYMM"
	} else {
		ret = "NA"
	}

	fmt.Println(ret)
}
