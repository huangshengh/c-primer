void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//��words���ֵ������в�ɾ���ظ�����
	//�������򣬱������Ԫ�ص��ֵ���Խ����Ԫ��Խ�ں��档
	stable_sort(words.begin(), words.end(), [](const string &a, const sttring &b) {return a.size() < b.size(); });
	//���ص�һ��size���ڹ涨��С��Ԫ��λ��
	auto wc = partition(words.begin(), words.end(), [sz](const string&a) {return a.size < sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << "of length" << sz << "or longer" << endl;
	for_each(wc, words.end(), [](const string&s) {cout << s << " "; });
	cout << endl;
}