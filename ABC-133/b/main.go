package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n, d int
	fmt.Scan(&n)
	fmt.Scan(&d)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	points := make([][]int, n)
	for i := 0; i < n; i++ {
		points[i] = make([]int, d)
		for j := 0; j < d; j++ {
			scanner.Scan()
			points[i][j], _ = strconv.Atoi(scanner.Text())
		}
	}

	var ret int
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			var s float64
			for k := 0; k < d; k++ {
				s += float64((points[i][k] - points[j][k]) * (points[i][k] - points[j][k]))
			}
			s = math.Sqrt(s)
			f := math.Floor(s)
			if s == f {
				ret++
			}
		}
	}

	fmt.Println(ret)
}
