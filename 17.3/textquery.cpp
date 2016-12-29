#include "textquery.h"
#include <iterator>
#include <algorithm>
#include <sstream>

TextQuery::TextQuery(std::ifstream&s) :file(new vector<string >> )
{
	string line;
	while (getline(s, line))
	{
		file->push_back(line);
		int index = file->size() - 1;
		std::stringstream linesteam(line);
		string word;
		while (linesteam >> word)
		{
			shared_ptr<set<index_Tp>>& sp_lineIndex = wm[word];
			if (!sp_lineIndex)
				sp_lineIndex.reset(new set < index_Tp>);
			sp_lineIndex->insert(index);
		}
	}

}


result_tuple TextQuery::query_return_tuple(const string&s)const
{
	static shared_ptr<set<index_Tp>> nodata(new set<index_Tp>);
	auto iter = wm.find(s);
	if (iter == wm.end())
		return result_tuple(s, nodata, file);
	else
		return result_tuple(s, iter->second, file);
}