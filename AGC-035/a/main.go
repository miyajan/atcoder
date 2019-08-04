package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Count [][]int

func (c Count) Len() int {
	return len(c)
}
func (c Count) Less(i, j int) bool {
	return c[i][0] >= c[j][0]
}
func (c Count) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	countMap := make(map[int]int)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		countMap[a]++
	}

	var count Count
	for k, v := range countMap {
		count = append(count, []int{v, k})
	}
	sort.Sort(count)

	if len(count) == 1 {
		if count[0][1] == 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		return
	}

	if n%3 != 0 {
		fmt.Println("No")
		return
	}

	u := n / 3
	if len(count) == 2 {
		if count[0][0] == 2*u && count[1][0] == u {
			if count[1][1] == 0 {
				fmt.Println("Yes")
				return
			}
		}
		fmt.Println("No")
		return
	}

	if len(count) == 3 {
		if count[0][0] == u && count[1][0] == u && count[2][0] == u && count[0][1]^count[1][1] == count[2][1] {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}
