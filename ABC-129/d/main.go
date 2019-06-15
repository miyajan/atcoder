package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var h, w int
	fmt.Scan(&h)
	fmt.Scan(&w)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	cStarts := make([]int, w)
	light := make([][]int, h)
	for i := 0; i < h; i++ {
		light[i] = make([]int, w)
	}

	for i := 0; i < h; i++ {
		rStart := 0
		scanner.Scan()
		row := scanner.Text()
		for j := 0; j < w; j++ {
			if row[j] == '#' {
				for k := rStart; k < j; k++ {
					light[i][k] += j - rStart
				}
				for k := cStarts[j]; k < i; k++ {
					light[k][j] += i - cStarts[j] - 1
				}
				rStart = j + 1
				cStarts[j] = i + 1
			}
		}

		for k := rStart; k < w; k++ {
			light[i][k] += w - rStart
		}
	}

	for j := 0; j < w; j++ {
		for k := cStarts[j]; k < h; k++ {
			light[k][j] += h - cStarts[j] - 1
		}
	}

	var max int
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if light[i][j] > max {
				max = light[i][j]
			}
		}
	}

	fmt.Println(max)
}
