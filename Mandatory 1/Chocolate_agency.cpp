#include <iostream>
#include <string>

int check_cross_profit(int x, int y, int z, int* sell, int* buy){
    int best_buy=buy[y],best_sell=sell[y], output=0;

    for(int i=y;i>=x;i--){
        if(best_sell>(sell[i]+100*(y-i))){
            best_sell=(sell[i]+100*(y-i)); 
        }
    }
    for(int i=y+1;i<=z;i++){
        if(best_buy<(buy[i]-100*(i-y))){
            best_buy=(buy[i]-100*(i-y));
        }
    }
    //std::cout<<"           From: ["<<x<<", "<<y<<", "<<z<<"] Minimum sell : "<<best_sell<<" maximum buy: "<<best_buy<<"\n";
    output=best_buy-best_sell;
    return output;
}

int check_profit(int first, int last, int* sell, int* buy){
    int half;
    int best_first_profit, best_last_profit, best_cross_profit, best_profit=0;
    //std::cout << "division is " << first <<", "<< last << "\n";
    if(first!=last){
        half=(last-first)/2;
        //std::cout << "Half is " << half << "\n";
        best_first_profit=check_profit(first, first+half, sell, buy);
        best_last_profit=check_profit(first+half+1, last, sell, buy);
                
        (best_first_profit > best_last_profit) ? best_profit=best_first_profit : best_profit=best_last_profit;
        
        best_cross_profit=check_cross_profit(first, first+half, last, sell, buy);
        
        if(best_cross_profit > best_profit) best_profit=best_cross_profit;
    }
    else{
        best_profit=buy[first]-sell[first]-((first-first)*100);
    }
        //std::cout<<"returning from "<<first<<" and "<<last<<": "<<best_profit<<"\n";
        return best_profit;
}

int main(){
  std::int32_t N;
  std::int32_t i,benefit;
  //std::cout << "Introduce N ";
  std::cin >> N;
  std::int32_t s[N],b[N];
  for(i=0;i<N;i++){
      std::cin >> s[i];
  }
    for(i=0;i<N;i++){
      std::cin >> b[i];
  }
  benefit=check_profit(0,N-1,s,b);
  if(benefit<0)benefit=0;
  std::cout << benefit;
}