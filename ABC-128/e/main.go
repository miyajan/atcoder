package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, q int
	fmt.Scan(&n)
	fmt.Scan(&q)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	stops := map[int]int{}
	for i := 0; i < n; i++ {
		scanner.Scan()
		s, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())

		for j := s; j < t; j++ {
			if stops[j-x] == 0 || x < stops[j-x] {
				stops[j-x] = x
			}
		}
	}

	for i := 0; i < q; i++ {
		scanner.Scan()
		d, _ := strconv.Atoi(scanner.Text())
		if _, ok := stops[d]; ok {
			fmt.Println(stops[d])
		} else {
			fmt.Println(-1)
		}
	}
}
