#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct datum_rodjenja{
    int d, m, g;
};

class Student{
public:
    string ime, prezime;
    double prosjek;
    struct datum_rodjenja dr;
    Student(){
        dr.d = dr.m = 1;
        dr.g = 2000;
    }
};

#define MAX_STUDENTS 15
void get_student(Student& st);
void define_students(vector<Student>& studenti);
void sort(vector<Student>& studenti);
int find_student_by_grade(vector<Student> studenti, double prosjek);

int main(void){
    vector<Student> studenti;
    define_students(studenti);
    double target_prosjek;
    
    cout << "Unesi prosjek studenta za pretragu: ";
        cin >> target_prosjek;
    
    int res = find_student_by_grade(studenti, target_prosjek);
    if (res == -1) cout << "Student sa prosjekom " << target_prosjek << " nije pronadjen." << endl;
    else{
        Student p = studenti[res];
        cout << "Pronadjen je student sa prosjekom " << target_prosjek << ":" << endl;
        cout << p.ime << " " << p.prezime << " | " << p.prosjek << endl;
    }

    return 0;
}

void get_student(Student *st){
    cout << "Ime: ";
        cin >> st->ime;

    cout << "Prezime: ";
        cin >> st->prezime;

    cout << "Prosjek: ";
        cin >> st->prosjek;

    cout << "Datum rodjenja: ";
        cin >> st->dr.d >> st->dr.m >> st->dr.g;
}

void define_students(vector<Student>& studenti){
    int n;
    do{
        cout << "Unesi broj studenata: ";
        cin >> n;
    } while (n < 1 || n > MAX_STUDENTS);

    for (int i = 0; i < n; i++){
        Student *new_student = new Student;
        get_student(new_student);
        studenti.push_back(*new_student);
    }
}

void sort(vector<Student>& studenti){
    int i, j, h;
    Student temp;
    int size = studenti.size();

    for (h = size / 2; h > 0; h /= 2){
        for (i = 1; i < size; i++){
            temp = studenti[i];
            for (j = i; j >= h && temp.prosjek < studenti[j - h].prosjek; j -= h)
                studenti[j] = studenti[j - h];
            studenti[j] = temp;
        }
    }
}

int find_student_by_grade(vector<Student> studenti, double prosjek){
    int beg = 0, end = studenti.size() - 1, mid;

    do{
        mid = (beg + end) / 2;
        Student curr = studenti[mid];

        if (curr.prosjek == prosjek) return mid;

        if (prosjek > curr.prosjek) beg = mid + 1;
        if (prosjek < curr.prosjek) end = mid - 1;

    } while (beg <= end);

    return -1;
}