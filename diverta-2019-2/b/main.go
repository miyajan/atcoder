package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Balls [][]int

func (b Balls) Len() int {
	return len(b)
}

func (b Balls) Less(i, j int) bool {
	if b[i][0] != b[j][0] {
		return b[i][0] < b[j][0]
	}
	return b[i][1] < b[j][1]
}

func (b Balls) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	balls := make(Balls, n)
	point := make(map[int]map[int]bool)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		balls[i] = []int{x, y}
		if _, ok := point[x]; !ok {
			point[x] = make(map[int]bool)
		}
		point[x][y] = true
	}
	sort.Sort(balls)

	groups := make(map[int]map[int][][][]int)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			p := balls[j][0] - balls[i][0]
			q := balls[j][1] - balls[i][1]

			if _, ok := groups[p]; !ok {
				groups[p] = make(map[int][][][]int)
			}
			if _, ok := groups[p][q]; !ok {
				groups[p][q] = [][][]int{}
			}

			var found bool
			for _, g := range groups[p][q] {
				for _, ball := range g {
					if balls[j][0] == ball[0] && balls[j][1] == ball[1] {
						found = true
						break
					}
				}
				if found {
					break
				}
			}
			if found {
				continue
			}

			group := [][]int{
				{balls[i][0], balls[i][1]},
				{balls[j][0], balls[j][1]},
			}
			x := balls[j][0] + p
			y := balls[j][1] + q
			for point[x][y] {
				group = append(group, []int{x, y})
				x += p
				y += q
			}
			groups[p][q] = append(groups[p][q], group)
		}
	}

	min := n
	for _, val := range groups {
		for _, group := range val {
			cost := n
			for _, g := range group {
				cost -= len(g) - 1
			}
			if cost < min {
				min = cost
			}
		}
	}

	fmt.Println(min)
}
