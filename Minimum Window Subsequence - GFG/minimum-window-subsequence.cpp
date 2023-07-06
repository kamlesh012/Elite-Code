//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
    	int i=0,j=0;
    	int end=-1,min_length=10000,min_start=-1,min_end=-1;
    	for(int i=0;i<n;i++){
    		if(s[i]==t[j]){
    			j++;
    			if(j==m){
    				end=i;
    				j--;
    				while(j>=0){
    					if(t[j]==s[i])j--;
    					i--;
    				}
    				i++;
    				j++;
    				if ((end - i) < min_length){
    					min_start = i;
    					min_end = end;
    					min_length=(min_end-min_start);
    				}
    			}
            }
    	}
    	if(min_start==-1)return "";
    	else return s.substr(min_start,min_length+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends