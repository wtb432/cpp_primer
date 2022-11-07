#include <iostream>
#include <algorithm>
#include <set>
class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void addFd(Folder *f) { folders.insert(f); }
    void remFd(Folder *f) { folders.erase(f); }

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void Message::save(Folder &f)
{
    addFd(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    remFd(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    using std::swap;
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

class Folder
{
public:
    Folder() {}
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void addMsg(Message *);
    void remMsg(Message *);

private:
    std::set<Message *> mesg;
    void add_Message(const Folder &);
    void remove_Message();
};

void Folder::add_Message(const Folder &f)
{
    for (auto msg : f.mesg)
        msg->addFd(this);
}

void Folder::remove_Message()
{
    for (auto msg : mesg)
        msg->remFd(this);
}

void Folder::addMsg(Message *msg)
{
    mesg.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    mesg.erase(msg);
}

Folder::Folder(const Folder &f) : mesg(f.mesg)
{
    add_Message(f);
}

Folder &Folder::operator=(const Folder &f)
{
    remove_Message();
    mesg = f.mesg;
    add_Message(f);
}

Folder::~Folder()
{
    remove_Message();
}
