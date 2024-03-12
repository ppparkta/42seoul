#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &obj);
	Warlock &operator=(Warlock const &obj);

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	std::string getName() const;
	std::string getTitle() const;
	void setTitle(std::string title);
	void introduce() const;
};