class Student {
public:
	Student();
	Student(int newAge, double newGPA, char *newName);
	Student(Student &copy);

	~Student();

	int getAge();
	double getGPA();
	char *getName();
	
	void setAge(int newAge);
	void setGPA(double newGPA);
	void setName(char *newName);

private:
	int age;
	double GPA;
	char* name;
};