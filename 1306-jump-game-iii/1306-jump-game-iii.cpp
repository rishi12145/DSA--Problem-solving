class Solution {
public:
    
    bool search(vector<int>& arr, int index, vector<int>& visited){

        if(index < 0 || index >= arr.size()){
            return false;
        }

        if(visited[index] == 1){
            return false;
        }

        if(arr[index] == 0){
            return true;
        }

        visited[index] = 1;

        return search(arr, index + arr[index], visited) || search(arr, index - arr[index], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        vector<int> visited(arr.size(), 0);
        return search(arr, start, visited);
        
    }
};