#include <iostream>
#include <string>
#include <vector>

class Window_mgr;

class Screen {
    friend Window_mgr;
    public:
        using pos = std::string::size_type;
        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {  }
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {  }

        char get() const { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos);
        Screen &set(char);
        Screen &set(pos, pos, char);

        void some_member() const;
    
        Screen &display(std::ostream &os) { do_display(os); return *this; }
        const Screen &display(std::ostream &os) const { do_display(os); return *this; }

    private:
        void do_display(std::ostream &os) const { os << contents; }
        mutable size_t access_ctr;
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;

    return *this;
}

inline
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
void Screen::some_member() const {
    ++access_ctr;
}

inline
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;
    return *this;
}

void Window_mgr::clear(Window_mgr::ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);

    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}

