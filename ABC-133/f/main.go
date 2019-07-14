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

	nodes := make([][][]int, n)
	for i := 0; i < n; i++ {
		nodes[i] = [][]int{}
	}

	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		c, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		d, _ := strconv.Atoi(scanner.Text())
		a--
		b--
		c--
		nodes[a] = append(nodes[a], []int{b, c, d})
		nodes[b] = append(nodes[b], []int{a, c, d})
	}

	log2n := 17
	parents := make([][]int, n)
	depths := make([]int, n)
	for i := 0; i < n; i++ {
		parents[i] = make([]int, log2n+1)
	}

	queues := [][]int{
		{0, 0, 0},
	}
	for len(queues) > 0 {
		node := queues[0][0]
		parent := queues[0][1]
		depth := queues[0][2]

		parents[node][0] = parent
		depths[node] = depth

		for i := 0; i < len(nodes[node]); i++ {
			if nodes[node][i][0] == parent {
				continue
			}
			queues = append(queues, []int{nodes[node][i][0], node, depth + 1})
		}

		queues = queues[1:]
	}

	for i := 1; i <= log2n; i++ {
		for j := 0; j < n; j++ {
			parents[j][i] = parents[parents[j][i-1]][i-1]
		}
	}

	x := make([]int, q)
	y := make([]int, q)
	u := make([]int, q)
	v := make([]int, q)
	lca := make([]int, q)
	need := make([]map[int]bool, n)
	for i := 0; i < n; i++ {
		need[i] = make(map[int]bool)
	}

	for i := 0; i < q; i++ {
		scanner.Scan()
		x[i], _ = strconv.Atoi(scanner.Text())
		x[i]--
		scanner.Scan()
		y[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		u[i], _ = strconv.Atoi(scanner.Text())
		u[i]--
		scanner.Scan()
		v[i], _ = strconv.Atoi(scanner.Text())
		v[i]--

		uu := u[i]
		vv := v[i]
		xx := x[i]
		if depths[uu] > depths[vv] {
			uu, vv = vv, uu
		}

		a := uu
		b := vv
		diff := depths[vv] - depths[uu]
		for j := uint(0); j < uint(log2n); j++ {
			if (diff>>j)&1 == 1 {
				b = parents[b][j]
			}
		}
		if a == b {
			lca[i] = a
		} else {
			for j := log2n; j >= 0; j-- {
				if parents[a][j] != parents[b][j] {
					a = parents[a][j]
					b = parents[b][j]
				}
			}
			lca[i] = parents[a][0]
		}

		need[uu][xx] = true
		need[vv][xx] = true
		need[lca[i]][xx] = true
 	}

	prefixSum := make([]int64, n)
	totalColorCount := make([]int, n-1)
	totalColorDist := make([]int64, n-1)
	prefixColorCount := make([][]int, n)
	prefixColorDist := make([][]int64, n)
	for i := 0; i < n; i++ {
		prefixColorCount[i] = make([]int, n-1)
		prefixColorDist[i] = make([]int64, n-1)
	}

	var dfs func(node int, parent int)
	dfs = func(node int, parent int) {
		for c := range need[node] {
			prefixColorCount[node][c] = totalColorCount[c]
			prefixColorDist[node][c] = totalColorDist[c]
		}

		for i := 0; i < len(nodes[node]); i++ {
			child := nodes[node][i][0]
			if child == parent {
				continue
			}

			c := nodes[node][i][1]
			d := nodes[node][i][2]

			prefixSum[child] = prefixSum[node] + int64(d)

			totalColorCount[c]++
			totalColorDist[c] += int64(d)
			dfs(child, node)
			totalColorCount[c]--
			totalColorDist[c] -= int64(d)
		}
	}
	dfs(0, 0)

	/*
	queues = [][]int{{0, 0, 0, -1, 0}}
	for len(queues) > 0 {
		op := queues[0][0]
		node := queues[0][1]
		parent := queues[0][2]
		color := queues[0][3]
		dist := queues[0][4]

		queues = queues[1:]

		if op == 0 {
			if color != -1 {
				totalColorCount[color]++
				totalColorDist[color] += int64(dist)
			}

			for c := range need[node] {
				prefixColorCount[node][c] = totalColorCount[c]
				prefixColorDist[node][c] = totalColorDist[c]
			}

			for i := 0; i < len(nodes[node]); i++ {
				child := nodes[node][i][0]
				if child == parent {
					continue
				}

				c := nodes[node][i][1]
				d := nodes[node][i][2]

				prefixSum[child] = prefixSum[node] + int64(d)

				queues = append([][]int{{0, child, node, c, d}, {1, child, node, c, d}}, queues...)
			}
		} else {
			totalColorCount[color]--
			totalColorDist[color] -= int64(dist)
		}
	}
	 */

	for i := 0; i < q; i++ {
		uu := u[i]
		vv := v[i]
		xx := x[i]
		yy := y[i]
		ll := lca[i]

		du := prefixSum[uu] - prefixColorDist[uu][xx] + int64(prefixColorCount[uu][xx]*yy)
		dv := prefixSum[vv] - prefixColorDist[vv][xx] + int64(prefixColorCount[vv][xx]*yy)
		dlca := prefixSum[ll] - prefixColorDist[ll][xx] + int64(prefixColorCount[ll][xx]*yy)
		d := du + dv - 2*dlca
		fmt.Println(d)
	}
}
