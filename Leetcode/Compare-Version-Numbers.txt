//Java (brute force)
import java.util.*;
class Solution {
    private int compare(int a, int b){
        if(a < b) return -1;
        else if(a > b) return 1;
        else return 0;
    }
    public int compareVersion(String version1, String version2) {
        String[] s1 = version1.split("\\.");
        String[] s2 = version2.split("\\.");
        List<String> l1 = new ArrayList<>();
        Collections.addAll(l1, s1);
        List<String> l2 = new ArrayList<>();
        Collections.addAll(l2, s2);
        int ans = 0;
        int diff = Math.abs(l1.size() - l2.size());
        if(l1.size() > l2.size()){
            for(int i = 0; i < diff; i++){
                l2.add("0");
            }
        }else{
            for(int i = 0; i < diff; i++){
                l1.add("0");
            }
        }
        
        for(int i = 0; i < l1.size(); i++){
            ans = compare(Integer.parseInt(l1.get(i)), Integer.parseInt(l2.get(i)));
            if(ans != 0){
                return ans;
            }
        }

        return ans;
    }
}