#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

/*
KEY HELPER FUNCS:
get_move_index() ---helps---> sift_down() ---> helps all / delete, heapify
sift_up() ----helps----> insert


*/


//todo: insert, delete
// MIN HEAP ///

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
inline int get_min_index(int l, int r, std::vector<int>& heap){
	if (heap[l] < heap[r]) return l;
	else return r;
}

// get the idx to which the hole must next move to. if the idx is the same
// as the one we passed to it, it means there's no place for the hole to go
// and we should stop
// for sift down
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

// assume we only sift down a heavier value
// sift the idx i down to its right position
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
// assume we only sift up a lighter value
// so if i is 1, there's nowhere for it to "sift up" to
void sift_up(std::vector<int>& heap, int i)
{
	int hole_val = heap[i];

	while(i > 1)
	{
		if (hole_val < heap[PARENT(i)]){
			heap[i] = std::move(heap[PARENT(i)]);
			i = PARENT(i);
		}
		else{
			break;
		}


	}
	heap[i] = hole_val;
}

// Insert a node into a heap
void insert(std::vector<int>& heap, int x)
{
	heap.push_back(x);
	int i = heap.size() - 1;
	sift_up(heap, i);
	
}

// replace the root with the last node. nuke the last node. sift the new root down. 
void delete_min(std::vector<int>& heap)
{
	int min = heap[1]; // to return
	heap[1] = heap.back();
	heap.pop_back();

	sift_down(heap, 1);
}

// heap is a vector of nums
// turn it into an actual heap
//---
// start at the last-most internal node, work your way to the top
// sift each of them down to keep making sub heaps
// at the end the final 2 subheaps will automatically combine into 1 heap

void heapify(std::vector<int>& heap)
{
	int t = PARENT(heap.size() - 1);

	for (t; t != 0; t--){
		sift_down(heap, t);
	}
}


//
/*
Successive inserts: Level by level sift up
Heapify : Reverse lev by levl sift down, better than succ. inserts
*/

int main() {
  
} 