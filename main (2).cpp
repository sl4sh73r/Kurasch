#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

class Core {
  public:
  
  int protect_marks() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 5) {
            clear_all();
            return val;
          }
          cout << "[CODE_ERROR] - Введены неверные данные" << endl;
          clear_all();
      }
  }
  int protect() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 9) {
            clear_all();
            return val;
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          clear_all();
      }
  }
  int protect_change() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 4) {
            clear_all();
            return val;
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          clear_all();
      }
  }
  int protect_task() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 5) {
            clear_all();
            return val;
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          clear_all();
      }
  }
  int protect_day() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 31) {
              clear_all();
              return(val);
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          cout << "Неверная Дата" << endl;
          clear_all();
      }
  }
  int protect_month() {
      int val;
      while(true) {
          cin >> val;
          if (val > 0 && val <= 12) {
              clear_all();
              return(val);
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          cout << "Неверная Дата" << endl;
          clear_all();
      }
  }
  int protect_year() {
      int val;
      while(true) {
          cin >> val;
          if (val > 1922 && val <= 2022) {
              clear_all();
              return(val);
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          cout << "Неверная Дата" << endl;
          clear_all();
      }
  }
  char protect_ch() {
      char val;
      while(true) {
          cin >> val;
          if (val == 'M' || val == 'F') {
            clear_all();
            return val;
          }
          cout << "[CODE_ERROR]  - Введены неверные данные" << endl;
          clear_all();
      }
  }
  
  void clear_all() {
    cin.seekg(0, ios::end);
	cin.clear();
  }
};

class Task : Core {
  private:
  int command;
  int a = 0;
  int b = 0;
  int c = 0;
  char gradebook_number[32];
  char number[32];
  int matan;
  int phys;
  int practise;
  int inf_tech;
  int history;
  int english;
  int count = 0;
  char surname[32];
  char name[32];
  char patronymic[32];
  int day;
  int month;
  int year;
  int year_of_receipt;
  char gender;
  char faculty[32];
  char department[32];
  char group[32];
  public:
    
    void task_menu() {
    
        check_marks();
        cout << "Сортировка по полу [M и F]==>[1]" << endl;
        cout << "Сортировка по полу [M only]==>[2]" << endl;
        cout << "Сортировка по полу [F only]==>[3]" << endl;
        cout << " > ";
        cin >> command; clear_all();
        cout << "Номер Студенческого Билета | Математика | Физика | Учебная практика | ЯП | История | Английский язык" << endl;
        switch(command) {
            case 1:
            {
                find_F_or_M();
                break;
            }
            case 2:
            {
                find_M();
                break;
            }
            case 3:
            {
                find_F();
                break;
            }
        }
    }
    
    void find_M() {
      check_marks();
      ifstream input("Base.txt", std::ios::app);
      ifstream marks_input("SemMarks.txt", std::ios::app);
      
      for (int i = 0; i < count; i++) {
        input >> number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        if (gender == 'M') {
          for (int j = 0; j < count; j++) {
            marks_input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
                int tmp(1);
                for (int i = 0; i < 7; i++) {
                    if (gradebook_number[i] != number[i]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp == 1) {
                    if (matan == 5 && phys == 5 && practise == 5 && inf_tech == 5 && history == 5 && english == 5) {
                        cout << "Отличник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if ((matan == 5 || matan == 4) && (phys == 5 || phys == 4) && (practise == 5 || practise == 4) && (inf_tech == 5 || inf_tech == 4) && (history == 5 || history == 4) && (english == 5 || english == 4)) {
                        cout << "Хорошист: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if (matan == 3 || phys == 3 || practise == 3 || inf_tech == 3 || history == 3 || english == 3) {
                        cout << "Троечник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                }
          }
              
        } 
      }
     
      input.close();
      marks_input.close();   
    }
    void find_F() {
      check_marks();
      ifstream input("Base.txt", std::ios::app);
      ifstream marks_input("SemMarks.txt", std::ios::app);
      
      for (int i = 0; i < count; i++) {
        input >> number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        if (gender == 'F') {
          for (int j = 0; j < count; j++) {
            marks_input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
                int tmp(1);
                for (int i = 0; i < 7; i++) {
                    if (gradebook_number[i] != number[i]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp == 1) {
                    if (matan == 5 && phys == 5 && practise == 5 && inf_tech == 5 && history == 5 && english == 5) {
                        cout << "Отличник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if ((matan == 5 || matan == 4) && (phys == 5 || phys == 4) && (practise == 5 || practise == 4) && (inf_tech == 5 || inf_tech == 4) && (history == 5 || history == 4) && (english == 5 || english == 4)) {
                        cout << "Хорошист: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if (matan == 3 || phys == 3 || practise == 3 || inf_tech == 3 || history == 3 || english == 3) {
                        cout << "Троечник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                }
          }
              
        } 
      }
     
      input.close();
      marks_input.close();  
    }
    void find_F_or_M() {
      check_marks();
      ifstream input("Base.txt", std::ios::app);
      ifstream marks_input("SemMarks.txt", std::ios::app);
      
      for (int i = 0; i < count; i++) {
        input >> number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        if (gender == 'M' || gender == 'F') {
          for (int j = 0; j < count; j++) {
            marks_input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
                int tmp(1);
                for (int i = 0; i < 7; i++) {
                    if (gradebook_number[i] != number[i]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp == 1) {
                    if (matan == 5 && phys == 5 && practise == 5 && inf_tech == 5 && history == 5 && english == 5) {
                        cout << "Отличник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if ((matan == 5 || matan == 4) && (phys == 5 || phys == 4) && (practise == 5 || practise == 4) && (inf_tech == 5 || inf_tech == 4) && (history == 5 || history == 4) && (english == 5 || english == 4)) {
                        cout << "Хорошист: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                    else if (matan == 3 || phys == 3 || practise == 3 || inf_tech == 3 || history == 3 || english == 3) {
                        cout << "Троечник: " << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
                        break;
                    }
                }
          }
              
        } 
      }
     
      input.close();
      marks_input.close();   
    }
    
    void check_marks() {
      ifstream check("SemMarks.txt", std::ios::app);
      count = 0;
      while(!check.eof()) {
        count++;
        check >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
      }
      count--;
  }
    
    friend class Student;
    friend class Menu;
    friend class Stud_marks;
    
    void clear_all() {
    cin.seekg(0, ios::end);
	cin.clear();
  }
};

class Student : Core {
  private:
    char* surname = nullptr;
	char* name = nullptr;
	char* patronymic = nullptr;
	int day;
	int month;
	int year;
	char* gender = nullptr;
	int year_of_receipt;
	char* faculty = nullptr;
	char* department = nullptr;
	char* group = nullptr;
	char* gradebook_number = nullptr;
    
  public:
   

   Student() {
        surname = new char[31]();
        name = new char[31]();
        patronymic = new char[31]();
        gender = new char('\0');
    
        day = 0;
        month = 0;
        year = 0;
        year_of_receipt = 0;
    
        faculty = new char[32];
        department = new char[32];
        group = new char[32];
        gradebook_number = new char[32];
   }
   
   Student(
		char* surname,
        char* name,
        char* patronymic,
        int day,
	    int month,
	    int year,
        int year_of_receipt,
        char* gender,
        char* faculty,
        char* department,
        char* group,
        char* gradebook_number)
    {
        surname = new char[31]();
        name = new char[31]();
        patronymic = new char[31]();
        gender = new char('\0');
    
        day = 0;
        month = 0;
        year = 0;
        year_of_receipt = 0;
    
        faculty = new char[32];
        department = new char[32];
        group = new char[32];
        gradebook_number = new char[32];
        
        this -> surname = surname;
        this -> name = name;
        this -> patronymic = patronymic;
        this -> day = day;
        this -> month = month;
        this -> year = year;
        this -> year_of_receipt = year_of_receipt;
        this -> faculty = faculty;
        this -> department = department;
        this -> group = group;
        this -> gradebook_number = gradebook_number;
        this -> gender = gender;
    }
  
  void set() {
      set_name();
      set_surname();
      set_patronymic();
      set_gender();
      set_birthdate();
      set_year_of_receipt();
      set_faculty();
      set_department();
      set_group();
      set_gradebook_number();
  }
  
  void write() {
      ofstream output("Base.txt", std::ios::app);
      output << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
      
      output.close();
  }
  
  void set_name() {
      cout  <<  "Введите Имя Студента: ";
      cin >> name;
      clear_all();
  }
  void set_surname() {
      cout  <<  "Введите Фамилию Студента: ";
      cin >> surname;
      clear_all();
  }
  void set_patronymic() {
      cout  <<  "Введите Отчество Студента: ";
      cin >> patronymic;
      clear_all();
  }
  void set_gender() {
      cout  <<  "Введите Пол Студента: ";
      *gender = protect_ch();
  }
  void set_birthdate() {
      cout  <<  "Введите Дату Рождения Студента- [День Месяц год]: ";
      day = protect_day();
      month = protect_month();
      year = protect_year();
  }
  void set_year_of_receipt() {
      cout  << "Введите Дату Поступления Студента ";
      year_of_receipt = protect_year();
  }
  void set_faculty() {
      cout  << "Введите Название Факультета ";
      cin >> faculty;
      clear_all();
  }
  void set_department() {
      cout  << "Введите Название Кафедры ";
      cin >> department;
      clear_all();
  }
  void set_group() {
      cout  << "Введите Группу Студента ";
      cin >> group; 
      clear_all();
  }
  void set_gradebook_number() {
      cout  << "Введите Номер Студенческого Билета ";
      cin >> gradebook_number;
      clear_all();
  }
  

  
  void get() {
     get_name();
     get_surname();
     get_patronymic();
     get_gender();
     get_birthdate();
     get_year_of_receipt();
     get_faculty();
     get_department();
     get_group();
     get_gradebook_number();
  }
  
  void get_name() {
      cout << endl <<  "Имя Студента: ";
      cout << name;
  }
  void get_surname() {
      cout << endl <<  "Фамилия Студента: ";
      cout << surname;
  }
  void get_patronymic() {
      cout << endl <<  "Отчество Студента: ";
      cout << patronymic;
  }
  void get_gender() {
      cout << endl <<  "Пол Студента: ";
      cout << gender;
  }
  void get_birthdate() {
      cout << endl <<  "Дата Рождения Студента -[Д М Г]: ";
      cout << day << " " << month << " " << year;
  }
  void get_year_of_receipt() {
      cout << endl <<  "Дата Поступления Студента: ";
      cout << year_of_receipt;
  }
  void get_faculty() {
      cout << endl <<  "Факультет Студента: ";
      cout << faculty;
  }
  void get_department() {
      cout << endl <<  "Кафедра Студента: ";
      cout << department;
  }
  void get_group() {
      cout << endl <<  "Группа Студента: ";
      cout << group;
  }
  void get_gradebook_number() {
      cout << endl <<  "Номер Студенческого Билета: ";
      cout << gradebook_number;
  }
  
  char ret_gradebook_number() {
      return *gradebook_number;
  }
  char ret_name() const {
      return *name;
  }
  char ret_surname() const {
      return *surname;
  }
  char ret_patronymic() const {
      return *patronymic;
  }
  char ret_gender() const {
      return *gender;
  }
  int ret_day() const{
      return day;
  }
  int ret_month() const{
      return month;
  }
  int ret_year() const{
      return year;
  }
  int ret_year_of_receipt() const{
      return year_of_receipt;
  }
  char ret_faculty() const {
      return *faculty;
  }
  char ret_department() const {
      return *department;
  }
  char ret_group() const {
      return *group;
  }
  char ret_gradebook_number() const {
      return *gradebook_number;
  }
  
  void clear_all() {
	cin.seekg(0, ios::end);
	cin.clear();
  }
  
  ~Student() {
    delete surname;
    delete name;
    delete patronymic;
    delete faculty;
    delete department;
    delete group;
    delete gradebook_number;
  }
  
};

class Stud_marks : Core {
  private:
  int count;
  char gradebook_number[32];
  char number[32];
  int command;
  int matan;
  int phys;
  int practise;
  int inf_tech;
  int history;
  int english;
  public:
  
  friend class Student;
  friend class Core;
  friend class Menu;
  
  Stud_marks() {
      count = 0;
      check_marks();
  }
  
  void add_mark() {
      count++;
      
      cout << "Введите Номер Студенческого Билета: " << endl;
      cin >> gradebook_number; clear_all();
      cout << "Введите Оценку По Математике: ";
      cin >> matan; clear_all();
      cout << "Введите Оценку По Физике: ";
      cin >> phys; clear_all();
      cout << "Введите Оценку По Учебной практике: ";
      cin >> practise; clear_all();
      cout << "Введите Оценку По ЯП: ";
      cin >> inf_tech; clear_all();
      cout << "Введите Оценку По История: ";
      cin >> history; clear_all();
      cout << "Введите Оценку По Английский Язык: ";
      cin >> english; clear_all();
      
      ofstream output("SemMarks.txt", std::ios::app);
       output << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
       output.close();
        
  }
  
  void delete_mark() {
      ifstream input("SemMarks.txt", std::ios::app);
      ofstream output("Replaser.txt");
      cout << endl << "Введите Номер Студенческого Билета: " << endl;
      cin >> number;
      clear_all();
      check_marks();
      for (int i = 0; i < count; i++) {
        
        input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
        
        
        int tmp(1);
        for (int i = 0; i < 7; i++) {
            if (gradebook_number[i] != number[i]) {
                tmp = 0;
                break;
            }
        }
        if (tmp == 0) {
            output << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
        }
        
        
      }
      
      ifstream if_rewrite("Replaser.txt", std::ios::app);
      ofstream of_rewrite("SemMarks.txt");
      count -= 1;
      for (int i = 0; i < count; i++) {
          
          if_rewrite >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
          of_rewrite << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
          
      }
      cout << "Оценки Студента Удалены Из Списка" << endl;
      if_rewrite.close();
      of_rewrite.close();
      input.close();
      output.close();
  }
  
  void Change_Marks() {
      ifstream input("SemMarks.txt", std::ios::app);
      ofstream output("Replaser.txt");
      cout << endl << "Введите Номер Студенческого Билета: " << endl;
      cin >> number;
      clear_all();
      
      cout << endl;
      cout << "Что Вы Хотите Изменить? " << endl << endl;
      cout << "[1] Номер Студенческого Билета" << endl;
      cout << "[2] Математика" << endl;
      cout << "[3] Физика" << endl;
      cout << "[4] Учебная практика" << endl;
      cout << "[5] ЯП" << endl;
      cout << "[6] История" << endl;
      cout << "[7] Английский Язык" << endl;
      cout << "[8] Назад" << endl;
      cout << " > ";
      command = protect();
      
      check_marks();
      for (int i = 0; i < count; i++) {
        
        input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
        
        int tmp(1);
        for (int i = 0; i < 7; i++) {
            if (gradebook_number[i] != number[i]) {
                tmp = 0;
                break;
            }
        }
        
        if (tmp == 1) {
            switch(command) {
                case 1:
                {
                    cout << "Введите Новый Номер Студенческого Билета: ";
                    cin >> gradebook_number;
                    clear_all();
                    break;
                }
                case 2:
                {
                    cout << "Введите Оценку По Математике: ";
                    cin >> matan; clear_all();
                    break;
                }
                case 3:
                {
                    cout << "Введите Оценку По Физике: ";
                    cin >> phys; clear_all();
                    break;
                }
                case 4:
                {
                    cout << "Введите Оценку По Учебной практике: ";
                    cin >> practise; clear_all();
                    break;
                }
                case 5:
                {
                    cout << "Введите Оценку По ЯП: ";
                    cin >> inf_tech; clear_all();
                    break;
                }
                case 6:
                {
                    cout << "Введите Оценку По История: ";
                    cin >> history; clear_all();
                }
                case 7:
                {
                    cout << "Введите Оценку По Английский Язык: ";
                    cin >> english; clear_all();
                }
                case 8:
                {
                    break;
                }
            }
            output << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
        
        }
        else output << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
        
        
      }
      
      ifstream if_rewrite("Replaser.txt", std::ios::app);
      ofstream of_rewrite("SemMarks.txt");
      for (int i = 0; i < count; i++) {
          
          if_rewrite >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
          of_rewrite << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
          
      }
      cout << "Оценки Студента Изменены" << endl;
      if_rewrite.close();
      of_rewrite.close();
      input.close();
      output.close(); 
  }
  
  
  void Show_Marks() {
      check_marks();
      ifstream input("SemMarks.txt", std::ios::app);
      cout << "Номер Студенческого Билета | Математика | Физика | Учебная практика | ЯП | История | Английский язык" << endl;
      for (int i = 0; i < count; i++) {
        input >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
        cout << gradebook_number << " " << matan << " " << phys << " " << practise << " " << inf_tech << " " << history << " " << english << endl;
      }
      input.close();
  }
  
  void check_marks() {
      ifstream check("SemMarks.txt", std::ios::app);
      count = 0;
      while(!check.eof()) {
        count++;
        check >> gradebook_number >> matan >> phys >> practise >> inf_tech >> history >> english;
      }
      count--;
  }
  
  ~Stud_marks() {
      
  }
  
  void clear_all() {
    cin.seekg(0, ios::end);
	cin.clear();
  }
  
};

class Menu : Core {
  private:
    int command;
    int count;
    char surname[32];
    char name[32];
    char patronymic[32];
    int day;
	int month;
	int year;
    int year_of_receipt;
    char gender;
    char faculty[32];
    char department[32];
    char group[32];
    char gradebook_number[32];
    
    char number[32];
  public:
  
  friend class Core;
  friend class Student;
  friend class Task;
  friend class Stud_marks;
  
  Menu() {
      count = 0;
  }
  
  int welcome() {
    ifstream check("Base.txt");
    count = 0;
    while(!check.eof()) {
        count++;
        check >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
    }
    count--;
    cout << "WELCOME!" << endl << endl;
    cout << "[1] - Добавить студента" << endl;
    cout << "[2] - Удалить студента" << endl;
    cout << "[3] - Изменить данные студента" << endl;
    cout << "[4] - Вывести всю базу студентов" << endl;
    cout << "[5] - Найти студента по зачетке" << endl;
    cout << "[6] - Выполнение задачи" << endl;
    cout << "[7] - Редактор Оценок" << endl;
    cout << "[8] - Очистить экран" << endl;
    cout << "[9] - Выйти из программы" << endl;
    cout << " > ";
    command = protect();
    if (command == 1) {
        Student student;
        student.set();
        student.write();
        

        
        count++;
        cout << "Студент Добавлен в список" << endl << endl;
        welcome();
    }
    else if (command == 2) {
        Delete_Student();
        cout << endl;
        welcome();
    }
    else if (command == 3) {
        Change_Student();
        cout << endl;
        welcome();
    }
    else if (command == 4) {
        Show_Students();
        cout << endl;
        welcome();
    }
    else if (command == 5) {
        Find_Student();
        cout << endl;
        welcome();
    }
    else if (command == 6) {
        cout << "\033[2J\033[1;1H";
        Task ttask;
        ttask.task_menu();
        cout << endl;
        welcome();
    }
    else if (command == 7) {
        cout << "\033[2J\033[1;1H";
        Marks_menu();
    }
    else if (command == 8) {
        cout << "\033[2J\033[1;1H";
        welcome();
    }
    else if (command == 9) {
        return 0;
    }
    return 0;
  }
  
  void Marks_menu() {
      cout << "[1] - Добавить Оценки Студента (По Студенческому Билету)" << endl;
      cout << "[2] - Удалить Оценки Студента (По Студенческому Билету)" << endl;
      cout << "[3] - Изменить Оценки Студента (По Студенческому Билету)" << endl;
      cout << "[4] - Вывести весь список оценок" << endl;
      cout << "[5] - Назад" << endl;
      cout << " > ";
      int command = protect_marks();
      
      switch(command) {
          case 1: {
              Stud_marks Marks;
              Marks.add_mark();
              cout << endl;
              Marks_menu();
              break;
          }
          case 2: {
              Stud_marks Marks;
              Marks.delete_mark();
              cout << endl;
              Marks_menu();
              break;
          }
          case 3: {
              cout << endl;
              Stud_marks Marks;
              Marks.Change_Marks();
              Marks_menu();
              break;
          }
          case 4: {
              Stud_marks Marks;
              Marks.Show_Marks();
              cout << endl;
              Marks_menu();
              break;
          }
          case 5: {
              cout << "\033[2J\033[1;1H";
              welcome();
              break;
          }
      }
  }
  
  void Show_Students() {
      ifstream input("Base.txt");
      cout << endl;
      int counter = 0;
      for (int i = 0; i < count; i++) {
          input >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
          
          
          counter++;
          cout << "(" << counter << ")" << endl;
          cout << "ФИО(пол): " << surname << " " << name << " " << patronymic << " (" << gender << ") " << endl;
          cout << "Дата Рождения, Дата поступления: " << day << " " << month << " " << year << ", " << year_of_receipt << endl;
          cout << "Номер Студенческого Билета, Группа, Факультет, Кафедра: " << gradebook_number << " " << group << " " << faculty << " " << department << endl << endl;
          
      }
      
      input.close();
  }
  
  void Delete_Student() {
      ifstream input("Base.txt", std::ios::app);
      ofstream output("Replaser.txt");
      cout << endl << "Введите Номер Студенческого Билета: " << endl;
      cin >> number;
      clear_all();
      
      for (int i = 0; i < count; i++) {
        
        input >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        
        
        int tmp(1);
        for (int i = 0; i < 7; i++) {
            if (gradebook_number[i] != number[i]) {
                tmp = 0;
                break;
            }
        }
        if (tmp == 0) {
            output << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
        
        }
        
        
      }
      
      ifstream if_rewrite("Replaser.txt", std::ios::app);
      ofstream of_rewrite("Base.txt");
      count-=1;
      for (int i = 0; i < count; i++) {
          
          if_rewrite >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
          of_rewrite << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
          
      }
      cout << "Студент Удален Из Списка" << endl;
      if_rewrite.close();
      of_rewrite.close();
      input.close();
      output.close();
  }
  
  void Change_Student() {
      ifstream input("Base.txt", std::ios::app);
      ofstream output("Replaser.txt");
      cout << endl << "Введите Номер Студенческого Билета: " << endl;
      cin >> number;
      clear_all();
      
      cout << endl;
      cout << "Что Вы Хотите Изменить? " << endl << endl;
      cout << "[1] ФИО, Пол" << endl;
      cout << "[2] {День, Месяц, Год} - Рождения и Год Поступления" << endl;
      cout << "[3] Факультет, Кафедра, Группа" << endl;
      cout << "[4] Номер Студенческого Билета" << endl;
      cout << " > ";
      command = protect_change();
      
      
      for (int i = 0; i < count; i++) {
        
        input >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        
        int tmp(1);
        for (int i = 0; i < 7; i++) {
            if (gradebook_number[i] != number[i]) {
                tmp = 0;
                break;
            }
        }
        
        if (tmp == 1) {
            switch(command) {
                case 1:
                {
                    cout << "Введите ФИО и Пол{M/F} Студента: " << endl;
                    cin >> surname >> name >> patronymic >> gender;
                    clear_all();
                    break;
                }
                case 2:
                {
                    cout << "Введите {День, Месяц, Год} - Рождения и Год Поступления: " << endl;
                    day = protect_day();
                    month = protect_month();
                    year = protect_year();
                    year_of_receipt = protect_year();
                    break;
                }
                case 3:
                {
                    cout << "Введите Название Факультета, Кафедры, Группы" << endl;
                    cin >> faculty >> department >> group;
                    clear_all();
                    break;
                }
                case 4:
                {
                    cout << "Введите Новый Номер Студенческого Билета" << endl;
                    cin >> gradebook_number;
                    clear_all();
                    break;
                }
            }
            output << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
        
        }
        else output << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
        
        
      }
      
      ifstream if_rewrite("Replaser.txt", std::ios::app);
      ofstream of_rewrite("Base.txt");
      for (int i = 0; i < count; i++) {
          
          if_rewrite >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
          of_rewrite << gradebook_number << " " << name << " " << surname << " " << patronymic << " " << gender << " " << day << " " << month << " " << year << " " << year_of_receipt << " " << faculty << " " << department << " " << group << endl;
          
      }
      cout << "Студент Изменен" << endl;
      if_rewrite.close();
      of_rewrite.close();
      input.close();
      output.close(); 
  }
  
  void Find_Student() {
      ifstream input("Base.txt", std::ios::app);
      int C_tmp(0);
      
      cout << endl << "Введите Номер Студенческого Билета: " << endl;
      cin >> number;
      clear_all();
      
      for (int i = 0; i < count; i++) {
        
        input >> gradebook_number >> name >> surname >> patronymic >> gender >> day >> month >> year >> year_of_receipt >> faculty >> department >> group;
        
        
        int tmp(1);
        for (int i = 0; i < 7; i++) {
            if (gradebook_number[i] != number[i]) {
                tmp = 0;
                break;
            }
        }
        
        if (tmp == 1) {
            cout << endl <<  "Имя Студента: ";
            cout << name;
            cout << endl <<  "Фамилия Студента: ";
            cout << surname;
            cout << endl <<  "Отчество Студента: ";
            cout << patronymic;
            cout << endl <<  "Пол Студента: ";
            cout << gender;
            cout << endl <<  "Дата Рождения Студента {Д,М,Г}: ";
            cout << day << " " << month << " " << year;
            cout << endl <<  "Дата Поступления Студента: ";
            cout << year_of_receipt;
            cout << endl <<  "Факультет Студента: ";
            cout << faculty;
            cout << endl <<  "Кафедра Студента: ";
            cout << department;
            cout << endl <<  "Группа Студента: ";
            cout << group;
            cout << endl <<  "Номер Студенческого Билета: ";
            cout << gradebook_number;
            cout << endl << endl;
            C_tmp = 1;
            break;
        }
        
      }
      input.close();
      
      if (C_tmp == 0) cout << "Студент Не Найден" << endl << endl;
  }
  
  void clear_all() {
    cin.seekg(0, ios::end);
	cin.clear();
  }
  
  ~Menu() {
    
  }
};

int main() {
    Menu menu;
    menu.welcome();
    return 0;
}

