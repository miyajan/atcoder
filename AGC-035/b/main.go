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

	if m%2 != 0 {
		fmt.Println("-1")
		return
	}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	edges := make([][]int, n)
	direction := make(map[int]map[int]bool)
	outboundCountOdd := make(map[int]bool)
	for i := 0; i < n; i++ {
		edges[i] = []int{}
	}

	for i := 0; i < m; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		a--
		b--

		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		if _, ok := direction[a]; !ok {
			direction[a] = make(map[int]bool)
		}
		direction[a][b] = true
		if _, ok := outboundCountOdd[a]; ok {
			delete(outboundCountOdd, a)
		} else {
			outboundCountOdd[a] = true
		}
	}

	if len(outboundCountOdd)%2 != 0 {
		fmt.Println("-1")
	}

	e := make(map[int]map[int]bool)
	seen := make(map[int]bool)
	var dfs func(node int, e map[int]map[int]bool)
	dfs = func(node int, e map[int]map[int]bool) {
		seen[node] = true
		if outboundCountOdd[node] {
			for k1, v := range e {
				for k2 := range v {
					if _, ok := direction[k1]; !ok {
						direction[k1] = make(map[int]bool)
					}
					if _, ok := direction[k2]; !ok {
						direction[k2] = make(map[int]bool)
					}
					if direction[k1][k2] {
						delete(direction[k1], k2)
						direction[k2][k1] = true
					} else {
						delete(direction[k2], k1)
						direction[k1][k2] = true
					}
				}
			}
		}
		delete(outboundCountOdd, node)
		if len(outboundCountOdd) == 0 {
			return
		}

		for i := 0; i < len(edges[node]); i++ {
			n := edges[node][i]
			if seen[n] {
				continue
			}

			if _, ok := e[node]; !ok {
				e[node] = make(map[int]bool)
			}
			e[node][n] = true
			dfs(n, e)
			delete(e[node], n)
		}
	}
	dfs(0, e)

	for k1, v := range direction {
		for k2 := range v {
			fmt.Printf("%d %d\n", k1+1, k2+1)
		}
	}
}
