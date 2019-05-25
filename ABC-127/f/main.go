package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
)

type Int64Heap []int64

func (h Int64Heap) Len() int           { return len(h) }
func (h Int64Heap) Less(i, j int) bool { return h[i] < h[j] }
func (h Int64Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Int64Heap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int64))
}

func (h *Int64Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type InverseInt64Heap []int64

func (h InverseInt64Heap) Len() int           { return len(h) }
func (h InverseInt64Heap) Less(i, j int) bool { return h[j] < h[i] }
func (h InverseInt64Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *InverseInt64Heap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int64))
}

func (h *InverseInt64Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var q int
	fmt.Scan(&q)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	la := &InverseInt64Heap{}
	ra := &Int64Heap{}
	var laSum int64
	var raSum int64
	heap.Init(la)
	heap.Init(ra)
	var bSum int64
	for i := 0; i < q; i++ {
		scanner.Scan()
		o, _ := strconv.Atoi(scanner.Text())

		if o == 1 {
			scanner.Scan()
			a, _ := strconv.Atoi(scanner.Text())
			aa := int64(a)
			if len(*la) == 0 {
				heap.Push(la, aa)
				laSum += aa
			} else if (*la)[0] < aa {
				heap.Push(ra, aa)
				raSum += aa
				if la.Len() < ra.Len() {
					v := heap.Pop(ra).(int64)
					raSum -= v
					heap.Push(la, v)
					laSum += v
				}
			} else {
				heap.Push(la, aa)
				laSum += aa
				if la.Len()-ra.Len() > 1 {
					v := heap.Pop(la).(int64)
					laSum -= v
					heap.Push(ra, v)
					raSum += v
				}
			}
			scanner.Scan()
			b, _ := strconv.Atoi(scanner.Text())
			bSum += int64(b)
		} else {
			x := (*la)[0]
			fx := bSum + (x * int64(la.Len())) - laSum + (-x * int64(ra.Len())) + raSum
			fmt.Printf("%d %d\n", x, fx)
		}
	}
}
