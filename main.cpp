// Automaton tester
#include "nfa.cpp"
int main(int argc, char const *argv[]) {
  //Pass automaton data filename and string to NDFA class, else end program
  if (argv[1] && argv[2]) {
    std::string automatonFilename(argv[1]);
    std::string testString(argv[2]);
    // This constructor runs test
    NFA x(automatonFilename, testString);
    return 0;
  } else {
    std::cout << "/* Missing arguments */" << '\n';
    return -1;
  }
}
