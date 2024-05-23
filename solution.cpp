#include<iostream>
#include<climits>
#define rep(i,a,b) for(int i= a; i <b ;i++)
using namespace std  ;

int main(){
    int n,m ;
    cin >> n >> m ;
    int arr[n][m];
    int curr_max = INT_MIN;
    int curr_day = 0 ;
    int net_max = INT_MIN ;
    int net_day = 0 ;
   
    rep(i,0,n){
        rep(j,0,m) {
            cin >> arr[i][j] ;
        }
    }

    rep(i,0,m){
        rep(j,0,n){
            if(curr_max+arr[j][i] > arr[j][i]){
                curr_max += arr[j][i] ;
                curr_day++ ;
            }else{
                curr_max = arr[j][i];
                curr_day= 1;
            }

            if(curr_max > net_max){
                net_max = curr_max ;
                net_day = curr_day ;
            }
            if(curr_max==net_max){
                net_day = min(curr_day,net_day) ;
            }

        }
        curr_day =0 ;
        curr_max = INT_MIN;
    }
    cout << net_day << " " << net_max << '\n';
}
