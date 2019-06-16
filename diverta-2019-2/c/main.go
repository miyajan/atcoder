package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		aa, _ := strconv.Atoi(scanner.Text())
		a[i] = aa
	}
	sort.Ints(a)

	var plus []int
	var minus []int
	for i := 0; i < n; i++ {
		if a[i] < 0 {
			minus = append(minus, a[i])
		} else {
			plus = append(plus, a[i])
		}
	}

	var ret int
	var ops [][]int
	if len(plus) == 0 {
		ret = minus[len(minus)-1]
		for i := len(minus) - 2; i >= 0; i-- {
			x := ret
			y := minus[i]
			ret = x - y
			ops = append(ops, []int{x, y})
		}
	} else {
		ret = plus[len(plus)-1]

		if len(plus) > 1 && len(minus) == 0 {
			z := plus[0]
			for i := 1; i < len(plus)-1; i++ {
				x := z
				y := plus[i]
				z = x - y
				ops = append(ops, []int{x, y})
			}
			x := ret
			y := z
			ret = x - y
			ops = append(ops, []int{x, y})
		} else if len(plus) > 1 {
			z := minus[0]
			for i := 0; i < len(plus)-1; i++ {
				x := z
				y := plus[i]
				z = x - y
				ops = append(ops, []int{x, y})
			}
			x := ret
			y := z
			ret = x - y
			ops = append(ops, []int{x, y})
			minus = minus[1:]
		}

		for i := 0; i < len(minus); i++ {
			x := ret
			y := minus[i]
			ret = x - y
			ops = append(ops, []int{x, y})
		}
	}

	fmt.Println(ret)
	for i := 0; i < n-1; i++ {
		fmt.Print(ops[i][0])
		fmt.Print(" ")
		fmt.Print(ops[i][1])
		fmt.Println("")
	}
}
