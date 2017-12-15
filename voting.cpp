/* Given a list of n ballots (each ballot represents the vote rankings of the person) and a list of m candidates, determine the winner
 * {{a,b},{b,a}} determines that 1st person ranked candidate a as first and candidate b as second, 2nd person ranked candidate b as first and candidate a as second. 
 * A winner is a candidate with > n/2 votes
 * If no winner, discard the person with least votes in the current round and for all people who had voted for the discarded candidate in the current round go to their next choice. And so on, until a winner is determined.
 */
 
 #include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

/*
 * b is assumed to be ranked in order of preference. So, b[0][0], b[0][1] represents 0th person's 1st choice and 0th person's 2nd choice respectively.
 * Also, assuming that no ballot is empty and each ballot's size is the same = n_candidates.
 */
 
 int winner(vector<vector<int> > &b, vector<int> &c){

    int n = b.size();   //number of people who voted
    int m = c.size();   //number of candidates
    if(n == 0 || m == 0) {
        return INT_MIN; //no winner
    }
    if(n == 1){
        return b[0][0]; //if only one person voted, return his first choice
    }
    if(m == 1){
        return m;   //if there is only one candidate and the ballots are not empty, declare him as winner
    }


    //marker denotes where each ballot's processing should start. Initially, it is 0 idx.
    vector<int> marker(n,0);
//count stores pair<votes,candidate_idx> in ascending order of votes. If 2 candidates have same votes, they are ranked acc. to their candidate_idx. Uniqueness is guaranteed - only if p.first and p.second are the same, will it be deduped.
    bool cmp = [](pair<int,int> a, pair<int,int> b){return a.first < b.first;};
    set<pair<int,int>,decltype(cmp)> count(cmp);

    //m is a mapping between candidate_idx and the corresponding set element
    unordered_map<int,set<pair<int,int> >::iterator> map1;

    //keep the discarded candidates because they got the lowest number of votes
    unordered_set<int> discard;


  while(true){
    for(int i = 0; i < b.size(); i++){
        int idx = marker[i];
        //This is required from the second iteration (no winner found in first). If the current element we are evaluating is not in discard pile (non-empty since it is second roundonwards), we don't have to consider their 2nd choice.
        if(!discard.empty() && !discard.count(b[i][idx])) {
            continue;
        }
        while(idx < m && discard.count(b[i][idx])) {
            idx = ++marker[i];    //this rank has been discarded; move to next
        }
        //k indicates each ballot's idx'th choice. Initially idx = 0, so,1st choice.
        int k = b[i][idx];

        //if that candidate has been found before, increase his count
        if(map1.count(k)) {
            //get the iterator dereferenced. Then increment the pair's first element; votes. We have to erase the existing set element and insert the new set element since its val has changed. So, update map as well.
            pair<int,int> p = *(map1[k]);
            count.erase(map1[k]);
            p.first++;
            map1[k] = (count.insert(p)).first;
        } else {    //it is a new candidate; insert into set and update map
            map1[k] = (count.insert(make_pair(1,k))).first;
        }
    }
//if the highest-voted candidate has gained > half the ballots, he wins.
    if((*(count.end())).first > n/2){
        return (*(count.end())).second;
    }

    //to keep track of min votes; every iteration has a unique minimum
    int min_votes = INT_MAX;

    //if nobody won majority, we discard the candidate(s) with lowest number of votes
    for(auto it = count.begin(); it != count.end(); it++){
        //compute the new minimum; since set is sorted, this will happen only once.
        if(((*it).first) < min_votes) {
            min_votes = (*it).first;
        }
        //discard all the candidates with the new minimum and remove them from count and map
        if((*it).first == min_votes){
            discard.insert((*it).second);
            map1.erase((*it).second);
            count.erase(it);
        } else if((*it).first > min_votes) {
            break;
        }
    }
  }

  return INT_MIN;
}

int main(){
    vector<vector<int> > b ={{1,2,3,4,5,6,7,8},
                            {7,4,1,2,5,6,3,8},
                            {1,7,3,4,5,6,2,8},
                            {7,4,8,5,4,6,2,3},
                            {1,8,2,4,5,6,7,3},
                            {3,1,4,2,5,6,7,8},
                            {1,7,3,4,5,6,2,8},
                            {4,2,1,3,5,6,7,8},
                            {8,2,3,6,5,4,7,1},
                            {3,6,7,4,5,1,2,8} };
    vector<int> c = {1,2,3,4,5,6,7,8};
    cout << winner(b,c);
    return 1;
}

/* Not tested.
 * Time complexity: O(nmlogm)
 * Space complexity: O(max(n,m))
 */
