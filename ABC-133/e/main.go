package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	nodes := make([][]int, n)
	for i := 0; i < n; i++ {
		nodes[i] = []int{}
	}

	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		nodes[a-1] = append(nodes[a-1], b-1)
		nodes[b-1] = append(nodes[b-1], a-1)
	}

	mod := 1000000007
	ret := k % mod
	p := k - 1
	var queue [][]int
	for i := 0; i < len(nodes[0]); i++ {
		queue = append(queue, []int{0, nodes[0][i]})
		ret = (ret * p) % mod
		p--
	}

	for len(queue) > 0 {
		parent := queue[0][0]
		current := queue[0][1]
		queue = queue[1:]

		p := k - 2
		for i := 0; i < len(nodes[current]); i++ {
			if nodes[current][i] == parent {
				continue
			}
			queue = append(queue, []int{current, nodes[current][i]})
			ret = (ret * p) % mod
			p--
		}
	}

	fmt.Println(ret)
}
