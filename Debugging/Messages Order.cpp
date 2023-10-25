#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message
{
    string text_;
    int seq_ = 0;

  public:
    Message() {}

    Message(const string& text, int seq = 0) : text_(text), seq_(seq)
    {
    }

    const string& get_text() const
    {
        return text_;
    }

    bool operator<(const Message& o) const
    {
        return seq_ < o.seq_;
    }
};
class MessageFactory
{
    int seq_ = 0;

  public:
    MessageFactory() {}

    Message create_message(const string& text)
    {
        return Message(text, seq_++);
    }
};
