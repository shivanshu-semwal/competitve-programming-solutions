package com.shivanshu;

import java.util.*;

public class Problem139 {

    public boolean solve(String s, HashSet<String> h, int idx){
        // reached the end of string
        if(idx == s.length()) return true;

        for(int i=idx + 1; i<s.length(); i++){
            if(h.contains(s.substring(idx, i + 1))){
                if(solve(s, h, i + 1)) return true;
            }
        }
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> h = new HashSet<>();
        for(var word: wordDict) h.add(word);
        if(h.contains(s)) return true;
        return solve(s, h, 0);
    }

    public static void main(String[] args) {
        {
            Problem139 p = new Problem139();
            String s = "leetcode";
            List<String> wordDict = new ArrayList<>(Arrays.asList(new String[] {"leet", "code"}));
            System.out.println(p.wordBreak(s, wordDict));
        }
    }
}
