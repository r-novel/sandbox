package main

import (
	"strconv"
	"sync"
	"testing"
)

type Set struct {
	set map[interface{}]struct{}
	sync.Mutex
}

func (it *Set) Add(x interface{}) {
	it.Lock()
	defer it.Unlock()

	it.set[x] = struct{}{}
}

func (it *Set) Delete(x interface{}) {
	it.Lock()
	defer it.Unlock()

	delete(it.set, x)
}

func BenchmarkSetDelete(b *testing.B) {
	var testSet []string
	for i := 0; i < 1024; i++ {
		testSet = append(testSet, strconv.Itoa(i))
	}
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		b.StopTimer()
		set := Set{set: make(map[interface{}]struct{})}
		for _, elem := range testSet {
			set.Add(elem)
		}
		b.StartTimer()
		for _, elem := range testSet {
			set.Delete(elem)
		}
	}
}
