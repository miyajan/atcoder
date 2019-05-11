package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	val      int
	children []*Node
}

func main() {
	var n int
	fmt.Scan(&n)

	linesMap := make(map[int][]int)

	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n-1; i++ {
		var a, b int
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
		linesMap[a] = append(linesMap[a], b)
		linesMap[b] = append(linesMap[b], a)
	}

	_, s := farthest(1, linesMap)
	depth, _ := farthest(s, linesMap)

	dp := make([]bool, depth+1)
	dp[0] = true
	if depth > 0 {
		dp[1] = false
	}
	for i := 2; i <= depth; i++ {
		if dp[i-1] && dp[i-2] {
			dp[i] = false
		} else {
			dp[i] = true
		}
	}

	if dp[depth] {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}

func farthest(i int, linesMap map[int][]int) (depth int, node int) {
	ancestors := make(map[int]bool)
	ancestors[i] = true
	current := linesMap[i]
	node = i
	for current != nil {
		var next []int
		for _, j := range current {
			node = j
			for _, k := range linesMap[j] {
				if !ancestors[k] {
					next = append(next, k)
				}
			}
			ancestors[j] = true
		}
		depth++
		current = next
	}

	return depth, node
}
