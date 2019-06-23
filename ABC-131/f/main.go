package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	par := make([]int, 200000)
	xcount := make([]int, 200000)
	ycount := make([]int, 200000)
	for i := 0; i < 200000; i++ {
		par[i] = i
	}
	for i := 0; i < 100000; i++ {
		xcount[i] = 1
	}
	for i := 100000; i < 200000; i++ {
		ycount[i] = 1
	}

	root := func(i int) int {
		for par[i] != i {
			i = par[i]
		}
		return i
	}

	union := func(x int, y int) {
		xroot := root(x)
		yroot := root(y)
		if xroot == yroot {
			return
		}

		par[xroot] = yroot
		xcount[yroot] += xcount[xroot]
		ycount[yroot] += ycount[xroot]
	}

	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		x = x - 1
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		y = y + 99999
		union(x, y)
	}

	var sum int
	for i := 0; i < 200000; i++ {
		if root(i) == i {
			sum += xcount[i] * ycount[i]
		}
	}

	fmt.Println(sum - n)
}
