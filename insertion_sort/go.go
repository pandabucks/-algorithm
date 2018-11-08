package main

import (
	"fmt"
)

func main() {
	a := []int{32, 12, 43, 243, 19, 54, 14, 20}
	for i, _ := range a {
		if i == 0 {
			continue
		}
		key := a[i]
		j := i - 1
		for j >= 0 && a[j] > key {
			a[j+1] = a[j]
			j = j - 1
		}
		a[j+1] = key
	}
	fmt.Println(a)
}
