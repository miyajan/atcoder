package main

import (
	"bufio"
	"fmt"
	"os"
)

type BitSet struct {
	length uint
	set    []uint64
}

func newBitSet() *BitSet {
	return &BitSet{
		length: 0,
		set:    []uint64{},
	}
}

func (b *BitSet) setBit(i uint, bit bool) {
	setIndex := i / 64
	if i >= b.length {
		newSet := make([]uint64, setIndex+1)
		copy(newSet, b.set)
		b.set = newSet
		b.length = i + 1
	}
	b.set[setIndex] |= 1 << i % 64
}

func (b *BitSet) getBit(i uint) bool {
	if i >= b.length {
		return false
	}
	setIndex := i / 64
	return b.set[setIndex]&(1<<i%64) != 0
}

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	winMap := make(map[int]map[int]bool)
	for i := 1; i <= n; i++ {
		winMap[i] = make(map[int]bool)
	}
	for i := 2; i <= n; i++ {
		scanner.Scan()
		str := scanner.Text()
		for j := 1; j < i; j++ {
			if str[j-1] == '1' {
				winMap[i][j] = true
				winMap[j][i] = false
			} else {
				winMap[i][j] = false
				winMap[j][i] = true
			}
		}
	}

	dpl := make([][]bool, n)
	dpr := make([][]bool, n)
	for i := 0; i < n; i++ {
		dpl[i] = make([]bool, n)
		dpr[i] = make([]bool, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n-i; j++ {
			if i == 0 {
				dpl[j][j+i] = true
				dpr[j+i][j] = true
			} else {
				for k := j; k <= j+i; k++ {
					if k != j && winMap[j+1][k+1] && dpl[k][j+i] && dpr[k][j+1] {
						dpl[j][j+i] = true
					}
					if k != j+i && winMap[j+i+1][k+1] && dpl[k][j+i-1] && dpr[k][j] {
						dpr[j+i][j] = true
					}
				}
			}
		}
	}

	var ret int
	for i := 0; i < n; i++ {
		if dpl[i][n-1] && dpr[i][0] {
			ret++
		}
	}
	fmt.Println(ret)
}
