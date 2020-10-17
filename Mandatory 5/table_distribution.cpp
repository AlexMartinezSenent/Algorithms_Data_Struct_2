#include <iostream>
#include <string>

void print_matrix(int** matrix, int a, int b){
    for(int ii=0;ii<a;ii++){     // print the matrix
      for(int jj=0;jj<b;jj++){
      std::cout << matrix[ii][jj] << " ";
      }
      std::cout << "\n";
  }
}
int place_tables(int** rows_to_cols, int* salida, int* llegada, int rows, int cols){
    for(int x=0; x<rows; x++){
        for(int y=0;y<cols;y++){
            //std::cout <<"S to R is: "<<salida[x]<<std::endl;
            if(salida[x]<2){
                //std::cout <<"  R to C is: "<<rows_to_cols[x][y]<<std::endl;
                if(rows_to_cols[x][y]==0){
                    //std::cout <<"    C to t is: "<<llegada[y]<<std::endl;
                    if(llegada[y]==0){
                        salida[x]+=1;
                        rows_to_cols[x][y]=1;
                        llegada[y]=1;
                        //print_matrix(rows_to_cols,rows,cols);
                        //std::cout <<"\n";
                    }
                }
            }
            else break;
        }
    }
    int sol=0;
    for(int d=0;d<cols;d++){
        sol+=llegada[d];
    }
    return sol;

}
int main(){
  std::int32_t n,m,i,j,k,solution;

  std::cin >> n;        // number of rows
  std::cin >> m;        // number of columns

  int sR[n];            // s to rows matrix
  int Ct[m];            // C to t columns matrix
  for(int q=0;q<n;q++){
      sR[q]=0;
  }
  for(int q=0;q<m;q++){
      Ct[q]=0;
  }
  int** RC;             // init row to columns matrix pointers
  RC= new int*[n];      // array of pointers to rows
  

  for(i=0;i<n;i++){     // each row has an array of m columns
      RC[i]= new int[m];
  }
  
  for(i=0;i<n;i++){     // fill the capacities of obstructed cells
      for(std::cin>>j;j>0;j--){
        std::cin >> k;
        RC[i][k]=2;
      }
  }
  //print_matrix(RC,n,m);
  //std::cout <<"place tables function"<<std::endl;
  solution=place_tables(RC,sR,Ct,n,m);
  //std::cout <<" Solution is:";
  std::cout<<solution;

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
  //best_path=compute_path(n-1,n-1,R,D,W);
  //std::cout << best_path << std::endl;
}