package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type AB [][]int

func (ab AB) Len() int {
	return len(ab)
}

func (ab AB) Less(i, j int) bool {
	return ab[i][1] < ab[j][1]
}

func (ab AB) Swap(i, j int) {
	ab[i], ab[j] = ab[j], ab[i]
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	ab := make(AB, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		ab[i] = []int{a, b}
	}
	sort.Sort(ab)

	t := 0
	for i := 0; i < n; i++ {
		t += ab[i][0]
		// fmt.Println(ab[i][0], ab[i][1], t)
		if t > ab[i][1] {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}
