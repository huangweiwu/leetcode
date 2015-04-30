//给定一个绝对路径，将其简化
//思路：
//利用strtok/strtok_s进行分割，用栈保存已读取的字符串，对于当前读到的字符
//1) 如果为".."，则判断栈是否为空，不为空则出栈
//2) 如果不为"."或者"/"或者""，则入栈
//最终栈里的内容即为完整的绝对路径

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmp;
        char *path_c = (char*)path.c_str();
		char *pnext = NULL;
        char *tokenPtr=strtok_s(path_c, "/", &pnext);    //略过第一个"/"符号
        while(tokenPtr != NULL) {
            string str = tokenPtr;
            if(str == "..") {
                if(!tmp.empty()) {
                    tmp.pop_back();
                }
            }
            else if(str != "" && str!=".") {
                tmp.push_back(str);
            }
            tokenPtr=strtok_s(NULL, "/", &pnext);
        }
        string result = "/";
		if(!tmp.empty()) {
			for(int i=0; i<tmp.size()-1; i++) {
				result += tmp[i];
				result += "/";
			}
			result += tmp[tmp.size()-1];
		}
        return result;
    }
};