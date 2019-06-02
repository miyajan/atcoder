package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type UnionFind struct {
	par []int
}

func newUnionFind(n int) *UnionFind {
	u := &UnionFind{}
	u.par = make([]int, n)
	for i := range u.par {
		u.par[i] = -1
	}
	return u
}

func (u UnionFind) root(x int) int {
	if u.par[x] < 0 {
		return x
	}
	return u.root(u.par[x])
}

func (u UnionFind) unite(x, y int) {
	xr := u.root(x)
	yr := u.root(y)
	if xr == yr {
		return
	}
	u.par[yr] += u.par[xr]
	u.par[xr] = yr
}

func (u UnionFind) same(x, y int) bool {
	return u.root(x) == u.root(y)
}

func (u UnionFind) size(x int) int {
	return -u.par[u.root(x)]
}

type Node struct {
	n        int
	children []*Node
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	u := newUnionFind(n)
	tMap := make(map[int][]int)
	for i := 1; i <= n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		if _, ok := tMap[a]; !ok {
			tMap[a] = []int{}
		}
		u.unite(a-1, b-1)
		tMap[a] = append(tMap[a], b)
		if _, ok := tMap[b]; !ok {
			tMap[b] = []int{}
		}
		tMap[b] = append(tMap[b], a)
	}

	c := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		c[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Ints(c)

	root := u.root(0) + 1
	r := &Node{
		n: root,
	}
	parents := map[int]bool{root: true}
	var build func(n *Node, parents map[int]bool)
	build = func(node *Node, parents map[int]bool) {
		if _, ok := tMap[node.n]; !ok {
			return
		}

		parents[node.n] = true
		for _, child := range tMap[node.n] {
			if !parents[child] {
				c := &Node{n: child}
				node.children = append(node.children, c)
				build(c, parents)
			}
		}
	}
	build(r, parents)

	var order []int
	q := []*Node{r}
	for len(q) > 0 {
		order = append(order, q[0].n-1)
		q = append(q, q[0].children...)
		q = q[1:]
	}

	ts := make([]int, n)
	for i := 0; i < n; i++ {
		ts[order[i]] = c[n-1-i]
	}

	var sum int
	for k, v := range tMap {
		for i := 0; i < len(v); i++ {
			if k < v[i] {
				if ts[k-1] < ts[v[i]-1] {
					sum += ts[k-1]
				} else {
					sum += ts[v[i]-1]
				}
			}
		}
	}
	fmt.Println(sum)

	for i := 0; i < n; i++ {
		fmt.Print(ts[i])
		if i != n-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println("")
}
