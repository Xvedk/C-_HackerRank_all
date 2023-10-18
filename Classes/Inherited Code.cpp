class BadLengthException : public exception {
public:
    BadLengthException(int len) : length(len) {}

    const char* what() const noexcept override {
        static string message;
        message = to_string(length);
        return message.c_str();
    }

private:
    int length;
};

