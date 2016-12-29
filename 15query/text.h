#ifndef text_h
#define text_h


#include <memory>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <iterator>

using std::string;
using std::shared_ptr;
using std::vector;
using std::map;
using std::set;



class QueryResult;
class TextQuery
{
public:  
	using line_no = vector<string>::size_type;  
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;//指向输入文件；
	map < string, shared_ptr<set<line_no>> > wm;//每个单词到他所在行号的集合的映射；
};

//构造函数，读取文件并建立单词到行号的映射。
TextQuery::TextQuery(std::ifstream& is) :file(new vector<string>)
{
	string text;
	while (getline(is, text))//把文件的每一行都读入到text上
	{
		file->push_back(text);//file是一个指向vector<string>的指针，所以每一行都当成一个string插入到vector中
		int n = file->size() - 1;//n是此行的行号
		std::istringstream line(text);
		string word;
		while (line >> word)//把这一行的每个string都都入到word中
		{
			//wm是个map，所以如果不存在就直接添加了，lines也是一个指针
			auto &lines = wm[word]; 
			if (!lines)//如果word是第一次出现，则指针为空
				lines.reset(new set < line_no>);//delete掉lines原来的指针，指向新的对象，即指向line_no的集合
			lines->insert(n);//然后不管是不是第一次出现，现在指针都指向行号的集合，现在将此行插进去；
		}
	}
}

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}
	auto begin() { return lines->begin(); }
	auto end() { return lines->end(); }
	shared_ptr<vector<string>> get_file() { return file; }

private:  
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string & sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())//未找到就在最后
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}


string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << std::endl;
	return os;
} 

#endif // !text_h
