void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//将words按字典序排列并删除重复单词
	//重新排序，保持相等元素的字典序，越长的元素越在后面。
	stable_sort(words.begin(), words.end(), [](const string &a, const sttring &b) {return a.size() < b.size(); });
	//返回第一个size大于规定大小的元素位置
	auto wc = partition(words.begin(), words.end(), [sz](const string&a) {return a.size < sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << "of length" << sz << "or longer" << endl;
	for_each(wc, words.end(), [](const string&s) {cout << s << " "; });
	cout << endl;
}