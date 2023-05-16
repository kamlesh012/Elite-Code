class Solution {
public:
     bool give(string& s) {
      int d  = 3;  // 0  1  2  3 -> down  left  up  right

      int x = 0 , y = 0 , db = 0;
      for (auto & e : s) {
        if (e == 'G') {
          if (d == 0) x++;
          else if (d == 1) y--;
          else if (d == 2) x--;
          else y++;
        }

        else if (e == 'R') {
          d = (d + 1) % 4;
          db |= 1;
        }

        else {
          d--;
          if (d < 0) d += 4;
          db |= 2;
        }
      }

      if (!x && !y) return 1;
      return 0;
}
    bool isRobotBounded(string s) {
        string a=s+s,b=a+a;
        if(give(s) || give(a) || give(b)){
            return true;
        }
        else return false;
    }
};