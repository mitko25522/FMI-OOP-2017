class CommandParser {
private:
	enum Type{
		NOT_SET,
		MAKE_HEADING,
		MAKE_ITALIC,
		MAKE_BOLD,
		MAKE_COMBINE,
		ADD_LINE,
		REMOVE_LINE
	} type;
	char* text;
	bool isValid();
	bool areEqual(char*, const char*);
public:
	bool promptInput();

	CommandParser();
	~CommandParser();
};