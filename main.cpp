#include <iostream>
#include <string>
#include <fstream>









//Lukasz Szczurek
using namespace std;


struct Student {
    int id;
    string name;
    string group;
    struct exam {
        bool isPassed;
        unsigned char grade;
        float score;
    } e1, e2, e3, e4;
} r1;


std::istream& SubInputStream(std::istream& input,
                             Student::exam& exam) {
    input >> exam.isPassed;
    int tmp = 0;
    input >> tmp;
    exam.grade = tmp;
    input >> exam.score;

    return input;
}

std::ostream& SubOutputStream(std::ostream& output,
                              const Student::exam& exam) {
    output << exam.isPassed << " " << (int)exam.grade << " " << exam.score
           << std::endl;

    return output;
}

std::istream& InputStream(std::istream& input, Student& student) {
    input >> student.id;
    std::getline(input, student.name);  // Double to skip \n after int
    std::getline(input, student.name);

    std::getline(input,student.group);

    SubInputStream(input, student.e1);
    SubInputStream(input, student.e2);
    SubInputStream(input, student.e3);
    SubInputStream(input, student.e4);

    return input;
}

std::ostream& OutputStream(std::ostream& output, const Student& student) {
    output << student.id << std::endl
           << student.name << std::endl
           << student.group << std::endl;

    SubOutputStream(output, student.e1);
    SubOutputStream(output, student.e2);
    SubOutputStream(output, student.e3);
    SubOutputStream(output, student.e4);

    return output;
}



int recordCounter(string f1){

    ifstream plik;
    //
    plik.open(f1.c_str());
    Student student;
    int liczba = 0;

    while (InputStream(plik,student)){

        liczba++;
    }
    return liczba;
}


void SortIntIter(string f1,string f2,int ileSort,int ilePrzek){
    Student student;
    ifstream wejscie;
    wejscie.open(f1.c_str());
    ofstream wyjscie;
    wyjscie.open(f2.c_str());

    InputStream(wejscie,student);

    for(int i=1;i<ileSort;i++){
        Student student2;
        InputStream(wejscie,student2);
        if(student.id < student2.id){
            OutputStream(wyjscie,student);
            student = student2;

        }



        else{
            OutputStream(wyjscie,student2);
        }

    }
    OutputStream(wyjscie,student);
    for(int i=0;i<ilePrzek;i++){
        InputStream(wejscie,student);
        OutputStream(wyjscie,student);
    }

}
void Copy(std::string from, std::string to) {
    fstream fFrom;
    std::fstream fTo;
    fFrom.open(from.c_str());
    fTo.open(to.c_str());

    Student data;
    while (InputStream(fFrom, data)) {
        OutputStream(fTo, data);
    }

    fFrom.close();
    fTo.close();
}




void SortInt(string f1,string f2,string f3){
    int n= recordCounter(f1);
    cout << n << endl;
    Copy(f1,f2);
    for(int i=n;i>0;i--){
        if((n-i)%2 == 0 ){
            SortIntIter(f2,f3,i,n-i);

        } else{
            SortIntIter(f3,f2,i,n-i);
        }
    }
    if(n % 2 == 0){
        Copy(f2,f1);

    } else{
        Copy(f3,f1);
    }





}



void Writer(fstream &fr,fstream &to,Student& student){
    Student next;
}

void Series(fstream &fr, fstream &to, Student &student){
    Student next;
    OutputStream(to,next);
    student = next;

}




