package main

import (
"bufio"
"fmt"
"math"
"os"
"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	prefixSum := make([]int, n)
	var sum int
	for i := 0; i < n; i++ {
		scanner.Scan()
		w, _ := strconv.Atoi(scanner.Text())
		sum += w
		prefixSum[i] = sum
	}

	smallest := math.MaxInt32
	for i := 0; i < n-1; i++ {
		s1 := prefixSum[i]
		s2 := prefixSum[n-1] - prefixSum[i]
		abs := s2 - s1
		if abs < 0 {
			abs = -abs
		}
		if abs < smallest {
			smallest = abs
		}
	}

	fmt.Println(smallest)
}
