class Student{
    string name;
    double cgpa;
    public:
        Student(string name, double cgpa);
        Student(Student &from);
        // ~Student();
        double get_cgpa();
        void set_cgpa(double cgpa);
        void to_print();

};