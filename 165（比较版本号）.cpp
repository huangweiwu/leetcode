public class Solution {
	public int compareVersion(String version1, String version2) {
		if (version1 == null || version2 == null) {
			return 0;
		}
		String[] v1 = version1.split("\\.");
		String[] v2 = version2.split("\\.");
		int length = Math.min(v1.length, v2.length);
		int value1, value2;
		int i;
		for(i=0; i<length; i++) {
			value1 = Integer.parseInt(v1[i]);
			value2 = Integer.parseInt(v2[i]);
			if(value1 < value2)
				return -1;
			else if(value1 > value2)
				return 1;
		}
		if(v1.length == v2.length) 
			return 0;
		else if(v1.length > v2.length) {
			for(; i<v1.length; i++) {
				if(Integer.parseInt(v1[i]) > 0)
					return 1;
			}
			return 0;
		}
		else {
			for(; i<v2.length; i++) {
				if(Integer.parseInt(v2[i]) > 0)
					return -1;
			}
			return 0;
		}
	}
}
