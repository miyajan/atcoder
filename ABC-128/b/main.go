package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Restaurants [][]int

func (r Restaurants) Len() int {
	return len(r)
}
func (r Restaurants) Less(i, j int) bool {
	return r[i][1] > r[j][1]
}
func (r Restaurants) Swap(i, j int) {
	r[i], r[j] = r[j], r[i]
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var cities []string
	restaurantsMap := make(map[string]Restaurants)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		scanner.Scan()
		p, _ := strconv.Atoi(scanner.Text())
		if _, ok := restaurantsMap[s]; !ok {
			cities = append(cities, s)
			restaurantsMap[s] = [][]int{}
		}
		restaurantsMap[s] = append(restaurantsMap[s], []int{i + 1, p})
	}

	sort.Strings(cities)
	for i := 0; i < len(cities); i++ {
		restaurants := restaurantsMap[cities[i]]
		sort.Sort(restaurants)
		for j := 0; j < len(restaurants); j++ {
			fmt.Println(restaurants[j][0])
		}
	}
}
