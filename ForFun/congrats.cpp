#include <iostream>
#include <string>


int main() {


    std::cout << "What's your name?:  ";
    std::string n;
    std::getline(std::cin, n);

    std::string t[] = {
        "       .''.             *''*    :_\\/_:     .\n",
        "    |     ^&     |      Y}     +!     !  \n",
        "      :_\\/_:   .    .:.*_\\/_*   : /\\ :  .'.:.'.\n",
        "    1-     =+_:!     +     ><     ?  \n",
        "  .''.: /\\ : _\\(/_  ':'* /\\ *  : '..'.  -=:o:=-\n",
        "    !#     $     $%     $     ^     &     *^% @&  \n",
        " :_\\/_:'.:::. /)\\*''*  .|.* '.\\'/.'_\\(/_ '.'.'\n",
        "    _*      Y     }     @     +     *     ^     d  \n",
        " : /\\ : :::::  '*_\\/_* | |  -= o =- /)\\    '  *\n",
        "    &    *!*!    $*!v     #    !v     #    &   &   \n",
        "  '..'  ':::'   * /\\ * |'|  .'/ \\.\\'.  '._____\n",
        "    %&*      ^#@    ^ @^                   cvfvffff \n",
        "      *        __*..* |  |     :      |.   |' .---\"|\n",
        "    ] @^@^@^   ~!@8^& (*(*          567 $^&   %#   \n",
        "       _*   .-'   '-. |  |     .--'|  ||   | _|    |\n",
        "    *&^%           $  #^  $$    !@ #         55 77$ \n",
        "    .-'|  _.|  |    ||   '-__  |   |  |    ||      |\n",
        "    *    &^&^%       # 5    y5      @%    $    @  \n",
        "    |' | |.    |    ||       | |   |  |    ||      |\n",
        "    ^    *(  d   )$564  ##$   !!@#   34%      7   ^  \n",
        " ___|  '-'     '    \"\"       '-'   '-.'    '`      |____\n"
    };

    for (int i = 0; i < 21; i++) {
        if (i % 2 == 0) {
            std::cout << t[i];
        }
    }

    int totalLen = 55;
    int textLen = n.length();
    int leftSpaces = (totalLen - textLen) / 2;
    int rightSpaces = totalLen - textLen - leftSpaces;
    std::cout << "|                                                       |\n";
    std::cout << "|";
    for (int i = 0; i < leftSpaces-14; ++i) {
        std::cout << " ";
    }
    std::cout << "Happy Birthday " << n << "!!!";
    for (int i = 0; i < rightSpaces-4; ++i) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "|                                                       |\n";

    return 0;
}


//Fireworks over city - Cleveland by Joan Stark