#include <string>
#include <set>
#include <iostream>
#include <utility>

using std::string;
using std::set;

class Folder;

class Message
{
	friend void swap(Message &lhs, Message &rhs);
	friend class Folder;
public:
	explicit Message(const string& str = " " ):contents(str){}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&& m) :contents(std::move(m.contents))
	{
		move_Folders(&m);
	} 
	Message& operator=(Message &&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void print_debug();

private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *m);

	void addFolder(Folder *f) { folders.insert(f); }
	void remFolder(Folder *f) { folders.erase(f);}
};

void swap(Message&lhs, Message &rhs)
{
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f :folders)
		f->remMsg(this);
}

void Message::move_Folders(Message*m)
{
	folders = std::move(m->folders);//move得到右值，然后使用set的移动赋值运算符来给folders赋值
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();//移后源对象进行销毁
}

Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message::operator=(Message&&rhs)
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
	remove_from_Folders;
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
 }

class Folder
{
	friend void swap(Folder &, Folder &);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	Folder();

private:
	set<Message*> msgs;
	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }

	void add_to_Message(const Folder&);
	void remove_from_Message();

};

void Folder::add_to_Message(const Folder&hs)
{
	for (auto f : hs.msgs)
		f->addFolder(this);
}

void Folder::remove_from_Message()
{
	for (auto f : msgs)
		f->remFolder(this);
}

Folder::Folder(const Folder&hs) :msgs(hs.msgs)
{
	add_to_Message(hs);
}

Folder& Folder::operator=(const Folder&hs)
{
	remove_from_Message();
	msgs = hs.msgs;
	add_to_Message(hs);
	return *this;
}

Folder::~Folder()
{
	remove_from_Message();
}

void swap(Folder&lhs, Folder&rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}