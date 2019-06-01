package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n, m uint
	fmt.Scan(&n)
	fmt.Scan(&m)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	s := make([][]uint, m)
	for i := uint(0); i < m; i++ {
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())

		for j := 0; j < k; j++ {
			scanner.Scan()
			sj, _ := strconv.Atoi(scanner.Text())
			s[i] = append(s[i], uint(sj))
		}
	}

	p := make([]int, m)
	for i := uint(0); i < m; i++ {
		scanner.Scan()
		p[i], _ = strconv.Atoi(scanner.Text())
	}

	max := int(math.Pow(2, float64(n)))
	var ret int
	for i := 0; i < max; i++ {
		on := make([]bool, n)
		for j := uint(0); j < n; j++ {
			on[j] = (i>>j)%2 == 1
		}
		var miss bool
		for j := uint(0); j < m; j++ {
			var num int
			for _, v := range s[j] {
				if on[v-1] {
					num++
				}
			}
			if num%2 != p[j] {
				miss = true
				break
			}
		}

		if !miss {
			ret++
		}
	}

	fmt.Println(ret)
}
