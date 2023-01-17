#include<bits/stdc++.h>
using namespace std;

int get_random_number(int min,int max)
{
	int random_variable=rand();
	return min + (random_variable % (max - min + 1));
}

vector<vector<int>> generate_2d_array(int numberOfRows,int numberOfColumns){
  vector<vector<int>> arr(numberOfRows,vector<int>(numberOfColumns));
  
  srand(time(nullptr));
  
  for(int i=0;i<numberOfRows;i++){
    for(int j=0;j<numberOfColumns;j++){
      int value=get_random_number(0,100);
      arr[i][j]=value;
    }
  }
  
  return arr;
}

vector<vector<int>> sort_2d_list(vector<vector<int>> &arr,int columnIndex){
    vector<int> unsorted_column;
    for(int i=0;i<arr.size();i++){
      unsorted_column.push_back(arr[i][columnIndex]);
    }
    sort(unsorted_column.begin(),unsorted_column.end());
    for(int i=0;i<arr.size();i++) {
      arr[i][columnIndex]=unsorted_column[i];
    }
    
    return arr;
}

int main() {
    vector<vector<int>> arr=generate_2d_array(5,6);
    cout<<"Initially created 2d array : \n";
    for(auto row:arr){
      for(auto ele:row)cout<<ele<<" ";
      cout<<endl;
    }
    sort_2d_list(arr,3);
    cout<<endl;
    cout<<"2d array after sorting : \n";
    for(auto row:arr){
      for(auto ele:row)cout<<ele<<" ";
      cout<<endl;
    }
}