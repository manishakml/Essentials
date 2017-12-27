/* Implement the datastructure bitset. This DS stores bits. Constructor will have the number of bits to be stored. If it doesn't, use default. Implement set(n), get(n), clear(), iterate() and compress the DS. */

class Bitset{
private:
vector<uint_32> A(32,0);
public:
Bitset(){}
Bitset(int n){
  int slots = (n+31)/32;  //n is number of bits. Each slot in A can store uint32 = 32 bits. So, ((n-1)/32) + 1 should be the size of the array.
  A.resize(slots);
}

void set(int i){  //set i-th bit
int slot = i/32;  //if 0-31 in 0th slot and so on
int idx = i%32;   //to find the bit within the slot
A[slot] |= (1U << idx);
}

bool get(int i){
int slot = i/32;  //if 0-31 in 0th slot and so on
int idx = i%32;   //to find the bit within the slot
return A[slot] & (1U << idx);
}

void clear(int i){
int slot = i/32;  //if 0-31 in 0th slot and so on
int idx = i%32;   //to find the bit within the slot
A[slot] &= !(1U << idx);
}

/* If we have very low number of set bits, vector/array is a waste of space. We can use a map instead.
 * unordered_map<int,uint32> m will store (slot,slot_contents).
 * This compresses space.
 */
 
 /* In order to iterate over set bits and return them */
 vector<int> setbits(){
 vector<int> res;
 for(int slot = 0; slot < A.size(); slot++){  //replace with for(const pair<int,uint32> &p : m) for map 
  for(int i = 0; i < 32; i++){
    if((1<<i)&A[slot]) {    //replace A[slot] with p.second
      res.push_back((slot*32)+i); //replace slot with p.first
 }
 return res;
 }
};
 
