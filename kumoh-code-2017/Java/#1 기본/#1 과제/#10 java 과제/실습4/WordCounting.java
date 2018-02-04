import java.util.*;

public class WordCounting
{
	public static void main(String[] args)
	{
		Map<String, Integer> hashMap = new HashMap<String, Integer>();
		Map<String, Integer> treeMap = new TreeMap<String, Integer>();
		Map<String, Integer> linkedHashMap = new LinkedHashMap<String, Integer>();
		
		Integer hashFreq;
		Integer treeFreq;
		Integer linkedHashFreq;
		
		for(String key : args)
		{
			hashFreq = hashMap.get(key);
			treeFreq = treeMap.get(key);
			linkedHashFreq = linkedHashMap.get(key);
			
			hashMap.put(key, (hashFreq == null) ? 1 : hashFreq+1);
			treeMap.put(key, (treeFreq == null) ? 1 : treeFreq+1);
			linkedHashMap.put(key, (linkedHashFreq == null) ? 1 : linkedHashFreq+1);
		}
		
		System.out.println("HashMap");
		System.out.println(hashMap.size() + "distinct words:");
		System.out.println(hashMap);
		
		System.out.println("TreeMap");
		System.out.println(treeMap.size() + "distinct words:");
		System.out.println(treeMap);
		
		System.out.println("LinkedHashMap");
		System.out.println(linkedHashMap.size() + "distinct words:");
		System.out.println(linkedHashMap);
	}
}
