import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Map.Entry;

public class Day2 {
    public static void main(String[] args) {
        System.out.println("IsIsomorphic: " + isIsomorphic("badc", "baba"));
        System.out.println("isSubsequence: " +isSubsequence("bacv","bvsdcvga"));
    }

    /*
    205. Isomorphic Strings
    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself. 
    */
    
    public static boolean isIsomorphic(String s, String t) {
        HashMap<Character,Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if(map.containsValue(t.charAt(i))){
                for(Entry<Character, Character> entry: map.entrySet()) {
                    if(entry.getValue() == t.charAt(i) && entry.getKey() != s.charAt(i)) {
                      return false;
                    }
                }
            }

            if(map.get(s.charAt(i)) == null){
                map.put(s.charAt(i), t.charAt(i));
            }
            else{
                if (map.get(s.charAt(i)) == t.charAt(i)) {
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

    /*  
    392. Is Subsequence
    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
    of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
     */

    public static boolean isSubsequence(String s, String t) {
        Queue<Character>queue = new LinkedList<Character>();
        for (int i = 0; i < t.length(); i++) {
            queue.add(t.charAt(i));
        }
        for (int i = 0; i < s.length(); i++) {            
            while (queue.size()!=0) {
                System.out.println("testing i : "+ i);
                System.out.println("testing size : "+ queue.size());
                
                if(queue.peek() != s.charAt(i)){
                    System.out.println("testing: "+ queue.peek());
                    queue.poll();
                }
                else{
                    if(i==s.length()-1){
                        return true;
                    }
                    System.out.println("testing removed : "+ queue.peek());
                    queue.poll();
                    break;
                }
                System.out.println("");   
            }
            if (queue.size() == 0) {                
                return false;
            }
        }
        return true;
    }
}
