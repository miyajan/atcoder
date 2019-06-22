package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k int64
	fmt.Scan(&n)
	fmt.Scan(&k)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	prefixSum := make([]int64, n+1)
	prefixSum[0] = 0
	for i := int64(0); i < n; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		prefixSum[i+1] = prefixSum[i] + int64(a)
	}

	if n == 1 && prefixSum[1] >= k {
		fmt.Println(1)
		return
	} else if n == 1 && prefixSum[1] < k {
		fmt.Println(0)
		return
	}

	var ret int64
	for i := int64(0); i <= n-1; i++ {
		upper := n
		lower := i
		for {
			if upper < lower {
				break
			}
			mid := lower + (upper-lower)/2
			if mid == 0 {
				ret += n - i
				break
			}
			if prefixSum[mid]-prefixSum[i] >= k && prefixSum[mid-1]-prefixSum[i] < k {
				ret += n - mid + 1
				break
			}
			if prefixSum[mid]-prefixSum[i] >= k {
				upper = mid - 1
			} else {
				lower = mid + 1
			}
		}
	}

	fmt.Println(ret)
}
