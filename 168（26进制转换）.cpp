public class Solution {
    public String convertToTitle(int n) {
        //26进制转换
    	String s = "";
    	char tmp;
    	int remain = 0;
    	while(n > 26) {
    		remain = n % 26;
    		if(remain == 0)
    			remain = 26;
    		tmp = (char)('A' + remain - 1);
    		s = tmp + s;
    		
    		n = (n-1) / 26;
    	}
    	tmp = (char)('A' + n - 1);
    	s = tmp + s;
    	return s;
    }
}