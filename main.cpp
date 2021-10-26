#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string name;
    string author;
public:
    Book(const string &name, const string &author) {
        this->author = author;
        this->name = name;
    }

    const string &getName() const {
        return name;
    }

    const string &getAuthor() const {
        return author;
    }

};

class Library {
private:
    vector<Book> book;
    unsigned short count;
public:
    explicit Library(vector<Book> &book) {
        this->book = book;
    }

    Library(int count) {
        this->count = count;
    }

    ~Library() {
        book.clear();
    }

    bool SearchByName(string &name){

        for(unsigned short i = 0; i < count; i++)
            if(name == book[i].getName())
                return true;
    }

    bool SearchByAuthor(string &author){

        for(unsigned short i = 0; i < count; i++)
            if(author == book[i].getAuthor())
                return true;
    }

    bool SearchBoth(const Book &BOOK) {

        for(unsigned short i = 0; i < count; i++)
            if((BOOK.getAuthor() == book[i].getAuthor()) && (BOOK.getName() == book[i].getName()))
                return true;
    }
};

class Librarian : public Library {
private:
    string LName;
public:
    Librarian(vector<Book> book, string Name) : Library(book) {
        LName = Name;
    }

    void getBookByName(string name) {
        if (SearchByName(name))
            cout << "Книга найдена по названию. Держите книгу " << name << endl;
    }

    void getBookByAuthor(string author) {
        if (SearchByAuthor(author))
            cout << "Книга найдена по автору. Держите книгу автора " << author <<  endl;
    }

    void getBookByBoth(string name, string author) {
        if (SearchBoth({name, author}))
            cout << "Книга найдена по названию и автору. Держите книгу " << name << " автора " << author << endl;
    }
};

int main() {
    Library(7);
    Book book1{"Вино из одуванчиков", "Рей Брэдбери"};
    Book book2{"Заводной апельсин", "А.Пушкин"};
    Book book3{"Война и мир", "Л.Толстой"};
    Book book4{"Герой нашего времени", "М.Лермонтов"};
    Book book5{"Преступление и наказание", "Ф.Достоевский"};
    Book book6{"Отцы и дети", "И.Тургенев"};
    Book book7{"Евгений Онегин", "А.Пушкин"};

    vector<Book> book = {
            book1,
            book2,
            book3,
            book4,
            book5,
            book6,
            book7
    };
    Library library(book);

    Librarian librarian(book, "librarian");

    librarian.getBookByName("Вино из одуванчиков");
    librarian.getBookByAuthor("А.Пушкин");
    librarian.getBookByBoth("Война и мир", "Л.Толстой");
}