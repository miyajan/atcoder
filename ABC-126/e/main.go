package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	p := make(map[int]map[int]int)
	for i := 1; i <= n; i++ {
		p[i] = make(map[int]int)
	}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 1; i <= m; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		z, _ := strconv.Atoi(scanner.Text())
		p[x][y] = z
		p[y][x] = z

	}

	searched := make(map[int]bool)
	var search func(pos int)
	search = func(pos int) {
		if searched[pos] {
			return
		}
		searched[pos] = true

		for k := range p[pos] {
			search(k)
		}
	}

	var ret int
	for i := 1; i <= n; i++ {
		if !searched[i] {
			ret++
			search(i)
		}
	}

	fmt.Println(ret)
}
