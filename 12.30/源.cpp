#include <memory>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <iostream>

using std::string;
using std::shared_ptr;
using std::vector;
using std::map;
using std::set;

using line_no = vector<string>::size_type;
class DebugDelete
{
public:
	DebugDelete(std::ostream& s= std::cerr):os(s){}
	template <typename T> void operator() (T* p) const
	{
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}
private: 
	std::ostream& os;

};



class QueryResult;
class TextQuery
{
public: 
	
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;//ָ�������ļ���
	map < string, shared_ptr<set<line_no>> > wm;//ÿ�����ʵ��������кŵļ��ϵ�ӳ�䣻
};

//���캯������ȡ�ļ����������ʵ��кŵ�ӳ�䡣
TextQuery::TextQuery(std::ifstream& is) :file(new vector<string>,DebugDelete())
{
	string text;
	while (getline(is, text))//���ļ���ÿһ�ж����뵽text��
	{
		file->push_back(text);//file��һ��ָ��vector<string>��ָ�룬����ÿһ�ж�����һ��string���뵽vector��
		int n = file->size() - 1;//n�Ǵ��е��к�,Ҫ���뵽set��
		std::istringstream line(text);
		string word;
		while (line >> word)//����һ�е�ÿ��string�����뵽word��
		{
			//wm�Ǹ�map������������ǲ����ھ�ֱ������ˣ�linesҲ��һ��ָ��
			auto &lines = wm[word];
			if (!lines)//���word�ǵ�һ�γ��֣���ָ��Ϊ��
				lines.reset(new set < line_no>);//delete��linesԭ����ָ�룬ָ���µĶ��󣬼�ָ��line_no�ļ���
			lines->insert(n);//Ȼ�󲻹��ǲ��ǵ�һ�γ��֣�����ָ�붼ָ���кŵļ��ϣ����ڽ����в��ȥ��
		}
	}
}

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f):sought(s),lines(p),file(f){}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string & sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())//δ�ҵ��������
		return QueryResult(sought, nodata, file);
	else//�ҵ���sought�ͰѶ�Ӧ���кŵ�set����ȥ��
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