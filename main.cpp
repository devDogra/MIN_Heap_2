#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

// MIN HEAP //

void printvec(std::vector<int>& v, bool newline = true){
    if (newline) std::cout << "\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));       
}

// these perform no validity checks
inline int PARENT(int i){ 
    return i/2; 
}
inline int LEFT( int i){
	return 2 * i;
}
inline int RIGHT(int i){
	return 2 * i + 1;   
}

// check if i is a valid index
inline bool is_valid_index(int i, std::vector<int>& heap){
	return (i > 0 and i < heap.size());
}

// get the idx with the minimum value of theones we passed
int get_min_index(int l, int r, std::vector<int>& heap){
	if (heap[l] < heap[r]) return l;
	else return r;
}

// get the idx to which the hole must next move to. if the idx is the same
// as the one we passed to it, it means there's no place for the hole to go
// and we should stop
int get_move_index(int i, std::vector<int>& heap)
{
	int min_index;
	if ( is_valid_index(LEFT(i), heap) and is_valid_index(RIGHT(i), heap) ){
		min_index = get_min_index(LEFT(i), RIGHT(i), heap); 
	}
	else if (is_valid_index(LEFT(i), heap)){
		min_index = LEFT(i);
	} 
	// no right case because of the heap structure property
	else{
		min_index = i;
	}

	return min_index;

	


}

// sift the idx i down
void sift_down(std::vector<int>& heap, int i)
{
	int hole_val = heap[i];
	
	// move the hole (i) where it belongs 
	while(true)
	{
		int move_idx = get_move_index(i, heap);
		if (move_idx == i) {
			break;
		}
		heap[i] = std::move(heap[move_idx]);
		i = move_idx;

	}

	heap[i] = hole_val;
}

/*
Successive inserts: Level by level sift up
Heapify : Reverse lev by levl sift down, better than succ. inserts
*/

int main() {
  
} 