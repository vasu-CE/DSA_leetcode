type MaxHeap []int

func (h MaxHeap) Len() int { return len(h)}
func (h MaxHeap) Less(i , j int) bool { return h[i] > h[j]}
func (h MaxHeap) Swap(i , j int) {h[i] , h[j] = h[j] , h[i]}

func (h *MaxHeap) Push (x interface{}){
    *h = append(*h , x.(int))
}

func (h *MaxHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[ : n-1]
    return x
}

func lastStoneWeight(stones []int) int {
    h := &MaxHeap{}
    *h = stones
    heap.Init(h)

    for h.Len() > 1 {
        y := heap.Pop(h).(int)
        x := heap.Pop(h).(int)

        if y > x {
            heap.Push(h , y-x)
        }
    }

    if h.Len() == 1 {
        return (*h)[0]
    }
    return 0
}