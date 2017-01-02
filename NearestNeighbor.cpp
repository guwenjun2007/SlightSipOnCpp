#include <iostream>
#include <math.h> 
#include <vector>
#include <float.h>
using namespace std;
// input: database, query
//output: index of the nearestNeighbor;
//        minimun distance;
//        whether the result is trustable;
bool nearest_neighbor(const std::vector<std::vector<float> > & database, const std::vector<float> & query, unsigned int& index, float& min_dist){
    // test the input
     if(query.size() == 0||database.size() == 0){
         return false;  
     }
     // query dimention
    int l = query.size();
    //set the distance to maximum value
    min_dist = FLT_MAX;
    //count the illegle number in database, if all illeagle, return false;
    int illegleNum = 0; 
    // database size;                                                
    int m = database.size();
  
  for(int i = 0; i < m; i++){
      // take each one of the input value and initialize the distance
       float dis = 0.0;
       //get the dimention of the data
       int n = database[i].size();
       //if the dimention of the data is different with the query data, 
       //that means there are some missing values, this data is illegal, jump to next data
       if(n != l){
           illegleNum++;
           continue;
       }
       //calculate the Euclidia distance
       for(int j = 0; j < n; j++){
            dis += (database[i][j] - query[j]) * (database[i][j] - query[j]);
            //if it is already larger than the min_dist, no need to continue, break directly
            if(dis > min_dist){
              break;
            }
       }
       // if the distance is smaller, update the index and the distance.
        if(dis < min_dist){
            index = i;
            min_dist = dis;
        }     
   }
   //take the sqrt of the min_dist.
   min_dist = sqrt(min_dist);
   // if all the data in the database has missing data, the caluclated result is false;
   if(illegleNum == m){
     return false;
   }else{
     return true;  
    }
}


int main() {
  vector< vector<float> > database;
  // initialize the database
  for(int i = 0; i < 4; i++){
      vector<float> temp;
      for(int j = 0; j < 3; j++){
          temp.push_back(1.1*j+i);
      }
      database.push_back(temp);
  }
  // print the database for visilazation 
  cout<<"database:"<<'\n';
  for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
        cout << database[i][j] << " ";
    }
    cout<<'\n';
  }
  // initialze the query
  vector<float> query;
  query.push_back(1.2);
  query.push_back(2.3);
  query.push_back(3.4);
  //print the query for visilazation
  cout<<"query:"<<'\n';
  for(int i = 0; i < 3; i++){
      cout << query[i]<<" ";
  }
  cout<<'\n';
  // test the code and print
  unsigned int index = 0;
  float min_dist = 0.0;
  bool res = nearest_neighbor(database, query, index, min_dist);
  cout<<"Is solution reliable? "<< res <<'\n';
  cout<<"index: " << index <<'\n';
  cout<<"min distance: "<<min_dist<<'\n';
  return 0;
}
