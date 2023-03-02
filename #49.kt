class Solution {
    private var theMap=HashMap<List<Int>,MutableList<String>>();
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        theMap=HashMap<List<Int>,MutableList<String>>();
        for(str in strs) {
            CountChar(str);
        }
        var ans:MutableList<List<String>> = mutableListOf();
        for((key, list) in theMap) {
            ans.add(list);
        }
        return ans.toList();
    }
    fun CountChar(str: String) {
        val charList:MutableList<Int> = mutableListOf();
        for(i in 0..25) {
            charList.add(0);
        }
        for(c in str) {
            charList[c.toInt()-'a'.toInt()]++;
        }
        if(theMap.containsKey(charList.toList())==false) {
            theMap[charList.toList()]=mutableListOf();
        }   
        theMap[charList.toList()]!!.add(str);
    }
}