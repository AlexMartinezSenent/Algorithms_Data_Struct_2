#include <iostream>
#include <string>

int compute_path(int row, int col, int** CR, int** CD, int** P){
    int computed_path;
    if(P[row][col]==0){
        if(row==0 && col==0)P[row][col]=0;
        else if(row==0)P[row][col]=compute_path(row,col-1,CR,CD,P)+CR[row][col-1];
        else if(col==0)P[row][col]=compute_path(row-1,col,CR,CD,P)+CD[row-1][col];
        else {
            if(    (compute_path(row,col-1,CR,CD,P)+CR[row][col-1]) > (compute_path(row-1,col,CR,CD,P)+CD[row-1][col])   ){
                P[row][col]=compute_path(row,col-1,CR,CD,P)+CR[row][col-1];
            }
            else {
                P[row][col]=compute_path(row-1,col,CR,CD,P)+CD[row-1][col];
            }
        }
    }
    //std::cout << "division is " << first <<", "<< last << "\n";
    computed_path=P[row][col];
        //std::cout<<"returning from "<<first<<" and "<<last<<": "<<best_profit<<"\n";
        return computed_path;
}

int main(){
  std::int32_t n,i,j,best_path;
  int** R;
  int** D;
  int** W;
  
  //std::cout << "Introduce N ";
  std::cin >> n;
  R= new int*[n];
  D= new int*[n-1];
  W= new int*[n];

  for(i=0;i<n;i++){
      R[i]= new int[n-1];
  }
  for(i=0;i<n-1;i++){
      D[i]= new int[n];
  }
  for(i=0;i<n;i++){
      W[i]= new int[n];
  }

  for(i=0;i<n;i++){
      for(j=0;j<n-1;j++){
        std::cin >> R[i][j];
      }
      
  }
  for(i=0;i<n-1;i++){
      for(j=0;j<n;j++){
      std::cin >> D[i][j];

      }
  }

//    for(i=0;i<n;i++){
//      for(j=0;j<n-1;j++){
//        std::cout << R[i][j];
//      }
//      std::cout << "\n";
//  }
//  for(i=0;i<n-1;i++){
//      for(j=0;j<n;j++){
//      std::cout << D[i][j];
//
//      }
//      std::cout << "\n";
//  }
  //std::fill(*W,*W + n*n,NULL);
  best_path=compute_path(n-1,n-1,R,D,W);
  std::cout << best_path << std::endl;
}